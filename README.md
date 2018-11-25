# Weekend project: LED Mood Lamp

This is a just for fun project. Remote controlled (SIRC IR protocol) lamp using 24-LED Neopixel Ring, 
ATtiny85 microcontroller and some C code in Atmel Studio 7.0.

# Wiring it up

You need an ATtiny85 uC, set up to use internal RC oscillator set to 8 MHz (CLKDIV8 fuse disabled), A 24-led Neopixel Ring and IR Receiver.

Connect VCC to 5V line, GND to ground.
PB0 - Neopixel Data line
PB1 - Optional switch for changing effects
PB2 - IR receiver signal

# Compiling and programming

To compile this software Atmel Studio 7.0 with avr-gcc is needed.
ATtiny85 can be ISP programmed using STK500 or compatible programmer (I used original STK500). Program uC first 
or make disconnecting IR Receiver possible or it will not program in system with IR line connected.

# Powering up

ATtiny85 consumes at most 30 mA with IR Receiver connected. Calculate your power budget accordingly to LEDs connected. 
My setup needs around 650 mA at 5V.

# How to use?

Lamp can be controlled using four color keys on Sony TV remote control.
RED - Turn lamp On and Off
GREEN - Change between effect mode and solid color mode
BLUE - Change current color used by most effects and solid color mode
YELLOW - Change to next effect. Effect changes even if in solid color mode but it is not visible until mode change

Effects available - 8
Color available - 27

Enjoy :-)
