/*
 * I2C_Prog.c
 *
 * Created: 7/15/2023 6:47:23 AM
 *  Author: Menna Eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "I2C_Priv.h"
#include "I2C_Config.h"
#include "I2C_Init.h"
ES_t I2C_enuMasterInit(void)
{
	ES_t LocalErrorState = ES_NOK;
	TWBR = (uint8_t)BITRATE(IIC_SPEED);
	TWAR = 0x02;
#if IIC_PRES == 1
	TWSR &= ~(1<<TWPS0);
	TWSR &= ~(1<<TWPS1);
#elif IIC_PRES == 4
	TWSR |= (1<<TWPS0);
	TWSR &= ~(1<<TWPS1);
#elif IIC_PRES == 16
	TWSR &= ~(1<<TWPS0);
	TWSR |= (1<<TWPS1);
#elif IIC_PRES == 64
	TWSR |= (1<<TWPS0);
	TWSR |= (1<<TWPS1);
#endif
	// enable I2C
	TWCR |= (1<<TWEN);
	return LocalErrorState;
}
ES_t I2C_enuSlaveInit(void)
{
	ES_t LocalErrorState = ES_OK;
    TWAR = NODE_ADDRESS;
   // enable I2C
   TWCR |= (1<<TWEN);
	return LocalErrorState;
}


ES_t I2C_enuStartCondition(void)
{
	ES_t LocalErrorState = ES_NOK;
	TWCR |= (1<<TWSTA);
	TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));	
	if((TWSR & 0xf8)==0x08)
	{
		LocalErrorState = ES_OK;
	}
	
	
	return LocalErrorState;
}

ES_t I2C_enuStopCondition(void)
{
	ES_t LocalErrorState = ES_NOK;
	TWCR |=(1<<TWSTO);
    TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	return LocalErrorState;
}

ES_t I2C_enuRepeatedStartCondition(void)
{
	ES_t LocalErrorState = ES_NOK;
	// clear flag
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if((TWSR & 0xf8)==0x10)
	{
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t I2C_enuWriteData(uint8_t Copy_u8data)
{
	ES_t LocalErrorState = ES_NOK;
	TWDR = Copy_u8data;
	TWCR |= (1<<TWEA);
	// clear flag
	TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	if((TWSR & 0xf8)==0x28)
	{
		LocalErrorState = ES_OK;
	}
	
	return LocalErrorState;
}

ES_t I2C_enuReadData(uint8_t*Copy_u8data)
{
	ES_t LocalErrorState = ES_NOK;
	TWCR |= (1<<TWEA);
	TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	if((TWSR & 0xf8)==0x80)
	{
		*Copy_u8data = TWDR;
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t I2C_enuWriteSlaveAddress(uint8_t Copy_u8SlaveAddress , uint8_t Copy_u8operation)
{
	ES_t LocalErrorState = ES_NOK;
	TWDR = (Copy_u8SlaveAddress<<1);
	TWDR |= Copy_u8operation;
	TWCR &= ~(1<<TWSTA);
	TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	if(Copy_u8operation==0) // write
	{
		if((TWSR & 0xf8)==0x18)
		{
			LocalErrorState = ES_OK;
		}
	}
	else if(Copy_u8operation==1)
	{
		if((TWSR & 0xf8)==0x40)
		{
			LocalErrorState = ES_OK;
		}
	}
	return LocalErrorState;
}

ES_t I2C_enuCheckMyAddress(void)
{
	ES_t LocalErrorState = ES_NOK;
	 TWCR |= (1<<TWEA);
	 TWCR |= (1<<TWINT);
	 while (!(TWCR & (1<<TWINT)));
	 if((TWSR & 0xf8)==0x60) // SLA+Write
	 {
		 LocalErrorState = ES_OK;
	 }
	 else if((TWSR & 0xf8)==0xA8) // SLA+Read
	 {
		 LocalErrorState = ES_OK;
	 }
	return LocalErrorState;
}