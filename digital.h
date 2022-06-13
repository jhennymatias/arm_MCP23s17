
#ifndef __DIGITAL__
#define __DIGITAL__
#include <stdint.h>

#define PIN(P,B) ((P<<5)|B)
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0



uint8_t digitalRead (uint8_t pb);
void digitalWrite( uint8_t pb, uint8_t valor);
void pinMode (uint8_t pb, uint8_t tipo);

#endif
