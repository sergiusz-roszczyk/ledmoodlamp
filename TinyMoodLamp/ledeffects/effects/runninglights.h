/*
 * runninglights.h
 *
 * Original source code: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 *
 * Some tweaks applied to fit into ATtiny85 platform and to keep C naming consistent.
 * For licensing and reusing constraints please refer to original article mentioned above.
 */ 


#ifndef RUNNINGLIGHTS_H_
#define RUNNINGLIGHTS_H_

#include <stdint.h>

void running_lights(uint8_t red, uint8_t green, uint8_t blue, uint8_t wave_delay);

#endif /* RUNNINGLIGHTS_H_ */