

//#define MY_RX 14
//#define MY_TX 15
#include <stdio.h>
#include <string.h>
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "pico/stdlib.h"
#include "RX_pio.pio.h"
#include "TX_pio.pio.h"

#define MY_LED 16
#define MY_RX 14
#define MY_TX 15
#define BIGDATA_COL 100
#define BIGDATA_ROWS 10
#define SIZE_TX 100
#define SIZE_RX 100

volatile uint8_t TX_count=0; 
repeating_timer_t TX_timer;

volatile uint32_t rxdata[SIZE_RX];
volatile uint32_t txdata[SIZE_TX];
volatile char bigdata[BIGDATA_ROWS][BIGDATA_COL];
volatile bool row_rdy[BIGDATA_ROWS];

volatile int chan_rx=0;
volatile int chan_tx=0;
volatile int count=0;
int bd_row=0;
const char mess_d1mini[]="hello d1 mini\n";


void setup ();
void config_dma(pio_hw_t* pio,dma_channel_config c, uint8_t sm, bool is_tx, int chan, size_t size);
void RX_handler();
void TX_handler();
int cpy_charto32(volatile uint32_t* dst, char* src, size_t size_dst,size_t size_src);
int cpy_32tochar(char* dst,volatile uint32_t* src, size_t size_dst,size_t size_src);
void get_string(volatile char *data,size_t size,char*str);
int my_print(volatile char* data, size_t size);

//void transmit();
//bool TX_timer_callback(repeating_timer_t *TX_timer);

void setup(){
	gpio_init(MY_LED);
        gpio_set_dir(MY_LED, GPIO_OUT);
        gpio_put(MY_LED, 1);
}


void RX_dma_handler(){

 	//clear interrupt
	dma_channel_acknowledge_irq0(chan_rx);
	/*
	if(bd_row<BIGDATA_ROWS&&(row_rdy[bd_row]==false)){
	
		for(int i=0;i<100;i++){
			bigdata[bd_row][i]=(char)rxdata[i];
			if(rxdata[i]=='\n'){break;}
		}
	
		row_rdy[bd_row]=true;
		bd_row++;
	}
	if(bd_row>=BIGDATA_ROWS){bd_row=0;}
*/
	dma_channel_set_write_addr(chan_rx, &rxdata[0], true);


}


void TX_dma_handler(){
	dma_channel_acknowledge_irq1(chan_tx);
	dma_channel_set_read_addr(chan_tx, &txdata[0], true);

}


void config_dma(pio_hw_t* pio,dma_channel_config c, uint8_t sm, bool is_tx, int chan, size_t size) {
	//get dma dreq for pio
	uint8_t dreq=pio_get_dreq(pio, sm, is_tx);
	
	if(is_tx){
		dma_channel_config c = dma_channel_get_default_config(chan);
	        channel_config_set_transfer_data_size(&c, DMA_SIZE_8);
	        channel_config_set_read_increment(&c, true);
	        channel_config_set_write_increment(&c, false);

		//dreq doesnt start transmiisson, by transmission is paced by dreq signals
		channel_config_set_dreq(&c,dreq);

	        dma_channel_configure(
	                chan,          // Channel to be configured
	                &c,        // The configuration we just created
	                &pio0_hw->txf[sm],// The initial write address
			txdata,            // The initial read address, data to send
	                size, // Number of transfers; in this case each is 1 byte.
	                true           // Start immediately. <-dreq dosent start
	        );
	//	dma_channel_set_irq0_enabled(chan, true);


	}


	else {
		dma_channel_config c = dma_channel_get_default_config(chan);
	        channel_config_set_transfer_data_size(&c, DMA_SIZE_8);
	        channel_config_set_read_increment(&c, false);
	        channel_config_set_write_increment(&c, true);

		//dreq doesnt start transmiisson, by transmission is paced by dreq signals
		channel_config_set_dreq(&c,dreq);

	        dma_channel_configure(
	                chan,          // Channel to be configured
	                &c,        // The configuration we just created
	                rxdata,           // The initial write address
	                &pio0_hw->rxf[sm],           // The initial read address
	                size, // Number of transfers; in this case each is 1 byte.
	                true           // Start immediately. <-dreq dosent start
	        );

	}

}

int cpy_charto32(volatile uint32_t* dst, char* src, size_t size_dst,size_t size_src){

	if(size_dst>=size_src){	
		for (int i=0;i<size_src;i++){
			dst[i]=(int)src[i];

		}
		return 0;
	}

	return -1;

}


int cpy_32tochar(char* dst,volatile uint32_t* src, size_t size_dst,size_t size_src){

	
	if(size_dst>=size_src){	
		for (int i=0;i<size_src;i++){
			dst[i]=(char)src[i];

		}
		return 0;
	}

	return -1;

}


void get_string(volatile char *data,size_t size,char*str){
	for(int i=0;i<size;i++){
		if(data[i]=='\n'){
			//cpy_32tochar(str, data, size,size);
			break;
		}	
	}
}
int my_print(volatile char * data, size_t size){
	char a=0;
	for (int i=0;i<size;i++){
		if(data[i]=='\n'){
			printf("\n");
			return 0;	
		}
		a=(char)*data;
		printf("%c",a);
	}
	return -1;
}
int main(){
	
	stdio_init_all();
	
	// setup gpio
	setup();
	
	//wait so we can have time to connect via putty
	sleep_ms(5500);
	puts("hello d1 mini");

//start of pio conf

	//choose pio from 0 or 1	
	PIO pio=pio0;

	//claim state machine
	uint sm_rx =pio_claim_unused_sm(pio,true);
	uint sm_tx =pio_claim_unused_sm(pio,true);
	
	//return offset of the program
	uint offset_rx=pio_add_program(pio, &pio_uart_RX_program);
	uint offset_tx=pio_add_program(pio, &pio_uart_TX_program);
	
	//get clocking speed and set dividers
	uint32_t clk=clock_get_hz(clk_sys);
	float div_rx =0;	
	float div_tx =0;
	static const uint rx_freq=9600*6;
	static const uint tx_freq=9600;
	
	div_tx= (float) (clk / tx_freq);
	div_rx= (float) (clk / rx_freq);
	
	pio_uart_RX_program_init(pio, sm_rx, offset_rx, MY_RX, div_rx); 
	pio_uart_TX_program_init(pio, sm_tx, offset_tx, MY_TX, div_tx); 
		
	pio_sm_set_enabled(pio, sm_rx, true);
	pio_sm_set_enabled(pio, sm_tx, true);
	
	//rx fifo has one word in by default so we must get rid of it
	uint32_t test;
	test=pio_sm_get_blocking(pio,sm_rx);
	
//end of pio conf


//setup DMA CHANNELS

	for(int i=0;i<100;i++){
		rxdata[i]=0;
	}
	
	size_t size_dst=sizeof(mess_d1mini)/sizeof(mess_d1mini[0]);
	
	if(cpy_charto32(txdata,mess_d1mini,SIZE_TX,size_dst)==-1){
		printf("cpying error\n");
	}

	chan_tx = dma_claim_unused_channel(true);
	chan_rx = dma_claim_unused_channel(true);

	dma_channel_config dma_tx = dma_channel_get_default_config(chan_tx);
	dma_channel_config dma_rx = dma_channel_get_default_config(chan_rx);

	dma_channel_set_irq0_enabled(chan_rx, true);
	dma_channel_set_irq1_enabled(chan_tx, true);

	// Configure the processor to run dma_handler() when DMA IRQ 0 is asserted
	irq_set_exclusive_handler(DMA_IRQ_0, RX_dma_handler);
	irq_set_enabled(DMA_IRQ_0, true);

	// Configure the processor to run dma_handler() when DMA IRQ 1 is asserted
	irq_set_exclusive_handler(DMA_IRQ_1, TX_dma_handler);
	irq_set_enabled(DMA_IRQ_1, true);
	
	printf("transmission starting\n");
	config_dma(pio,dma_rx,sm_rx,false,chan_rx,SIZE_RX);
	config_dma(pio,dma_tx,sm_tx,true,chan_tx,SIZE_TX);

//end of DMA conf
	


	puts("starting reading\n");
//end of conf, starting infinite loop
	while(1){
		for(int i=0;i<BIGDATA_ROWS;i++){
			if(row_rdy[i]){	
				printf("i=%d ",i);
				printf("%s",bigdata[i]);
			//	my_print(bigdata[i],BIGDATA_COL);
				memset(bigdata[i],0,BIGDATA_ROWS);
				row_rdy[i]=false;
				printf("\n");
			}
		}
		puts("loop end rows done\n");
	        gpio_put(MY_LED, 1);
		sleep_ms(500);
	        gpio_put(MY_LED, 0);
		sleep_ms(500);
	}


}
	//size_t bd_size=sizeof(bigdata)/sizeof(bigdata[0]);
	//char c=0;
	
//	for(int i=0; i<bd_size;i++){
	//	c=(char)bigdata[i];
	//size_t size_big=sizeof(bigdata)/sizeof(bigdata[0]);
	//char str[size_big];
	//get_string(bigdata,size_big,str);
//	}
	
	//while(1){
		//processor retiring and baking bread
	//	tight_loop_contents();
	//}


