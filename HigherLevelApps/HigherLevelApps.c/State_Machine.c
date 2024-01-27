/**
 * @file State_Machine.c
 * @author Leo Liu
 * @brief control the state of the robot
 * @version 1.0
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "State_Machine.h"

State_Machine_t State_Machine;

void Remote_Control_Update(void);
void Computer_Update(void);

State_Machine_Func_t State_Machine_Func = State_Machine_Func_GroundInit;
#undef State_Machine_Func_GroundInit

void Remote_Control_Update(void)
{
	/*
	Disable the robot when the right switch is DOWN
	Also disable the robot if remote control receives no data 
	*/
	if(DR16_Export_Data.Remote_Control.Right_Switch == SWITCH_DOWN
		|| DR16_Export_Data.Info_Update_Frame < 1)
	{
		Robot_Control_Func.Robot_Control_Disabled();
	}
	
	/*
	Define logic states for when the right switch is toggled mid
	*/
	else if(DR16_Export_Data.Remote_Control.Right_Switch == SWITCH_MID) 
	{
		State_Machine.Control_Source = Remote_Control;
		
		/*
		Set actions for left switch states here
		*/
		switch(DR16_Export_Data.Remote_Control.Left_Switch)
		{
			case(SWITCH_DOWN):
			{
				break;
			}
			case(SWITCH_MID):
			{
				break;
			}
			case(SWITCH_UP):
			{
				break;
			}
		}
	}
	
	/*
	Define logic states for when the right switch is toggled up
	*/
	else if(DR16_Export_Data.Remote_Control.Right_Switch == SWITCH_UP)
	{
		/*
		Set actions for left switch states here
		*/
		switch(DR16_Export_Data.Remote_Control.Left_Switch)
		{
			case(SWITCH_DOWN):
			{
				State_Machine.Control_Source = Remote_Control;				
				break;
			}	
			case(SWITCH_MID):
			{
				State_Machine.Control_Source = Remote_Control;
				break;
			}
			case(SWITCH_UP):
			{
				State_Machine.Control_Source = Computer;
				break;
			}
		}
	
	}

	Computer_Update();
}

/**
Logical States for keybord input
*/
void Computer_Update(void)
{
	if(State_Machine.Control_Source == Computer)
	{
		/*
		Place your actions here, pay attention to the switch flags/ keyboard keys

		Read DR16_Removete.h for accepted inputs
		*/
		if(DR16_Export_Data.Keyboard.Press_A.Switch_Flag)
		{

		}
		
		if(DR16_Export_Data.Keyboard.Press_Shift.Hold_Flag)
		{

		}
	}
}
