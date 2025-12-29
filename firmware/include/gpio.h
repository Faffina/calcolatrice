#pragma once
#include "mmio.h"
#include <stdbool.h>

typedef struct {
    u32 moder;
    u32 otyper;
    u32 ospeedr;
    u32 pupdr;
    u32 idr;
    u32 ord;
    u32 bsrr;
    u32 lckr;
    u32 afrl;
    u32 afrh;
} gpio_port_t;

typedef enum {
    GPIO_A, 
    GPIO_B, 
    GPIO_C, 
    GPIO_D,
    GPIO_E, 
    GPIO_F, 
    GPIO_G, 
    GPIO_H,
    GPIO_I
} gpio_port_name;

static volatile gpio_port_t* const gpio_ports[] = {
    [GPIO_A] = (volatile gpio_port_t*) MM_GPIOA,
    [GPIO_B] = (volatile gpio_port_t*) MM_GPIOB,
    [GPIO_C] = (volatile gpio_port_t*) MM_GPIOC,
    [GPIO_D] = (volatile gpio_port_t*) MM_GPIOD,
    [GPIO_E] = (volatile gpio_port_t*) MM_GPIOE,
    [GPIO_F] = (volatile gpio_port_t*) MM_GPIOF,
    [GPIO_G] = (volatile gpio_port_t*) MM_GPIOG,
    [GPIO_H] = (volatile gpio_port_t*) MM_GPIOH,
    [GPIO_I] = (volatile gpio_port_t*) MM_GPIOI,
};

typedef struct {
    u8 number;
    gpio_port_name port_name;
} gpio_pin;

typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_ALTERNATE = 2,
    GPIO_MODE_ANALOG = 3,
} gpio_mode;

typedef enum {
    GPIO_OUTPUT_PUSH_PULL = 0,
    GPIO_OUTPUT_OPEN_DRAIN = 1,
} gpio_output_type;

typedef enum {
    GPIO_SPEED_LOW = 0,
    GPIO_SPEED_MEDIUM = 1,
    GPIO_SPEED_HIGH = 2,
    GPIO_SPEED_VERY_HIGH = 3,
} gpio_speed;

typedef enum {
    gpio_no_pull = 0,
    gpio_pull_up = 1,
    gpio_pull_donw = 2,
} gpio_pull_up_down_state;

typedef enum {
    GPIO_AF0, 
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15,
} gpio_alternate_functions;

#define gpio_get_pin(port, n) (gpio_pin) {.port_name = port, .number = n}

void gpio_init(gpio_port_name name);
void gpio_init_pin(
        gpio_pin pin, 
        gpio_mode mode, 
        gpio_speed speed, 
        gpio_pull_up_down_state pull_state, 
        gpio_alternate_functions function
);
void gpio_write(gpio_pin pin, bool high);
void gpio_set(gpio_pin pin);
void gpio_clear(gpio_pin pin);
void gpio_toggle(gpio_pin pin);
bool gpio_read(gpio_pin pin);
