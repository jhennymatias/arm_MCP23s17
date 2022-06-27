// Foi utilizada a função disponibilizada no material do professor

#include "spi.h"

uint8_t PINO_CS, PINO_MISO, PINO_MOSI, PINO_SCK;
void spi_configura (uint8_t pino_cs, uint8_t pino_miso, uint8_t pino_mosi, uint8_t pino_sck){
	PINO_CS   = pino_cs;
	PINO_MISO = pino_miso;
	PINO_MOSI = pino_mosi;
	PINO_SCK  = pino_sck;
	pinMode(PINO_CS, OUTPUT);
	pinMode(PINO_MISO, INPUT);
	pinMode(PINO_MOSI, OUTPUT);
	pinMode(PINO_SCK, OUTPUT);

	digitalWrite(PINO_SCK, LOW);
	digitalWrite(PINO_CS, HIGH);
}


void spi_desabilita (void){
    digitalWrite(PINO_CS, LOW);
}

void spi_habilita(void){
	digitalWrite(PINO_CS, HIGH);
}

uint8_t spi_write (uint8_t dado){
	uint8_t valor = 0, x, bit;

	for (x=0;x<8;x++){
		bit = (dado >> (7-x)) & 1;
		digitalWrite(PINO_MOSI, bit);
		digitalWrite(PINO_SCK, HIGH);
		delay_ms(5);
		valor = (valor << 1 ) | digitalRead(PINO_MISO);
		digitalWrite(PINO_SCK, LOW);
		delay_ms(5);
	}

	return valor;
}