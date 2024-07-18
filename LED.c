/*
 * LED.c
 *
 * Created: 15/02/2023 02:34:41 م
 *  Author: Alaa Mohamed
 */ 

#include "LED.h"
#include "DIO_Driver.h"

void LEDInitialize(unsigned char PortName , unsigned char PinNumber)
{
	DIO_setPinDirection(PortName,PinNumber,OUTPUT);
}

void LEDTurnOn(unsigned char PortName , unsigned char PinNumber)
{
	DIO_writePin(PortName,PinNumber,1);
}

void LEDTurnOff(unsigned char PortName , unsigned char PinNumber)
{
	DIO_writePin(PortName,PinNumber,0);
}

void LEDToggle(unsigned char PortName , unsigned char PinNumber)
{
	DIO_TogglePin(PortName,PinNumber);
}
