/*
 * BCDSevenSegment.c
 *
 * Created: 20/02/2023 12:26:44 ص
 *  Author: Alaa Mohamed
 */ 

#include "BCDSevenSegment.h"
#include "DIO_Driver.h"

void BCDSevenSegInitialize()
{
		#if defined LOWNIBBLEPORT
		DIO_setPinDirection(BCD_PORT,0,OUTPUT);
		DIO_setPinDirection(BCD_PORT,1,OUTPUT);
		DIO_setPinDirection(BCD_PORT,2,OUTPUT);
		DIO_setPinDirection(BCD_PORT,3,OUTPUT);
			
		#elif defined HIGHNIBBLEPORT
		DIO_setPinDirection(BCD_PORT,4,OUTPUT);
		DIO_setPinDirection(BCD_PORT,5,OUTPUT);
		DIO_setPinDirection(BCD_PORT,6,OUTPUT);
		DIO_setPinDirection(BCD_PORT,7,OUTPUT);
		#endif	

}

void BCDSevenSegWrite(unsigned char Number)
{
	#if defined LOWNIBBLEPORT
	DIO_writeLowNibble(BCD_PORT,Number);
			
	#elif defined HIGHNIBBLEPORT
	DIO_writeHighNibble(BCD_PORT,Number);
	#endif
}