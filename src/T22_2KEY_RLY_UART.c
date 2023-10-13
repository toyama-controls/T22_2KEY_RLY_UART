/***********************************************************************
*
*  FILE        : T22_2KEY_RLY_UART.c
*  DATE        : 2023-06-08
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include "TOUCH_LED.h"
#include "EEPROM.h"
#include "UART.h"
#include "string.h"

extern uint8_t Rx_Buffer[8];
extern uint8_t RX_Byte[1];
extern uint8_t Rx_count;
extern qe_touch_main(void);
extern uint8_t mili_sec_timer;
void main(void);
void main(void)
{
	key11=1;
		key12=0;
		key21=1;
		key22=0;

	R_Config_RIIC0_Create();
	R_Config_RIIC0_Start();
	EEPROM_READ();
	EEPROM_LED_POSITION();

	ENABLE_PIN=0;
	R_BSP_SoftwareDelay(3,BSP_DELAY_SECS);
		send_data(17,RELAY1);

		R_BSP_SoftwareDelay(3,BSP_DELAY_SECS);
		send_data(19,RELAY3);
	R_Config_SCI12_Start();
	R_Config_SCI12_Serial_Receive(&RX_Byte, 1);
	qe_touch_main();


}
