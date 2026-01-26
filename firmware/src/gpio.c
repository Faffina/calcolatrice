#include "gpio.h"

#define RCC_AHB1ENR   (*(volatile uint32_t*) 0x40023830)
void gpio_init(gpio_port_name name) {
    RCC_AHB1ENR |= (name + 1);
}
void gpio_init_pin(
        gpio_pin pin, 
        gpio_mode mode, 
        gpio_speed speed, 
        gpio_pull_up_down_state pull_state, 
        gpio_alternate_functions function
) {
    volatile gpio_port_t* port = gpio_ports[pin.port_name];
    u8 number = pin.number;

    port->moder &= ~(3 << (number * 2));
    port->moder |= mode << (number *2);

    port->ospeedr &= ~(3 << (number * 2));
    port->ospeedr |= speed << (number * 2);

    port->pupdr &= ~(3 << (number * 2));
    port->pupdr |= pull_state << (number * 2);

    if (number <= 7) {
        port->afrl &= ~(0xF << (number * 4));
        port->afrl |= function << (number * 4);
    } else {
        port->afrh &= ~(0xF << (number * 4));
        port->afrh |= function << (number * 4);
    }
}

void gpio_set(gpio_pin pin) {
    volatile gpio_port_t* port = gpio_ports[pin.port_name];
    u8 number = pin.number;
    port->bsrr = 1U << number;
}
void gpio_clear(gpio_pin pin) {
    volatile gpio_port_t* port = gpio_ports[pin.port_name];
    u8 number = pin.number;
    port->bsrr = 1U << (number + 16);
}
void gpio_toggle(gpio_pin pin) {
    volatile gpio_port_t* port = gpio_ports[pin.port_name];
    u8 number = pin.number;
    port->odr ^= 1 << number;
}
bool gpio_read(gpio_pin pin) {
    volatile gpio_port_t* port = gpio_ports[pin.port_name];
    u8 number = pin.number;
    return (port->idr & (1 << number)) > 0;
}
