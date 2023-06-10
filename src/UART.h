/*
 * UART.h
 *
 *  Created on: Jun 8, 2023
 *      Author: aishw
 */

#ifndef UART_H_
#define UART_H_
#define ENABLE_PIN (PORTA.PODR.BIT.B1)
#define STX 		0XF7
#define SWITCH_ID          0X03
#define CONTROLCOMMAND 0XC1
#define CMD_LEN 0X01
#define COMMAND 0X31
extern unsigned char RX_Int,TX_Int;
#endif /* UART_H_ */
