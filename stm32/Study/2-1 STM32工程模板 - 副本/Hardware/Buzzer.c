#include "stm32f10x.h"                  // Device header
void Buzzer_Init_GPIOB(uint16_t PIN)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//打开时钟

  GPIO_InitTypeDef GPIO_InitStructure;//配置端口模式
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin = PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  //GPIO_SetBits(GPIOA, PIN);
}

void Buzzer_ON_GPIOB(uint16_t PIN)
{
  GPIO_ResetBits(GPIOA, PIN);
}

void Buzzer_OFF_GPIOB(uint16_t PIN)
{
  GPIO_SetBits(GPIOB, PIN);
}

void Buzzer_Turn_GPIOB(uint16_t PIN)//调用的时候，状态取反
{
  if (GPIO_ReadOutputDataBit(GPIOB, PIN) == 0)//读取自己目前的状态
    {
      GPIO_SetBits(GPIOB, PIN);
    }
  else
    {
      GPIO_ResetBits(GPIOB, PIN);
    }
}