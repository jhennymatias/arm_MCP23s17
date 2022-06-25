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
    periodica_init();
    delay_init();
	mcp_init();

    uint8_t status;
    
    mcp_config(7, OUTPUT);
    mcp_config(6, OUTPUT);
    mcp_config(5, OUTPUT);
    mcp_config(4, OUTPUT);
    mcp_config(3, INPUT);
    mcp_config(2, INPUT);
    mcp_config(1, INPUT);
    mcp_config(0, INPUT);

    mcp_write(7, 1, WRITE);
    mcp_write(6, 1, WRITE);
    mcp_write(5, 1, WRITE);
    mcp_write(4, 1, WRITE);
    mcp_write(3, 1, WRITE);
    mcp_write(2, 1, WRITE);
    mcp_write(1, 1, WRITE);
    mcp_write(0, 1, WRITE);
	
    while(1) {
        status = mcp_write(3, 0, READ);
		printf("%d", status);
	    
        delay_ms(100);
    }

	return 0;

}

