/*
 * rgbloop.h
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 


#ifndef RGBLOOP_H_
#define RGBLOOP_H_

#include <stdint.h>

void rgb_loop(uint8_t speed_delay);

#endif /* RGBLOOP_H_ */