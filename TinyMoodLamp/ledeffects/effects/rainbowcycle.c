/*
 * rainbowcycle.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include "rainbowcycle.h"
#include "../common.h"

uint8_t * wheel(uint8_t wheel_pos) {
	static uint8_t c[3];
	
	if(wheel_pos < 85) {
		c[0] = wheel_pos * 3;
		c[1] = 255 - wheel_pos * 3;
		c[2] = 0;
		} else if(wheel_pos < 170) {
		wheel_pos -= 85;
		c[0] = 255 - wheel_pos * 3;
		c[1] = 0;
		c[2] = wheel_pos * 3;
		} else {
		wheel_pos -= 170;
		c[0] = 0;
		c[1] = wheel_pos * 3;
		c[2] = 255 - wheel_pos * 3;
	}

	return c;
}

void rainbow_cycle(uint8_t speed_delay) {
	uint8_t *c;
	uint16_t i, j;

	for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
		for(i = 0; i< NUM_LEDS; i++) {
			c = wheel(((i * 256 / NUM_LEDS) + j) & 255);
			set_pixel(i, *c, *(c+1), *(c+2));
		}
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
}
