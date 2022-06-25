#include "MCP.h"

uint8_t IODIRA_atual = 0x00;
uint8_t GPIOA_atual = 0xFF;
uint8_t IODIRB_atual = 0xFF;
uint8_t GPIOB_atual = 0x00;

void mcp_init (void){
	spi_configura (PIN_4_28, PIN_3_25, PIN_3_26, PIN_4_29);
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA);
  spi_write(IODIRA_atual);
  spi_desabilita();
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA);
  spi_write(GPIOA_atual);
  spi_habilita();

  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRB);
  spi_write(IODIRB_atual);
  spi_desabilita();
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRB);
  spi_write(GPIOB_atual);
  spi_habilita();

  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(GPPUA);
  spi_write(0x0F);
  spi_habilita();

  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(GPPUB);
  spi_write(0x0F);
  spi_habilita();
  
}

void mcp_config(uint8_t pino, int operacao){
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  if(operacao == INPUT){
    spi_write(IODIRB);
    IODIRB_atual |= (1 << pino);
    spi_write(IODIRB_atual);
  }else{
    spi_write(IODIRA);
    IODIRA_atual &= ~(1 << pino);
    spi_write(IODIRA_atual);
  }

  spi_habilita(); 
}

uint8_t mcp_write(uint8_t pino, uint8_t data, int operacao) {
    uint8_t b =0;
    if(operacao == INPUT){
      if (data == 1) {
        GPIOB_atual |= (1 << pino);
      }else if (data == 0){ 
        GPIOB_atual &= ~(1 << pino);
      }
    }else{
      if (data == 1) {
        GPIOA_atual |= (1 << pino);
      }else if (data == 0){ 
        GPIOA_atual &= ~(1 << pino);
      } 
    }

    spi_desabilita();
    spi_write(OPCODE_ESCRITA + operacao);
    if(operacao == INPUT){
      spi_write(GPIOB);
      b = spi_write(GPIOB_atual);
    }else{
      spi_write(GPIOA);
      b = spi_write(GPIOA_atual);
    }

    spi_habilita();

    if(operacao == READ) {
        return (b >> pino) & 1;
    }
    
    return (uint8_t)0;
}

// void mcp23S17_invert_pin(uint8_t pino) {
//     uint8_t current = mcp_write(pino, 0, READ);
//     mcp_write(pino, !current, WRITE);
// }


