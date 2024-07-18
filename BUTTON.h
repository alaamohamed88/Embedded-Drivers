/*
 * BUTTON.h
 *
 * Created: 15/02/2023 07:17:03 م
 *  Author: Alaa Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void ButtonInitialize(unsigned char PortName,unsigned char PinNumber);
unsigned char ButtonRead(unsigned char PortName,unsigned char PinNumber);
void ButtonEnablePullup(unsigned char PortName,unsigned char PinNumber);

#endif /* BUTTON_H_ */