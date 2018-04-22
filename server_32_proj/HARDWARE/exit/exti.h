#ifndef __EXTI_H
#define __EXTI_H
#include "stm32f10x.h"
#include "sys.h"
#define PB2 PBout(2)
#define CONT_JD PBout(7)
#define FIRE_EX PBout(8)
#define FIRE_B8 GPIO_Pin_8  //外部中断 PB8
#define CONT_B7 GPIO_Pin_7  //空气阀控制

#define k_left GPIO_Pin_2  

void exti_init(void);  //外部中断初始化
void CON_Init(void);
void exti2_init(void);


#endif 
