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
	
	printf("jhenny");
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

	uint8_t status, contador = 0;

	// mcp_write(MCP_PIN_A7, 1, WRITE);
    // mcp_write(MCP_PIN_A6, 1, WRITE);
    // mcp_write(MCP_PIN_A5, 1, WRITE);
    // mcp_write(MCP_PIN_A4, 1, WRITE);

while(1){
	mcp_write(MCP_PIN_A7, 1, WRITE);
    mcp_write(MCP_PIN_A6, 1, WRITE);
    mcp_write(MCP_PIN_A5 ,1, WRITE);
    mcp_write(MCP_PIN_A4, 1, WRITE);
	// delay_ms(2000);
	// mcp_write(MCP_PIN_A7, 1, WRITE);
    // mcp_write(MCP_PIN_A6, 1, WRITE);
    // mcp_write(MCP_PIN_A5 ,1, WRITE);
    // mcp_write(MCP_PIN_A4, 1, WRITE);
	// delay_ms(2000);	

}
    // while(1) {
    //     status = mcp_write(MCP_PIN_B0, 0, READ);
    //     print("%d", status);
    //     if (status == 0) {
    //         mcp23S17_invert_pin(contador+4);
    //         contador = (contador +1) % 4;
    //     }
    //     delay_ms(100);
    // }
	return 0;


}
	// while(1){
	// 	if((mcp_write(MCP_PIN_B0, 0, READ))==0){
	// 		periodica_cria("LED0", 1000, mcp_write(MCP_PIN_A7, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B1, 0, READ))==0){
	// 		periodica_cria("LED1", 1000, mcp_write(MCP_PIN_A6, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B2, 0, READ))==0){
	// 		periodica_cria("LED2", 1000, mcp_write(MCP_PIN_A5, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B3, 0, READ))==0){
	// 		periodica_cria("LED3", 1000, mcp_write(MCP_PIN_A4, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B4, 0, READ))==0){
	// 		periodica_cria("LED4", 1000, mcp_write(MCP_PIN_A3, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B5, 0, READ))==0){
	// 		periodica_cria("LED5", 1000, mcp_write(MCP_PIN_A2, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B6, 0, READ))==0){
	// 		periodica_cria("LED6", 1000, mcp_write(MCP_PIN_A1, 1, WRITE));
	// 	}
	// 	if((mcp_write(MCP_PIN_B7, 0, READ))==0){
	// 		periodica_cria("LED7", 1000, mcp_write(MCP_PIN_A0, 1, WRITE));
	// 	}
//	}

