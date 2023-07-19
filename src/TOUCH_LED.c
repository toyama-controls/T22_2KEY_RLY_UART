/*
 * TOUCH_LED.c
 *
 *  Created on: May 31, 2023
 *      Author: aishw
 */
#include "r_smc_entry.h"
#include "TOUCH_LED.h"
#include "EEPROM.h"
#include "UART.h"
extern uint8_t SUB_ID=17;
extern uint8_t WRITE_BUFFER[14];
int flag1;
int flag2;
int key1_ledstate=0;
int key2_ledstate=0;
int key3_ledstate=0;
int key4_ledstate=0;
int LED_FUNCTION(int STATUS)
{
	if(key1_ledstate==0 && STATUS==1)
	{

		key21=~key21;
		key22=~key22;
		key1_ledstate=1;
		RELAY1=~RELAY1;

		EEPROM_WRITE(key21);
		send_data(SUB_ID,key22);
	}
	else if(key1_ledstate==1 && STATUS==0)
	{
		flag1=0;
		key1_ledstate=0;
	}
	if(key2_ledstate==0 && STATUS==2)
	{
		key11=~key11;
		key12=~key12;
		key2_ledstate=1;
		RELAY3=~RELAY3;

		EEPROM_WRITE(key11);
		send_data(SUB_ID+1,key12);
	}
	else if(key2_ledstate==1 && STATUS==0)
	{

		key2_ledstate=0;
	}
	return 0;
}

