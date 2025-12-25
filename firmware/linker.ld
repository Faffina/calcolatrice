MEMORY {
    flash (rx): ORIGIN = 0x08000000, LENGTH = 128K
    ram(rwx): ORIGIN = 0x20000000, LENGTH = 16K
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

    .preinit_array :
    {
        PROVIDE_HIDDEN(__preinit_array_start = .);
        KEEP(*(.preinit_array*))
        PROVIDE_HIDDEN(__preinit_array_end = .);
    } > flash

    .init_array :
    {
        PROVIDE_HIDDEN(__init_array_start = .);
        KEEP(*(SORT(.init_array*)))
        PROVIDE_HIDDEN(__init_array_end = .);
    } > flash

    .fini_array :
    {
        PROVIDE_HIDDEN(__fini_array_start = .);
        KEEP(*(SORT(.fini_array*)))
        PROVIDE_HIDDEN(__fini_array_end = .);
    } > flash

    .bss : 
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > ram

    . = ALIGN(8);
    _end = .;
}
