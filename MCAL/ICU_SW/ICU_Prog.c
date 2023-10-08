/*
 * ICU_Prog.c
 *
 * Created: 8/29/2023 12:50:01 PM
 *  Author: Menna Eid
 */ 
#include "../DIO/Registers1.h"
#include "../DIO/StdTypes.h"
#include "../DIO/errorstate.h"
#include "../DIO/DIO_priv.h"
#include "../EX_Intrrupt/interrupt.h"
#include "../EX_Intrrupt/EX_Intrrupt_priv.h"
#include "../EX_Intrrupt/EX_Interrupt_Interface.h"
#include "ICU_Priv.h"
#include "ICU_Init.h"
uint8_t TimeOn;
uint8_t TimeOf;
uint8_t Total;
f32 Time;
void ICU_Calculation()
{
	if(state==start)
	{
		Timer_voidStart();
		EXI_SetSenceMode(EX_INT0,FALLING_EDGE);
		state = TON;
	}
	else if(state==TON)
	{
		TimeOn =TCNT0;
		EXI_SetSenceMode(EX_INT0,RISING_EDGE);
		state = Tt;
		
	}
	else if(state==Tt)
	{
		Total =TCNT0;
		state = TOFF;
		
	}
}
void ICU_voidInit()
{
	// enable INT0 , Rising 
	DIO_SetPinDirection(PORT_D,PIN2,IN);
	Enable_EXInterrupt(EX_INT0);
	EXI_SetSenceMode(EX_INT0,RISING_EDGE);
	EXI_SetCallBack(EX_INT0,&ICU_Calculation,NULLPTR);
	sei();
}

void ICU_voidGetDuty(f32*Copy_f32duty)
{
	*Copy_f32duty = ((f32)TimeOn/Total)*100;
}

void ICU_voidGetFrequancy(f32*Copy_f32freq)
{
	Time = ((f32)Total*1024/8000000ul)*1000;
	*Copy_f32freq = 1.0/Time;
	Disable_EXInterrupt(EX_INT0);
	
}