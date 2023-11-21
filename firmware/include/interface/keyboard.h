// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      keyboard.h
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      21st November 2023
//      Reviewed :  No
//      Purpose :   Keyboard prototypes
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _KEYBOARD_H
#define _KEYBOARD_H

void KBDInitialise(void);
void KBDSync(void);

void KBDCheckTimer(void);
void KBDEvent(uint8_t isDown,uint8_t keyCode,uint8_t modifiers);
uint8_t *KBDGetStateArray(void);
bool KBDIsKeyAvailable(void);
uint8_t KBDGetKey(void);

//
//		Keyboard repeat rates, in 1/100 sec
//
#define KBD_REPEAT_START 	(90)  												// Time for first repeat
#define KBD_REPEAT_AFTER  	(12)  												// Time for subsequent repeats
#endif

