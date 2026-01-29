#define SCB_CPACR   (*(volatile unsigned int *)0xE000ED88)
#include "rcc.h"

static inline void enable_fpu(void)
{
    SCB_CPACR |= (0xF << 20);

    __asm volatile ("dsb");
    __asm volatile ("isb");
}

#define SCB_VTOR (*(volatile uint32_t*)0xE000ED08)
void init(void) {
    enable_fpu();
    SCB_VTOR = 0x08000000;
    rcc_reset_clock_config();
    return;
}
