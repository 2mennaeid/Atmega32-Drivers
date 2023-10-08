/*
 * KeyPad_Prog.c
 *
 * Created: 20/02/2023 08:35:12 م
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "../LCD/LCD_Interface.h"
#include "KeyPad_Config.h"
#include "KetPad_Priv.h"
#include "KETPAD_INTERFACE.h"
ES_t KeyPad_enuInit()
{
	ES_t LocalErrorstate=ES_OK;
	DIO_SetPinDirection(KEYPAD_ROW0_PORT,KEYPAD_ROW0_PIN,IN);
	DIO_SetPinDirection(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,IN);
	DIO_SetPinDirection(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,IN);
	DIO_SetPinDirection(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,IN);
	
	DIO_SetPinDirection(KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN0_PIN,OUT);
	DIO_SetPinDirection(KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN1_PIN,OUT);
	DIO_SetPinDirection(KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN2_PIN,OUT);
	DIO_SetPinDirection(KEYPAD_COLUMN3_PORT,KEYPAD_COLUMN3_PIN,OUT);
	
	DIO_SetPinValue(KEYPAD_ROW0_PORT,KEYPAD_ROW0_PIN,PULL_UP);
	DIO_SetPinValue(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,PULL_UP);
	DIO_SetPinValue(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,PULL_UP);
	DIO_SetPinValue(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,PULL_UP);
	
	DIO_SetPinValue(KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN0_PIN,HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN1_PIN,HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN2_PIN,HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN3_PORT,KEYPAD_COLUMN3_PIN,HIGH);
	return LocalErrorstate;
}
uint8_t KeyPad_u8KeyPressedVal(uint8_t *_flag)
{
	uint8_t LocalPressedKeyVal = KEY_VALUE;
	
	static uint8_t KeyArr[ROW_NUM][COLUMN_NUM] = KEYVALues;
	static uint8_t KeyColumnPin[COLUMN_NUM] = {KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	static uint8_t KeyROWPin[ROW_NUM] = {KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};
		
	static uint8_t KeyColumnPort[COLUMN_NUM] = {KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN3_PORT};
	static uint8_t KeyROWPort[ROW_NUM] = {KEYPAD_ROW0_PORT,KEYPAD_ROW1_PORT,KEYPAD_ROW2_PORT,KEYPAD_ROW3_PORT};	
	static uint8_t LocalColindex;
	static uint8_t LocalRowindex;
    * _flag= LOW;
	for(LocalColindex=0;LocalColindex<COLUMN_NUM;LocalColindex++)
	{
		// Activate current column
		DIO_SetPinValue(KeyColumnPort[LocalColindex],KeyColumnPin[LocalColindex],LOW);
		for(LocalRowindex=0;LocalRowindex<ROW_NUM;LocalRowindex++)
		{
			// read current row
			DIO_readpinvalue(KeyROWPort[LocalRowindex],KeyROWPin[LocalRowindex],&LocalPressedKeyVal);
			if(LOW==LocalPressedKeyVal)
			{		
				
          		// Polling(busy wait)
     			while(LOW==LocalPressedKeyVal)
				{
					DIO_readpinvalue(KeyROWPort[LocalRowindex],KeyROWPin[LocalRowindex],&LocalPressedKeyVal);
				}
				LocalPressedKeyVal= KeyArr[LocalRowindex][LocalColindex];
				*_flag=HIGH;
				if(LocalPressedKeyVal=='c')
				{
					LCD_enSendCommand(0x01);
				}
				return LocalPressedKeyVal;
			}
		}
		// deactivate current column
		DIO_SetPinValue(KeyColumnPort[LocalColindex],KeyColumnPin[LocalColindex],HIGH);
	}
	return LocalPressedKeyVal;
}