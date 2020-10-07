/*
 * adc.h
 *
 *  Created on: Sep 21, 2020
 *      Author: doaay
 */

#ifndef ADC_H_
#define ADC_H_

/****************************************
 * Including Libraries
 */
#include"common_macros.h"
#include"std_types.h"
#include"micro_config.h"
#include"lcd.h"
/*******************************************
 * Defining Variables
 */
/**Decomment the following line to use ADC with interrupt instead of Polling*/


/*#define ADC_Interrupt
*/
extern volatile uint16 g_adcResult;

typedef enum {
	AREF,AVCC,RESERVED,INTERNAL
}ADC_reference;

typedef enum{
	PRE_2,PRE_2_2,PRE_4,PRE_8,PRE_16,PRE_32,PRE_64,PRE_128
}ADC_prescaler;

typedef enum{
	CHANNEL_0,CHANNEL_1,CHANNEL_2,CHANNEL_3,CHANNEL_4,CHANNEL_5,CHANNEL_6,CHANNEL_7
}ADC_channel;
typedef struct {
	ADC_reference ref;
	ADC_prescaler pre;
	ADC_channel ch;
}ADC_configType;
/************************
 * *******Functions Prototypes**************
 */

void ADC_init(void);
void ADC_readChannel(const ADC_configType * ConfigPtr);





#endif /* ADC_H_ */
