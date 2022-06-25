// Foi utilizada a função disponibilizada no material do professor

#ifndef _SPI_
#define _SPI_
#include <inttypes.h>
#include "digital.h"
#include "delay.h"


void    spi_habilita (void);
void    spi_desabilita();
void    spi_configura (uint8_t pino_cs, uint8_t pino_miso, uint8_t pino_mosi, uint8_t pino_sck); 
uint8_t spi_write (uint8_t dado);
#endif
