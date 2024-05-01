// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      blitter.h
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      24th March 2024
//      Reviewed :  No
//      Purpose :   Blitter header
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _BLITTER_H
#define _BLITTER_H

struct BlitterArea {
	uint16_t 	address;
	uint8_t 	page,_filler;
	uint32_t  	stepSize;
	uint32_t  	stepOffset;
	uint32_t  	stepCount;
};

uint8_t BLTSimpleCopy(uint8_t pageFrom,uint16_t addressFrom, uint8_t pageTo, uint16_t addressTo, uint16_t transferSize);
uint8_t BLTComplexCopy(uint8_t action,uint16_t aSource,uint16_t aTarget);
#endif

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************
