#ifndef SYSTIME_H
#define SYSTIME_H

#include "stm32f1xx_hal.h"

// 全局变量声明
extern uint32_t g_system_time;

// 初始化系统时间函数声明
void SysTime_Init(TIM_HandleTypeDef *htim);

// 获取系统时间函数声明
uint32_t SysTime_Get(void);

#endif // SYSTIME_H