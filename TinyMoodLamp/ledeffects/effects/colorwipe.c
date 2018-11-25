/*
 * colorwipe.c
 *
 * Color wipe effect.
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 * 
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include "colorwipe.h"
#include "../common.h"

void color_wipe(uint8_t red, uint8_t green, uint8_t blue, uint8_t speed_delay) {
	for(uint8_t i = 0; i < NUM_LEDS; i++) {
		set_pixel(i, red, green, blue);
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
}