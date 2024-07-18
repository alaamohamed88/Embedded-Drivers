/*
 * BUTTON.c
 *
 * Created: 15/02/2023 07:16:24 م
 *  Author: Alaa Mohamed
 */ 

#include "BUTTON.h"
#include "DIO_Driver.h"

void ButtonInitialize(unsigned char PortName,unsigned char PinNumber)
{
	DIO_setPinDirection(PortName,PinNumber,INPUT); //set pin as input pin
}

unsigned char ButtonRead(unsigned char PortName,unsigned char PinNumber)
{
	unsigned char ReadValue = 0;
	ReadValue = DIO_readPin(PortName,PinNumber);
	return ReadValue;
}

void ButtonEnablePullup(unsigned char PortName,unsigned char PinNumber)
{
	DIO_setInternalPullup(PortName,PinNumber,1);
}