/*
 * I2C_Priv.h
 *
 * Created: 7/15/2023 6:46:59 AM
 *  Author: Menna Eid
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define f_CPU  8000000ul
// define bits TWCR
#define TWINT  7
#define TWEA   6  
#define TWSTA  5
#define TWSTO  4
#define TWWC   3
#define TWEN   2
#define TWIE   0

// defines  TWSR bits
#define TWPS0 0
#define TWPS1 1
///////////////////////////////////////////////////////////////////////////////
#define IIC_MASTER   7
#define IIC_SLAVE    8
#define IIC_PRES     1
#define BITRATE(IIC_SPEED)     ((f_CPU-16*IIC_SPEED)/(2*IIC_SPEED*IIC_PRES))

#endif /* I2C_PRIV_H_ */