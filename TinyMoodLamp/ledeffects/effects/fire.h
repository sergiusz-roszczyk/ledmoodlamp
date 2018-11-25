/*
 * fire.h
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 


#ifndef FIRE_H_
#define FIRE_H_

#include <stdint.h>

void fire(uint16_t cooling, uint16_t sparking, uint16_t speed_delay);

#endif /* FIRE_H_ */