#include "main.h"
#include "clock.h"

/*  Configure the Clock for the system
    1. ICLK  - System clock                 (CPU, DTC, DMAC, FLASH, RAM)
    2. PCLKA - Peripheral module clock A    (ETHERC, EDMAC, QSPI, SCI, SPI, CRC, DOC, ADC12, DAC12, SCE9, GPT bus clock)
    3. PCLKB - Peripheral module clock B    (Peripheral modules (CAC, ELC, I/O ports, POEG, RTC, WDT, IWDT, AGT, IIC, CAN, USBFS, SSIE, SDHI, Standby SRAM))
    4. PCLKC - Peripheral module clock C    (Peripheral module (ADC12 conversion clock))
    5. PCLKD - Peripheral module clock D    (Peripheral module (GPT count clock))
*/
void clock_config(void)
{
    R_SYSTEM->SCKSCR &= ~R_SYSTEM_SCKSCR_CKSEL_Msk;   // Select HOCO
    R_SYSTEM->PLLCR &= ~R_SYSTEM_PLLCR_PLLSTP_Msk;    // No PLL Operation
    R_SYSTEM->PLL2CR &= ~R_SYSTEM_PLL2CR_PLL2STP_Msk; // No PLL2 Operation

    /* Clock Divisions*/
    /* PCLKD(20MHz) - 1, PCLKC(20MHz) - 1, PCLKB(10MHz) - 2, PCLKA(10MHz) - 2, ICLK(20MHz) - 1, FLCK(20MHz) - 1*/
    R_SYSTEM->SCKDIVCR &= ~((7 << R_SYSTEM_SCKDIVCR_PCKD_Pos) | (7 << R_SYSTEM_SCKDIVCR_PCKC_Pos) |
                            (6 << R_SYSTEM_SCKDIVCR_PCKB_Pos) | (6 << R_SYSTEM_SCKDIVCR_PCKA_Pos) |
                            (7 << R_SYSTEM_SCKDIVCR_ICK_Pos) | (7 << R_SYSTEM_SCKDIVCR_FCK_Pos));

    R_SYSTEM->HOCOCR &= ~R_SYSTEM_HOCOCR_HCSTP_Msk; // Operate the HOCO
    while (!((R_SYSTEM->OSCSF) & (R_SYSTEM_OSCSF_HOCOSF_Msk))); // Wait for HOCO clock to stable
}