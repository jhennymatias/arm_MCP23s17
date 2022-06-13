


#include "uart.h"



extern 
int _write (int fd, const void *buf, size_t count)
{
	uint8_t x;
	char *vet = (char *) buf;

	for (x=0;x<count;x++) UART0_Sendchar(  vet[x]);
	return count;
}
 extern 
int _read (int fd, const void *buf, size_t count)
{
	uint8_t contador=0;
	char *vet = (char *) buf;
	char letra;


	while (contador < count)
	{
		letra = UART0_Getchar();
		if (letra=='\n') break;
		vet[contador]=letra;
		contador++;	
	}
	vet[contador]='\n';
	return contador+1;
}

// ***********************
// Function to set up UART
void UART0_Init(int baudrate)
{
	int pclk;
	unsigned long int Fdiv;

	// PCLK_UART0 is being set to 1/4 of SystemCoreClock
	pclk = SystemCoreClock / 4;	
	
	// Turn on power to UART0
	LPC_SC->PCONP |=  PCUART0_POWERON;
		
	// Turn on UART0 peripheral clock
	LPC_SC->PCLKSEL0 &= ~(PCLK_UART0_MASK);
	LPC_SC->PCLKSEL0 |=  (0 << PCLK_UART0);		// PCLK_periph = CCLK/4
	
	// Set PINSEL0 so that P0.2 = TXD0, P0.3 = RXD0
	LPC_PINCON->PINSEL0 &= ~0xf0;
	LPC_PINCON->PINSEL0 |= ((1 << 4) | (1 << 6));
	
	LPC_UART0->LCR = 0x83;		// 8 bits, no Parity, 1 Stop bit, DLAB=1
    Fdiv = ( pclk / 16 ) / baudrate ;	// Set baud rate
    LPC_UART0->DLM = Fdiv / 256;							
    LPC_UART0->DLL = Fdiv % 256;
    LPC_UART0->LCR = 0x03;		// 8 bits, no Parity, 1 Stop bit DLAB = 0
    LPC_UART0->FCR = 0x07;		// Enable and reset TX and RX FIFO
}

// ***********************
// Function to send character over UART
void UART0_Sendchar(char c)
{
	while( (LPC_UART0->LSR & LSR_THRE) == 0 );	// Block until tx empty
	
	LPC_UART0->THR = c;
}

// Function to get character from UART
char UART0_Getchar()
{
	char c;
	while( (LPC_UART0->LSR & LSR_RDR) == 0 );  // Nothing received so just block 	
	c = LPC_UART0->RBR; // Read Receiver buffer register
	return c;
}


