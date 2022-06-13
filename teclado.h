#ifndef __TECLADO__
#define __TECLADO__

#include <stdint.h>


 void teclado_configura(uint8_t coluna0, uint8_t coluna1, uint8_t coluna2,uint8_t  coluna3, uint8_t linha0, uint8_t linha1, uint8_t linha2, uint8_t linha3);

void teclado_bread(uint8_t *letra);


#endif