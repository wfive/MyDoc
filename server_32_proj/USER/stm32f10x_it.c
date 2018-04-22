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
 void USART1_IRQHandler(void)	//串口1中断函数
{

}


void EXTI2_IRQHandler()	   //外部中断2中断函数
{
	if(EXTI_GetITStatus(EXTI_Line2)==SET)
	{
   		//EXTI_ClearITPendingBit(EXTI_Line0);//清除EXTI线路挂起位
			delay_ms(1000);//延时处理
		//if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)== 1)	   //传感器触发
		
				TIM_SetCompare2(TIM3,1199);
				printf("401室1号床输液完毕******\r\n");
					delay_ms(1000);
		//while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)==0)
		//										;
	}		
	EXTI_ClearITPendingBit(EXTI_Line2);
}
