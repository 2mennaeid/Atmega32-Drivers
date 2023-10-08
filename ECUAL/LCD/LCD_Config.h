/*
 * LCD_Config.h
 *
 * Created: 14/02/2023 08:45:46 ص
 *  Author: Menna Eid
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

// LCD Mode
#define LCD_MODE  EIGHT
#define LCD_LINE1 1
#define LCD_LINE2 2
// LCD Control PINS
#define RS_PORT PORT_B
#define RS_PIN  PIN3

#define RW_PORT PORT_B
#define RW_PIN  PIN4

#define EN_PORT PORT_B
#define EN_PIN  PIN5

// LCD DATA PINS
#define D7_PORT PORT_A
#define D7_PIN  PIN0

#define D6_PORT PORT_A
#define D6_PIN  PIN1

#define D5_PORT PORT_A
#define D5_PIN  PIN2

#define D4_PORT PORT_A
#define D4_PIN  PIN3

#define D3_PORT PORT_A
#define D3_PIN  PIN4

#define D2_PORT PORT_A
#define D2_PIN  PIN5

#define D1_PORT PORT_A
#define D1_PIN  PIN6

#define D0_PORT PORT_A
#define D0_PIN  PIN7






#endif /* LCD_CONFIG_H_ */