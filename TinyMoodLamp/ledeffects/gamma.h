/*
 * gamma.h
 *
 * 8-bit color gamma tables for LED calibration
 */ 


#ifndef GAMMA_H_
#define GAMMA_H_

#include <avr/io.h>

extern const uint8_t gammaR[256];
extern const uint8_t gammaG[256];
extern const uint8_t gammaB[256];

#endif /* GAMMA_H_ */