/*
 * sirc.c
 *
 * SIRC IR protocol decoder.
 * Resources used: Timer0, Interrupt 0 (PB2)
 * Hardware: ATtiny85 @ 8MHz, TSOP38438 at 5V
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "sirc.h"
#include "ledeffects/common.h"

#define SIRC_START_MIN 80
#define SIRC_START_MAX 105
#define SIRC_ONE_MIN 50
#define SIRC_ONE_MAX 70
#define SIRC_ZERO_MIN 30
#define SIRC_ZERO_MAX 45

volatile uint32_t sirc_code = 0;
volatile uint8_t sirc_state = SIRC_IDLE;
static volatile uint32_t sirc_data = 0;

void sirc_setup() {
	/* Set up SIRC timer */
	TCCR0B |= (1<<CS02); // 1:256
	TIMSK |= (1<<TOIE0); // Timer Overflow Interrupt Enable 0
	
	/* Set up SIRC INT0 Falling Edge detection */
	MCUCR |= (1<<ISC01);
	GIMSK |= (1<<INT0);
}

/**
Falling Edge of IR signal detected
*/
ISR(INT0_vect) {
	uint8_t length = TCNT0;
	TCNT0 = 0;
	switch(sirc_state) {
		case SIRC_IDLE:
			// Begin detecting START signal
			sirc_data = 0;
			sirc_state = SIRC_START_DETECT;
			break;
		case SIRC_START_DETECT:
			// Check if START signal is 2,4ms + 0,6 gap long
			if ( (length > SIRC_START_MIN) && (length < SIRC_START_MAX)) {
				sirc_state = SIRC_PACKET_RECEIVING;
				} else {
				sirc_state = SIRC_IDLE;
			}
			break;
		case SIRC_PACKET_RECEIVING:
			// Check bit length. 1 is 1,2ms + 0,6ms, 0 is 0,6ms + 0,6ms
			if (length < SIRC_ONE_MIN) {
				// 0
				sirc_data = sirc_data << 1;
				} else if (length < SIRC_ONE_MAX) {
				// 1
				sirc_data = sirc_data << 1;
				sirc_data++;
			};
			break;
	}
}

ISR(TIMER0_OVF_vect) {
	switch (sirc_state) {
		case SIRC_START_DETECT:
			sirc_state = SIRC_IDLE;
			break;
		case SIRC_PACKET_RECEIVING:
			sirc_data = sirc_data << 1;
			sirc_data++;
			sirc_state = SIRC_PACKET_RECEIVED;
			sirc_code = sirc_data;
			if ( (sirc_code == SIRC_BTN_RED)
				|| (sirc_code == SIRC_BTN_GREEN)
				|| (sirc_code == SIRC_BTN_YELLOW)
				|| (sirc_code == SIRC_BTN_BLUE) ) {
					break_loop = 1;
			}
			break;
	}
}