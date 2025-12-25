#include "gpio.h"
#include <stdint.h>

void delay(uint32_t times) {
  for (uint32_t i = 0; i < times; i++) {
    __asm__ volatile("nop" ::: "memory");
  }
}

#define RCC_BASE 0x40021000UL
#define RCC_AHBENR (*(volatile uint32_t *)(RCC_BASE + 0x14U))

void main() {
    RCC_AHBENR |= (1U << 17);
    gpio_init_pin(A1, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_HIGH_SPEED, GPIO_NO_PULL_UP_DOWN);
    gpio_init_pin(A2, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_HIGH_SPEED, GPIO_NO_PULL_UP_DOWN);
    gpio_init_pin(A3, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_HIGH_SPEED, GPIO_NO_PULL_UP_DOWN);

    while (1) {
        gpio_toggle(A1);
        gpio_toggle(A2);
        gpio_toggle(A3);
        delay(100000);
    }
}
