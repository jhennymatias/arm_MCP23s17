#ifndef _MCP_
#define _MCP_
#include <inttypes.h>
#include "spi.h"
#include "spi.h"
#include "digital.h"
#include "delay.h"

#define OPCODE_ESCRITA   0x40
#define OPCODE_LEITURA   0X41
#define IODIRA     0x00
#define IODIRB     0x10
#define IPOLA      0x01
#define IPOLB      0x11
#define GPINTENA   0x02
#define GPINTENB   0x12
#define DEFVALA    0x03
#define DEFVALB    0x13
#define INTCONA    0x04
#define INTCONB    0x14
#define IOCON1     0x05
#define IOCON2     0x15
#define GPPUA      0x0C
#define GPPUB      0x16
#define INTFA      0x07
#define INTFB      0x17
#define INTCAPA    0x08
#define INTCAPB    0x18
#define GPIOA      0x12
#define GPIOB      0x13
#define OLATA      0x0A
#define OLATB      0x1A

#define MCP_PIN_A0 0
#define MCP_PIN_A1 1
#define MCP_PIN_A2 2
#define MCP_PIN_A3 3
#define MCP_PIN_A4 4
#define MCP_PIN_A5 5
#define MCP_PIN_A6 6
#define MCP_PIN_A7 7

#define MCP_PIN_B0 0
#define MCP_PIN_B1 1
#define MCP_PIN_B2 2
#define MCP_PIN_B3 3
#define MCP_PIN_B4 4
#define MCP_PIN_B5 5
#define MCP_PIN_B6 6
#define MCP_PIN_B7 7


#define WRITE 0
#define READ 1

void mcp_init (void);
void mcp_config(uint8_t pino, uint8_t operacao);
uint8_t mcp_write(uint8_t pino, uint8_t data, uint8_t operacao);
void mcp23S17_invert_pin(uint8_t pino);

#endif
