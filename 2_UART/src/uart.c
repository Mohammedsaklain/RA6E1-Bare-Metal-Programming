#include "main.h"
#include "uart.h"

void Init_UART_SCI9(void){
    // Unlock for MSTP (PRC1)
    R_SYSTEM->PRCR = 0xA502U;

    // Enable SCI9 module
    R_MSTP->MSTPCRB &= ~(1U << 22);

    // Lock PRCR
    R_SYSTEM->PRCR = 0xA500U;

    // Delay for PCLKA propagation (~1 µs)
    for (volatile uint32_t i = 0; i < 200; i++); // Calibrate at 20 MHz

    // Force SCR reset (direct write, as in FSP and manual)
    R_SCI9->SCR = 0x00U;

    // Verify in debugger: SCR should now be 0x00 and modifiable

    // Rest of config (non-FIFO async)
    R_SCI9->FCR &= ~R_SCI0_FCR_FM_Msk;        // FM=0
    R_SCI9->SCR &= ~R_SCI0_SCR_CKE_Msk;       // CKE=00b
    R_SCI9->SIMR1 &= ~R_SCI0_SIMR1_IICM_Msk;  // IICM=0
    R_SCI9->SPMR &= ~(0xC0U << 0);            // CKPH=0, CKPOL=0
    R_SCI9->SMR = 0x00U;                      // 8N1 async defaults
    R_SCI9->SCMR &= ~(0x0DU << 0);            // LSB first, no invert
    R_SCI9->SEMR = 0x00U;
    R_SCI9->SPTR = 0x00U;
    R_SCI9->ACTR = 0x00U;

    // Baud 38.4 kbps @ 20 MHz PCLKA
    R_SCI9->BRR = 31U;
    R_SCI9->SEMR |= (1U << 5);  // BGDM=1
    R_SCI9->MDDR = 4U;

    UART_Port_Init();

    // Enable TX/RX last
    R_SCI9->SCR = (1U << 7) | (1U << 6);  // TE=1, RE=1
}

void uart_putc(char c)
{
    while (!(R_SCI9->SSR & R_SCI0_SSR_TDRE_Msk));
    R_SCI9->TDR = c;
}

char uart_getc(void)
{
    while (!(R_SCI9->SSR & R_SCI0_SSR_RDRF_Msk));
    return R_SCI9->RDR;
}

void uart_puts(const char *s)
{
    while (*s) {
        uart_putc(*s++);
    }
}

void UART_Port_Init(void)
{
    PORT_Pin_Init(PORT1,9,OUTPUT);
    PORT_Pin_Init(PORT1,10,INPUT);
    R_PFS->PORT[1].PIN[9].PmnPFS = 0;               // Clear P109PFS
    R_PFS->PORT[1].PIN[10].PmnPFS = 0;              // Clear P110PFS

    R_PFS->PORT[1].PIN[9].PmnPFS_b.PMR = 1;         // Set to peripheral mode
    R_PFS->PORT[1].PIN[10].PmnPFS_b.PMR = 1;        // Set to peripheral mode

    R_PFS->PORT[1].PIN[9].PmnPFS_b.PSEL = 0b0101;   // Select TXD9
    R_PFS->PORT[1].PIN[10].PmnPFS_b.PSEL = 0b0101;  // Select RXD9
}