/*
 * ADC.c
 *
 * Created: 15/07/2023 06:45:01 م
 *  Author: Alaa Mohamed
 */ 

#include "ADC.h"
#include "MACROS.h"

void ADC_Initialize()
{
	SET_BIT(MyADMUX,MyREFS0); //adjust Vref to be AVCC
	SET_BIT(MyADCSRA,MyADEN); //enable ADC
	//default channel is channel 0
	SET_BIT(MyADCSRA,MyADPS1);
	SET_BIT(MyADCSRA,MyADPS2); // adjusting the clock to be 125KHz
}

unsigned short ADC_read()
{
	unsigned short ADC_Read_Value;
	SET_BIT(MyADCSRA,MyADSC); // start conversion 
	while(READ_BIT(MyADCSRA,MyADSC)==1); //stand still until conversion is complete
	/* 
	//Or
	while(READ_BIT(MyADCSRA,MyADIF)==0); //stand still until conversion is complete
	SET_BIT(MyADCSRA,MyADIF) //clear flag
	*/
	ADC_Read_Value = (MyADCL);
	ADC_Read_Value |= (MyADCH<<8);
	return ADC_Read_Value;
}