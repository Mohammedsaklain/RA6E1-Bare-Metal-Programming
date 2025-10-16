#ifndef UART_H_
#define UART_H_

#include "R7FA6E10F.h"

/*
SCI9 -> P109(TXD9), P110(RXD9)
*/
void UART_Port_Init(void);
void Init_UART_SCI9(void);
void uart_putc(char c);
char uart_getc(void);
void uart_puts(const char *s);

#endif
