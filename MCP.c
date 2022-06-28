#include "MCP.h"


void mcp_init (void){
  
  uint8_t GPIOB_atual = 0x00, IODIRB_atual = 0x00, IODIRA_atual = 0x00, GPIOA_atual = 0xFF;
  
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
  spi_write(IODIRB);
  spi_write(IODIRB_atual);
  spi_habilita();
  
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRB);
  spi_write(GPIOB_atual);
  spi_habilita();

  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(GPPUB); //pull up
  spi_write(0xFF);
  spi_habilita();
  
}

void mcp_config_ladoA(uint8_t pino){
  uint8_t IODIRA_atual = 0x00;
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRA); 
  IODIRA_atual &= ~(1 << pino);
  spi_write(IODIRA_atual);
  spi_habilita(); 
}

uint8_t mcp_write_ladoA(uint8_t pino, uint8_t data) {
    /* 
      Operação de gravação no SPI:
      - desabilita: CS em nível baixo
      - write opcode 0x40
      - write endereço
      - write dado
      - habilita: CS em nível alto
    */
    
    uint8_t GPIOA_atual = 0xFF;
      if (data == 1) {
        GPIOA_atual |= (1 << pino);
      }else if (data == 0){ 
        GPIOA_atual &= ~(1 << pino);
      } 
    
      spi_desabilita();
      spi_write(OPCODE_ESCRITA);
      spi_write(GPIOA);
      uint8_t b = spi_write(GPIOA_atual);
      spi_habilita();  
      return (uint8_t)0;   
}


void mcp_config_ladoB(uint8_t pino){ 
  uint8_t IODIRB_atual = 0xFF;
  spi_desabilita();
  spi_write(OPCODE_ESCRITA);
  spi_write(IODIRB);
  IODIRB_atual |= (1 << pino);
  spi_write(IODIRB_atual);
  spi_habilita(); 
}

uint8_t mcp_read_ladoB(uint8_t pino, uint8_t data) {
    /* 
    Operação de gravação no SPI:
    - desabilita: CS em nível baixo
    - write opcode 0x40
    - write endereço
    - habilita: CS em nível alto
  */

    uint8_t GPIOB_atual = 0x00;  
    
      if (data == 1) {
          GPIOB_atual |= (1 << pino);
      }else if (data == 0){ 
          GPIOB_atual &= ~(1 << pino);
      } 

      spi_desabilita();
      spi_write(OPCODE_LEITURA);
      spi_write(GPIOB);
      uint8_t b = spi_write(GPIOB_atual); // Retorno do valor SPI
      spi_habilita(); 
      return (b >> pino) & 1; // dado antes da boorda de descida
}
