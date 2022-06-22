#include "LPC17xx.h"
#include "digital.h"
#include <stdint.h>
#include <stdio.h>
#include "periodica.h"
#include "delay.h"
#include "uart.h"
#include "MCP.h"
#include "spi.h"

void configura_chaves(void)
{
	pinMode(PIN_1_08, INPUT);
	pinMode(PIN_1_04, INPUT);
	pinMode(PIN_1_01, INPUT);
	pinMode(PIN_1_00, INPUT);
	pinMode(PIN_2_10, INPUT);
}


void configura_pino_MCP(void){
	
}

uint8_t le_configuracao_chaves(void)
{
	uint8_t v=0;

	v = ((digitalRead(PIN_1_08) << 3) | 
         (digitalRead(PIN_1_04) << 2) | 
        (digitalRead(PIN_1_01) << 1) | 
         (digitalRead(PIN_1_00) )) ;
	return v;
}

int main(){
  SystemInit();
  UART0_Init(9600);
	mcp_init();

  return 0;
}
