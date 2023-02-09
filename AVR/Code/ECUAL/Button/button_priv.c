/*
 * button_priv.c
 *
 * Created: 30/01/2023 07:04:42 م
 *  Author: Menna Eid
 */ 

#include "button_interface.h"
ES_t Button_eninit(uint8_t portnumber,uint8_t pinnumber,uint8_t type_conecction)
{
	ES_t LocalErrorstate;
	if(portnumber>='A'&& portnumber<='D')
	{
		DIO_SetPinDirection(portnumber,pinnumber,IN);
		DIO_SetPinValue(portnumber,pinnumber,type_conecction);
		LocalErrorstate=ES_OK;
	}
	else
	{
		LocalErrorstate=ES_NOK;
	}
	return LocalErrorstate;
	
}
ES_t Button_Getstate(uint8_t portnumber,uint8_t pinnumber,uint8_t *value)
{
	ES_t LocalErrorstate;
	if(portnumber>='A'&& portnumber<='D')
	{
		DIO_readpinvalue(portnumber,pinnumber,value);
		LocalErrorstate=ES_OK;
	}
	else
	{
		LocalErrorstate=ES_NOK;
	}
	return LocalErrorstate;
}