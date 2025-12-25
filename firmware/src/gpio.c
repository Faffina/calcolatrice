#include "gpio.h"

void gpio_init_pin(
        gpio_pin pin, 
        gpio_port_mode mode, 
        gpio_output_type output, 
        gpio_speed_type speed, 
        gpio_pull_type pull
){
    gpio_ports[pin.port]->mode_r &= ~(3 << pin.number*2);
    gpio_ports[pin.port]->mode_r |= mode << pin.number*2;

    gpio_ports[pin.port]->output_type_r &= ~(1 << pin.number);
    gpio_ports[pin.port]->output_type_r |= output << pin.number;

    gpio_ports[pin.port]->speed_r &= ~(3 << pin.number*2);
    gpio_ports[pin.port]->speed_r |= speed << pin.number*2;

    gpio_ports[pin.port]->pull_up_down_r &= ~(3 << pin.number*2);
    gpio_ports[pin.port]->pull_up_down_r |= pull << pin.number*2;
}

void gpio_set(gpio_pin pin) {
    gpio_ports[pin.port]->bit_set_reset_r &= ~(1 << (pin.number + 16));
    gpio_ports[pin.port]->bit_set_reset_r |= 1 << pin.number;
}

void gpio_reset(gpio_pin pin) {
    gpio_ports[pin.port]->bit_set_reset_r &= ~(1 << pin.number);
    gpio_ports[pin.port]->bit_set_reset_r |= 1 << (pin.number + 16);
}

void gpio_toggle(gpio_pin pin) {
    gpio_ports[pin.port]->output_data_r ^= 1 << pin.number;
}

bool gpio_read(gpio_pin pin) {
    return gpio_ports[pin.port]->input_data_r &= 1 << pin.number > 0;
}

void gpio_set_altenate(gpio_pin pin, uint8_t number) {
    if (pin.number <= 7) {
        gpio_ports[pin.port]->alternate_function_low_r &= (0xf << pin.number*4);
        gpio_ports[pin.port]->alternate_function_low_r |= (number << pin.number*4);
    } else {
        gpio_ports[pin.port]->alternate_function_high_r &= (0xf << pin.number*4);
        gpio_ports[pin.port]->alternate_function_high_r |= (number << pin.number*4);
    }
}

void gpio_set_port_data(gpio_port_name name, uint16_t out){
    gpio_ports[name]->output_data_r = out;
}

uint16_t gpio_get_port_data(gpio_port_name name) {
    return gpio_ports[name]->input_data_r;
}
