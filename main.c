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

    mcp_config(MCP_PIN_A7, OUTPUT);
    mcp_config(MCP_PIN_A6, OUTPUT);
    mcp_config(MCP_PIN_A5, OUTPUT);
    mcp_config(MCP_PIN_A4, OUTPUT);
    mcp_config(MCP_PIN_A3, OUTPUT);
    mcp_config(MCP_PIN_A2, OUTPUT);
    mcp_config(MCP_PIN_A1, OUTPUT);
    mcp_config(MCP_PIN_A0, OUTPUT);

    mcp_config(MCP_PIN_B7, INPUT);
    mcp_config(MCP_PIN_B6, INPUT);
    mcp_config(MCP_PIN_B5, INPUT);
    mcp_config(MCP_PIN_B4, INPUT);
    mcp_config(MCP_PIN_B3, INPUT);
    mcp_config(MCP_PIN_B2, INPUT);
    mcp_config(MCP_PIN_B1, INPUT);
    mcp_config(MCP_PIN_B0, INPUT);

	while(1){
		if((mcp_write(MCP_PIN_B0, 0, READ))==0){
			periodica_cria("LED0", 1000, mcp_write(MCP_PIN_A7, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B1, 0, READ))==0){
			periodica_cria("LED1", 1000, mcp_write(MCP_PIN_A6, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B2, 0, READ))==0){
			periodica_cria("LED2", 1000, mcp_write(MCP_PIN_A5, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B3, 0, READ))==0){
			periodica_cria("LED3", 1000, mcp_write(MCP_PIN_A4, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B4, 0, READ))==0){
			periodica_cria("LED4", 1000, mcp_write(MCP_PIN_A3, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B5, 0, READ))==0){
			periodica_cria("LED5", 1000, mcp_write(MCP_PIN_A2, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B6, 0, READ))==0){
			periodica_cria("LED6", 1000, mcp_write(MCP_PIN_A1, 1, WRITE));
		}
		if((mcp_write(MCP_PIN_B7, 0, READ))==0){
			periodica_cria("LED7", 1000, mcp_write(MCP_PIN_A0, 1, WRITE));
		}
	}

	return 0;

}

