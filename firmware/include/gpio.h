#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef enum {A, B, C, D, E, F} gpio_port_name;
typedef enum {GPIO_INPUT = 0b00, GPIO_OUTPUT = 0b01, GPIO_ALTERNATE_FUNC = 0b10, GPIO_ANALOG = 0b11} gpio_port_mode;
typedef enum {GPIO_PUSH_PULL = 0, GPIO_OPEN_DRAIN = 1} gpio_output_type;
typedef enum {GPIO_LOW_SPEED = 0b00, GPIO_MEDIUM_SPEED = 0b01, GPIO_HIGH_SPEED = 0b11} gpio_speed_type;
typedef enum {GPIO_NO_PULL_UP_DOWN = 0b00, GPIO_PULL_UP = 0b01, GPIO_PULL_DOWN = 0b10} gpio_pull_type;

typedef struct {
     volatile uint32_t mode_r;
     volatile uint16_t output_type_r;
     uint16_t _reservd0;
     volatile uint32_t speed_r;
     volatile uint32_t pull_up_down_r;
     volatile uint16_t input_data_r;
     uint16_t _reservd1;
     volatile uint16_t output_data_r;
     uint16_t _reservd2;
     volatile uint32_t bit_set_reset_r;
     volatile uint32_t lock_r;
     volatile uint32_t alternate_function_low_r;
     volatile uint32_t alternate_function_high_r;
     volatile uint16_t bit_reset_r;
     uint16_t _reservd3;
} gpio_port;

typedef struct { 
    gpio_port_name port: 4;
    uint8_t number: 4;
} gpio_pin;

static volatile gpio_port* gpio_ports[] = { 
    [A] = (volatile gpio_port*)0x48000000,
    [B] = (volatile gpio_port*)0x48000400,
    [C] = (volatile gpio_port*)0x48000800,
    [D] = (volatile gpio_port*)0x48000C00,
    [E] = (volatile gpio_port*)0x48001000,
    [F] = (volatile gpio_port*)0x48001400,
};

void gpio_init_pin(
        gpio_pin pin, 
        gpio_port_mode mode, 
        gpio_output_type output, 
        gpio_speed_type speed, 
        gpio_pull_type pull
);

void gpio_set(gpio_pin pin);
void gpio_reset(gpio_pin pin);
void gpio_toggle(gpio_pin pin);
bool gpio_read(gpio_pin pin);
void gpio_set_altenate(gpio_pin pin, uint8_t number);

void gpio_set_port_data(gpio_port_name name, uint16_t out);
uint16_t gpio_get_port_data(gpio_port_name name);


#define A0  (gpio_pin) {A,  0}
#define A1  (gpio_pin) {A,  1}
#define A2  (gpio_pin) {A,  2}
#define A3  (gpio_pin) {A,  3}
#define A4  (gpio_pin) {A,  4}
#define A5  (gpio_pin) {A,  5}
#define A6  (gpio_pin) {A,  6}
#define A7  (gpio_pin) {A,  7}
#define A8  (gpio_pin) {A,  8}
#define A9  (gpio_pin) {A,  9}
#define A10 (gpio_pin) {A, 10}
#define A11 (gpio_pin) {A, 11}
#define A12 (gpio_pin) {A, 12}
#define A13 (gpio_pin) {A, 13}
#define A14 (gpio_pin) {A, 14}
#define A15 (gpio_pin) {A, 15}
#define B0  (gpio_pin) {B,  0}
#define B1  (gpio_pin) {B,  1}
#define B2  (gpio_pin) {B,  2}
#define B3  (gpio_pin) {B,  3}
#define B4  (gpio_pin) {B,  4}
#define B5  (gpio_pin) {B,  5}
#define B6  (gpio_pin) {B,  6}
#define B7  (gpio_pin) {B,  7}
#define B8  (gpio_pin) {B,  8}
#define B9  (gpio_pin) {B,  9}
#define B10 (gpio_pin) {B, 10}
#define B11 (gpio_pin) {B, 11}
#define B12 (gpio_pin) {B, 12}
#define B13 (gpio_pin) {B, 13}
#define B14 (gpio_pin) {B, 14}
#define B15 (gpio_pin) {B, 15}
#define C13 (gpio_pin) {C, 13}
#define C14 (gpio_pin) {C, 14}
#define C15 (gpio_pin) {C, 15}
#define F0  (gpio_pin) {F,  0}
#define F1  (gpio_pin) {F,  1}
