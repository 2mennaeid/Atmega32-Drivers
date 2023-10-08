/*
 * Stepper_Prog.c
 *
 * Created: 8/23/2023 8:56:28 AM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "util/delay.h"
#include "Stepper_Priv.h"
#include "stepper_Config.h"
#include "Stepper_Init.h"

void Stepper_voidInit()
{
	DIO_SetPinDirection(BLUE_PORT,BLUE_PIN,OUT);
	DIO_SetPinDirection(PINK_PORT,PINK_PIN,OUT);
	DIO_SetPinDirection(YELLOW_PORT,YELLOW_PIN,OUT);
	DIO_SetPinDirection(ORANGE_PORT,ORANGE_PIN,OUT);
}

void Stepper_voidSet_Angle(uint8_t Copy_u8angle,f32 Copy_f32step_angle)
{
	uint8_t steps = ((f32)Copy_u8angle/Copy_f32step_angle)/4;
	uint8_t i =0;
	#if MOTOR_DIRECTION == ACW
		for(;i<steps;i++)
		{
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,HIGH);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,HIGH);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,HIGH);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,HIGH);
			_delay_ms(200);
		}
	#elif MOTOR_DIRECTION == CW
		for(;i<steps;i++)
		{
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,HIGH);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,HIGH);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,LOW);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,HIGH);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
			DIO_SetPinValue(BLUE_PORT,BLUE_PIN,HIGH);
			DIO_SetPinValue(PINK_PORT,PINK_PIN,LOW);
			DIO_SetPinValue(YELLOW_PORT,YELLOW_PIN,LOW);
			DIO_SetPinValue(ORANGE_PORT,ORANGE_PIN,LOW);
			_delay_ms(200);
		}
	#endif
}