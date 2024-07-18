/*
 * LED.h
 *
 * Created: 15/02/2023 02:34:29 م
 *  Author: Alaa Mohamed
 */ 


#ifndef LED_H_
#define LED_H_

void LEDInitialize(unsigned char PortName , unsigned char PinNumber);
void LEDTurnOn(unsigned char PortName , unsigned char PinNumber);
void LEDTurnOff(unsigned char PortName , unsigned char PinNumber);
void LEDToggle(unsigned char PortName , unsigned char PinNumber);

#endif /* LED_H_ */