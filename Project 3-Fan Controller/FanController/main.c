#include"adc.h"
#include"dcmotor.h"
#include"lm35.h"
#include<util/delay.h>
#include"lcd.h"
#include<avr/io.h>

int main(void){
	ADC_ConfigType adc_config={F_CPU_8,Internal_Voltage};
	LCD_init();
	ADC_init(&adc_config);
	DCMotor_init();

	LCD_displayString("Fan is");

	LCD_moveCursor(1,0);
	LCD_displayString("Temp =     C");

	uint8 temperature;


	while(1){
		temperature = LM35_GetTemperature();
		LCD_moveCursor(1,7);

		/*Temperature value get displayed on the lcd*/
		if(temperature >= 100)
		{
			LCD_integerToString(temperature);
		}
		else
		{
			LCD_integerToString(temperature);
			LCD_displayCharacter(' ');
		}

		/*rotate motor based on temperature*/
		if(temperature<30)
		{
			DCMotor_rotate(0,OFF);
			LCD_moveCursor(0,6);
			LCD_displayString(" off");
			//_delay_ms(10);
		}

		if((temperature >=30)&&(temperature<60)){
			DCMotor_rotate(25,CW);
			LCD_moveCursor(0,6);
			LCD_displayString(" on ");
			//_delay_ms(10);
		}


		if((temperature >=60)&&(temperature<90)){
			DCMotor_rotate(50,CW);
			LCD_moveCursor(0,6);
			LCD_displayString(" on ");
			//_delay_ms(10);
		}

		if((temperature >=90)&&(temperature<120)){
			DCMotor_rotate(75,CW);
			LCD_moveCursor(0,6);
			LCD_displayString(" on ");
			//_delay_ms(10);
		}

		if(temperature>=120){
			DCMotor_rotate(100,CW);
			LCD_moveCursor(0,6);
			LCD_displayString(" on ");
			//_delay_ms(10);
		}
	}
}

