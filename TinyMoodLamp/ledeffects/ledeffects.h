/*
 * ledeffects.h
 *
 * Created: 18.11.2018 14:46:24
 *  Author: Sergio
 */ 


#ifndef LEDEFFECTS_H_
#define LEDEFFECTS_H_

#include <stdint.h>
#include "../ws2812/ws2812.h"
#include "common.h"

#define EFFECT_CNT 8
#define MAX_COLORS 28

void load_color(uint8_t color);
void set_all_to_color();
void play_effect(uint8_t effect);

static const uint8_t colors[MAX_COLORS * 3];

#endif /* LEDEFFECTS_H_ */