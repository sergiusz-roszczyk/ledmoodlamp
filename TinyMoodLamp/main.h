/*
 * main.h
 * Color cycling inspired mood lamp. It uses 24-LED NeoPixel ring mounted into existing LAMP.
 * Utilizing ATtiny85 provides low power, USB powered device, remote controller using SIRC (Sony)
 * TV remote control (Red, Green, Yellow and Blue buttons).
 *
 * Button mapping:
 * RED - ON/Off
 * Green - Effect / Solid color
 * Yellow - Next color
 * Blue - Next effect
 *
 * Effects source code and inspiration: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
 * LED Gamma curves calculated using: https://github.com/sergiusz-roszczyk/LedCalculator
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define MODE_OFF 0
#define MODE_STATIC 1
#define MODE_EFFECT 2

/**
 * Set up LED outputs and buffers
 */
static void color_setup();
/**
 * Set up mechanical effect switch input
 */
static void switch_setup();
/**
 * Toggle lamp mode (effect / static)
 */
static void toggle_lamp_mode();
/**
 * Toggle lamp mode ON and OFF
 */
static void toggle_lamp_onoff();
/**
 * Cycles through colors
 */
static void next_color();
/**
 * Cycles through visual effects
 */
static void next_effect();

#endif /* MAIN_H_ */