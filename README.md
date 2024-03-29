
# Utilização do expansor MCP23s17 no Arm 

Este projeto tem como objetivo utilizar o expansor de I/O MCP23s17 no ARM, com onjetivo de ligar leds e botões.


## Definição das portas na placa:

- 4.28 Pino de Chip Select (CS)
- 4.29 Pino de Clock (SCK)
- 3.25 Pino de Miso (SO)
- 3.26 Pino de Miso (SI)

Caso desejar trocar acessar o arquivo: MCP.c

## Definição no expansor de I/O:

- LADO A: definido previamente como INPUT
- LADO B: definido previamente como OUTPUT

Caso desejar trocar alterar as funções: 
- mcp_config_ladoA (OUTPUT) 
- mcp_config_ladoB (INPUT)
- mcp_write_ladoA (OUTPUT)
- mcp_read_ladoB (INPUT)


## Referência

 - [SPI comunicação](https://github.com/fabiorochaufsc/SistemasDigitalsEmbarcados/tree/master/Unidade5/C%C3%B3digo/radio)
 - [MCP23S17](https://downloads.arduino.cc/libraries/github.com/RobTillaart/MCP23S17-0.1.3.zip?_gl=1*13m880u*_ga*NTQ3NzA5MzM1LjE2NTUxNTAwNjE.*_ga_NEXN8H46L5*MTY1NjM3NjA5OC4yLjAuMTY1NjM3NjA5OC42MA..)
 - [MCP23S!7](https://people.ece.cornell.edu/land/courses/ece4760/PIC32/index_port_expander.html)

