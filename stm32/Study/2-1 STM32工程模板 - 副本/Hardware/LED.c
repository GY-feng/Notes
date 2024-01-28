#include "stm32f10x.h"                  // Device header
//初始化，GPIOA，设置为推挽输出模式
void LED_Init_GPIOA(uint16_t PIN)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//打开时钟

  GPIO_InitTypeDef GPIO_InitStructure;//配置端口模式
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin = PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  //GPIO_SetBits(GPIOA, PIN);
}

void LED_ON_GPIOA(uint16_t PIN)
{
  GPIO_ResetBits(GPIOA, PIN);
}

void LED_OFF_GPIOA(uint16_t PIN)
{
  GPIO_SetBits(GPIOA, PIN);
}

void LED_Turn_GPIOA(uint16_t PIN)//调用的时候，状态取反
{
  if (GPIO_ReadOutputDataBit(GPIOA, PIN) == 0)
    {
      GPIO_SetBits(GPIOA, PIN);
    }
  else
    {
      GPIO_ResetBits(GPIOA, PIN);
    }
}


