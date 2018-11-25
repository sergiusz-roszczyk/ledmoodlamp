/*
 * newkitt.c
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 

#include "../common.h"

static void center_to_outside(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay) {
	for(int16_t i = ((NUM_LEDS - eye_size)/2); i>=0; i--) {
		set_all(0,0,0);
		
		set_pixel(i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(i+j, red, green, blue);
		}
		set_pixel(i+eye_size+1, red/10, green/10, blue/10);
		
		set_pixel(NUM_LEDS-i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(NUM_LEDS-i-j, red, green, blue);
		}
		set_pixel(NUM_LEDS-i-eye_size-1, red/10, green/10, blue/10);
		
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
	delay(return_delay);
}

static void outside_to_center(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay) {
	for(uint8_t i = 0; i <= ((NUM_LEDS-eye_size)/2); i++) {
		set_all(0,0,0);
		
		set_pixel(i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(i+j, red, green, blue);
		}
		set_pixel(i+eye_size+1, red/10, green/10, blue/10);
		
		set_pixel(NUM_LEDS-i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(NUM_LEDS-i-j, red, green, blue);
		}
		set_pixel(NUM_LEDS-i-eye_size-1, red/10, green/10, blue/10);
		
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
	delay(return_delay);
}

static void left_to_right(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay) {
	for(uint8_t i = 0; i < NUM_LEDS-eye_size-2; i++) {
		set_all(0,0,0);
		set_pixel(i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(i+j, red, green, blue);
		}
		set_pixel(i+eye_size+1, red/10, green/10, blue/10);
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
	delay(return_delay);
}

static void right_to_left(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay) {
	for(int16_t i = NUM_LEDS-eye_size-2; i > 0; i--) {
		set_all(0,0,0);
		set_pixel(i, red/10, green/10, blue/10);
		for(uint8_t j = 1; j <= eye_size; j++) {
			set_pixel(i+j, red, green, blue);
		}
		set_pixel(i+eye_size+1, red/10, green/10, blue/10);
		show_strip();
		delay(speed_delay);
		if (break_loop == 1) return;
	}
	delay(return_delay);
}

void new_kitt(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay){
	right_to_left(red, green, blue, eye_size, speed_delay, return_delay);
	left_to_right(red, green, blue, eye_size, speed_delay, return_delay);
	outside_to_center(red, green, blue, eye_size, speed_delay, return_delay);
	center_to_outside(red, green, blue, eye_size, speed_delay, return_delay);
	left_to_right(red, green, blue, eye_size, speed_delay, return_delay);
	right_to_left(red, green, blue, eye_size, speed_delay, return_delay);
	outside_to_center(red, green, blue, eye_size, speed_delay, return_delay);
	center_to_outside(red, green, blue, eye_size, speed_delay, return_delay);
}
