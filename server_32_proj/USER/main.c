#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "exti.h"
#include "pwm.h"

 int main(void)
 {		  	
	 delay_init();	    	 //��ʱ������ʼ��	  
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	 uart_init(115200);	 	 //���ڳ�ʼ��Ϊ115200
	 LED_Init();			     //LED�˿ڳ�ʼ��
	 KEY_Init();           //��ʼ���밴�����ӵ�Ӳ���ӿ�
	 exti2_init();
	 //CON_Init();
	 TIM_PWM_Init(9999,143);//����ƵPWMƵ��=72*10^6/(9999+1)/(143+1)=50Hz
	 TIM_SetCompare2(TIM3,499);
	 printf("401��1�Ŵ�������Һ######\r\n");
	 
 	while(1)
	{
		LED_light();
	} 
 }
 

