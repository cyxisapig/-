#include "main.h"
#include "systime.h"
#include "speed_machine.h"
#include <math.h>

// 定义全局变量
int g_target_angle_A = 90;
int g_current_angle_A = 90;
int g_target_angle_B = 90;
int g_current_angle_B = 90;
int g_target_angle_C = 90;
int g_current_angle_C = 90;
int g_target_angle_D = 90;
int g_current_angle_D = 90;
uint32_t g_last_servo_update_time_A = 0;
uint32_t g_last_servo_update_time_B = 0;
uint32_t g_last_servo_update_time_C = 0;
uint32_t g_last_servo_update_time_D = 0;

// 定义不同的速度间隔时间（毫秒）
#define STOP_INTERVAL 0
#define LOW_INTERVAL 10
#define MEDIUM_INTERVAL 5
#define HIGH_INTERVAL 5

// 计算速度间隔时间的函数
uint32_t SpeedMachine_CalculateInterval(float angle_difference) {
    if (fabs(angle_difference) < 30) {
        return LOW_INTERVAL;
    } else if (fabs(angle_difference) < 60) {
        return MEDIUM_INTERVAL;
    } else {
        return HIGH_INTERVAL;
    }
}

// 初始化速度控制状态机
void SpeedMachine_Init(void)
{
    g_target_angle_A = 90;
    g_current_angle_A = 90;
    g_target_angle_B = 90;
    g_current_angle_B = 90;
    g_target_angle_C = 90;
    g_current_angle_C = 90;
    g_target_angle_D = 90;
    g_current_angle_D = 90;
    g_last_servo_update_time_A = SysTime_Get();
	g_last_servo_update_time_B = SysTime_Get();
	g_last_servo_update_time_C = SysTime_Get();
	g_last_servo_update_time_D = SysTime_Get();
}

// 速度控制状态机处理函数
void SpeedMachine_Process(void) {
    uint32_t current_time = SysTime_Get();

    // 检查是否需要更新舵机角度
    //if (current_time - g_last_servo_update_time >= 20) {
        // 处理舵机A
        float angle_difference_A = g_target_angle_A - g_current_angle_A;
        if (angle_difference_A != 0) {
            uint32_t interval_A = SpeedMachine_CalculateInterval(angle_difference_A);
            if (current_time - g_last_servo_update_time_A >= interval_A) {
                if (angle_difference_A > 0) {
                    g_current_angle_A += 1; // 每次增加1度
                } else {
                    g_current_angle_A -= 1; // 每次减少1度
                }
                Servo_SetAngle('A', (int)g_current_angle_A);
								g_last_servo_update_time_A = current_time;
            }
        }

        // 处理舵机B
        float angle_difference_B = g_target_angle_B - g_current_angle_B;
        if (angle_difference_B != 0) {
            uint32_t interval_B = SpeedMachine_CalculateInterval(angle_difference_B);
            if (current_time - g_last_servo_update_time_B >= interval_B) {
                if (angle_difference_B > 0) {
                    g_current_angle_B += 1; // 每次增加1度
                } else {
                    g_current_angle_B -= 1; // 每次减少1度
                }
                Servo_SetAngle('B', (int)g_current_angle_B);
								g_last_servo_update_time_B = current_time;
            }
        }

        // 处理舵机C
        float angle_difference_C = g_target_angle_C - g_current_angle_C;
        if (angle_difference_C != 0) {
            uint32_t interval_C = SpeedMachine_CalculateInterval(angle_difference_C);
            if (current_time - g_last_servo_update_time_C >= interval_C) {
                if (angle_difference_C > 0) {
                    g_current_angle_C += 1; // 每次增加1度
                } else {
                    g_current_angle_C -= 1; // 每次减少1度
                }
                Servo_SetAngle('C', (int)g_current_angle_C);
								g_last_servo_update_time_C = current_time;
            }
        }

        // 处理舵机D
        float angle_difference_D = g_target_angle_D - g_current_angle_D;
        if (angle_difference_D != 0) {
            uint32_t interval_D = SpeedMachine_CalculateInterval(angle_difference_D);
            if (current_time - g_last_servo_update_time_D >= interval_D) {
                if (angle_difference_D > 0) {
                    g_current_angle_D += 1; // 每次增加1度
                } else {
                    g_current_angle_D -= 1; // 每次减少1度
                }
                Servo_SetAngle('D', (int)g_current_angle_D);
								g_last_servo_update_time_D = current_time;
            }
        }

        // 更新最后更新时间
        //g_last_servo_update_time = current_time;
    //}
}

// 设置目标角度函数
void SpeedMachine_SetTargetAngle(char servo_name, int angle) {
    switch (servo_name) {
        case 'A':
            g_target_angle_A = angle;
            break;
        case 'B':
            g_target_angle_B = angle;
            break;
        case 'C':
            g_target_angle_C = angle;
            break;
        case 'D':
            g_target_angle_D = angle;
            break;
        default:
            // 如果舵机名字无效，可以在这里处理错误
            break;
    }
}
