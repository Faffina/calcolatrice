#include <stdint.h>
#include "gpio.h"
#include "mmio.h"
#include <stdbool.h>

#define RCC_AHB1ENR   (*(volatile uint32_t*) 0x40023830)

void delay(u32 time) {
    for (; time > 0; time--) {
        __asm__ volatile ("nop");
    }
}

int main(void) {
    RCC_AHB1ENR |= 1;
    gpio_pin led1 = gpio_get_pin(GPIO_A, 7);
    gpio_pin led2 = gpio_get_pin(GPIO_A, 6);
    gpio_init_pin(led1, GPIO_MODE_OUTPUT, GPIO_SPEED_VERY_HIGH, GPIO_NO_PULL, GPIO_AF0);
    gpio_init_pin(led2, GPIO_MODE_OUTPUT, GPIO_SPEED_VERY_HIGH, GPIO_NO_PULL, GPIO_AF0);
    gpio_toggle(led1);

    while(1) {
        gpio_toggle(led1);
        gpio_toggle(led2);
        delay(1000000);
    }
}
