#include "main.h"
#include "port.h"

// User LEDs on 407 & 408

void PORT_Pin_Init(R_PORT0_Type *PORT, uint8_t pin,  uint8_t mode){
    PORT->PDR &= ~(65535U);     // Clear pins before setting
    PORT->PDR |= (mode<<pin);   // Set the mode, IN or OUT
}

void PORT_Pin_Write(R_PORT0_Type *PORT, uint8_t pin, uint8_t level){
    PORT->PODR |= (level<<pin); // Set the State 
}

void PORT_Pin_Toggle(R_PORT0_Type *PORT, uint8_t pin){
    PORT->PODR^= (1<<pin);
}

uint16_t PORT_Pin_Read(R_PORT0_Type *PORT,uint16_t pin){
    return ((PORT->PIDR & (1<<pin))>>pin);
}