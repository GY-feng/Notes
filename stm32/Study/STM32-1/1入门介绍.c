#include "stm32f10x.h"                  // Device header
int main(void)
{
	//����ָʾ�ƣ��͵�ƽ����
	RCC->APB2ENR = 0x00000010;
	GPIOC->CRH = 0x00300000;
	GPIOC->ODR = 0x00002000;//0x00000000;����
	//���õĵط���Ӱ���������˿ڵ�ԭ�����ã����Ҫֻ����PC13����������λ��Ҫ&=��|=�Ĳ�����

	//ʹ��ʱ�ӣ����������������ʱ��
	//������ѡ�������ѡ���µ�״̬
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_init;
	GPIO_init.GPIO_Mode = GPIO_Mode_Out_PP;//�������
	GPIO_init.GPIO_Pin = GPIO_Pin_13;
	GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
	//���ö˿�ģʽ,ʹ�ýṹ������(����,ָ��ṹ���ָ��)
	GPIO_Init(GPIOC, &GPIO_init);

	GPIO_SetBits(GPIOC, GPIO_Pin_13);//���óɸߵ�ƽ��
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);//���óɵ͵�ƽ
	while (1)
	{

	}
}