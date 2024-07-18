/*
 * SPI.c
 *
 * Created: 11/08/2023 12:13:35 ص
 *  Author: Alaa Mohamed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "MACROS.h"
#include "DIO_Driver.h"
#include "SPI.h"

void SPI_MasterInitialize()
{
	/*Set MOSI, SS, and SCK pins as output*/
	DIO_setPinDirection(SPI_PORT,MOSI,OUTPUT);
	DIO_setPinDirection(SPI_PORT,SS,OUTPUT);
	DIO_setPinDirection(SPI_PORT,SCK,OUTPUT);
	/*Enable Master Mode*/
	SET_BIT(MySPCR,MyMSTR);
	/*Choosing Clock Prescalar = 16*/
	SET_BIT(MySPCR,MySPR0);
	/*Enable SPI*/
	SET_BIT(MySPCR,MySPE);
	/*Write Logic High to SS pin*/ 
	DIO_writePin(SPI_PORT,SS,1);
}
void SPI_SlaveInitialize()
{
	/*Enable SPI*/
	SET_BIT(MySPCR,MySPE);
	/*set MISO pin as output*/
	DIO_setPinDirection(SPI_PORT,MISO,OUTPUT);
}
unsigned char SPI_MasterSendCharacter(unsigned char data)
{
	/*Clear SS pin to send data*/
	DIO_writePin(SPI_PORT,SS,0);
	/*Load data in SPDR register*/
	MySPDR = data;
	while (READ_BIT(MySPSR,MySPIF)==0);
	/*Read SPDR to clear SPIF flag*/
	return MySPDR;
}
unsigned char SPI_SlaveReceiveData(unsigned char data)
{
	/*Load data in SPDR register*/
	MySPDR = data;
	while (READ_BIT(MySPSR,MySPIF)==0);
	/*Read received data and clear SPIF flag*/
	return MySPDR;
}
void SPI_MasterSendString(unsigned char* data)
{
	while ((*data) != 0)
	{
		SPI_MasterSendCharacter(*data);
		_delay_ms(300);
		data++;
	}
}