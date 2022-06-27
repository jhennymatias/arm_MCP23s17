#ifndef __SEG__
#define __SEG__
#include <stdint.h>

#define SEGA PIN(0,4)
#define SEGB PIN(0,5)
#define SEGC PIN(0,6)
#define SEGD PIN(0,7)
#define SEGE PIN(0,8)
#define SEGF PIN(0,9)
#define SEGG PIN(0,10)
#define DISPLAY0 PIN(3,25)
#define DISPLAY1 PIN(3,26)
#define DISPLAY2 PIN(4,28)
#define DISPLAY3 PIN(4,29)

void seg_init (void);
void seg_apresenta (uint16_t valor);

#endif

