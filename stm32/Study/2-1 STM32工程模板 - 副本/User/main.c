#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "timer2-PWM.h"

int main(void)
{
	PWM_Init();
	while (1)
	{
		//LED_ON_GPIOA(GPIO_Pin_All);
		//GPIO_Write(GPIOA,0x0001);
	}
}
