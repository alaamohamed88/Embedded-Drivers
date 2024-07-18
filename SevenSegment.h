/*
 * SevenSegment.h
 *
 * Created: 18/02/2023 06:41:47 م
 *  Author: Alaa Mohamed
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#define COMMON_CATHODE
#define SEVEN_SEGMENT_PORT 'D'
void SevenSegmentInitialize();
void SevenSegmentWrite(unsigned char Number);

#endif /* SEVENSEGMENT_H_ */