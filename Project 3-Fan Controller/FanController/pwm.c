#include"pwm.h"
#include<avr/io.h>
#include"gpio.h"

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;
	OCR0= duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
