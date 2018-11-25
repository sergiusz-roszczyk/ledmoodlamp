/*
 * common.c
 *
 * Created: 24.11.2018 13:08:12
 *  Author: Sergio
 */ 

#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdlib.h>
#include "common.h"
#include "../ws2812/ws2812.h"
#include "gamma.h"

volatile uint8_t break_loop = 0;

void delay(uint8_t ms) {
	while (ms > 0) {
		_delay_ms(1);
		ms--;
	}
}

uint16_t randint(uint16_t min, uint16_t max) {
	if (min >= max) {
		return min;
	}
	uint16_t diff = max - min;
	uint16_t rnd = random() % diff;
	return rnd + min;
}

void show_strip() {
	send_ws_buffer();
}

void set_pixel(uint8_t pixel, uint8_t red, uint8_t green, uint8_t blue) {
	//GRB
	if (pixel < WS_LED_COUNT) {
		ws_buffer[pixel * 3 + 0] = pgm_read_byte(&gammaG[green]);
		ws_buffer[pixel * 3 + 1] = pgm_read_byte(&gammaR[red]);
		ws_buffer[pixel * 3 + 2] = pgm_read_byte(&gammaB[blue]);
	}
}

void set_all(uint8_t red, uint8_t green, uint8_t blue) {
	for (uint8_t pixel = 0; pixel < WS_LED_COUNT; pixel++) {
		set_pixel(pixel, red, green, blue);
	}
	show_strip();
}
