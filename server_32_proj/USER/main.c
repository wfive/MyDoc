#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "exti.h"
#include "pwm.h"

 int main(void)
 {		  	
	 delay_init();	    	 //延时函数初始化	  
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 uart_init(115200);	 	 //串口初始化为115200
	 LED_Init();			     //LED端口初始化
	 KEY_Init();           //初始化与按键连接的硬件接口
	 exti2_init();
	 //CON_Init();
	 TIM_PWM_Init(9999,143);//不分频PWM频率=72*10^6/(9999+1)/(143+1)=50Hz
	 TIM_SetCompare2(TIM3,499);
	 printf("401室1号床正在输液######\r\n");
	 
 	while(1)
	{
		LED_light();
	} 
 }
 

