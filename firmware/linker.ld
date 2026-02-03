ENTRY(start)

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
        . = ALIGN(4);
        KEEP(*(.vectors*))
        . = ALIGN(4);
    } > flash

    .text : 
    {
        . = ALIGN(4);
        *(.text.start*)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > flash

    .preinit_array :
    {
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP(*(.preinit_array*))
        __preinit_array_end = .;
    } > flash

    .init_array :
    {
        . = ALIGN(4);
        __init_array_start = .;
        KEEP(*(.init_array*))
        __init_array_end = .;
    } > flash

    .fini_array :
    {
        . = ALIGN(4);
        __fini_array_start = .;
        KEEP(*(.fini_array*))
        __fini_array_end = .;
    } > flash

    .ARM.exidx :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > flash

    .data : 
    {
        . = ALIGN(4);
        _data_start = .;
        *(.data*)
        . = ALIGN(4);
        _data_end = .;
    } > ram AT > flash

    _data_start_flash = LOADADDR(.data);

    .bss : 
    {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > ram

    .ccmram :
    {
        . = ALIGN(4);
        *(.ccmram*)
        . = ALIGN(4);
    } > ccm
    
    _end = .;
}
