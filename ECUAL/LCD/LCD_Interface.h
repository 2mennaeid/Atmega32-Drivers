/*
 * LCD_Interface.h
 *
 * Created: 14/02/2023 08:44:41 ص
 *  Author: Menna Eid
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
ES_t LCD_enInit(void);
ES_t LCD_enDisplayChar(uint8_t u8name);
ES_t LCD_enSendCommand(uint8_t _u8command);
ES_t LCD_enuDisplayString(uint8_t*str);
ES_t LCD_goto(uint8_t Copy_u8Line,uint8_t Copy_u8Location);
ES_t LCD_enDisplayNum(s32 s32num);
void LCD_voidSendSpecialChar(uint8_t Copy_u8CharAddress, uint8_t*Copy_u8SpecialChar);

#endif /* LCD_INTERFACE_H_ */