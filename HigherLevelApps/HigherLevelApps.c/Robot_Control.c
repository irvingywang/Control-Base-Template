/**
 * @file Robot_Control.c
 * @author Leo Liu
 * @brief general robot control
 * @version 1.0
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Robot_Control.h"

void Robot_Control_Update(void); 
void Robot_Control_Send(void);
void Robot_Control_Disabled(void);

Robot_Control_Func_t Robot_Control_Func = Robot_Control_Func_GroundInit;
#undef Robot_Control_Func_GroundInit

Robot_Mode_t Robot_Mode;

/*
This function is called on every loop, use this function to get/send and process data
*/
void Robot_Control_Update(void)
{
	State_Machine_Func.Remote_Control_Update(); 
	Referee_System_Func.Referee_Set_Robot_State();

	Tx2_Func.Jetson_Tx2_Get_Data();
	Tx2_Func.Jetson_Tx2_Send_Data();
	
	Robot_Control_Func.Robot_Control_Send();
}

/*
Send your data to motor controllers here
*/
void Robot_Control_Send(void)
{

}

/*
Run disable functions here
*/
void Robot_Control_Disabled(void)
{

}
