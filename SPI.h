/*
 * SPI.h
 *
 * Created: 11/08/2023 12:13:42 ص
 *  Author: Alaa Mohamed
 */ 


#ifndef SPI_H_
#define SPI_H_

#define MySPCR *(volatile unsigned char*) 0x2D
#define MySPSR *(volatile unsigned char*) 0x2E
#define MySPDR *(volatile unsigned char*) 0x2F

#define MySPIE 7 //SPI Interrupt Enable
#define MySPE 6 //SPI Enable
#define MyDORD 5 //Data Order (LSB or MSB first)
#define MyMSTR 4 //Master/Slave select
#define MyCPOL 3 //Clock Polarity
#define MyCPHA 2 //Clock Phase
#define MySPR1 1 //SPI Clock Rate Select 1
#define MySPR0 0 //SPI Clock Rate Select 0

#define MySPIF 7 //SPI Interrupt Flag
#define MyWCOL 6 //Write Collision Flag
#define MySPI2X 0 //Double SPI Speed Bit

#define SPI_PORT 'B'
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_MasterInitialize();
void SPI_SlaveInitialize();
unsigned char SPI_MasterSendCharacter(unsigned char data);
unsigned char SPI_SlaveReceiveData(unsigned char data);
void SPI_MasterSendString(unsigned char* data);

#endif /* SPI_H_ */