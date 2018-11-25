/*
 * sirc.h
 *
 * SIRC IR protocol decoder.
 * Resources used: Timer0, Interrupt 0 (PB2)
 * Hardware: ATtiny85 @ 8MHz, TSOP38438 at 5V
 */ 


#ifndef SIRC_H_
#define SIRC_H_

#define SIRC_IDLE 0
#define SIRC_START_DETECT 1
#define SIRC_PACKET_RECEIVING 2
#define SIRC_PACKET_RECEIVED 4

#define SIRC_BTN_RED 0x52e9
#define SIRC_BTN_GREEN 0x32e9
#define SIRC_BTN_YELLOW 0x72e9
#define SIRC_BTN_BLUE 0x12e9

extern volatile uint32_t sirc_code;
extern volatile uint8_t sirc_state;

void sirc_setup();

#endif /* SIRC_H_ */