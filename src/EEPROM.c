/*
 * EEPROM.c
 *
 *  Created on: May 31, 2023
 *      Author: aishw
 */

#include "r_smc_entry.h"
#include "EEPROM.h"
#include "TOUCH_LED.h"
extern uint8_t TRANSMISSION_BUFFER[5];
extern uint8_t SUB_ID;
char RX_FLAG,TX_FLAG;
uint8_t WRITE_BUFFER[14];
uint8_t READ_BUFFER[14];
uint8_t TX[2];
void delay(unsigned int x)
{
	for(;x>0;x--)
  	{
  		nop();nop();nop();nop();nop();nop();nop();nop();
  	}
}

void EEPROM_READ()
{
	TX[0] = 0x01;
	R_Config_RIIC0_Master_Send(0x0050,TX,1);
	while(TX_FLAG == 0);
	TX_FLAG=0;
	delay(10000);
	R_Config_RIIC0_Master_Receive(0x0050,READ_BUFFER,14);
	while(RX_FLAG == 0);
	RX_FLAG=0;
}

void EEPROM_WRITE(TRANSMISSION_BUFFER)
{
	WRITE_BUFFER[0] = 0x01;
	WRITE_BUFFER[1] = key11;
 	WRITE_BUFFER[2] = key12;
 	WRITE_BUFFER[3]	= key21;
 	WRITE_BUFFER[4]	= key22;
 	WRITE_BUFFER[5] = SUB_ID;
 	delay(10000);
 	R_Config_RIIC0_Master_Send(0x0050, WRITE_BUFFER,7);
 	while(TX_FLAG == 0);
 	TX_FLAG=0;
 	delay(10000);
}
EEPROM_LED_POSITION()
{
	if(READ_BUFFER[0]==1)
	{
		key11=1;
		key12=0;
		RELAY1=1;
	}
	else if(READ_BUFFER[0]==0)
	{
		key11=0;
		key12=1;
		RELAY1=0;
	}
	if(READ_BUFFER[2]==1)
	{
		key21=1;
		key22=0;
		RELAY2=1;
	}
	else if(READ_BUFFER[2]==0)
	{
		key21=0;
		key22=1;
		RELAY2=0;
	}


}
