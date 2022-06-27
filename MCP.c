#include "MCP.h"

uint8_t IODIRA_atual = 0x00;
uint8_t GPIOA_atual = 0xFF;
uint8_t IODIRB_atual = 0xFF;
uint8_t GPIOB_atual = 0x00;

void mcp_init (void){
  //uint8_t pino_cs, uint8_t pino_miso, uint8_t pino_mosi, uint8_t pino_sck
  spi_configura (PIN_4_28, PIN_3_25, PIN_3_26, PIN_4_29);
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA);
  spi_write(IODIRA_atual);
  spi_habilita();
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA);
  spi_write(GPIOA_atual);
  spi_habilita();
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(GPPUA);
  spi_write(0x0F);
  spi_habilita();
  
}

void mcp_config(uint8_t pino, int operacao){
  /* 
    Operação de gravação no SPI:

    - desabilita: CS em nível baixo
    - write opcode 0x40
    - write endereço
    - habilita: CS em nível alto
  */
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA);
  
  if (operacao == INPUT)
        IODIRA_atual |= (1 << pino);
  else if (operacao == OUTPUT)
       IODIRA_atual &= ~(1 << pino);
  spi_write(IODIRA_atual);

  spi_habilita(); 
  
}

uint8_t mcp_write(uint8_t pino, uint8_t data, uint8_t operacao) {
    uint8_t b =0;
      if (data == 1) {
        GPIOA_atual |= (1 << pino);
      }else if (data == 0){ 
        GPIOA_atual &= ~(1 << pino);
      } 
  

    spi_desabilita();
    spi_write(0x40 +operacao);
      spi_write(GPIOA);
      b = spi_write(GPIOA_atual);
  
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


