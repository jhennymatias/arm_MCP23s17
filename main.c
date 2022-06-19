#include "LPC17xx.h"
#include "digital.h"
#include <stdint.h>
#include <stdio.h>
#include "periodica.h"
#include "delay.h"
#include "uart.h"
#include "MCP.h"

int main()
{
  const int bus = 0;
  const int chip_select = 0;
  const int hw_addr = 0;

  // conecta com o SPI e inicializa
  int mcp23s17_fd = mcp23s17_init(bus, chip_select);
  const uint8_t ioconfig = BANK_OFF |
                          INT_MIRROR_OFF |
                          SEQOP_OFF |
                          DISSLW_OFF |
                          HAEN_ON |
                          ODR_OFF |
                          INTPOL_LOW;

  while (1){
    mcp23s17_write_bit(ioconfig, 0, IOCON, hw_addr, mcp23s17_fd);
    delay_ms(1000);
    mcp23s17_write_bit(ioconfig, 1, IOCON, hw_addr, mcp23s17_fd);
  
  }
}