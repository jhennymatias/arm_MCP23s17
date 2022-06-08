// EXEMPLO DE UM Pisca Pisca que usa a Lampada do kit
// para compilar:  
//                    make
// para gravar na placa (usando o bootloader): 
//                   lpc21isp -control -bin main.bin /dev/ttyUSB0 115200 12000
//
// para gravar na placa (usando o JTAG)
//                   openocd -f lpc1768.cfg
// abrir outro shell
// telnet localhost 4444
// > reset halt
// > flash write_image erase main.bin 0x0 bin
#include "LPC17xx.h"
#include "delay.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>
#include "digital.h"
#include <inttypes.h>

#define COMANDO_LIGA_L1 1
#define COMANDO_LIGA_L2 2
#define COMANDO_DESLIGA_L1 3
#define COMANDO_DESLIGA_L2 4
#define OUTRO 5




int main ( void ) 
{

	SystemInit();
	char linha[20]; int inteiro;

	
	UART0_Init(9600);
	pinMode(PIN_4_29, OUTPUT);
	pinMode(PIN_3_26, OUTPUT);
	pinMode(PIN_4_28, OUTPUT);
	pinMode(PIN_3_25, INPUT);

    digitalWrite(PIN_4_29, LOW);
    digitalWrite(PIN_3_26, LOW);
	digitalWrite(PIN_4_28, LOW);

	

	
	
	printf("............INTERPRETADOR DE COMANDOS.................\n");

	while(1){
		scanf("%s %d",linha, &inteiro); 
		printf("Comando recebido string=%s inteiro=%d\n",linha, inteiro);
		digitalWrite(PIN_4_29, HIGH);
	}
    return 0 ;
}

