/*
 * Seven_seg_interface.h
 *
 * Created: 30/01/2023 11:18:24 م
 *  Author: Pc
 */ 


#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_
ES_t Seven_Segment_enInit(void);
ES_t Seven_Segment_enDisplayNum(uint8_t num);
ES_t Seven_Segment_enTurnOf();
ES_t Seven_Segment_enDisableCommon(void);
ES_t Seven_Segment_enEnableCommon(void);
ES_t Seven_Segment_enDisableDot(void);
ES_t Seven_Segment_enEnableDot(void);



#endif /* SEVEN_SEG_INTERFACE_H_ */