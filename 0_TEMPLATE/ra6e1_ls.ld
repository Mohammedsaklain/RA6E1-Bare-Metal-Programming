ENTRY(Reset_Handler)

MEMORY
{
	CODE_FLASH	(rx)		: ORIGIN = 0x00000000, LENGTH = (1024*1024) /* while assigning value to ORIGIN/LENGTH, give space */
	SRAM		(rwx)		: ORIGIN = 0x20000000, LENGTH = (256 *1024) 
}

SECTIONS
{
	/*The order represents order of the linker places on final executable in memory*/
	.text : /* give space for colon */
	{
		. = ALIGN(4);
		KEEP(*(.interrupt_vector_section)) /* bcz isr is the 1st section we would like to place */
		*(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
		. = ALIGN(4); 	/* To allign and padding purpose */
		_etext = .; 	/*Symbol with location counter to know the end address in .text section */
	}> CODE_FLASH AT> CODE_FLASH /* we want to place the code/Instructions in Flash itself, so VMA & LMA same */

	_data_flash = .;
	.data :
	{
		. = ALIGN(4);
		_sdata = .; 	/* symbol which will hold SRAM, bcz wkt Location counter always hold VM, here SRAM */
		*(.data) 		/* All the file which contains initialized data should come here */
		*(.data*)
		. = ALIGN(4);
		_edata = .; 
	}> SRAM AT> CODE_FLASH /* take from Flash and executed in sram */

	.bss :
	{
		_sbss = .;
	    *(.bss)
        *(.bss*)
        *(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}> SRAM AT> SRAM /* Uninitialized data must be present in SRAM only */

	_stack_size = 1024;
	_stack_end  = ORIGIN(SRAM)+LENGTH(SRAM);
	_stack_begin = _stack_end - _stack_size;
	. = _stack_begin;
	._stack :
	{
		. = . + _stack_size;
	} >SRAM
}
