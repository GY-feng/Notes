#include "stm32f10x.h"                  // Device header
int main(void)
{
	//点亮指示灯，低电平点亮
	RCC->APB2ENR = 0x00000010;
	GPIOC->CRH = 0x00300000;
	GPIOC->ODR = 0x00002000;//0x00000000;开灯
	//不好的地方：影响了其他端口的原有配置，如果要只配置PC13不配置其他位，要&=和|=的操作了

	//使能时钟，用这个函数来开启时钟
	//参数：选择外设和选择新的状态
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_init;
	GPIO_init.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_init.GPIO_Pin = GPIO_Pin_13;
	GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
	//配置端口模式,使用结构体配置(外设,指向结构体的指针)
	GPIO_Init(GPIOC, &GPIO_init);

	GPIO_SetBits(GPIOC, GPIO_Pin_13);//设置成高电平；
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);//设置成低电平
	while (1)
	{

	}
}