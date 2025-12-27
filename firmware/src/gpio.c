#include "gpio.h"

void gpio_init() {}
void gpio_init_pin(
        gpio_pin pin, 
        gpio_mode mode, 
        gpio_speed speed, 
        gpio_pull_up_down_state pull_state, 
        gpio_alternate_functions function
) {}

void write(gpio_pin pin, bool high) {}
bool read(gpio_pin pin) {}
