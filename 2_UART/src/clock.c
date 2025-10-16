#include "main.h"

/*  Configure the Clock for the system
    1. ICLK  - System clock                 (CPU, DTC, DMAC, FLASH, RAM)
    2. PCLKA - Peripheral module clock A    (ETHERC, EDMAC, QSPI, SCI, SPI, CRC, DOC, ADC12, DAC12, SCE9, GPT bus clock)
    3. PCLKB - Peripheral module clock B    (Peripheral modules (CAC, ELC, I/O ports, POEG, RTC, WDT, IWDT, AGT, IIC, CAN, USBFS, SSIE, SDHI, Standby SRAM))
    4. PCLKC - Peripheral module clock C    (Peripheral module (ADC12 conversion clock))
    5. PCLKD - Peripheral module clock D    (Peripheral module (GPT count clock))
*/
void clock_config(void)
{
    R_SYSTEM->PRCR = (uint16_t)0xA503; // Unlock PRC0,1,3

    // Disable PLLs
    R_SYSTEM->PLLCR &= ~R_SYSTEM_PLLCR_PLLSTP_Msk;
    R_SYSTEM->PLL2CR &= ~R_SYSTEM_PLL2CR_PLL2STP_Msk;

    // Clock divisions: ICLK=20MHz/div1, PCLKA=20MHz/div1, PCLKB=10MHz/div2, etc.
    R_SYSTEM->SCKDIVCR &= ~((7 << R_SYSTEM_SCKDIVCR_PCKD_Pos) | (7 << R_SYSTEM_SCKDIVCR_PCKC_Pos) |
                            (7 << R_SYSTEM_SCKDIVCR_PCKB_Pos) | (7 << R_SYSTEM_SCKDIVCR_PCKA_Pos) |
                            (7 << R_SYSTEM_SCKDIVCR_ICK_Pos) | (7 << R_SYSTEM_SCKDIVCR_FCK_Pos));
    R_SYSTEM->SCKDIVCR |= (0 << R_SYSTEM_SCKDIVCR_PCKD_Pos) | (0 << R_SYSTEM_SCKDIVCR_PCKC_Pos) |
                          (1 << R_SYSTEM_SCKDIVCR_PCKB_Pos) | (0 << R_SYSTEM_SCKDIVCR_PCKA_Pos) |
                          (0 << R_SYSTEM_SCKDIVCR_ICK_Pos) | (0 << R_SYSTEM_SCKDIVCR_FCK_Pos);

    // Set HOCO frequency (override OFS1 if invalid)
    R_SYSTEM->HOCOCR2 = 0x02U;  // 20 MHz

    // Start HOCO
    R_SYSTEM->HOCOCR &= ~R_SYSTEM_HOCOCR_HCSTP_Msk;
    while (!(R_SYSTEM->OSCSF & R_SYSTEM_OSCSF_HOCOSF_Msk)); // Wait stable

    // Select HOCO
    R_SYSTEM->SCKSCR &= ~R_SYSTEM_SCKSCR_CKSEL_Msk;

    // Delay for switch settling (~250 ns min per manual)
    for (volatile uint32_t i = 0; i < 10; i++); // Adjust based on freq

    R_SYSTEM->PRCR = (uint16_t)0xA500; // Lock
}
    