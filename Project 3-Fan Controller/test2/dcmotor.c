#include"dcmotor.h"
#include"gpio.h"
#include<avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;
	OCR0= duty_cycle;
	DDRB  = DDRB | (1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

void DCMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	//GPIO_writePin(PORTB_ID, PIN0_ID, 0);
	//GPIO_writePin(PORTB_ID, PIN1_ID, 0);/*stop motor at the beginning*/
}

void DCMotor_rotate(uint8 speed,DCMotor_State state){
	PORTB = (PORTB & 0xFC);
	PORTB|=state;
	PWM_Timer0_Start((uint8)MOTOR_MAX_SPEED*(speed/100));
}

