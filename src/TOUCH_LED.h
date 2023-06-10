/*
 * TOUCH_LED.h
 *
 *  Created on: May 31, 2023
 *      Author: aishw
 */

#ifndef TOUCH_LED_H_
#define TOUCH_LED_H_
#define key11 (PORT5.PODR.BIT.B5)
#define key12 (PORTH.PODR.BIT.B0)
#define key21 (PORT1.PODR.BIT.B2)
#define key22 (PORT1.PODR.BIT.B3)
#define RELAY1 (PORT0.PODR.BIT.B3)
#define RELAY2 (PORT0.PODR.BIT.B4)
#define RELAY3 (PORT0.PODR.BIT.B6)
int LED_FUNCTION(int STATUS);
#endif /* TOUCH_LED_H_ */
