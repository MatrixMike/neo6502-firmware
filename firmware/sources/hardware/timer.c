// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      timer.c
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      21st November 2023
//      Reviewed :  No
//      Purpose :   System 100Hz Timer
//
// ***************************************************************************************
// ***************************************************************************************

#include "common.h"

// ***************************************************************************************
//
//								Read 100Hz timer
//
// ***************************************************************************************

uint32_t TMRRead(void) {
	uint32_t time32 = (uint32_t)time_us_64() >> 10;								// divide by 1024
	return (time32 * 210) >> 11; 												// Error of about 0.07%
}

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************