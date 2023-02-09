/*
 * Seven_seg_priv.c
 *
 * Created: 30/01/2023 11:19:04 م
 *  Author: Menna Eid
 */
#include "../../MCAL/DIO/DI0_interface.h"
#include "Seven_seg_interface.h"
#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"
ES_t Seven_Segment_enInit(void)
{
	ES_t LocalErrorState;
	uint8_t Local_u8check =0;
    if(DIO_SetPinDirection(SEG_APORT,SEG_APIN,OUT)==1)
	{
		Local_u8check++;
	}
   if(DIO_SetPinDirection(SEG_BPORT,SEG_BPIN,OUT)==1)
   {
	   Local_u8check++;
   }
   if(DIO_SetPinDirection(SEG_CPORT,SEG_CPIN,OUT)==1)
   {
	   Local_u8check++;
   }
   if(DIO_SetPinDirection(SEG_DPORT,SEG_DPIN,OUT)==1)
   {
	   Local_u8check++;
   }
  if(DIO_SetPinDirection(SEG_EPORT,SEG_EPIN,OUT)==1)
  {
	  Local_u8check++;
  }
  if(DIO_SetPinDirection(SEG_FPORT,SEG_FPIN,OUT)==1)
  {
	  Local_u8check++;
  }
  if(DIO_SetPinDirection(SEG_GPORT,SEG_GPIN,OUT)==1)
  {
	  Local_u8check++;
  }
#if SEG_COMMON <= PIN7 && SEG_CMN_PORT >='A' && SEG_CMN_PORT <='D'
      DIO_SetPinDirection(SEG_CMN_PORT,SEG_COMMON,OUT);
#endif

#if SEG_DOT <= PIN7 && SEG_DOT_PORT >='A' && SEG_DOT_PORT <='D'
      DIO_SetPinDirection(SEG_DOT_PORT,SEG_DOT,OUT);
#endif
 if(Local_u8check==7)
 {
	 LocalErrorState = ES_OK;
 }
 else
 {
	 LocalErrorState = ES_NOK;
 }
 
 return LocalErrorState;
}	
ES_t Seven_Segment_enDisplayNum(uint8_t num)
{
	ES_t LocalErrorState;
	uint8_t localu8_check=0;
	#if SEG_TYPE == COMMON_CATHODE
	      if(DIO_SetPinValue(SEG_APORT, SEG_APIN, ((SEG_NumDisplay[num]>>0)&1) )==ES_OK)
		  {
		        localu8_check++;
		  } 
		 if(DIO_SetPinValue(SEG_BPORT, SEG_BPIN, ((SEG_NumDisplay[num]>>1)&1) )==ES_OK)
		 {
				localu8_check++;
		 }
		 if(DIO_SetPinValue(SEG_CPORT, SEG_CPIN, ((SEG_NumDisplay[num]>>2)&1) )==ES_OK)
		 {
				localu8_check++;
		 }
		 if(DIO_SetPinValue(SEG_DPORT, SEG_DPIN, ((SEG_NumDisplay[num]>>3)&1) )==ES_OK)
		 {
				localu8_check++;
		 }
		 if(DIO_SetPinValue(SEG_EPORT, SEG_EPIN, ((SEG_NumDisplay[num]>>4)&1) )==ES_OK)
		 {
			    localu8_check++;
		 }
		 if(DIO_SetPinValue(SEG_FPORT, SEG_FPIN, ((SEG_NumDisplay[num]>>5)&1) )==ES_OK)
		 {
				localu8_check++;
		 }
		if(DIO_SetPinValue(SEG_GPORT, SEG_GPIN, ((SEG_NumDisplay[num]>>6)&1) )==ES_OK)
		{
				localu8_check++;
		}
		
  #elif SEG_TYPE == COMMON_ANODE
            if(DIO_SetPinValue(SEG_APORT, SEG_APIN, !((SEG_NumDisplay[num]>>0)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_BPORT, SEG_BPIN, !((SEG_NumDisplay[num]>>1)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_CPORT, SEG_CPIN, !((SEG_NumDisplay[num]>>2)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_DPORT, SEG_DPIN, !((SEG_NumDisplay[num]>>3)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_EPORT, SEG_EPIN, !((SEG_NumDisplay[num]>>4)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_FPORT, SEG_FPIN, !((SEG_NumDisplay[num]>>5)&1) )==ES_OK)
            {
	            localu8_check++;
            }
            if(DIO_SetPinValue(SEG_GPORT, SEG_GPIN, !((SEG_NumDisplay[num]>>6)&1) )==ES_OK)
            {
	            localu8_check++;
            }
 #else
 #error "SEG type has a wrong selection"
 #endif
  if(localu8_check==7)
  {
	  LocalErrorState = ES_OK;
  }
  else
  {
	  LocalErrorState = ES_NOK;
  }
  return LocalErrorState;
}
ES_t Seven_Segment_enTurnOf()
{
	ES_t LocalenErrorstate;
	uint8_t Local_u8check=0;
	#if SEG_TYPE== COMMON_CATHODE
		if(DIO_SetPinDirection(SEG_APORT,SEG_APIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_BPORT,SEG_BPIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_CPORT,SEG_CPIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_DPORT,SEG_DPIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_EPORT,SEG_EPIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_FPORT,SEG_FPIN,LOW)==1)
		{
			Local_u8check++;
		}
		if(DIO_SetPinDirection(SEG_GPORT,SEG_GPIN,LOW)==1)
		{
			Local_u8check++;
		}
	#elif SEG_TYPE== COMMON_ANODE
		  if(DIO_SetPinDirection(SEG_APORT,SEG_APIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_BPORT,SEG_BPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_CPORT,SEG_CPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_DPORT,SEG_DPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_EPORT,SEG_EPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_FPORT,SEG_FPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
		  if(DIO_SetPinDirection(SEG_GPORT,SEG_GPIN,HIGH)==1)
		  {
			  Local_u8check++;
		  }
    #else
    #error "SEG type has a wrong selection"
	#endif
	if(Local_u8check==7)
	{
		LocalenErrorstate=ES_OK;
	}
	else
	{
		LocalenErrorstate=ES_NOK;
	}
	
	
	return LocalenErrorstate;
}
ES_t Seven_Segment_enDisableCommon(void)
{
	ES_t LocalenErrorstate;
	#if SEG_COMMON <= PIN7 && SEG_CMN_PORT>='A' && SEG_CMN_PORT<='D'
		#if SEG_TYPE == COMMON_CATHODE
			DIO_SetPinValue(SEG_CMN_PORT,SEG_COMMON,HIGH);
			LocalenErrorstate=ES_OK;
		#elif SEG_TYPE==COMMON_ANODE
			  DIO_SetPinValue(SEG_CMN_PORT,SEG_COMMON,LOW);
			LocalenErrorstate=ES_OK;
		#endif
	#else
		LocalenErrorstate=ES_NOK;
	#endif
	return LocalenErrorstate;
}
ES_t Seven_Segment_enEnableCommon(void)
{
	ES_t LocalenErrorstate;
	#if SEG_COMMON <= PIN7 && SEG_CMN_PORT>='A' && SEG_CMN_PORT<='D'
		#if SEG_TYPE == COMMON_CATHODE
			DIO_SetPinValue(SEG_CMN_PORT,SEG_COMMON,LOW);
			LocalenErrorstate=ES_OK;
		#elif SEG_TYPE==COMMON_ANODE
			 DIO_SetPinValue(SEG_CMN_PORT,SEG_COMMON,HIGH);
			 LocalenErrorstate=ES_OK;
		#endif
	#else
		LocalenErrorstate=ES_NOK;
	#endif
	return LocalenErrorstate;
}
ES_t Seven_Segment_enDisableDot(void)
{
	ES_t LocalenErrorstate;
	#if SEG_DOT <= PIN7 && SEG_DOT_PORT>='A' && SEG_CMN_PORT<='D'
		#if SEG_TYPE == COMMON_CATHODE
			DIO_SetPinValue(SEG_DOT_PORT,SEG_DOT,LOW);
			LocalenErrorstate=ES_OK;
		#elif SEG_TYPE==COMMON_ANODE
			 DIO_SetPinValue(SEG_DOT_PORT,SEG_DOT,HIGH);
			 LocalenErrorstate=ES_OK;
		#endif
	#else
		LocalenErrorstate=ES_NOK;
	#endif
	return LocalenErrorstate;	
}
ES_t Seven_Segment_enEnableDot(void)
{
	ES_t LocalenErrorstate;
	#if SEG_DOT <= PIN7 && SEG_DOT_PORT>='A' && SEG_CMN_PORT<='D'
		#if SEG_TYPE == COMMON_CATHODE
			DIO_SetPinValue(SEG_DOT_PORT,SEG_DOT,HIGH);
			LocalenErrorstate=ES_OK;
		#elif SEG_TYPE==COMMON_ANODE
			  DIO_SetPinValue(SEG_DOT_PORT,SEG_DOT,LOW);
			LocalenErrorstate=ES_OK;
		#endif
	#else
		LocalenErrorstate=ES_NOK;
	#endif
	return LocalenErrorstate;
}
