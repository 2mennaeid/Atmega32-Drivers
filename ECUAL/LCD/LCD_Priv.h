/*
 * LCD_Priv.h
 *
 * Created: 14/02/2023 08:45:16 ص
 *  Author: Menna Eid
 */ 


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT				8
#define FOUR				4
#define CLEAR_LCD			0x01
#define FUNCTION_SET_8MODE  0x38
#define FUNCTION_SET_4MODE  0x28
#define DISPLAYON_CURSOR_ON 0x0c
#define CG_ADDRESS				0b01000000
#define DDRAM_ADDRESS_LINE1           0x80
#define DDRAM_ADDRESS_LINE2           0xC0
static inline void LCD_invidSendCommend(uint8_t _command);
static void LCD_Latch(uint8_t _u8command);





#endif /* LCD_PRIV_H_ */