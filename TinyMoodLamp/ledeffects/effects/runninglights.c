/*
 * runninglights.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include <stdlib.h>
#include <math.h>
#include "runninglights.h"
#include "../common.h"

void running_lights(uint8_t red, uint8_t green, uint8_t blue, uint8_t wave_delay) {
	uint16_t position=0;
	
	for(uint16_t j=0; j<NUM_LEDS*2; j++)
	{
		position++; // = 0; //Position + Rate;
		for(uint8_t i=0; i<NUM_LEDS; i++) {
			// sine wave, 3 offset waves make a rainbow!
			//float level = sin(i+Position) * 127 + 128;
			//setPixel(i,level,0,0);
			//float level = sin(i+Position) * 127 + 128;
			set_pixel(i,((sin(i+position) * 127 + 128)/255)*red,
			((sin(i+position) * 127 + 128)/255)*green,
			((sin(i+position) * 127 + 128)/255)*blue);
		}
		
		show_strip();
		delay(wave_delay);
		if (break_loop == 1) return;
	}
}