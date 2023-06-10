/*
 * UART.c
 *
 *  Created on: Jun 8, 2023
 *      Author: aishw
 */
#include "UART.h"

#include "r_smc_entry.h"
#include "EEPROM.h"
#include "TOUCH_LED.h"
#include "string.h"
extern uint8_t SUB_ID;
extern uint8_t WRITE_BUFFER[14];
extern uint8_t Rx_count;
uint8_t ADDRESS_BUFFER[8];
extern uint8_t Rx_Buffer[8];
uint8_t RX_Int,TX_Int;
extern uint8_t CMD;
extern int count1=0;
extern int count2=0;
extern uint8_t RX_Byte[1];
int FLAG;
int y;
int *p;
uint8_t data[8];
uint8_t t1;
uint8_t t2;
void handle_receive_data()
{
	int y=strlen(Rx_Buffer);
	t1=Rx_Buffer[0]^Rx_Buffer[1]^Rx_Buffer[2]^Rx_Buffer[3]^Rx_Buffer[4]^Rx_Buffer[5];
	t2=Rx_Buffer[0]+Rx_Buffer[1]+Rx_Buffer[2]+Rx_Buffer[3]+Rx_Buffer[4]+Rx_Buffer[5]+Rx_Buffer[6];

	if (Rx_Buffer[0] == STX && Rx_Buffer[1] == SWITCH_ID && Rx_Buffer[3] == COMMAND && Rx_Buffer[4] == CMD_LEN && Rx_Buffer[6] == t1 && Rx_Buffer[7] == t2)
	{
		FLAG=1;
		if (Rx_Buffer[2] == SUB_ID + 1 && Rx_Buffer[5] == 01 && count1==0)
	    {
				count1 = 1;
				key11 = 1;
				key12 = 0;
				EEPROM_WRITE(key12);
				memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    }
	    else if (Rx_Buffer[2] == SUB_ID + 1 && Rx_Buffer[5] == 00 && count1==1)
	    {
	        count1 = 0;
	        key11 = 0;
	        key12 = 1;
	        EEPROM_WRITE(key12);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    }
	    else if (Rx_Buffer[2] == SUB_ID && Rx_Buffer[5] == 01 && count2==0)
	    {
	        count2 = 1;
	        key21 = 1;
	        key22 = 0;
	        EEPROM_WRITE(key22);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    }
	    else if (Rx_Buffer[2] == SUB_ID && Rx_Buffer[5] == 00 && count2==1)
	    {
	        count2 = 0;
	        key21 = 0;
	        key22 = 1;
	        EEPROM_WRITE(key22);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    }




	}
if(Rx_Buffer[0]!=247)
{
	memset(Rx_Buffer,9,sizeof(Rx_Buffer));
	Rx_count=0;
}
}
void send_data(SUB_ID,CMD)
{
 	data[0]=STX;
 	data[1]=SWITCH_ID;
 	data[2]=SUB_ID;
 	data[3]=CONTROLCOMMAND;
 	data[4]=CMD_LEN;
 	data[5]=CMD;
 	data[6]=data[0]^data[1]^data[2]^data[3]^data[4]^data[5];
 	data[7]=data[0]+data[1]+data[2]+data[3]+data[4]+data[5]+data[6];
 	ENABLE_PIN=1;
 	R_Config_SCI12_Serial_Send(data,sizeof(data));
 	while(TX_Int == 0);
 	TX_Int = 0;
 	ENABLE_PIN=0;
}


