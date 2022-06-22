#include "digital.h"
#include "MCP.h"
#include "spi.h"
#include "delay.h"

void reset (void);

uint8_t pino_CE;

void mcp_init (void){
	// configura os pinos que serao usados para o CSN, MISO, MOSI, SCK
	spi_configura (PIN_4_28, PIN_3_25, PIN_3_26, PIN_4_29);
	pino_CE = PIN_4_30;
  delay_ms(500);
	reset();
}

void reset (void){
	digitalWrite(pino_CE, LOW);
	MEU_delay();
	spi_habilita();
	MEU_delay();
	spi_write(0x70);
	MEU_delay();
	spi_desabilita();
	digitalWrite(pino_CE, HIGH);
}

void clearBits(uint8_t addr, uint8_t bitmask){
  if (addr <= 0x15){
    uint8_t cur_val = readPE(addr);
    writePE(addr, cur_val & (~bitmask));
  }
}

void setBits(uint8_t addr, uint8_t bitmask){
  if (addr <= 0x15){
    uint8_t cur_val = readPE(addr);
    writePE(addr, cur_val | (bitmask));
  }
}

void toggleBits(uint8_t addr, uint8_t bitmask){
  if (addr <= 0x15){
    uint8_t cur_val = readPE(addr);
    writePE(addr, cur_val ^ (bitmask));
  }
}

uint8_t readBits(uint8_t addr, uint8_t bitmask){
  if (addr <= 0x15){
    uint8_t cur_val = readPE(addr) & bitmask ;
    return cur_val ;
  }
}

void mPortYSetPinsOut(uint8_t bitmask){
  clearBits(IODIRA, bitmask);
}

void mPortZSetPinsOut(uint8_t bitmask){
  clearBits(IODIRB, bitmask);
}

void mPortYSetPinsIn(uint8_t bitmask){
  setBits(IODIRA, bitmask);
}

void mPortZSetPinsIn(uint8_t bitmask){
  setBits(IODIRB, bitmask);
}

void mPortYIntEnable(uint8_t bitmask){
  setBits(GPINTENA, bitmask);
}

void mPortZIntEnable(uint8_t bitmask){
  setBits(GPINTENB, bitmask);
}

void mPortYIntDisable(uint8_t bitmask){
  clearBits(GPINTENA, bitmask);
}

void mPortZIntDisable(uint8_t bitmask){
  clearBits(GPINTENB, bitmask);
}

void mPortYEnablePullUp(uint8_t bitmask){
  setBits(GPPUA, bitmask);
}

void mPortZEnablePullUp(uint8_t bitmask){
  setBits(GPPUB, bitmask);
}

void mPortYDisablePullUp(uint8_t bitmask){
  clearBits(GPPUA, bitmask);
}

void mPortZDisablePullUp(uint8_t bitmask){
  clearBits(GPPUB, bitmask);
}

void writePE (uint8_t reg, uint8_t data){
	spi_habilita();
	spi_write(W_REGISTER|reg);
	spi_write(data);
	spi_desabilita();
}

uint8_t readPE (uint8_t reg){
	uint8_t x;
	spi_habilita();
	spi_write(R_REGISTER|reg);
	x = spi_write(0x00);
	spi_desabilita();
	return x;
}
