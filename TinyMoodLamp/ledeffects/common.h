/*
 * common.h
 *
 * Common utilities abstracting real LED and uC hardware implementation from effects
 * 
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include "../ws2812/ws2812.h"

#ifndef NUM_LEDS
#define NUM_LEDS WS_LED_COUNT
#endif

/** Break from effect loop **/
extern volatile uint8_t break_loop;

/**
 * Show strip memory contents
 */
void show_strip();
/**
 * Set pixel to RGB values using gamma tables
 */
void set_pixel(uint8_t pixel, uint8_t red, uint8_t green, uint8_t blue);
/**
 * Set all pixels to RGB using gamma tables and do showStrip()
 */
void set_all(uint8_t red, uint8_t green, uint8_t blue);

/**
 * Calculates random number in range [min, max)
 */
uint16_t randint(uint16_t min, uint16_t max);
/**
 * Performs delay in ms abstracting hardware macros
 */
void delay(uint8_t ms);

#endif /* COMMON_H_ */