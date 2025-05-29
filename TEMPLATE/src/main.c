#include "R7FA6E10F.h"
#include <stdint.h>

void clock_config(void);
void gpio_init(void);
void gpio_toggle(void);

void clock_config(void){
    R_SYSTEM->SCKSCR &= ~R_SYSTEM_SCKSCR_CKSEL_Msk;             // Select HOCO
    R_SYSTEM->HOCOCR &= ~R_SYSTEM_HOCOCR_HCSTP_Msk;             // Operate the HOCO
    while(!((R_SYSTEM->OSCSF) & (R_SYSTEM_OSCSF_HOCOSF_Msk)));  // Wait for HOCO clock to stable
}

void gpio_init(void){
    // 407 & 408
    R_PORT4->PDR |= ((1<<7) | (1<<8));
    R_PORT4->PODR |= ((1<<7) | (1<<8));
}
void gpio_toggle(void){
    R_PORT4->PODR ^= ((1<<7) | (1<<8));
}
int main(void)
{
    clock_config();
    gpio_init();
    while(1)
    {
        gpio_toggle();
        for(int i=0;i<10000;i++);
    }
    return 0;
}
