#include "rcc.h"

#define SCB_VTOR (*(volatile uint32_t*)0xE000ED08)
#define SCB_CPACR   (*(volatile unsigned int *)0xE000ED88)

static inline void enable_fpu(void)
{
    SCB_CPACR |= (0xF << 20);

    __asm volatile ("dsb");
    __asm volatile ("isb");
    return;
}

void systemInit (void) {
    SCB_VTOR = 0x08000000;
    enable_fpu();
    rcc_reset_clock_config();
    return;
}
