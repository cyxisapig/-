#include "main.h"
#include "servor_contral.h"
#include <math.h>

#define MIN_ANGLE 0.0f
#define MAX_ANGLE 180.0f
#define MIN_PULSE 50.0f // 占空比最小值（微秒）
#define MAX_PULSE 250.0f // 占空比最大值（微秒）
// 定义全局变量
float g_servo_a_angle = 90.0f;
float g_servo_b_angle = 0.0f;
float g_servo_c_angle = 0.0f;
float g_servo_d_angle = 0.0f;

void Servo_Init(void){
    Servo_SetAngle('A', 90);
    Servo_SetAngle('B', 0);
    Servo_SetAngle('C', 0);
    Servo_SetAngle('D', 0);
	HAL_Delay(1000);
}

void Servo_SetAngle(char servo_name, int angle)
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    float min_angle, max_angle;

    // 根据舵机名字设置对应的定时器、通道和角度限制
    switch (servo_name) {
        case 'A':
            htim = &SERVO_A_TIMER_HANDLE;
            channel = SERVO_A_CHANNEL;
            min_angle = SERVO_A_MIN_ANGLE;
            max_angle = SERVO_A_MAX_ANGLE;
            break;
        case 'B':
            htim = &SERVO_B_TIMER_HANDLE;
            channel = SERVO_B_CHANNEL;
            min_angle = SERVO_B_MIN_ANGLE;
            max_angle = SERVO_B_MAX_ANGLE;
            break;
        case 'C':
            htim = &SERVO_C_TIMER_HANDLE;
            channel = SERVO_C_CHANNEL;
            min_angle = SERVO_C_MIN_ANGLE;
            max_angle = SERVO_C_MAX_ANGLE;
            break;
        case 'D':
            htim = &SERVO_D_TIMER_HANDLE;
            channel = SERVO_D_CHANNEL;
            min_angle = SERVO_D_MIN_ANGLE;
            max_angle = SERVO_D_MAX_ANGLE;
            break;
        default:
            // 如果舵机名字无效，可以在这里处理错误
            return;
    }

    // 检查角度是否在允许的范围内
    if (angle < min_angle) {
        angle = min_angle;
    } else if (angle > max_angle) {
        angle = max_angle;
    }

    // 计算占空比
    uint16_t duty_cycle = (angle * (250 - 50) / 180) + 50;

    // 设置占空比
    __HAL_TIM_SET_COMPARE(htim, channel, duty_cycle);
}