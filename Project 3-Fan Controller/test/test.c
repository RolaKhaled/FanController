#include"std_types.h"
#include"gpio.h"
#include"dcmotor.h"
#include<avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;
	OCR0= duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	TCCR0|=(1<<3)|(1<<6)|(1<<1)|(1<<5);
}

int main(void){
	DCMotor_rotate(100,2);
}
