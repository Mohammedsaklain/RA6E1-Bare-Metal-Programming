#include "main.h"

void delay_ms(volatile uint32_t ms);

int main(void)
{
  //PORT_Pin_Init(PORT4,8,OUTPUT);
  clock_config();
  Init_UART_SCI9();
  PORT_Pin_Init(PORT4,7,OUTPUT);
  
  while (1){
    PORT_Pin_Toggle(PORT4,7);
    uart_puts("H");
    delay_ms(50);

    //char c = uart_getc();
    //uart_putc(c);
  }
  return 0;
}

void delay_ms(volatile uint32_t ms)
{
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 2000; j++);
}