/*
 * USART.h
 *
 * Created: 10/08/2023 03:14:48 م
 *  Author: Alaa Mohamed
 */ 

#ifndef USART_H_
#define USART_H_

#define MyUDR *(volatile unsigned char*) 0x2C
#define MyUBRRL *(volatile unsigned char*) 0x29
#define MyUBRRH *(volatile unsigned char*) 0x40
#define MyUCSRC *(volatile unsigned char*) 0x40
#define MyUCSRA *(volatile unsigned char*) 0x2B
#define MyUCSRB *(volatile unsigned char*) 0x2A

#define MyRXC 7 //USART receive complete flag
#define MyTXC 6 //USART transmit complete flag
#define MyUDRE 5 //USART data register empty flag
#define MyFE 4 //frame error flag
#define MyDOR 3 //Data overrun flag
#define MyPE 2 //parity error flag
#define MyU2X 1 //Double USART transmission speed
#define MyMPCM 0 //Multi-processor communication mode
#define MyRXCIE 7 //Rx complete interrupt enable
#define MyTXCIE 6 //Tx complete interrupt enable
#define MyUDRIE 5 //USART data register empty interrupt enable
#define MyRXEN 4 //receiver enable bit
#define MyTXEN 3 //transmitter enable bit
#define MyUCSZ2 2 //character size 3rd bit
#define MyRXB8 1 //receive 8th data bit 
#define MyTXB8 0 //transmit 8th data bit 
#define MyUMSEL 6 //USART mode select
#define MyUPM1 5 //parity mode 2nd bit
#define MyUPM0 4 //parity mode 1st bit
#define MyUSBS 3 //stop bit select
#define MyUCSZ1 2 //character size 2nd bit
#define MyUCSZ0 1 //character size 2nd bit
#define MyUCPOL 0 //clock polarity bit (synchronous mode only)

void UART_Initialize(unsigned long baud_rate);
void UART_SendCharacter(char data);
char UART_ReceiveData();
void UART_SendString(char* data);

#endif /* USART_H_ */