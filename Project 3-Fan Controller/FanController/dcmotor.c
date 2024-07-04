#include"dcmotor.h"
#include"gpio.h"
#include"pwm.h"
#include<avr/io.h>

void DCMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, 0);
	GPIO_writePin(PORTB_ID, PIN1_ID, 0);/*stop motor at the beginning*/
}

void DCMotor_rotate(uint8 speed,DCMotor_State state){
	PORTB = (PORTB & 0xFC);
	PORTB|=state;
	PWM_Timer0_Start((MOTOR_MAX_SPEED*speed)/100);
}

