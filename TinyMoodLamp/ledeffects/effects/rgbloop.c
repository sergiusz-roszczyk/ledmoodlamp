/*
 * rgbloop.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include "rgbloop.h"
#include "../common.h"

void rgb_loop(uint8_t speed_delay){
	for(uint8_t j = 0; j < 3; j++ ) {
		// Fade IN
		for(int16_t k = 0; k < 256; k++) {
			switch(j) {
				case 0: set_all(k,0,0); break;
				case 1: set_all(0,k,0); break;
				case 2: set_all(0,0,k); break;
			}
			show_strip();
			delay(speed_delay);
			if (break_loop == 1) return;
		}
		// Fade OUT
		for(int16_t k = 255; k >= 0; k--) {
			switch(j) {
				case 0: set_all(k,0,0); break;
				case 1: set_all(0,k,0); break;
				case 2: set_all(0,0,k); break;
			}
			show_strip();
			delay(speed_delay);
			if (break_loop == 1) return;
		}
	}
}

