#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "stm32f1xx_hal.h" 

// 舵机定时器和通道宏定义
#define SERVO_A_TIMER_HANDLE htim2
#define SERVO_A_CHANNEL      TIM_CHANNEL_2
#define SERVO_B_TIMER_HANDLE htim2
#define SERVO_B_CHANNEL      TIM_CHANNEL_3
#define SERVO_C_TIMER_HANDLE htim2
#define SERVO_C_CHANNEL      TIM_CHANNEL_4
#define SERVO_D_TIMER_HANDLE htim3
#define SERVO_D_CHANNEL      TIM_CHANNEL_1


// 舵机角度限制宏定义
#define SERVO_A_MIN_ANGLE 0
#define SERVO_A_MAX_ANGLE 180
#define SERVO_B_MIN_ANGLE 0
#define SERVO_B_MAX_ANGLE 80
#define SERVO_C_MIN_ANGLE 30
#define SERVO_C_MAX_ANGLE 150
#define SERVO_D_MIN_ANGLE 0
#define SERVO_D_MAX_ANGLE 37
// 全局变量声明
extern float g_servo_a_angle;
extern float g_servo_b_angle;
extern float g_servo_c_angle;
extern float g_servo_d_angle;

// 舵机初始化函数声明
void Servo_Init(void);

// 设置舵机角度函数声明
void Servo_SetAngle(char servo_name, int angle);

// 设置舵机速度函数声明
void Servo_SetSpeed(TIM_HandleTypeDef *htim, uint32_t channel, int speed);

#endif // SERVO_CONTROL_H
