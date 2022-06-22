#ifndef _NRF24_
#define _NRF24_
#include <inttypes.h>
#include "spi.h"

#define PE_OPCODE_HEADER 0b01000000
#define READ 0b00000001
#define WRITE 0b00000000

#define R_REGISTER 0x00
#define W_REGISTER 0x20

#define SET_BANK     0x80
#define CLEAR_BANK   0x00
#define SET_MIRROR   0x40
#define CLEAR_MIRROR 0x00
#define SET_SEQOP    0x20
#define CLEAR_SEQOP  0x00
#define SET_DISSLW   0x10
#define CLEAR_DISSLW 0x00
#define SET_HAEN     0x08
#define CLEAR_HAEN   0x00
#define SET_ODR      0x04
#define CLEAR_ODR    0x00
#define SET_INTPOL   0x02
#define CLEAR_INTPOL 0x00


// **** Register Addresses (BANK=0) ****
// Note: Rename all PortA to PortY, PortB to PortZ to avoid confusion with PIC
#define IODIRA   0x00
#define IODIRB   0x01
#define IPOLY    0x02
#define IPOLZ    0x03
#define GPINTENA 0x04
#define GPINTENB 0x05
#define DEFVALA  0x06
#define DEFVALB  0x07
#define INTCONA  0x08
#define INTCONB  0x09
#define IOCON    0x0A
//#define IOCON    0x0B
#define GPPUA    0x0C
#define GPPUB    0x0D
#define INTFA    0x0E
#define INTFB    0x0F
#define INTCAPA  0x10
#define INTCAPB  0x11
#define GPIOA    0x12
#define GPIOB    0x13
#define OLATA    0x14
#define OLATB    0x15

void    mcp_init (void);

void mPortYSetPinsOut(uint8_t );

void mPortZSetPinsOut(uint8_t );

void mPortYSetPinsIn(uint8_t );

void mPortZSetPinsIn(uint8_t );

void mPortYIntEnable(uint8_t );

void mPortYIntDisable(uint8_t );

void mPortZIntEnable(uint8_t );

void mPortZIntDisable(uint8_t );

void mPortYEnablePullUp(uint8_t );

void mPortZEnablePullUp(uint8_t );

void mPortYDisablePullUp(uint8_t );

void mPortZDisablePullUp(uint8_t );

void writePE (uint8_t reg, uint8_t data);

uint8_t readPE (uint8_t reg);

#endif
