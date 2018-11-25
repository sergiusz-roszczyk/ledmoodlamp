/*
 * sparkle.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include "../common.h"

void sparkle(uint8_t   red, uint8_t   green, uint8_t   blue, uint8_t speed_delay) {
	uint8_t pixel = randint(0, NUM_LEDS);
	set_pixel(pixel, red, green, blue);
	show_strip();
	delay(speed_delay);
	set_pixel(pixel, 0, 0, 0);
}