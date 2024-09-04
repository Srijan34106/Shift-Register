#include<reg51.h>
sbit serial_data= P2^7;
sbit SH_clock= P2^6; // pin 11 shift clock
sbit LA_clock_1= P2^5; // pin 2 latch clock
sbit LA_clock_2= P2^4; // pin 2 latch clock 

void delay(unsigned char); //define delay function
void send_data(unsigned char); //send data in serial
void clock(void); //function for clock

void main(){
	SH_clock=0; //set shift clock to low
	LA_clock_1=0; //set latch clock to 0;
	LA_clock_2=0;// set latch clock to 0;
	
	send_data(0xCD); //send data 01010101
	
	LA_clock_1=0;// send low
	delay(90);
	LA_clock_1=1;// send high
	
	send_data(0xF2);// send data 11000000
	clock(); //send clock for transfer data to next 74HC595
	
	LA_clock_2=0;
	delay(90);
	LA_clock_2=1;
	while(1);
}

void send_data(unsigned char Data){
	unsigned char y;
	for(y=0;y<8;y++){
		serial_data=(Data>>y)& 0x01;
		SH_clock=0;
		delay(90);
		SH_clock=0;
	}
}

void clock(void){
	unsigned char z;
	for(z=0;z<8;z++){
		SH_clock=0;
		delay(90);
		SH_clock=1;
	}
}

void delay(unsigned char ms){
	unsigned char i;
	for(i=0;i<ms;i++);
}
	




























