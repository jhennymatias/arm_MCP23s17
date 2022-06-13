#ifndef _TIMER_
#define _TIMER_
#include "LPC17xx.h"
void desabilita_timer (void);
void habilita_timer(void);


void timer_init(void (*f)(void));



#endif
