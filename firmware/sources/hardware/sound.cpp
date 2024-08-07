// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      sound.cpp
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      7th August 2024
//      Reviewed :  No
//      Purpose :   PWM Audio support for Neo6502
//
// ***************************************************************************************
// ***************************************************************************************

#include "common.h"
#include "stdlib.h"
#include "hardware/pwm.h"
#include "dvi.h"
#include "system/dvi_video.h"

#define AUDIO_PIN 	(20) 					// Beeper pin.
#define SAMPLE_DIVIDER (32)

static int adder = 0;
static int wrapper = 0;
static int state = 0;

static int sampleFrequency = -1;

int SNDGetSampleFrequency(void) {
    if (sampleFrequency < 0) {
        sampleFrequency = DVI_TIMING.bit_clk_khz * 1024 / SAMPLE_DIVIDER / 255;
    }
    return sampleFrequency;
}

void pwm_interrupt_handler() {
    pwm_clear_irq(pwm_gpio_to_slice_num(AUDIO_PIN));    

    if (adder == 0) return;

    if (wrapper++ >= adder) {
        wrapper = 0;
        state = state ^ 0xFF;
        pwm_set_gpio_level(AUDIO_PIN,state);
    }
}

// ***************************************************************************************
//
//				Initialise sound channel, return # of supported channels
//
// ***************************************************************************************

void SNDInitialise(void) {
    gpio_set_function(AUDIO_PIN, GPIO_FUNC_PWM);
    int audio_pin_slice = pwm_gpio_to_slice_num(AUDIO_PIN);
    // Setup PWM interrupt to fire when PWM cycle is complete
    pwm_clear_irq(audio_pin_slice);
    // set the handle function above
    irq_set_exclusive_handler(PWM_IRQ_WRAP, pwm_interrupt_handler); 
    irq_set_enabled(PWM_IRQ_WRAP, true);
    // Setup PWM for audio output
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, SAMPLE_DIVIDER); 
    pwm_config_set_wrap(&config, 255); 
    pwm_init(audio_pin_slice, &config, true);
    //
    pwm_set_gpio_level(AUDIO_PIN, 0);
    pwm_set_irq_enabled(audio_pin_slice, true);
}

// ***************************************************************************************
//
//									Play note on channel
//
// ***************************************************************************************

void SNDUpdateSoundChannel(uint8_t channel,SOUND_CHANNEL *c) {
    if (c->isPlayingNote) {    
        adder = SNDGetSampleFrequency() / c->currentFrequency / 2;
    } else {
        adder = 0;
    }
}

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************
