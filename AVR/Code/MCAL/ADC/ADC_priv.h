/*
 * ADC_priv.h
 *
 * Created: 11/03/2023 06:12:07 
 *  Author: Menna Eid
 */ 


#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define Right_Adjustment 0
#define Left_Adjustment  1
#define Prescaler		 8


typedef enum
{
	AVCC=0,
	Internal_VREF,
	AREF
	
}ADC_enTypesVref;

typedef enum
{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	
	}ADC_enCHANNELS;
typedef enum
{
	FREE_RUNNING=0,
	EX_IN
	//Analog_Comparator
	//Timer_Counter0_Compare_Match,
	//Timer_Counter0_Overflow,
	//Timer_Counter1_Capture_Event
	
	}ADC_enTriggeringTypes;	
// define bits in ADCSRA Register
#define  ADEN	7	   // ADC Enable
#define  ADSC	6    // start conversion
#define	 ADAIE	5   // adc outo triggering
#define	 ADIF   4  // adc interrupt flag
#define  ADIE   3 //
#define  ADPS2  2
#define  ADPS1  1
#define  ADPS0  0
// define SFIOR Register
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5
#endif /* ADC_PRIV_H_ */