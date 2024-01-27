#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"


int main(void)
{
	LED_Init_GPIOA(GPIO_Pin_All);
	
	while (1)
	{
		LED_ON_GPIOA(GPIO_Pin_All);
		//GPIO_Write(GPIOA,0x0001);
	}
}
