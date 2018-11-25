/*
 * ws2812.h
 *
 * Created: 2017-10-08 23:16:02
 */ 


#ifndef WS2812_H_
#define WS2812_H_

#include <util/delay.h>

#define WS_GRB
#define WS_LED_COUNT 24
#define WS_BUFFER_LENGTH WS_LED_COUNT * 3
#define WS_DDR DDRB
#define WS_PORT PORTB
#define WS_PIN PINB0
#define WS_HI WS_PORT |= (1 << WS_PIN);
#define WS_LO WS_PORT &= ~(1 << WS_PIN);
#define WS_1 WS_HI WS_HI WS_HI WS_LO
#define WS_0 WS_HI WS_LO WS_LO WS_LO
#define WS_RESET WS_PORT &= ~(1 << WS_PIN); _delay_us(60);

extern uint8_t ws_buffer[WS_LED_COUNT * 3];

void setup_ws_port(void);
void send_ws_buffer(void);
void clear_ws_buffer(void);

#endif /* WS2812_H_ */