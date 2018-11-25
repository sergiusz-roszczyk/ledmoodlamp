/*
 * fire.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include <math.h>
#include "fire.h"
#include "../common.h"

static void set_pixel_heat_color (uint8_t pixel, uint8_t temperature) {
	// Scale 'heat' down from 0-255 to 0-191
	uint8_t t192 = round((temperature/255.0)*191);
	
	// calculate ramp up from
	uint8_t heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252
	
	// figure out which third of the spectrum we're in:
	if( t192 > 0x80) {                     // hottest
		set_pixel(pixel, 255, 255, heatramp);
	} else if( t192 > 0x40 ) {             // middle
		set_pixel(pixel, 255, heatramp, 0);
	} else {                               // coolest
		set_pixel(pixel, heatramp, 0, 0);
	}
}

void fire(uint16_t cooling, uint16_t sparking, uint16_t speed_delay) {
	static uint8_t heat[NUM_LEDS];
	uint16_t cooldown;
	
	// Step 1.  Cool down every cell a little
	for( uint8_t i = 0; i < NUM_LEDS; i++) {
		cooldown = randint(0, ((cooling * 10) / NUM_LEDS) + 2);
		
		if(cooldown > heat[i]) {
			heat[i] = 0;
		} else {
			heat[i] = heat[i] - cooldown;
		}
	}
	
	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for( uint8_t k = NUM_LEDS - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}
	
	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if( randint(0, 255) < sparking ) {
		uint16_t y = randint(0, 7);
		heat[y] = heat[y] + randint(160,255);
		//heat[y] = random(160,255);
	}

	// Step 4.  Convert heat to LED colors
	for( uint8_t j = 0; j < NUM_LEDS; j++) {
		set_pixel_heat_color(j, heat[j] );
	}

	show_strip();
	delay(speed_delay);
}

