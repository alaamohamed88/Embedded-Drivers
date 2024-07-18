/*
 * USART.c
 *
 * Created: 10/08/2023 03:14:39 م
 *  Author: Alaa Mohamed
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include "USART.h"
#include "MACROS.h"

void UART_Initialize(unsigned long baud_rate)
{
	/*Configure baud rate*/
	unsigned short UBRR;
	UBRR = (F_CPU/(16*baud_rate))-1;
	MyUBRRH = (unsigned char)(UBRR>>8);
	MyUBRRL = (unsigned char) UBRR;
	/*Enable USART Tx and Rx*/
	SET_BIT(MyUCSRB,MyTXEN);
	SET_BIT(MyUCSRB,MyRXEN);
	/*choosing 8 data bits, 1 stop bit and no parity*/
	MyUCSRC = 0x86;
}
void UART_SendCharacter(char data)
{
	while (READ_BIT(MyUCSRA,MyUDRE)==0);
	MyUDR = data;
}
char UART_ReceiveData()
{
	while (READ_BIT(MyUCSRA,MyRXC)==0);
	return MyUDR;
}
void UART_SendString(char* data)
{
	while (*data != 0)
	{
		UART_SendCharacter(*data);
		data++;
		_delay_ms(100);
	}
}