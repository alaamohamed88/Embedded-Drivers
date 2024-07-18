/*
 * BCDSevenSegment.h
 *
 * Created: 20/02/2023 12:24:57 ص
 *  Author: Alaa Mohamed
 */ 


#ifndef BCDSEVENSEGMENT_H_
#define BCDSEVENSEGMENT_H_

#define LOWNIBBLEPORT
#define BCD_PORT 'D'
void BCDSevenSegInitialize();
void BCDSevenSegWrite(unsigned char Number);

#endif /* BCDSEVENSEGMENT_H_ */