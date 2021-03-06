/*
 * motor.h
 *
 *  Created on: Sep 22, 2020
 *      Author: doaay
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include"adc.h"

void PWM_Init(uint8);
void INT1_Init(void);
extern uint8 duty_cycle;

#define MOTOR_PORT PORTB
#define MOTOR_PORT_DIR DDRB
#define IN1 PB0
#define IN2 PB1
#define EN1 OC0


#endif /* MOTOR_H_ */
