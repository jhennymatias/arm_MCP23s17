#include "LPC17xx.h"
#include "digital.h"
#include <stdint.h>
#include <stdio.h>
#include "delay.h"
#include "MCP.h"
#include "spi.h"

int main(){
	SystemInit();
    delay_init();
	mcp_init();

// lado A sempre OUTPUT
    mcp_config_ladoA(MCP_PIN_A7);
    mcp_config_ladoA(MCP_PIN_A6);
    mcp_config_ladoA(MCP_PIN_A5);
    mcp_config_ladoA(MCP_PIN_A4);
    mcp_config_ladoA(MCP_PIN_A3);
    mcp_config_ladoA(MCP_PIN_A2);
    mcp_config_ladoA(MCP_PIN_A1);
    mcp_config_ladoA(MCP_PIN_A0);

// lado A sempre INPUT

    mcp_config_ladoB(MCP_PIN_B7);
    mcp_config_ladoB(MCP_PIN_B6);
    mcp_config_ladoB(MCP_PIN_B5);
    mcp_config_ladoB(MCP_PIN_B4);
    mcp_config_ladoB(MCP_PIN_B3);
    mcp_config_ladoB(MCP_PIN_B2);
    mcp_config_ladoB(MCP_PIN_B1);
    mcp_config_ladoB(MCP_PIN_B0);

    while(1){	
        mcp_write_ladoA(MCP_PIN_A7, 1); // Liga led fixo para testar se o circuito está funcionando
        if(mcp_write_ladoB(MCP_PIN_B6, 0) == 0){
            //desliga leds
            mcp_write_ladoA(MCP_PIN_A6, 0); 
            mcp_write_ladoA(MCP_PIN_A5, 0);
            mcp_write_ladoA(MCP_PIN_A4, 0);
            mcp_write_ladoA(MCP_PIN_A3, 0);
            mcp_write_ladoA(MCP_PIN_A2, 0);
            mcp_write_ladoA(MCP_PIN_A1, 0);
            mcp_write_ladoA(MCP_PIN_A0, 0);
        }else{
            // liga leds
            mcp_write_ladoA(MCP_PIN_A6, 1);
            mcp_write_ladoA(MCP_PIN_A5, 1);
            mcp_write_ladoA(MCP_PIN_A4, 1);
            mcp_write_ladoA(MCP_PIN_A3, 1);
            mcp_write_ladoA(MCP_PIN_A2, 1);
            mcp_write_ladoA(MCP_PIN_A1, 1);
            mcp_write_ladoA(MCP_PIN_A0, 1);
        }        
    }
        
	return 0;

}


