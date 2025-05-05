#include "main.h"
#include "systime.h"

// 定义全局变量
uint32_t g_system_time = 0;

// 定时器中断回调函数
void SysTime_TIM_IRQHandler(TIM_HandleTypeDef *htim) {
        g_system_time++;
}

// 初始化系统时间函数
void SysTime_Init(TIM_HandleTypeDef *htim) {
    // 初始化定时器1
    HAL_TIM_Base_Start_IT(htim);
}

// 获取系统时间函数
uint32_t SysTime_Get(void) {
    return g_system_time;
}

// 添加一个空行以确保文件末尾有换行符
