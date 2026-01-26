#include <stdint.h>
#include "gpio.h"
#include <stdbool.h>
#include "mmio.h"
#include "defult_vector.h"
#define RCC_AHB1ENR   (*(volatile uint32_t*) 0x40023830)

int main(void) {
    volatile u32* rcc_cr = (volatile u32*) MM_RCC;
    show_code_once(0, 2);
    *rcc_cr |= 1 << 16;
    while(1) {
        if((*rcc_cr & (1 << 17)) > 0) {
            show_code_once(0, 1);
        }
    }
}
