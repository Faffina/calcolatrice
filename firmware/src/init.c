#define SCB_CPACR   (*(volatile unsigned int *)0xE000ED88)


static inline void enable_fpu(void)
{
    SCB_CPACR |= (0xF << 20);

    __asm volatile ("dsb");
    __asm volatile ("isb");
}

void init(void) {
    enable_fpu();
}
