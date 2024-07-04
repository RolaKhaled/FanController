#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include"std_types.h"

/*Definitions*/
#define MOTOR_MAX_SPEED 256

/*Types Declaration*/
typedef enum{
	OFF,ACW,CW
}DCMotor_State;

/*Function Prototypes*/
void DCMotor_init(void);

void PWM_Timer0_Start(uint8 duty_cycle);

void DCMotor_rotate(uint8 speed,DCMotor_State state);
#endif /* DCMOTOR_H_ */
