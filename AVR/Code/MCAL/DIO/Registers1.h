/*
 * Registers1.h
 *
 * Created: 30/09/2022 08:30:42 م
 *  Author: Menna eid
 */ 

/*---------------------------
DIO register
-----------------------------*/
#ifndef REGISTERS1_H_
#define REGISTERS1_H_
typedef unsigned char uint8_t;
typedef unsigned long int uint32_t;
// PORTA
#define PORTA *((volatile uint8_t*)0x3B) // 8-bit 
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
// PORT B
#define PORTB *((volatile uint8_t*)0x38) // 8-bit
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
// PORT C 
#define PORTC *((volatile uint8_t*)0x35) // 8-bit
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
// PORT D
#define PORTD *((volatile uint8_t*)0x32) // 8-bit
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

// Timer Register
#define TCCR0 *((volatile uint8_t*)0x53) // 8-bit
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)
#endif /* REGISTERS1_H_ */