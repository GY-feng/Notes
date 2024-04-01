#include "stm32f10x.h"                  // Device header

void AD_Single_Init(void){	
	// 打开对应时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// PCLK，也就是ADC时钟，基准频率72MHz，这里使用6分频，为12MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	// AIN模式下，GPIO口断开，避免GPIO口电压影响电压测量
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 选择规则组输入通道
	// 采样时间长更稳定，采样时间短速度快,选择55.5个ADCCLK周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	
	ADC_InitTypeDef ADC_InitStructure;
	// 独立模式
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	// 右对齐
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;		// 外部触发源选择:无外部触发源
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	// 指定扫描是单次模式还是连续模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	// 指定转换是扫描模式还是非扫描模式
	ADC_InitStructure.ADC_NbrOfChannel = 1;	// 通道数，只在扫描模式下起作用
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// 需要中断或者模拟看门狗则在下面配置
	/*
	*/
	
	// ADC上电启动
	ADC_Cmd(ADC1, ENABLE);
	
	// ADC校准
	ADC_ResetCalibration(ADC1);
	while (ADC_GetResetCalibrationStatus(ADC1) == SET);
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) == SET);
}

uint16_t AD_GetValue(void){
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
	return ADC_GetConversionValue(ADC1);
}

