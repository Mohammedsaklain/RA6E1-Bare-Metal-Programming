#include <stdint.h>
#include "R7FA6E10F.h"

extern unsigned long _etext, _sdata, _edata, _ebss, _sbss;		// external symbols from Linkerscript to copy to RAM
extern unsigned long _stack_end, _data_flash;

extern void clock_config(void);
extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler(void)			 		 	 __attribute__((weak, alias("Default_Handler"))); /* alias used to eliminate manual entry of all the exceptions and IRQ's to be entered onto the vector array below, Default_Handler alias simply replaces by itself to the NMI when it is invoked*/
void Hard_Fault_Handler(void) 		 	 	 __attribute__((weak, alias("Default_Handler")));
void MemManage_Fault_Handler(void)       	 __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void) 		 	 	 __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) 	         	 __attribute__((weak, alias("Default_Handler")));
void Secure_Fault_Handler(void) 	 		 __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)		 	 		 __attribute__((weak, alias("Default_Handler")));
void Debug_Monitor_Handler(void)         	 __attribute__((weak, alias("Default_Handler")));
void PendableSrvReq_Handler(void)	     	 __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)		 	 		 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR0_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR1_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR2_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR3_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR4_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR5_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR6_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR7_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR8_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR9_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR10_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR11_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR12_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR13_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR14_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR15_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR16_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR17_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR18_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR19_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR20_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR21_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR22_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR23_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR24_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR25_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR26_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR27_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR28_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR29_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR30_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR31_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR32_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR33_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR34_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR35_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR36_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR37_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR38_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR39_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR40_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR41_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR42_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR43_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR44_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR45_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR46_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR47_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR48_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR49_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR50_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR51_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR52_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR53_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR54_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR55_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR56_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR57_Handler(void)            	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR58_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR59_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR60_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR61_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR62_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR63_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR64_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR65_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR66_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR67_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR68_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR69_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR70_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR71_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR72_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR73_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR74_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR75_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR76_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR77_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR78_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR79_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR80_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR81_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR82_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR83_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR84_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR85_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR86_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR87_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR88_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR89_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR90_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR91_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR92_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR93_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR94_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));
void ICU_IELSR95_Handler(void)           	 __attribute__((weak, alias("Default_Handler")));


__attribute__((section(".interrupt_vector_section")))
void (* const table_interrupt_vector[])(void) =
{
	(void *)&_stack_end,
	Reset_Handler,
	NMI_Handler,
	Hard_Fault_Handler,
	MemManage_Fault_Handler,
	Bus_Fault_Handler,
	Usage_Fault_Handler,
	Secure_Fault_Handler,
	0,
	0,
	0,
	SVCall_Handler,
	Debug_Monitor_Handler,
	0,
	PendableSrvReq_Handler,
	SysTick_Handler,
	ICU_IELSR0_Handler,
	ICU_IELSR1_Handler,
	ICU_IELSR2_Handler,
    ICU_IELSR3_Handler,
	ICU_IELSR4_Handler,
    ICU_IELSR5_Handler,
    ICU_IELSR6_Handler,
 	ICU_IELSR7_Handler,
	ICU_IELSR8_Handler,
	ICU_IELSR9_Handler,
    ICU_IELSR10_Handler,
    ICU_IELSR11_Handler,
    ICU_IELSR12_Handler,
    ICU_IELSR13_Handler,
	ICU_IELSR14_Handler,
	ICU_IELSR15_Handler,
	ICU_IELSR16_Handler,
	ICU_IELSR17_Handler,
	ICU_IELSR18_Handler, 
	ICU_IELSR19_Handler,                                                          
	ICU_IELSR20_Handler,
    ICU_IELSR21_Handler,
	ICU_IELSR22_Handler,
 	ICU_IELSR23_Handler,                                                                          
	ICU_IELSR24_Handler,
	ICU_IELSR25_Handler,
    ICU_IELSR26_Handler,
    ICU_IELSR27_Handler,
    ICU_IELSR28_Handler,
    ICU_IELSR29_Handler,
	ICU_IELSR30_Handler,
    ICU_IELSR31_Handler,
	ICU_IELSR32_Handler,
    ICU_IELSR33_Handler,
	ICU_IELSR34_Handler,
    ICU_IELSR35_Handler,
    ICU_IELSR36_Handler,
    ICU_IELSR37_Handler,
    ICU_IELSR38_Handler,
    ICU_IELSR39_Handler,
    ICU_IELSR40_Handler,
    ICU_IELSR41_Handler,
    ICU_IELSR42_Handler,
    ICU_IELSR43_Handler,
 	ICU_IELSR44_Handler,
 	ICU_IELSR45_Handler,
	ICU_IELSR46_Handler,
	ICU_IELSR47_Handler,
 	ICU_IELSR48_Handler,
 	ICU_IELSR49_Handler,
	ICU_IELSR50_Handler,
 	ICU_IELSR51_Handler,
 	ICU_IELSR52_Handler,
 	ICU_IELSR53_Handler,
	ICU_IELSR54_Handler,
	ICU_IELSR55_Handler,
	ICU_IELSR56_Handler,
	ICU_IELSR57_Handler,
	ICU_IELSR58_Handler,
	ICU_IELSR59_Handler,
	ICU_IELSR60_Handler,
	ICU_IELSR61_Handler,
	ICU_IELSR62_Handler,
	ICU_IELSR63_Handler,
	ICU_IELSR64_Handler,
	ICU_IELSR65_Handler,                   
	ICU_IELSR66_Handler,
	ICU_IELSR67_Handler,
	ICU_IELSR68_Handler,
	ICU_IELSR69_Handler,
	ICU_IELSR70_Handler,
	ICU_IELSR71_Handler,
	ICU_IELSR72_Handler,
	ICU_IELSR73_Handler, 
	ICU_IELSR74_Handler,
	ICU_IELSR75_Handler,                                                     
	ICU_IELSR76_Handler,
	ICU_IELSR77_Handler,
	ICU_IELSR78_Handler,
	ICU_IELSR79_Handler,
	ICU_IELSR80_Handler,
    ICU_IELSR81_Handler,
    ICU_IELSR82_Handler,
	ICU_IELSR83_Handler,
	ICU_IELSR84_Handler,
	ICU_IELSR85_Handler,
	ICU_IELSR86_Handler,
	ICU_IELSR87_Handler,
	ICU_IELSR88_Handler,
	ICU_IELSR89_Handler,
	ICU_IELSR90_Handler,
	ICU_IELSR91_Handler,
	ICU_IELSR92_Handler,
	ICU_IELSR93_Handler,
	ICU_IELSR94_Handler,
	ICU_IELSR95_Handler
}; /* __attribute__((section(".isr_section"))) added bcz to tell that don't add this section in .data section, rather put it in .isr section as mentioned*/ 


void Reset_Handler(void)
{
    unsigned long *source;
    unsigned long *destination;

	// 1. Copying .data section to SRAM
    source = &_data_flash;
    for(destination = &_sdata; destination < &_edata;)
        *(destination++) = *(source++);
    
	// 2. Initialize the .bss section to zero in SRAM
	// Since .bss section is an uninitialized data section in which still no data is know, hence we assign with the zero
    for(destination = &_sbss; destination < &_ebss;)
        *(destination++) = 0;
	

	// 3. Configure Clock & Jump to main
	main();

}

void Default_Handler(void)
{
	while(1);
}

