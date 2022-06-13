
#ifndef __PERIODICA__
#define __PERIODICA__
#include "LPC17xx.h"

struct elemento {
    char nome[50];
    uint16_t  periodo;
    uint16_t  contador;
    void (*funcao)(void);
    struct elemento *proximo;
};


void periodica_init(void);
void periodica_cria(char *nome, uint16_t periodo, void (*funcao)(void));
void periodica_remove (char *nome);

#endif
