#include<avr/io.h>
#include"adc.h"
#include"common_macros.h"

void ADC_init(const ADC_ConfigType *config_ptr){
	ADMUX = (ADMUX & 0x3F) | ((config_ptr->refVoltage)<<6); /*Select reference voltage*/
	ADMUX &= 0xE0; /*Initialize channel number to zero*/
	SET_BIT(ADCSRA,7);/*Enable ADC*/
	ADCSRA&=~(1<<ADSC) &~(1<<ADATE); /*Disable start conversion and auto trigger*/
	ADCSRA = (ADCSRA & 0xF8) | (config_ptr->prescaler); /*Select division factor*/
}

uint16 ADC_readChannel(void){
	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL_BITS); /*Select channel number*/
	SET_BIT(ADCSRA,ADSC); /*Start conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /*Wait till conversion is complete*/
	SET_BIT(ADCSRA,ADIF); /*Clear flag*/
	return ADC; /*Read digital value from the ADC data registers*/
}

