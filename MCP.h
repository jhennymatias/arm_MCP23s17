#pragma once
//
//    FILE: MCP23S17.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.3
// PURPOSE: Arduino library for SPI MCP23S17 16 channel port expander
//    DATE: 2021-12-30
//     URL: https://github.com/RobTillaart/MCP23S17


#include "SPI.h"


#define MCP23S17_LIB_VERSION              (F("0.1.3"))

#define MCP23S17_OK                       0x00
#define MCP23S17_PIN_ERROR                0x81
#define MCP23S17_SPI_ERROR                0x82
#define MCP23S17_VALUE_ERROR              0x83
#define MCP23S17_PORT_ERROR               0x84


#define MCP23S17_INVALID_READ             -100


class MCP23S17
{
public:
  MCP23S17(uint8_t select, uint8_t dataIn, uint8_t dataOut, uint8_t clock, uint8_t address = 0x00);
  MCP23S17(uint8_t select, uint8_t address = 0x00);

  bool     begin();
  bool     isConnected();  // needed ?