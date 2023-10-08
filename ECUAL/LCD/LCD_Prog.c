/*
 * LCD_Prog.c
 * Version : 3.0
 * Created: 14/02/2023 08:46:17 
 *  Author: Menna Eid				
 */
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "LCD_Priv.h"
#include "LCD_Config.h"
//#include "LCD_Interface.h"
#define F_CPU  1000000UL

#include "util/delay.h"

ES_t LCD_enInit(void)
{
	ES_t LocalErrorstate = ES_OK;
	// set control pins
	DIO_SetPinDirection(RS_PORT,RS_PIN,OUT);
	DIO_SetPinDirection(RW_PORT,RW_PIN,OUT);
	DIO_SetPinDirection(EN_PORT,EN_PIN,OUT);
	// set data pins
	DIO_SetPinDirection(D7_PORT,D7_PIN,OUT);
	DIO_SetPinDirection(D6_PORT,D6_PIN,OUT);
	DIO_SetPinDirection(D5_PORT,D5_PIN,OUT);
	DIO_SetPinDirection(D4_PORT,D4_PIN,OUT);
	_delay_ms(35);
#if LCD_MODE==EIGHT
	DIO_SetPinDirection(D3_PORT,D3_PIN,OUT);
	DIO_SetPinDirection(D2_PORT,D2_PIN,OUT);
	DIO_SetPinDirection(D1_PORT,D1_PIN,OUT);
	DIO_SetPinDirection(D0_PORT,D0_PIN,OUT);
	// function set
	LCD_invidSendCommend(FUNCTION_SET_8MODE);
#elif LCD_MODE == FOUR
	LCD_invidSendCommend(FUNCTION_SET_4MODE);
#endif
	_delay_ms(1);
	// display on
	LCD_invidSendCommend(DISPLAYON_CURSOR_ON);
	_delay_ms(1);
	// clear lcd
	LCD_invidSendCommend(CLEAR_LCD);
	_delay_ms(2);
	// entry mode set (I/D)
	LCD_invidSendCommend(0x06);
	return LocalErrorstate;
	
}

ES_t LCD_enDisplayChar(uint8_t u8name)
{
	ES_t LocalErrorstate =ES_OK;
	// set rs as data
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	LCD_Latch(u8name);
	return LocalErrorstate;
}
ES_t LCD_enuDisplayString(uint8_t*str)
{
	ES_t LocalErrorstate =ES_OK;
	while(*str!='\0')
	{
		LCD_enDisplayChar(*str);
		str++;
	}
	return LocalErrorstate;
}
ES_t LCD_enDisplayNum(s32 s32num)
{
	ES_t LocalErrorstate= ES_OK;
	s32 LocalReverse=0;
	uint8_t Numdigit=0;
	uint8_t LocalRemiander=0;
	// reverse number
	while(s32num)
	{
		LocalRemiander = s32num % 10;
		LocalReverse = LocalReverse*10 + LocalRemiander;
		s32num /=10;
		Numdigit++;
	}
	// display num
	while(Numdigit)
	{
		LocalRemiander = LocalReverse%10;
		DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
		LCD_Latch(LocalRemiander + '0');
		LocalReverse /=10;
		Numdigit--;
	}
	
	
	return LocalErrorstate;
}
ES_t LCD_enSendCommand(uint8_t _u8command)
{
	ES_t LocalErrorstate= ES_OK;
	// set rs  as command
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	LCD_Latch(_u8command);
	return LocalErrorstate;
}
void LCD_voidSendSpecialChar(uint8_t Copy_u8CharAddress, uint8_t*Copy_u8SpecialChar)
{
	
	LCD_invidSendCommend(0x40+(Copy_u8CharAddress*8));
	_delay_us(40);
	uint8_t Local_counter;
	for(Local_counter=0;Local_counter<8;Local_counter++)
	{
		LCD_enDisplayChar(Copy_u8SpecialChar[Local_counter]);
	}
	LCD_enSendCommand(0x80);
}

static void LCD_Latch(uint8_t _u8command)
{
	// set rw 0 as write
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	// EN is low
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	// set data pins
#if LCD_MODE == EIGHT
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
	DIO_SetPinValue(D3_PORT,D3_PIN, ((_u8command>>3)&1) );
	DIO_SetPinValue(D2_PORT,D2_PIN, ((_u8command>>2)&1) );
	DIO_SetPinValue(D1_PORT,D1_PIN, ((_u8command>>1)&1) );
	DIO_SetPinValue(D0_PORT,D0_PIN, ((_u8command>>0)&1) );
#elif LCD_MODE==FOUR
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
#endif
	// enable latch
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(10);
	
	
}
static inline void LCD_invidSendCommend(uint8_t _u8command)
{
	// set rw 0 as write
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	// EN is low
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	// set data pins
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
	DIO_SetPinValue(D3_PORT,D3_PIN, ((_u8command>>3)&1) );
	DIO_SetPinValue(D2_PORT,D2_PIN, ((_u8command>>2)&1) );
	DIO_SetPinValue(D1_PORT,D1_PIN, ((_u8command>>1)&1) );
	DIO_SetPinValue(D0_PORT,D0_PIN, ((_u8command>>0)&1) );
	
	// enable latch
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(10);
}
ES_t LCD_goto(uint8_t Copy_u8Line,uint8_t Copy_u8Location)
{
	ES_t Local=ES_OK;
	switch(Copy_u8Line)
	{
		case LCD_LINE1:
			LCD_invidSendCommend(DDRAM_ADDRESS_LINE1+Copy_u8Location);
			break;
		case LCD_LINE2:
			LCD_invidSendCommend(DDRAM_ADDRESS_LINE2+Copy_u8Location);
			break;
	}
	return Local;
}

