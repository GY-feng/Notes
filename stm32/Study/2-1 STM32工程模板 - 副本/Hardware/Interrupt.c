#include "stm32f10x.h"                  // Device header

void Count_Init(void)
{
	//配置：从GPIO到NVIC这一路中出现的外部模块配置好
	/*
	1,配置RCC，打开外设的时钟
	2，配置GPIO，端口为输入模式
	3，配置AFOIO，选择用我们这一路的GPIO，连接到后面的EXTI
	4，配置EXTI，选择边沿触发模式，比如上升沿、下降沿、双边沿…… 相应方式
	5，配置NVIC，给中断选择合适的优先级
	6，通过NVIC 外部信号可以进入CPU
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//注意：GPIOB是APB2的外设
}
