/*
 * LM35_PROG.c
 *
 * Created: 7/7/2023 2:54:44 PM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "../../MCAL/ADC/ADC_priv.h"
#include "../../MCAL/ADC/ADC_Init.h"
#include "LM35_Priv.h"
#include "LM35_Init.h"
void read(void*ptr)
{
	ADC_enHighValue((u16_t*)ptr);
	*(u16_t*)ptr = (*(u16_t*)ptr*MAX_ADC*1000ul)/MAX_ADC_RES;
}
ES_t Temp_enuInit(uint8_t Th_num)
{
	ES_t LocalErrorState = ES_OK;
	ADC_enuInit(AVCC,Left_Adjustment,Prescaler_8);
	DIO_SetPinDirection(PORT_A,Th_num,IN);
	ADC_SelectChannel(Th_num);
	return LocalErrorState;
}
ES_t Temp_enuGetTemp_val(u16_t*Tem_value)
{
	ES_t LocalErrorState = ES_OK;
	ADC_enEnableInterruptMode();
	ADC_enEnableTriggeringMode(EX_IN);
	ADC_enCallBack(&read,Tem_value);
	ADC_enStartConversion();
	return LocalErrorState;
}