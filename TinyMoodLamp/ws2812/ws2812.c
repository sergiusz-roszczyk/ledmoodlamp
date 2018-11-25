/*
* ws2812.c
*
* Created: 2017-10-08 23:13:45
*/

#include <avr/io.h>
#include <util/atomic.h>
#include "ws2812.h"

uint8_t ws_buffer[WS_BUFFER_LENGTH];

void setup_ws_port(void) {
	WS_DDR |= (1 << WS_PIN);
	clear_ws_buffer();
	send_ws_buffer();
}

void send_ws_byte(uint8_t b) {
	for (uint8_t bit = 0; bit < 8; bit++) {
		if (b & 0b10000000) { WS_1 } else { WS_0 }
		b = b << 1;
	}
}

void send_ws_buffer(void) {
	for (uint16_t i = 0; i < WS_BUFFER_LENGTH; ++i) {
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
			send_ws_byte(ws_buffer[i]);
		}
	}
	WS_RESET
}

void clear_ws_buffer(void) {
	for (uint16_t i = 0; i < WS_BUFFER_LENGTH; ++i) {
		ws_buffer[i] = 0;
	}
}

