/*
* ledeffects.c
*
* Created: 18.11.2018 14:46:37
*  Author: Sergio
*/

#include <avr/pgmspace.h>
#include "ledeffects.h"
#include "effects/rgbloop.h"
#include "effects/cylonbounce.h"
#include "effects/newkitt.h"
#include "effects/runninglights.h"
#include "effects/colorwipe.h"
#include "effects/rainbowcycle.h"
#include "effects/sparkle.h"
#include "effects/fire.h"

static uint8_t color_r;
static uint8_t color_g;
static uint8_t color_b;

void load_color(uint8_t color) {
	color_r = pgm_read_byte(&colors[color * 3 + 0]);
	color_g = pgm_read_byte(&colors[color * 3 + 1]);
	color_b = pgm_read_byte(&colors[color * 3 + 2]);
}

void set_all_to_color() {
	set_all(color_r, color_g, color_b);
}

void play_effect(uint8_t effect) {
	switch(effect) {
		case 0: color_wipe(color_r, color_g, color_b, 110); color_wipe(color_g, color_b, color_r, 110); color_wipe(color_b, color_r, color_g, 110); break;
		case 1: rainbow_cycle(25); break;
		case 2: sparkle(color_r, color_g, color_b, 15); break;
		case 3: fire(50,90,40); break;
		case 4: cylon_bounce(color_r, color_g, color_b, 4, 10, 50); break;
		case 5: new_kitt(color_r, color_g, color_b, 2, 10, 80); break;
		case 6: running_lights(color_r, color_g, color_b, 40); break;
		case 7: rgb_loop(10); break;
	}
}

static const uint8_t colors[MAX_COLORS * 3] PROGMEM = {
	0x30, 0x20, 0x01,
	0x7F, 0x5F, 0x3F,
	
	0x7F, 0x7F, 0x7F,
	0x7F, 0x00, 0x00,
	0x7F, 0x3F, 0x00,
	0x7F, 0x7F, 0x00,
	0x3F, 0x7F, 0x00,
	0x00, 0x7F, 0x00,
	0x00, 0x7F, 0x3F,
	0x00, 0x7F, 0x7F,
	0x00, 0x7F, 0x7F,
	0x00, 0x00, 0x7F,
	0x3F, 0x00, 0x7F,
	0x7F, 0x00, 0x7F,
	0x7F, 0x00, 0x3F,
	
	0xFF, 0xFF, 0xFF,
	0xFF, 0x00, 0x00,
	0xFF, 0x7F, 0x00,
	0xFF, 0xFF, 0x00,
	0x7F, 0xFF, 0x00,
	0x00, 0xFF, 0x00,
	0x00, 0xFF, 0x7F,
	0x00, 0xFF, 0xFF,
	0x00, 0x7F, 0xFF,
	0x00, 0x00, 0xFF,
	0x7F, 0x00, 0xFF,
	0xFF, 0x00, 0xFF,
	0xFF, 0x00, 0x7F
};
