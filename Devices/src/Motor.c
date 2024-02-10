#include "Motor.h"
#include "GM6020_Motor.h"

//
Motor_Container_t* new_motor(int can_ID, Motor_Type motor_type)
{
    Motor_Container_t *motor = (Motor_Container_t *) malloc(sizeof(Motor_Container_t));
    motor -> can_ID = can_ID;
    motor -> motor_type = motor_type;
    return motor;
}

void Get_Data(CAN_Export_Data_t RxMessage, Motor_Container_t *motor) {
    switch (motor->motor_type)
    {
    case GM6020: 
        GM6020_Get_Data(RxMessage, motor);
        break;
    case M2006:
        break;
    case M3508:
        break;
    default:
        // you did something very wrong
        break;
    }
}

void Send_Data(CAN_Export_Data_t RxMessage, Motor_Container_t *motor) {
    switch (motor->motor_type)
    {
    case GM6020: 
        GM6020_Send_Data(RxMessage, motor);
        break;
    case M2006:
        break;
    case M3508:
        break;
    default:
        // you did something very wrong
        break;
    }
}

//