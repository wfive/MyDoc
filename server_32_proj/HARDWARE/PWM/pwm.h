#ifndef _PWM_H
#define _PWM_H
#include "stm32f10x.h"
void TIM_PWM_Init(u16 arr,u16 psc);
void SetJointAngle(u8 ID, float angle);


#endif
