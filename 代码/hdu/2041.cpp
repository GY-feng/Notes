#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int dp[45];
void solve(int n)
{
    memset(dp, 0, sizeof(dp)); // dp置为0
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    // 枚举楼梯数，在第i阶楼梯有dp[i]种走法
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        solve(tmp);
        cout << dp[tmp] << endl;
    }
}
/*
void PWM_init()
{
    /*
    1,RCC 时钟TIM喝GPIO打开
    2,时钟单元
    3，配置输出比较单元
    4，配置GPIO，复用推挽输出
    5，运行控制，启动计数器
    配置输出比较模块
    一个对应一个单元
    void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
    void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
    void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
    void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);

    void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);默认值

    void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);配置强制输出模式，运行中输出波形，少用

    配置预装功能，影子寄存器，在更新事件生效，少用
    void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
配置快速使能，少用
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
少用：
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
单独设置输出比较的极性的，带N：高级定时器里互补通道的配置，也可以在初始化调用
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
单独更改输出比较模式：
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
单独更改CCR值的函数（可以改占空比），重要
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
补充：仅高级定时器输出PWM要调用，使能主输出，否则不会输出
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);

*/
/*
    //1开启时钟
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  //2，选择时基单元的时钟
  TIM_InternalClockConfig(TIM2);//选择内部时钟（也是系统默认）
  //3，配置时基单元，ARR，RSC，CNT等
  TIM_TimeBaseInitTypeDef i;
  i.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频，滤波器用
  i.TIM_CounterMode=TIM_CounterMode_Up;//计数器模式向上等

  //定时频率=72M/(PSC+1)/(ARR+1),定时1s=>定时频率为1
  //不要超65535
  i.TIM_Period=100-1;//ARR
  i.TIM_Prescaler=720-1;//PSC
  i.TIM_RepetitionCounter=0;//重复计数器，高级才有
  TIM_TimeBaseInit(TIM2,&i);


  //初始化输出比较单元
  TIM_OCInitTypeDef t;
  TIM_OCStructInit(&t);//赋初始值，懒得把所有成员给初始值
  t.TIM_OCMode=TIM_OCMode_PWM1;
    t.TIM_OCPolarity=TIM_OCPolarity_High;
    t.TIM_OutputState=TIM_OutputNState_Enable;
    t.TIM_Pulse=0;//脉冲，设置CCR寄存器值的
TIM_OC1Init(TIM2,&t);

//初始化输出PWM的GPIO：
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//打开时钟

  GPIO_InitTypeDef GPIO_InitStructure;//配置端口模式
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出，普通开漏、推挽输出，引脚的控制权来自于输出数据寄存器的。要让定时器来控制引脚，那么就要采用复用模式
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  //6，运行控制，使能一下计数器，定时器使能后，就会开始计数了，计数器更新后，触发中断
  TIM_Cmd(TIM2,ENABLE);
}
*/