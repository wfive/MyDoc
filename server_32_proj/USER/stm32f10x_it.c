#include "stm32f10x_it.h" 
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "exti.h"
#include "pwm.h"

#define WARD_NUM  301
#define SICK_NUM  01
int i=0;
 void USART1_IRQHandler(void)	//����1�жϺ���
{

}


void EXTI2_IRQHandler()	   //�ⲿ�ж�2�жϺ���
{
	if(EXTI_GetITStatus(EXTI_Line2)==SET)
	{
   		//EXTI_ClearITPendingBit(EXTI_Line0);//���EXTI��·����λ
			delay_ms(1000);//��ʱ����
		//if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)== 1)	   //����������
		
				TIM_SetCompare2(TIM3,1199);
				printf("401��1�Ŵ���Һ���******\r\n");
					delay_ms(1000);
		//while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)==0)
		//										;
	}		
	EXTI_ClearITPendingBit(EXTI_Line2);
}
