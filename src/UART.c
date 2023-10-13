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
int count1;
int count2;
uint8_t count3;
uint8_t count4;
uint8_t count5;
uint8_t STATUS[16];
int RELAY_STATUS(uint8_t c1,uint8_t c2,uint8_t c3,uint8_t c4)
{
	STATUS[0]=0XF7;
	STATUS[1]=0X03;
	STATUS[2]=0X10;
	STATUS[3]=0X81;
	STATUS[4]=0X09;
	STATUS[5]=c1;
	STATUS[6]=c2;
	STATUS[7]=c3;
	STATUS[8]=c4;
	STATUS[9]=0X00;
	STATUS[10]=0X00;
	STATUS[11]=0X00;
	STATUS[12]=0X00;
	STATUS[13]=0X00;
	STATUS[14]=STATUS[0]^STATUS[1]^STATUS[2]^STATUS[3]^STATUS[4]^STATUS[5]^STATUS[6]^STATUS[7]^STATUS[8];
	STATUS[15]=STATUS[0]+STATUS[1]+STATUS[2]+STATUS[3]+STATUS[4]+STATUS[5]+STATUS[6]+STATUS[7]+STATUS[8]+STATUS[9]+STATUS[10]+STATUS[11]+STATUS[12]+STATUS[13]+STATUS[14];
	ENABLE_PIN=1;
	R_Config_SCI12_Serial_Send(STATUS,sizeof(STATUS));
	while(TX_Int == 0);
	TX_Int = 0;
	ENABLE_PIN=0;
	return 0;
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
void handle_receive_data()
{

	t1=Rx_Buffer[0]^Rx_Buffer[1]^Rx_Buffer[2]^Rx_Buffer[3]^Rx_Buffer[4]^Rx_Buffer[5];
	t2=Rx_Buffer[0]+Rx_Buffer[1]+Rx_Buffer[2]+Rx_Buffer[3]+Rx_Buffer[4]+Rx_Buffer[5]+Rx_Buffer[6];

	if (Rx_Buffer[0] == STX && Rx_Buffer[1] == SWITCH_ID && Rx_Buffer[3] == COMMAND && Rx_Buffer[4] == CMD_LEN && Rx_Buffer[6] == t1 && Rx_Buffer[7] == t2)
	{


		if (Rx_Buffer[2] == SUB_ID + 2 && Rx_Buffer[5] == 01)
	    {

if(key12==0)
{
//
				count1 =1;
				key11 = 0;
				key12 = 1;
				RELAY3=1;
				send_data(SUB_ID+2,01);
				EEPROM_WRITE(key12);
				memset(Rx_Buffer,0,sizeof(Rx_Buffer));
}
if (key12==1)
		{

					key11 = 0;
					key12 = 1;
					RELAY3=1;
					memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		}

	    }
	    else if (Rx_Buffer[2] == SUB_ID + 2 && Rx_Buffer[5] == 00 )
	    {
	    	if(key12==1)
	    	{

	    	send_data(SUB_ID+2,00);
	        count1 = 0;
	        key11 = 1;
	        key12 = 0;
	        RELAY3=0;

	        EEPROM_WRITE(key12);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    	}
	    	if (key12==0)
	    			{
	    		key11 = 1;
	    		key12 = 0;
	    		RELAY3=0;
	    		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    			}

	    }
	    else if (Rx_Buffer[2] == SUB_ID && Rx_Buffer[5] == 01)
	    {
	    	if(key22==0)
	    	{
	    	send_data(SUB_ID,01);
	        count2 = 1;
	        key21 = 0;
	        key22 = 1;
	        RELAY1=1;

	        EEPROM_WRITE(key22);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    	}
	    	if(key22==1)
	    	{

	    		key21 = 0;
	    		key22 = 1;
	   	        RELAY1=1;
	   	     memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    	}

	    }
	    else if (Rx_Buffer[2] == SUB_ID && Rx_Buffer[5] == 00 )
	    {
if(key22==1)
{
	    	send_data(SUB_ID,00);
	        count2 = 0;
	        key21 = 1;
	        key22 = 0;
	        RELAY1=0;

	        EEPROM_WRITE(key22);
	        memset(Rx_Buffer,0,sizeof(Rx_Buffer));

}
if(key22==0)
	    	{

	    		key21 = 1;
	    		key22 = 0;
	   	        RELAY1=0;
	   	     memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	    	}
	    }




	}
	else if(Rx_Buffer[0]==STX && Rx_Buffer[1]==SWITCH_ID && Rx_Buffer[2]==240 && Rx_Buffer[3]==01 && Rx_Buffer[4]==00 && Rx_Buffer[5]==05 && Rx_Buffer[6]==240)
			{
				if(RELAY1==0 && RELAY3==0)
				{
					count5=0;
				}
				else if(RELAY1==1 && RELAY3==1)
						{
							count5=1;
						}
				if(RELAY3==1)
				{
					count1=1;;

				}
				else
				{
					count1=0;
				}
				if(RELAY1==1)
				{
					count2=1;
				}
				else
						{
							count2=0;
						}
//				if(RELAY2==1)
//				{
//					count3=1;
//				}
//				else
//						{
//							count3=0;
//						}
//				if(RELAY4==1)
//				{
//					count4=1;
//				}
//				else
//						{
//							count4=0;
//						}

				RELAY_STATUS(count1,count2,count3,count4);
				memset(Rx_Buffer,0,sizeof(Rx_Buffer));
			}


if(Rx_Buffer[0]!=247)
{
	memset(Rx_Buffer,0,sizeof(Rx_Buffer));
	Rx_count=0;
}
}

