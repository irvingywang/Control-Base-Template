/**
 * @file Robot_Control.h
 * @author Leo Liu
 * @brief header file for robot_control
 * @version 1.0
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ROBOT_CONTROL_H
#define __ROBOT_CONTROL_H

#include "State_Machine.h"
#include "Jetson_Tx2.h"
#include "Buzzer.h"
#include "Referee_System.h"

#define Robot_Control_Func_GroundInit \
	{                                 \
		&Robot_Control_Update,        \
			&Robot_Control_Send,      \
			&Robot_Control_Disabled,  \
	}

typedef struct
{
	enum
	{
		Follow_Gimbal,
		Not_Follow_Gimbal,
		Spin_Top,
		Disabled,
	} Mode;

	uint8_t Initialized_Flag;
} Robot_Mode_t;

typedef struct
{
	void (*Robot_Control_Update)(void);
	void (*Robot_Control_Send)(void);
	void (*Robot_Control_Disabled)(void);
} Robot_Control_Func_t;

extern Robot_Mode_t Robot_Mode;
extern Robot_Control_Func_t Robot_Control_Func;

#endif
