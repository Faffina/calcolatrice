#include <stdint.h>
#include <stdbool.h>
#include "mmio.h"
#include "defult_vector.h"
#define RCC_AHB1ENR   (*(volatile uint32_t*) 0x40023830)

int main(void) {
    show_code_once(0, 2);
    while(1) {
        show_code_once(0, 1);
    }
}
