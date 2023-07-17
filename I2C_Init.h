/*
 * I2C_Init.h
 *
 * Created: 7/15/2023 6:45:41 AM
 *  Author: Menna Eid
 */ 


#ifndef I2C_INIT_H_
#define I2C_INIT_H_

ES_t I2C_enuMasterInit(void);

ES_t I2C_enuSlaveInit(void);

ES_t I2C_enuStartCondition(void);

ES_t I2C_enuStopCondition(void);

ES_t I2C_enuRepeatedStartCondition(void);

ES_t I2C_enuWriteData(uint8_t Copy_u8data);

ES_t I2C_enuReadData(uint8_t*Copy_u8data);

ES_t I2C_enuWriteSlaveAddress(uint8_t Copy_u8SlaveAddress , uint8_t Copy_u8operation);

ES_t I2C_enuCheckMyAddress(void);



#endif /* I2C_INIT_H_ */