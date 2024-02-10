/**
 * @file WT61P_IMU.h
 * @author Leo Liu
 * @brief header file for WT61P IMu
 * @version 1.0
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __WT61P_IMU_H
#define __WT61P_IMU_H 

#include <stdint.h>
#include "i2c.h"
#include "User_Defined_Math.h"
#include "Kalman_Filter.h"
#include "I2C_Setup.h"
#include "Fusion.h"

#define I2C_TIMEOUT 100
#define CALIBRATION_SAMPLE 1000

#define DEV_ADDR 0xD0
#define SMPLRT_DIV 0x19 
#define PWR_MGMT_1 0x6B  
#define WHO_AM_I 0x75 
#define CONFIG 0x1A 
#define GYRO_CONFIG 0x1B 
#define ACCEL_CONFIG 0x1C
#define CLOCK_PLL_XGYRO 0x01

#define ACCEL_XOUT_H 0x3B 
#define ACCEL_XOUT_L 0x3C 
#define ACCEL_YOUT_H 0x3D 
#define ACCEL_YOUT_L 0x3E 
#define ACCEL_ZOUT_H 0x3F 
#define ACCEL_ZOUT_L 0x40
 
#define TEMP_OUT_H 0x41 
#define TEMP_OUT_L 0x42

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44 
#define GYRO_YOUT_H 0x45 
#define GYRO_YOUT_L 0x46 
#define GYRO_ZOUT_H 0x47 
#define GYRO_ZOUT_L 0x48 

#define MPU6050_IMU_Func_GroundInit		\
		{																	\
				&MPU6050_IMU_Init,						\
						&MPU6050_IMU_Calibrate,		\
						&MPU6050_IMU_Read_Data,		\
						&MPU6050_IMU_Calc_Angle,	\
		}
typedef struct
{
		struct
		{
			int16_t Ax;
			int16_t Ay;
			int16_t Az;
			int16_t Gx;
			int16_t Gy;
			int16_t Gz;
			int16_t temperature;
		}Raw_Data;
		
		struct
		{
			float Ax;
			float Ay;
			float Az;
			float Gx;
			float Gy;
			float Gz;
		}Offset;
		
		struct
		{
			float Ax;
			float Ay;
			float Az;
			float Gx;
			float Gy;
			float Gz;
			float temperature;
		}Calc_Data;
    
		struct
		{
			float Yaw;
			float Pitch;
			float Roll;
						
			float Prev_Yaw;
			float Total_Yaw;
			float turn_count;
			
			float Gyro_Yaw;
			float Gyro_Pitch;
			float Gyro_Roll;
			
			float temperature;
		}Export_Data;
		
		struct
		{
			float Now_Time;
			float Prev_Time;
			float Period;
		}Sample;
		
		uint8_t Calibrated_Flag;
		uint8_t offline_flag;
} MPU6050_IMU_t;

typedef struct
{
	void (*MPU6050_IMU_Init)(void);
	void (*MPU6050_IMU_Calibrate)(MPU6050_IMU_t *MPU6050_IMU);
	void (*MPU6050_IMU_Read_Data)(MPU6050_IMU_t *MPU6050_IMU);
	void (*MPU6050_IMU_Calc_Angle)(MPU6050_IMU_t *MPU6050_IMU);
}MPU6050_IMU_Func_t;

extern MPU6050_IMU_t MPU6050_IMU;
extern MPU6050_IMU_Func_t MPU6050_IMU_Func;
extern FusionAhrs MPU6050_IMU_AHRS;

#endif
