/*
 * app.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Twins
 */

#ifndef APP_H_
#define APP_H_

#include "avr/io.h"
#include "lcd.h"
#include "adc.h"
#include "dc_motor.h"
#include "pwm.h"
#include "lm35_sensor.h"


/*************types********/
typedef enum {
	FAN_OFF,
	FAN_ON
}FAN_STATUES;

#endif /* APP_H_ */
