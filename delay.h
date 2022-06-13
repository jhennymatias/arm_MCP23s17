#ifndef __DELAY__
#define __DELAY__
#include <stdint.h>

void delay_init(void);
void delay_us(uint32_t n);
void delay_ms(uint32_t n);


#endif
