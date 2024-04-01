#include "stm32f10x.h"                  // Device header

void AD_Single_Init(void){	
	// �򿪶�Ӧʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// PCLK��Ҳ����ADCʱ�ӣ���׼Ƶ��72MHz������ʹ��6��Ƶ��Ϊ12MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	// AINģʽ�£�GPIO�ڶϿ�������GPIO�ڵ�ѹӰ���ѹ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// ѡ�����������ͨ��
	// ����ʱ�䳤���ȶ�������ʱ����ٶȿ�,ѡ��55.5��ADCCLK����
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	
	ADC_InitTypeDef ADC_InitStructure;
	// ����ģʽ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	// �Ҷ���
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;		// �ⲿ����Դѡ��:���ⲿ����Դ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	// ָ��ɨ���ǵ���ģʽ��������ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	// ָ��ת����ɨ��ģʽ���Ƿ�ɨ��ģʽ
	ADC_InitStructure.ADC_NbrOfChannel = 1;	// ͨ������ֻ��ɨ��ģʽ��������
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// ��Ҫ�жϻ���ģ�⿴�Ź�������������
	/*
	*/
	
	// ADC�ϵ�����
	ADC_Cmd(ADC1, ENABLE);
	
	// ADCУ׼
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

