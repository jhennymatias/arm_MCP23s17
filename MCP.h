#ifndef _MCP_
#define _MCP_
#include <inttypes.h>
#include "spi.h"
#include "spi.h"
#include "delay.h"


#define OPCODE 0x40
#define IODIRA   0x00
#define IODIRB   0x10
#define IPOLA    0x01
#define IPOLB    0x11
#define GPINTENA 0x02
#define GPINTENB 0x12
#define DEFVALA  0x03
#define DEFVALB  0x12
#define INTCONA  0x04
#define INTCONB  0x14
#define IOCON1   0x05
#define IOCON2   0x15
#define GPPUA    0x0C
#define GPPUB    0x16
#define INTFA    0x07
#define INTFB    0x17
#define INTCAPA  0x08
#define INTCAPB  0x18
#define GPIOA    0x12
#define GPIOB    0x13
#define OLATA    0x0A
#define OLATB    0x1A

#define OUTPUT 0
#define INPUT 1
#define WRITE 0
#define READ 1


void mcp_init (void);
void mcp_config(uint8_t pino, int operacao);
uint8_t mcp_write(uint8_t pino, uint8_t data, int operacao);
void mcp23S17_invert_pin(uint8_t pino);

#endif
