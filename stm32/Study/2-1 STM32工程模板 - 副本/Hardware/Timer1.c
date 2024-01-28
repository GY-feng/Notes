#include "stm32f10x.h"                  // Device header

void Timer_init()
{
  /*
  1,打开RCC时钟
  2，选择时钟源
  3，配置时基单元，ARR，RSC，CNT等
  4，配置中断输出控制
  5，配置NVIC，在NVIC中打开定时器中断的通道，并分配一个优先级
  6，运行控制，使能一下计数器，定时器使能后，就会开始计数了，计数器更新后，触发中断
  void TIM_DeInit(TIM_TypeDef* TIMx);
  void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);配置时基函数

  void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);默认值

  void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);配置

  void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);使能外设的中断输出，定时器，配置哪个中断输出，新的状态

  void TIM_InternalClockConfig(TIM_TypeDef* TIMx);选择内部时钟
  void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);选择ITRX其他定时器时钟
  void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);选择捕获通道的时钟，后2极性、滤波器
  void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);配置ETR引脚的预分频器，极性，滤波器这些参数


  void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);单独写入预分频值，模式

  void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);改变计数器的计数模式，参数：选择新的计数器模式

  void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);自动重装其预装模式，使能失能

  uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);看当前计数器寄到哪里
  uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);获得预分频器的值

  获取标志位，清楚标志位
  FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
  void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
  ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
  void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
  */
  //1开启时钟
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  //2，选择时基单元的时钟
  TIM_InternalClockConfig(TIM2);//选择内部时钟（也是系统默认）
  //3，配置时基单元，ARR，RSC，CNT等
  TIM_TimeBaseInitTypeDef i;
  i.TIM_ClockDivision=1;//指定时钟分频，滤波器用
  i.TIM_CounterMode=TIM_CounterMode_Up;//计数器模式向上等

  //定时频率=72M/(PSC+1)/(ARR+1),定时1s=>定时频率为1
  //不要超65535
  i.TIM_Period=10000-1;//ARR
  i.TIM_Prescaler=7200-1;//PSC
  i.TIM_RepetitionCounter=0;//重复计数器，高级才有
  TIM_TimeBaseInit(TIM2,&i);
  
  TIM_ClearFlag(TIM2,TIM_FLAG_Update);//避免上电就进入中断
  //4，配置中断输出控制
  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//更新中断
  //5，配置NVIC，在NVIC中打开定时器中断的通道，并分配一个优先级
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitTypeDef n;
  n.NVIC_IRQChannel=TIM2_IRQn;
  n.NVIC_IRQChannelCmd=ENABLE;
  n.NVIC_IRQChannelPreemptionPriority=2;
  n.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&n);
  //6，运行控制，使能一下计数器，定时器使能后，就会开始计数了，计数器更新后，触发中断
  TIM_Cmd(TIM2,ENABLE);
}

void Timer_init_By_outsideclock()//使用外部时钟而不是内部时钟
{
  //引脚要用到GPIO，所以要先配置GPIO
	RCC_APB2PeriphClockCmd(RCC_APB 2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;//配置端口模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  //1开启时钟
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	  //2，选择时基单元的时钟
  TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);//不适用分频，不反向（高电平有效）,不使用滤波器）

  //TIM_InternalClockConfig(TIM2);//选择内部时钟（也是系统默认）
  //3，配置时基单元，ARR，RSC，CNT等
  TIM_TimeBaseInitTypeDef i;
  i.TIM_ClockDivision=1;//指定时钟分频，滤波器用
  i.TIM_CounterMode=TIM_CounterMode_Up;//计数器模式向上等

  //定时频率=72M/(PSC+1)/(ARR+1),定时1s=>定时频率为1
  //不要超65535
  i.TIM_Period=10-1;//ARR
  i.TIM_Prescaler=1-1;//PSC
  i.TIM_RepetitionCounter=0;//重复计数器，高级才有
  TIM_TimeBaseInit(TIM2,&i);
  
  TIM_ClearFlag(TIM2,TIM_FLAG_Update);//避免上电就进入中断
  //4，配置中断输出控制
  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//更新中断
  //5，配置NVIC，在NVIC中打开定时器中断的通道，并分配一个优先级
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitTypeDef n;
  n.NVIC_IRQChannel=TIM2_IRQn;
  n.NVIC_IRQChannelCmd=ENABLE;
  n.NVIC_IRQChannelPreemptionPriority=2;
  n.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&n);
  //6，运行控制，使能一下计数器，定时器使能后，就会开始计数了，计数器更新后，触发中断
  TIM_Cmd(TIM2,ENABLE);
}
//可以将中断函数放到主程序当中进行使用
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)//参数：选择更新中断
	{
	
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		//在变量前面加上extern，可以跨越.c使用变量
	}
}