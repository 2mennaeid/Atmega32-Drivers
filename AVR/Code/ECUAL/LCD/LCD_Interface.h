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




#endif /* LCD_INTERFACE_H_ */