/*
 * motor.c
 *
 *  Created on: Sep 22, 2020
 *      Author: doaay
 */

#include"motor.h"
uint8 duty_cycle=0;
void PWM_Init(uint8 duty){
	TCNT0=0;

	TCCR0 |= (1<<WGM01) |(1<<WGM00) |(1<<CS01) |(1<<COM01);

	OCR0=duty;

	DDRB|=(1<<PB3);


}
void INT1_Init(void){
	DDRD &=~(1<<PD3);
	MCUCR|=(1<<ISC11)|(1<<ISC10); //Rising Edge
	GICR|=(1<<INT1);//ENABLE MODULE FLAG
	SREG|=(1<<7); //Global Flag


}
ISR(INT1_vect){
	TOGGLE_BIT(PORTB,PB1);
	TOGGLE_BIT(PORTB,PB0);
}
