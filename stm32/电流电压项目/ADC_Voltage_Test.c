#include "delay.h"
#include "stm32f10x_it.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "AD_single.h"
#include "pwm.h"
#include "Timer.h"
#include "input_capture.h"

uint16_t Num;

int ADC_Voltage_Test(void){
	OLED_Init();

	OLED_Clear();
	OLED_ShowString(1,1,"Current:",16);
	AD_Single_Init();
	uint16_t voltage = 0;
	
	while (1){
		OLED_ShowNum(64,1,voltage,5,16);
		voltage = AD_GetValue();
		delay_ms(100);
	}
	return 0;
}

 

