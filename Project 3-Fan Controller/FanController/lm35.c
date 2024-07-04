#include"lm35.h"
#include"adc.h"

uint8 LM35_GetTemperature(void){
	uint16 adc_value;
	uint8 temperature;
	adc_value = ADC_readChannel();
	temperature = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP*ADC_REF_VOLT_VALUE)/(SENSOR_MAX_VOLT*ADC_MAXIMUM_VALUE));
	return temperature;
}
