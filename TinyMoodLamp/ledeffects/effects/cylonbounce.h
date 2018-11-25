/*
 * cylonbounce.h
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 


#ifndef CYLONBOUNCE_H_
#define CYLONBOUNCE_H_

#include <stdint.h>

void cylon_bounce(uint8_t red, uint8_t green, uint8_t blue, uint8_t eye_size, uint8_t speed_delay, uint8_t return_delay);

#endif /* CYLONBOUNCE_H_ */