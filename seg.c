#include "seg.h"
#include "delay.h"
#include "digital.h"
#include "periodica.h"

uint8_t digitos[4];
uint8_t mostra[4]={1,1,1,1};
uint8_t disp[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uint8_t v[]={DISPLAY0,DISPLAY1,DISPLAY2,DISPLAY3};

void mostraDisplay (uint8_t numero_display, uint8_t valor) {
    digitalWrite(SEGA, HIGH);
    digitalWrite(SEGB, HIGH);
    digitalWrite(SEGC, HIGH);
    digitalWrite(SEGD, HIGH);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, HIGH);
    digitalWrite(DISPLAY0, LOW);
    digitalWrite(DISPLAY1, LOW);
    digitalWrite(DISPLAY2, LOW);
    digitalWrite(DISPLAY3, LOW);
  
    digitalWrite(v[numero_display], HIGH);
  
    digitalWrite(SEGA, disp[valor]&1);
    digitalWrite(SEGB, (disp[valor]>>1)&1);
    digitalWrite(SEGC, (disp[valor]>>2)&1);
    digitalWrite(SEGD, (disp[valor]>>3)&1);
    digitalWrite(SEGE, (disp[valor]>>4)&1);
    digitalWrite(SEGF, (disp[valor]>>5)&1);
    digitalWrite(SEGG, (disp[valor]>>6)&1);
}

void funcRefresh (void) {
	static uint8_t v=0;
	static uint8_t podeOmitir = 1;

    if ((digitos[v] != 0) || (v==3)) podeOmitir=0;
    if (!podeOmitir) mostraDisplay(v,digitos[v]);

	v = (v + 1) % 4;
	if (v==0) 	podeOmitir =1;
}
 
void seg_init ( void ) {
    pinMode( SEGA, OUTPUT);
    pinMode( SEGB, OUTPUT);
    pinMode( SEGC, OUTPUT);
    pinMode( SEGD, OUTPUT);
    pinMode( SEGE, OUTPUT);
    pinMode( SEGF, OUTPUT);
    pinMode( SEGG, OUTPUT);
    pinMode(DISPLAY0, OUTPUT);
    pinMode(DISPLAY1, OUTPUT);
    pinMode(DISPLAY2, OUTPUT);
    pinMode(DISPLAY3, OUTPUT);
  
    for (uint8_t v =0; v<4;v++) digitos[v]=0;
    periodica_cria ("refresh",6, funcRefresh);
}

void seg_apresenta (uint16_t valor) {
	for (uint8_t v=0;v<4;v++) digitos[v]=0;
	uint16_t divisor=1000;
	for (int a=0;a<4;a++) {
		digitos[a]=valor/divisor;
		valor = valor - digitos[a]*divisor;
		divisor=divisor/10;
	}
}

