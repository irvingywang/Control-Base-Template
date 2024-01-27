/**
 * @file PID.h
 * @author Leo Liu
 * @brief header file for PID
 * @version 1.0
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __PID_H
#define __PID_H
#include "User_Defined_Math.h"
#include "M3508_Motor.h"
#include "GM6020_Motor.h"
#include "M2006_Motor.h"
#include "Super_Capacitor.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUFFER_LENGTH 20

#define PID_Func_GroundInit            \
	{                                  \
		&Positional_PID,               \
			&Positional_PID_Min_Error, \
			&Incremental_PID,          \
			&Clear_PID_Data,           \
	}

typedef struct
{
	float Target_Value;
	float Measured_Value;

	float Error;
	float Prev_Error;
	float Prev_Prev_Error;

	float Kp;
	float Ki;
	float Kd;

	float P_Out;
	float I_Out;
	float D_Out;

	float Output;
	float Output_Max;
	float I_Out_Max;
} PID_t;

typedef struct
{
	float (*Positional_PID)(PID_t *PID, float Target_Value, float Measured_Value);
	float (*Positional_PID_Min_Error)(PID_t *PID, float Target_Value, float Measured_Value, float Min_Error);
	float (*Incremental_PID)(PID_t *PID, float Target_Value, float Measured_Value);
	void (*Clear_PID_Data)(PID_t *PID);
} PID_Func_t;

/*
Use #define to create PIDInit macros here

ex:
#define PID_sample    
	{                 
			0,        \\ Target_Value
			0,        \\ Measured_Value
			0,        \\ Error
			0,        \\ Prev_Error
			0,        \\ Prev_Prev_Error
			2.0f,     \\ Kp
			0.05f,    \\ Ki
			0,        \\ Kd
			0,        \\ P_Out
			0,        \\ I_Out
			0,        \\ D_Out
			0,        \\ Output
			16384.0f, \\ Output_Max
			1000.0f   \\ I_Out_Max
	}
*/

/*
remember to extern them here
*/
extern PID_Func_t PID_Func;

#endif
