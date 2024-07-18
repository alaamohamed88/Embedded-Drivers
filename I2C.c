/*
 * I2C.c
 *
 * Created: 28/07/2023 04:58:55 م
 *  Author: Alaa Mohamed
 */ 

#include "I2C.h"
#include "MACROS.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#define TWPS_PRESCALAR 1

void I2C_MasterInitialize(unsigned long clock)
{
	/*Configuring the clock*/
	MyTWBR = (unsigned char)(((F_CPU/clock)-16)/(2*TWPS_PRESCALAR));
	if(TWPS_PRESCALAR == 1)
	{
		MyTWSR = 0;
	}
	else if(TWPS_PRESCALAR == 4)
	{
		MyTWSR = 1;
	}
	else if(TWPS_PRESCALAR == 16)
	{
		MyTWSR = 2;
	}
	else if(TWPS_PRESCALAR == 64)
	{
		MyTWSR = 3;
	}
}

void I2C_SetAddress(unsigned char address)
{
	MyTWAR = address;
}

void I2C_SendStartCondition()
{
	MyTWCR = (1<<MyTWINT)|(1<<MyTWSTA)|(1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x08);
}

void I2C_SendRepeatedStartCondition()
{
	MyTWCR = (1<<MyTWINT)|(1<<MyTWSTA)|(1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x10);
}

void I2C_SendStopCondition()
{
	MyTWCR = (1<<MyTWINT)|(1<<MyTWSTO)|(1<<MyTWEN);
}

void I2C_SendAddressandWrite(unsigned char slaveaddress)
{
	MyTWDR = slaveaddress;
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x18);
}

void I2C_SendAddressandRead(unsigned char slaveaddress)
{
	MyTWDR = slaveaddress;
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x40);
}

void I2C_MasterTransmitData(unsigned char data)
{
	MyTWDR = data;
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x28);
}

unsigned char I2C_MasterReceiveWithACK()
{
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN) | (1<<MyTWEA);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x50);
	return MyTWDR;
}

unsigned char I2C_MasterReceiveWithNACK()
{
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x58);
	return MyTWDR;
}

void I2C_SlaveTransmitData(unsigned char data)
{
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN) | (1<<MyTWEA);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8) != 0xA8);
	MyTWDR = data;
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0xB8);
}

unsigned char I2C_SlaveReceive()
{
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN) | (1<<MyTWEA);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8) != 0x60);
	MyTWCR = (1<<MyTWINT) | (1<<MyTWEN) | (1<<MyTWEA);
	while(READ_BIT(MyTWCR,MyTWINT)==0);
	while((MyTWSR & 0xF8)!= 0x80);
	return MyTWDR;
}
