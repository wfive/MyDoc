#include "exti.h"




void CON_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	
 GPIO_InitStructure.GPIO_Pin = CONT_B7;				 //LED0-->PA.0�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.0
 CONT_JD = 1;						 //PA.0 �����

}




/*******************************************************************************
* �� �� ��         : exti_init
* ��������		     : �ⲿ�ж�2�˿ڳ�ʼ������	   
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void exti_init(void)  //�ⲿ�жϳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;

	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Pin=FIRE_B8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	FIRE_EX = 0;
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);//ѡ��GPIO�ܽ������ⲿ�ж���·
	//�˴�һ��Ҫ��ס���˿ڹܽż����ж��ⲿ��·
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;//�������ж�
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure); 
	
	/* ����NVIC���� */	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; 	//��EXTI2��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  //��Ӧ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 		  //ʹ��
	NVIC_Init(&NVIC_InitStructure); 	
	

}

void exti2_init()  //�ⲿ�жϳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;

	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Pin=k_left;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	PB2 = 1;
	 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource2);//ѡ��GPIO�ܽ������ⲿ�ж���·
	//�˴�һ��Ҫ��ס���˿ڹܽż����ж��ⲿ��·
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure); 
	
	/* ����NVIC���� */	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; 	//��EXTI2��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  //��Ӧ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 		  //ʹ��
	NVIC_Init(&NVIC_InitStructure); 		
}

