/*
 * button_interface.h
 *
 * Created: 30/01/2023 07:03:41 م
 *  Author: Pc
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include "../../MCAL/DIO/DI0_interface.h"
ES_t Button_eninit(uint8_t portnumber,uint8_t pinnumber,uint8_t type_conecction);
ES_t Button_Getstate(uint8_t portnumber,uint8_t pinnumber,uint8_t *value);




#endif /* BUTTON_INTERFACE_H_ */