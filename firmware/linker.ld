MEMORY {
    flash (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    ram   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
    ccm   (rwx) : ORIGIN = 0x10000000, LENGTH = 64K
}

_stack_start = ORIGIN(ram) + LENGTH(ram);

SECTIONS 
{
    .vectors : 
    {
        KEEP(*(.vectors*))
    } > flash

    .text : 
    {
        *(.text.start*)
        *(.text*)
        *(.rodata*)
    } > flash

    .data : 
    {
        _data_start = .;
        *(.data*)
        _data_end = .;
    } > ram AT > flash

    _data_start_flash = LOADADDR(.data);

    .bss : 
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > ram

    .ccmram :
    {
        *(.ccmram*)
    } > ccm
    
    . = ALIGN(8);
    _end = .;
}
