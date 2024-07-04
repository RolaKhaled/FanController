#include"dcmotor.h"
#include"gpio.h"
#include<avr/io.h>
void PWM_Timer0_Start(uint8 duty_cycle);

void DCMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	PORTB&=~(1<<1)&~(1<<0); /*stop motor at the beginning*/
}

void DCMotor_rotate(uint8 speed,DCMotor_State state){
	PORTB = (PORTB & 0x3F);
	PORTB|=state;
	PWM_Timer0_Start(MOTOR_MAX_SPEED*(speed/100));
}
