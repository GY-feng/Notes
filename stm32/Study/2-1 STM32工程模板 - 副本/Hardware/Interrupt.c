#include "stm32f10x.h"                  // Device header

//使用GPIOB口
void Count_Init(uint16_t PIN)
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
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//注意：开启AFIO外设时钟
  //EXTI和NVIC的时钟时钟是开启着的

  //配置GPIO,EXIT推荐是浮空，上拉，下拉
  GPIO_InitTypeDef a;
  a.GPIO_Mode=GPIO_Mode_IPU;//上拉输入，默认为高电平的输入方式
  a.GPIO_Pin=PIN;
  a.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&a);

  //配置AFIO，库文件和GPIO一起
  /*
  void GPIO_AFIODeInit(void);复位AFIO外设，调用清楚配置

  void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);锁定配置，引脚的配置会被锁定
  //这两个函数用来配置AFIO的事件输出功能的，少用
  void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
  void GPIO_EventOutputCmd(FunctionalState NewState);

  void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);引脚重映射
  void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);配置AFIO的数据选择器，来选择我们想要的中断引脚
  void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);和以太网相关的外设
  */
  //AFIO外部中断引脚选择配置
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);

  //配置EXTI
  /*
  void EXTI_DeInit(void);清楚所有的EXTI配置或清除，恢复成上电默认的状态
  void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);//根据结构体配置外设，初始化
  void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);//将结构体赋予一个默认值

  void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);//软件触发外部中断

  主函数当中，清除或者查看标志位和清除标志位
  FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);获取指定的标志位是否被置1
  void EXTI_ClearFlag(uint32_t EXTI_Line);//清楚指定的标志位

  中断当中，清除或者查看标志位和清除标志位
  ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);获取中断标志位是否被置1
  void EXTI_ClearITPendingBit(uint32_t EXTI_Line);

  */
  EXTI_InitTypeDef ei;
  ei.EXTI_Line=EXTI_Line14;//指定要配置的中断线
  ei.EXTI_LineCmd=ENABLE;
  ei.EXTI_Mode=EXTI_Mode_Interrupt;//中断和事件模式
  ei.EXTI_Trigger=EXTI_Trigger_Falling;//指定触发信号的有效边沿,这里下降沿出发
  EXTI_Init(&ei);

  //配置NVIC
  /*
  void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);中断分组，参数是分组方式
  void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);//初始化NVIC
  void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);//设置中断向量表，系统低功耗配置，少用

  */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//一般终端不多，很难冲突，随意选用,这里2位抢占2位相应比较平均，也可以放在主函数
  NVIC_InitTypeDef i;

  i.NVIC_IRQChannel=EXTI15_10_IRQn;//指定中断通道来开启或关闭
  i.NVIC_IRQChannelCmd=ENABLE;
  //抢占优先级那些的配置
  i.NVIC_IRQChannelPreemptionPriority=1;
  i.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&i);
  //中断函数的名字都是固定的，一个通道对应一个函数
  //以IRQHandler的就是中断函数
}
void EXTI15_10_IRQHandler(void)
{
  //中断函数都是无参无返回值的，建议从启动文件赋值
  //判断是不是我们想要的通道进来的
  if(EXTI_GetFlagStatus(EXTI_Line14)==SET)
    {


    }
  //结束的时候要记得清楚，因为只要中断标志位置1了，那么程序就会跳转到中断函数
  EXTI_ClearITPendingBit(EXTI_Line14);
}
