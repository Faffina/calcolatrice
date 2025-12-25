#include <stdint.h>

#define RCC_AHB1ENR   (*(volatile uint32_t*)0x40023830)
#define GPIOA_MODER   (*(volatile uint32_t*)0x40020000)
#define GPIOA_ODR     (*(volatile uint32_t*)0x40020014)

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm volatile ("nop");
    }
}

int main(void)
{
    RCC_AHB1ENR |= (1 << 0);

    GPIOA_MODER &= ~((3 << (6 * 2)) | (3 << (7 * 2)));
    GPIOA_MODER |=  ((1 << (6 * 2)) | (1 << (7 * 2)));

    while (1)
    {
        GPIOA_ODR ^= (1 << 6);
        GPIOA_ODR ^= (1 << 7);

        delay(500000);
    }
}
