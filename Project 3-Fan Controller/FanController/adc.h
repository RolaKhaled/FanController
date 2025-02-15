#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

/*Definitions*/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC_CHANNEL_BITS 2
/* Types Declaration*/

typedef enum{
	F_CPU_2 = 1 ,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef enum{
	AREF,AVCC,Internal_Voltage = 3
}ADC_ReferenceVoltage;

typedef struct{
	ADC_Prescaler prescaler;
	ADC_ReferenceVoltage refVoltage;
}ADC_ConfigType;

/*Functions Prototypes*/

void ADC_init(const ADC_ConfigType *Config_Ptr);

uint16 ADC_readChannel(void);

#endif /* ADC_H_ */
