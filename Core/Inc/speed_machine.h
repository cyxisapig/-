#ifndef SPEED_MACHINE_H
#define SPEED_MACHINE_H

#include "stm32f1xx_hal.h"
#include "servor_contral.h"

// 定义速度控制状态
typedef enum {
    SPEED_STOP = 0,
    SPEED_LOW,
    SPEED_MEDIUM,
    SPEED_HIGH
} SpeedState_TypeDef;

// 全局变量声明
extern int g_target_angle_A;
extern int g_current_angle_A;
extern int g_target_angle_B;
extern int g_current_angle_B;
extern int g_target_angle_C;
extern int g_current_angle_C;
extern int g_target_angle_D;
extern int g_current_angle_D;
extern uint32_t g_last_servo_update_time;

// 初始化速度控制状态机函数声明
void SpeedMachine_Init(void);

// 速度控制状态机处理函数声明
void SpeedMachine_Process(void);

// 设置目标角度函数声明
void SpeedMachine_SetTargetAngle(char servo_name, int angle);

#endif // SPEED_MACHINE_H
