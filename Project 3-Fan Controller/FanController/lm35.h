#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"

#define SENSOR_MAX_TEMP 150
#define SENSOR_MAX_VOLT 1.5

uint8 LM35_GetTemperature(void);

#endif /* LM35_H_ */
