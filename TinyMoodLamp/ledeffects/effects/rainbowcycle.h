/*
 * rainbowcycle.h
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 


#ifndef RAINBOWCYCLE_H_
#define RAINBOWCYCLE_H_

#include <stdint.h>

void rainbow_cycle(uint8_t speed_delay);

#endif /* RAINBOWCYCLE_H_ */