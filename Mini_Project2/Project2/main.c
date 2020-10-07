/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: doaay
 */
#include"motor.h"





int main()
{
/*Initializing ADC AND LCD */
	ADC_init();
	LCD_init();
	ADC_configType ADC_Config={AREF,PRE_8,CHANNEL_0};
	LCD_clearScreen();
	LCD_displayString("ADC Value =");
/* Initializing Motor */
	MOTOR_PORT_DIR|=(1<<IN1)|(1<<IN2);
/*Clock Wise Direction*/
	SET_BIT(MOTOR_PORT,IN2);
	CLEAR_BIT(MOTOR_PORT,IN1);
/* Initializing Timer0 PWD */
	PWM_Init(duty_cycle);
/*Initializing Switch*/

	PORTD|=(1<<PD3);
	INT1_Init();
	while(1)
	{
		/*
		 * Displaying ADC Value on The LCD SCREEN
		 */


		LCD_goToRowColumn(0,12);
		ADC_readChannel(&ADC_Config);
		uint16 result=g_adcResult;
		LCD_intgerToString(result);
		if(result<1000){
			LCD_displayStringRowColumn(0,15," ");
		}
		/*
		 * to compare ADC value to Duty Cycle Value we divide by 4 to fit the 8-bit timer0
		 */
		duty_cycle=result/4;

		PWM_Init(duty_cycle);

		/*Switch trigger*/
		if(PIND&(1<<PD3)){

			ISR(INT1_vect);
		}


	}
}

