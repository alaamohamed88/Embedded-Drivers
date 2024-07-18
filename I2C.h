/*
 * I2C.h
 *
 * Created: 28/07/2023 04:58:25 م
 *  Author: Alaa Mohamed
 */ 


#ifndef I2C_H_
#define I2C_H_

#define MyTWDR *(volatile unsigned char*) 0x23
#define MyTWAR *(volatile unsigned char*) 0x22
#define MyTWSR *(volatile unsigned char*) 0x21
#define MyTWBR *(volatile unsigned char*) 0x20
#define MyTWCR *(volatile unsigned char*) 0x56

#define MyTWINT 7 //TWI Interrupt Flag
#define MyTWEA 6 //TWI Enable Acknowledge Bit
#define MyTWSTA 5 //TWI Start Condition Bit
#define MyTWSTO 4 //TWI Stop Condition Bit
#define MyTWWC 3 //TWI Write Collision Flag
#define MyTWEN 2 //TWI Enable Bit
#define MyTWIE 0 //TWI Interrupt Enable

void I2C_MasterInitialize(unsigned long clock);
void I2C_SetAddress(unsigned char address);
void I2C_SendStartCondition();
void I2C_SendRepeatedStartCondition();
void I2C_SendStopCondition();
void I2C_SendAddressandWrite(unsigned char slaveaddress);
void I2C_SendAddressandRead(unsigned char slaveaddress);
void I2C_MasterTransmitData(unsigned char data);
unsigned char I2C_MasterReceiveWithACK();
unsigned char I2C_MasterReceiveWithNACK();
void I2C_SlaveTransmitData(unsigned char data);
unsigned char I2C_SlaveReceive();

#endif /* I2C_H_ */