#include "LPC17xx.h"
#include "digital.h"
#include <stdint.h>
#include <stdio.h>
#include "periodica.h"
#include "delay.h"
#include "uart.h"
#include "MCP.h"
#include "spi.h"

int main(){
	

	SystemInit();
	UART0_Init(9600);
    delay_init();
	mcp_init();

    mcp_config(MCP_PIN_A7, OUTPUT);
    mcp_config(MCP_PIN_A6, OUTPUT);
    mcp_config(MCP_PIN_A5, OUTPUT);
    mcp_config(MCP_PIN_A4, OUTPUT);
    mcp_config(MCP_PIN_A3, OUTPUT);
    mcp_config(MCP_PIN_A2, OUTPUT);
    mcp_config(MCP_PIN_A1, OUTPUT);
    mcp_config(MCP_PIN_A0, OUTPUT);

while(1){
	
	mcp_write(MCP_PIN_A7, 1, WRITE);
    mcp_write(MCP_PIN_A6, 1, WRITE);
    mcp_write(MCP_PIN_A5, 1, WRITE);
    mcp_write(MCP_PIN_A4, 1, WRITE);
	mcp_write(MCP_PIN_A3, 1, WRITE);
    mcp_write(MCP_PIN_A2, 1, WRITE);
    mcp_write(MCP_PIN_A1, 1, WRITE);
    mcp_write(MCP_PIN_A0, 1, WRITE);
	delay_ms(1000);
}
	return 0;
	}

