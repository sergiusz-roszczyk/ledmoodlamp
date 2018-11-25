/*
 * TinyMoodLamp.c
 *
 * Color cycling inspired mood lamp. It uses 24-LED NeoPixel ring mounted into existing LAMP.
 * Utilizing ATtiny85 provides low power, USB powered device, remote controller using SIRC (Sony)
 * TV remote control (Red, Green, Yellow and Blue buttons).
 *
 * Button mapping:
 * RED - ON/Off
 * Green - Effect / Solid color
 * Yellow - Next color
 * Blue - Next effect
 *
 * Effects source code and inspiration: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 * LED Gamma curves calculated using: https://github.com/sergiusz-roszczyk/LedCalculator
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "main.h"
#include "ledeffects/ledeffects.h"
#include "sirc.h"

static volatile uint8_t effect = 0;
static uint8_t lamp_mode = MODE_STATIC;
static uint8_t last_lamp_mode = MODE_STATIC;
static uint8_t color = 0;
static uint8_t mode_applied = 0;

int main(void) {
	color_setup();
	switch_setup();
	sirc_setup();
	sei();
	
	while (1) {
		if (sirc_state == SIRC_PACKET_RECEIVED) {
			switch(sirc_code) {
				case SIRC_BTN_RED: toggle_lamp_onoff(); break;
				case SIRC_BTN_GREEN: toggle_lamp_mode(); break;
				case SIRC_BTN_YELLOW: next_color(); break;
				case SIRC_BTN_BLUE: next_effect(); break;
			}
			_delay_ms(250);
			sirc_state = SIRC_IDLE;
		}
		switch(lamp_mode) {
			case MODE_OFF:
			if (mode_applied == 0) {
				set_all(0, 0, 0);
				mode_applied = 1;
				_delay_ms(200);
			}
			set_sleep_mode(SLEEP_MODE_IDLE);
			sleep_mode();
			break;
			case MODE_STATIC:
			if (mode_applied == 0) {
				load_color(color);
				set_all_to_color();
				mode_applied = 1;
				_delay_ms(200);
			}
			set_sleep_mode(SLEEP_MODE_IDLE);
			sleep_mode();
			break;
			case MODE_EFFECT:
			if (mode_applied == 0) {
				set_all(0, 0, 0);
				load_color(color);
				mode_applied = 1;
				_delay_ms(200);
			}
			play_effect(effect);
			break;
		}
		break_loop = 0;
	}
}

/**
Mode switch button interrupt
*/
ISR(PCINT0_vect) {
	uint8_t btn = PINB & (1 << PINB1);
	if (btn == 0) {
		next_effect();
		_delay_ms(100);
		break_loop = 1;
	}
}

static void color_setup() {
	load_color(0);
	setup_ws_port();
	clear_ws_buffer();
	_delay_ms(100);
	set_all(0xff, 0, 0); _delay_ms(100);
	set_all(0, 0xff, 0); _delay_ms(100);
	set_all(0, 0, 0xff); _delay_ms(100);
}

static void switch_setup() {
	/* Set up mode switch button */
	GIMSK |= (1<<PCIE);
	PCMSK |= (1<<PCINT1);
	PORTB |= (1<<PINB1);
}

static void toggle_lamp_mode() {
	switch (lamp_mode) {
		case MODE_OFF:
		lamp_mode = last_lamp_mode;
		break;
		case MODE_EFFECT:
		lamp_mode = MODE_STATIC;
		break;
		default:
		lamp_mode = MODE_EFFECT;
		break;
	}
	mode_applied = 0;
}

static void toggle_lamp_onoff() {
	if (lamp_mode!=MODE_OFF) {
		last_lamp_mode = lamp_mode;
		lamp_mode = MODE_OFF;
		} else {
		lamp_mode = last_lamp_mode;
	}
	mode_applied = 0;
}

static void next_color() {
	color++;
	if (color >= MAX_COLORS) {
		color = 0;
	}
	mode_applied = 0;
}

static void next_effect() {
	effect++;
	if (effect >= EFFECT_CNT) {
		effect = 0;
	}
	mode_applied = 0;
}