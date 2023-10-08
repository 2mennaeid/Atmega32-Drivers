/*
 * KeyPad_Config.h
 *
 * Created: 20/02/2023 08:33:51 م
 *  Author: Menna Eid
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
#define ROW_NUM    4
#define COLUMN_NUM 4
// define pins row
#define KEYPAD_ROW0_PIN  PIN0
#define KEYPAD_ROW0_PORT  PORT_A

#define KEYPAD_ROW1_PIN  PIN1
#define KEYPAD_ROW1_PORT  PORT_A

#define KEYPAD_ROW2_PIN  PIN2
#define KEYPAD_ROW2_PORT  PORT_A

#define KEYPAD_ROW3_PIN  PIN3
#define KEYPAD_ROW3_PORT  PORT_A
// define column pins

#define KEYPAD_COLUMN0_PIN  PIN4
#define KEYPAD_COLUMN0_PORT  PORT_A

#define KEYPAD_COLUMN1_PIN  PIN5
#define KEYPAD_COLUMN1_PORT  PORT_A

#define KEYPAD_COLUMN2_PIN  PIN6
#define KEYPAD_COLUMN2_PORT  PORT_A

#define KEYPAD_COLUMN3_PIN  PIN7
#define KEYPAD_COLUMN3_PORT  PORT_A
// define array values
#define KEYVALues           {{'7','8','9','/'},{'4', '5', '6','x'},{'1', '2', '3', '-'},{'c', '0', '=', '+'}}

// define key value
#define KEY_VALUE  '.'



#endif /* KEYPAD_CONFIG_H_ */