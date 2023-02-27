

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
#define SIZE_ROW 5
#define SIZE_COL 400
#define SIZE_TX 100


volatile uint32_t rxdata[SIZE_ROW][SIZE_COL];
volatile uint32_t txdata[SIZE_TX];

volatile bool row_rdy[SIZE_ROW];
volatile bool TX_ended=false;
volatile int chan_rx=0;
volatile int chan_tx=0;
volatile int count=0;
volatile int bd_row=0;
const char mess_d1mini[]="{h}";


void setup ();
void config_dma(pio_hw_t* pio,dma_channel_config c, uint8_t sm, bool is_tx, int chan, size_t size);
void RX_handler();
void TX_handler();
int cpy_charto32(volatile uint32_t* dst, char* src, size_t size_dst,size_t size_src);
int cpy_32tochar(char* dst,volatile uint32_t* src, size_t size_dst,size_t size_src);
int get_string(volatile uint32_t *data,size_t size,char*str,int *dlug);


void setup(){
	gpio_init(MY_LED);
        gpio_set_dir(MY_LED, GPIO_OUT);
        gpio_put(MY_LED, 1);
}


void RX_dma_handler(){

 	//clear interrupt
	dma_channel_acknowledge_irq0(chan_rx);
	dma_channel_set_irq0_enabled(chan_rx,false);
	row_rdy[bd_row]=true;
	//printf("row %d is ready\n",bd_row);
	//printf("rxdata: ");
	//for(int i=0; i<SIZE_COL;i++){
	//	printf("%c",rxdata[bd_row][i]);
	//}
	//printf("\n");
	count++;
	bd_row++;
	if(bd_row>=SIZE_ROW){bd_row=0;}
	//printf("row %d is working\n",bd_row);
	//printf("count %d is \n",count);

	dma_channel_set_write_addr(chan_rx, &rxdata[bd_row], true);
	dma_channel_set_irq0_enabled(chan_rx,true);


}


void TX_dma_handler(){
	dma_channel_acknowledge_irq1(chan_tx);
	dma_channel_set_irq1_enabled(chan_tx,false);

	//printf("TX HANDLER\n");

	TX_ended=true;
	dma_channel_set_irq1_enabled(chan_tx,true);

}


void config_dma(pio_hw_t* pio,dma_channel_config c, uint8_t sm, bool is_tx, int chan, size_t size) {
	//get dma dreq for pio
	uint8_t dreq=pio_get_dreq(pio, sm, is_tx);
	
	if(is_tx){
		dma_channel_config c = dma_channel_get_default_config(chan);
	        channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
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
	        channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
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

int get_string(volatile uint32_t *data,size_t size,char*str,int *dlug){
	int beg=-1;
	int end=-1;
	int ret=-1;
	//ret==-1 { or }  not found
	//ret==0 found { 
	//ret==1 found } 
	//ret==2 found { and }
//	printf("start get string\n");

	for(int i=0;i<size;i++){
		if(data[i]=='{' && beg==-1){
			beg=i;//found beg
//			printf("in for found {\n");
			continue;
		}
		else if(data[i]=='}'){
			end=i;//found end
//			printf("in for found }\n");
			break;
		}
	}
//	printf("ended search\n");

	//found nothing
	if(beg==-1 && end==-1){
		printf("found nothing in get string\n");
		for(int i=0;i<size;i++){
			printf("\n char[ %d ]=%c\n",i,str[i]);
		}
		ret=-1;
		sleep_ms(100000);
	}

	//found only begining 
	else if(beg!=-1 && end==-1){
		ret=0;		
		int ile_char=(size-beg);
		*dlug=size;
		//printf("found beg\n");
		//printf("beg is %d\n",beg);
		//printf(	"ile_char is %d\n",ile_char);
		//printf(	"dlug is %d\n",*dlug);

		//for(int i=beg;i<=ile_char;i++){
		//	printf("\n char[ %d ]=%c\n",i,data[i]);
//		}
		cpy_32tochar(str, &data[beg], size,  ile_char);
		//for(int i=0;i<ile_char;i++){
		//	printf("\n char[ %d ]=%c\n",i,str[i]);
		//}
		//printf("&data[0][ilechar] is %d\n",&data[ile_char]);

	}

	//found end 
	else if(beg==-1 && end!=-1){
		ret=1;
		//printf("only found end\n");
		//printf("end is %d\n",end);
		int ile_char=end+1;
		*dlug=end+1;
		cpy_32tochar(str, &data[0], size,  ile_char);
	}

	//found begining and end 
	else if(beg!=-1 && end!=-1){
 		int ile_char=(end-beg+1);
		*dlug=end+1;
		//printf("found beg and end\n");
		//printf("beg is %d\n",beg);
		//printf("end is %d\n",end);
		cpy_32tochar(str, &data[beg], size, ile_char);
		ret=2;
	}
	
	return ret;
}


int main(){
	
	stdio_init_all();
	
	// setup gpio
	setup();
	
	//wait so we can have time to connect via putty
	sleep_ms(5500);
	puts(mess_d1mini);

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

	for(int j=0;j<SIZE_ROW;j++){
		for(int i=0;i<SIZE_COL;i++){
			rxdata[j][i]=0;
		}
		row_rdy[j]=false;
	}
	
	size_t size_src=sizeof(mess_d1mini)/sizeof(mess_d1mini[0]);
	printf("size const %d\n",size_src);
	if(cpy_charto32(txdata,mess_d1mini,SIZE_TX,size_src)==-1){
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
	config_dma(pio,dma_rx,sm_rx,false,chan_rx,SIZE_COL);
	config_dma(pio,dma_tx,sm_tx,true,chan_tx,size_src);

//end of DMA conf
	
	

	puts("starting reading\n");
//end of conf, starting infinite loop
	bool jest_pocz=false;
	char str_pocz[SIZE_COL+1]={0};

	while(1){
		sleep_ms(1);	
	
		for(int i=0;i<SIZE_ROW;i++){

			if(row_rdy[i]==true){
				int ret=0;
				int dlug=0;
				//ret==-1 { or }  not found
				//ret==0 found { 
				//ret==1 found } 
				//ret==2 found { and }
				//printf("rxdata[0][99] is %c\n",rxdata[0][99]);
				//printf("rxdata[1][0] is %c\n",rxdata[1][0]);
				//printf("&rxdata[0][99] is %d\n",&rxdata[0][99]);

				//printf("bd_row: %d, count: %d\n",bd_row,count);
				for (int j=0;j<SIZE_COL;){
					char str[SIZE_COL+1]={0};
					//sleep_ms(1000);
		//			printf("\nstart\n");					
		//			printf("&rxdata[i][j] is %d\n",&rxdata[i][j]);
		//			printf("rxdata[i][j] is %c\n",rxdata[i][j]);
				//	printf("j is %d\n",j);
		//			printf("SIZE_COL-j is is %d\n",(SIZE_COL-j));
					//str				
		//			printf("&dlug is %d\n",dlug);
					ret=get_string(&rxdata[i][j],(SIZE_COL-j),str,&dlug);
		//			printf("str is %s\n",str);
		//			printf("&dlug is %d\n",dlug);
		//			printf("\n end\n\n");										

					j=j+dlug;
					if(ret==-1 && jest_pocz!=true){
						printf("string not found\n");
						jest_pocz=false;
						memset(str_pocz,0,SIZE_COL+1);
						break;
					}

					else if (ret==0){
						//printf("znaleziono poczatek\n");

						//printf("str\n");
						//for(int i=0;i<sizeof(str_pocz)/sizeof(str[0]);i++){
						//	printf("\n char[ %d ]=%c\n",i,str[i]);
						//}
						strcpy(str_pocz,str);
						//printf("\n\n str_pocz\n");
						

						jest_pocz=true;
	
					}

					else if (ret==1){

						if(jest_pocz==true){
							
						//	printf("znaleziono dwie polowy str\n");
							//printf("str[0] is %c\n",str[0]);
						
						 //	for(int i=0;i<sizeof(str_pocz)/sizeof(str_pocz[0]);i++){
                                                 //     	printf("\n char[ %d ]=%c\n",i,str_pocz[i]);
                                               	 //	}	
						//	printf("i=%d ",i);
							printf("%s",str_pocz);
							printf("%s",str);
							printf("\n");
						}
						jest_pocz=false;
						memset(str_pocz,0,SIZE_COL+1);
						//sleep_ms(100000);
					}

					else if(ret==2){
						//printf("znaleziono caly str\n");
						//printf("i=%d ",i);
						printf("%s",str);
						printf("\n");
						memset(str_pocz,0,SIZE_COL+1);
					}

				}
				row_rdy[i]=false;

			}
		}
		//puts("loop end rows done\n");
	        //gpio_put(MY_LED, 1);
		//sleep_ms(500);
	        //gpio_put(MY_LED, 0);
		//sleep_ms(500);
		if(TX_ended){
			dma_channel_set_read_addr(chan_tx, &txdata[0], true);
			TX_ended=false;
		}

	}


}
