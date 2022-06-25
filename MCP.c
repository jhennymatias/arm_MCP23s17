#include "digital.h"
#include "MCP.h"


uint8_t pino_CE;
uint8_t current_IODIRA = 0xFF;
uint8_t current_GPIOA = 0x00;


void mcp_init (void){
	spi_configura (PIN_4_28, PIN_3_25, PIN_3_26, PIN_4_29);
  spi_desabilita();
  spi_write(OPCODE);
  spi_write(IODIRA);
  spi_write(current_IODIRA);
  set_cs_high();
  
  spi_desabilita();
  spi_write(OPCODE);
  spi_write(IODIRA);
  spi_write(current_GPIOA);
  spi_habilita();

   // set pull-up resistor for GPIOA - port 0-3
    spi_desabilita();
    spi_write(0x40);
    spi_write(GPPUA);
    spi_write(0x0F);
    spi_habilita();
}


void mcp_config(uint8_t pino, int operacao){
  spi_desabilita();
  spi_write(OPCODE);
  spi_write(IODIRA);

  if(operacao = INPUT){
    current_IODIRA |= (1 << pino);
  }else{
    current_IODIRA &= ~(1 << pino);
  }

  spi_write(current_IODIRA);
  spi_habilita(); 
}

uint8_t mcp_write(uint8_t pino, uint8_t data, int operacao) {
    if (data == 1) {
      current_GPIOA |= (1 << pino);
    }else if (data == 0){ 
      current_GPIOA &= ~(1 << pino);
    }

    spi_desabilita();
    spi_write(OPCODE + operacao);
    spi_write(GPIOA);
    uint8_t b = spi_write(current_GPIOA);
    spi_habilita();

    if(operacao == READ) {
        return (b >> pino) & 1;
    }
    return (uint8_t)0;
}

void mcp23S17_invert_pin(uint8_t pino) {
    uint8_t current = mcp23S17_write_pin(pino, 0, READ);
    mcp23S17_write_pin(pino, !current, WRITE);
}


