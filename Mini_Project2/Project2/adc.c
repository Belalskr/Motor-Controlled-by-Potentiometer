/*
 * adc.c
 *
 *  Created on: Sep 21, 2020
 *      Author: doaay
 */
#include"adc.h"

volatile uint16 g_adcResult;
ISR(ADC_vect){

	g_adcResult=ADC;

}

void ADC_init(void){

	ADMUX=0;/*reseting the mux register*/



}
void ADC_readChannel(const ADC_configType * ConfigPtr){

	ADMUX=((ADMUX)&(0XE0)) |(ConfigPtr->ch&(0x07));
	ADMUX=((ADMUX)&(0X3F)) |(ConfigPtr->ref &(0x03));
	ADCSRA=((ADCSRA)&(0XF8))|(ConfigPtr->pre &(0x07));
	ADCSRA|=(1<<ADEN)|(1<<ADSC);
#ifdef ADC_Interrupt
	ADCSRA|=(1<<ADIE);// Interrupt enable
	}
#else

	while(!ADCSRA&(1<<ADIF)){};
	ADCSRA|=(1<<ADIF);
	g_adcResult=ADC;
}
#endif
