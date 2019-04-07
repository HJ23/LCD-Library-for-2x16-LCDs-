#include<avr/io.h>
#include<util/delay.h>

#define PORT_DATA    PORTX
#define RS           NUMBER0
#define E            NUMBER1
#define SETTING_PORT PORTY
#define uchar unsigned char


void initialize();
void send_command(uchar command);
void display(uchar data);

void initialize(){
	SETTING_PORT&=~(1<<E);
	_delay_us(1000);
	send_command(0x38);
	_delay_us(1000);
	send_command(0x0E);
	_delay_us(1000);
	send_command(0x01);
	_delay_us(1000);
	send_command(0x06);
	_delay_us(10000);
	
}


void display(uchar data){
	PORT_DATA=data;
	SETTING_PORT|=1<<RS;
	SETTING_PORT|=1<<E;
	_delay_us(1000);
	SETTING_PORT&=~(1<<E);
	_delay_us(1000);
}

void send_command(uchar command){
	
	PORT_DATA=command;
	SETTING_PORT|=1<<E;
	SETTING_PORT&=~(1<<RS);
	_delay_us(2000);
	SETTING_PORT&=~(1<<E);
	_delay_us(1000);
}


void clear_display(){
	send_command(0x01);
	_delay_us(100);
	initialize();
}
void new_line(){
	send_command(0xC0);
	_delay_us(100);
	
}



