/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//#define MY_RX 14
//#define MY_TX 15
#define MY_LED 16
#define MY_RX 14
#define MY_TX 15

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "RX_pio.pio.h"
#include "TX_pio.pio.h"

volatile uint8_t TX_count=0; 
repeating_timer_t TX_timer;

void setup ();
//void transmit();
//bool TX_timer_callback(repeating_timer_t *TX_timer);


int main(){
	static const uint rx_freq=9600*6;
	static const uint tx_freq=9600;
	
	stdio_init_all();
	
	
	//choose pio from 0 or 1	
	PIO pio=pio0;
	sleep_ms(5400);

	uint32_t clk=clock_get_hz(clk_sys);
	printf ("clk of sys is: %zu\n",clk);
	
	uint sm_rx = pio_claim_unused_sm(pio,true);
	uint sm_tx = pio_claim_unused_sm(pio,true);
	
	
	//return offset of the program
	uint offset_rx=pio_add_program(pio, &pio_uart_RX_program);
	uint offset_tx=pio_add_program(pio, &pio_uart_TX_program);
	
	float div_rx =0;
	div_rx= (float) (clk / rx_freq);
	printf("div rx is %f\n",div_rx);
	
	float div_tx =0;
	div_tx= (float) (clk / tx_freq);
	printf("div tx is %f\n",div_tx);
	
	pio_uart_RX_program_init(pio, sm_rx, offset_rx, MY_RX, div_rx); 
	pio_uart_TX_program_init(pio, sm_tx, offset_tx, MY_TX, div_tx); 
		
	pio_sm_set_enabled(pio, sm_rx, true);
	pio_sm_set_enabled(pio, sm_tx, true);
	
	
	setup();
	/*
	if(!add_repeating_timer_us(-104,TX_timer_callback,NULL,&TX_timer)){
                printf("error");
                return -1;
        }
	*/
	
	puts("starting reading\n");
	
	uint32_t rxdata[100];
	uint32_t test=0;
	test=pio_sm_get_blocking(pio,sm_rx);
	printf("test is %d\n");

	for(int i=0;i<100;i++){
		pio_sm_put_blocking(pio,sm_tx,i);
		rxdata[i]=test=pio_sm_get_blocking(pio,sm_rx);
		printf("i is %d: data is %zu \n",i, rxdata[i]);
	}
	
	for(int i=0;i<100;i++){
		printf("%d: data is %zu \n",i, rxdata[i]);
	
	}	
	while(1){
	        gpio_put(MY_LED, 1);
		sleep_ms(250);
	        gpio_put(MY_LED, 0);
		sleep_ms(250);

	}
}


void setup(){
	gpio_init(MY_LED);
	//gpio_init(MY_TX);
        //gpio_init(MY_RX);

        gpio_set_dir(MY_LED, GPIO_OUT);
        gpio_put(MY_LED, 1);

        //gpio_set_dir(MY_TX, GPIO_OUT);
        //gpio_put(MY_TX, 1);

	
}
/*
void transmit(){
//	printf("transmiting\n");
        //start
        if(TX_count==0){
                gpio_put(MY_TX, 0);
                TX_count=TX_count+1;

        }

        //else if (TX_count<8) {
         //       gpio_put(MY_TX, 1);
         //       TX_count=TX_count+1;
       // }

        else if (TX_count==1) {
                gpio_put(MY_TX, 1);
                TX_count=TX_count+1;
	}
        else if (TX_count==2) {
                gpio_put(MY_TX, 1);
                TX_count=TX_count+1;
	}
        else if (TX_count==3) {
                gpio_put(MY_TX, 1);
                TX_count=TX_count+1;
	}
        else if (TX_count==4) {
                gpio_put(MY_TX, 1);
                TX_count=TX_count+1;
	}
        



	else if (TX_count==5) {
                gpio_put(MY_TX, 0);
                TX_count=TX_count+1;
	}
        else if (TX_count==6) {
                gpio_put(MY_TX, 0);
                TX_count=TX_count+1;
	}
        else if (TX_count==7) {
                gpio_put(MY_TX, 0);
                TX_count=TX_count+1;
	}
        else if (TX_count==8) {
                gpio_put(MY_TX, 0);
                TX_count=TX_count+1;
	}
        
        
	//stop
        else if (TX_count==9) {
                gpio_put(MY_TX, 1);
                TX_count=TX_count+1;

        }
	else{
		TX_count=0;
	}
}
bool TX_timer_callback(repeating_timer_t *TX_tim){
        transmit();
        return true;
}
*/
