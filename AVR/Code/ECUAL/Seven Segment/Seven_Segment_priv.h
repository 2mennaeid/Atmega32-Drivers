/*
 * Seven_Segment_priv.h
 *
 * Created: 31/01/2023 02:54:04 م
 *  Author: Pc
 */ 


#ifndef SEVEN_SEGMENT_PRIV_H_
#define SEVEN_SEGMENT_PRIV_H_

#define COMMON_ANODE  11
#define COMMON_CATHODE 13
#define NOT_CONNECTED 19 

uint8_t SEG_NumDisplay []= {  0x3f, 0x06, 0x5B,
	0x4F, 0x66, 0x6D,
	0x7D, 0x07, 0x7F,
0x6F};

#endif /* SEVEN_SEGMENT_PRIV_H_ */