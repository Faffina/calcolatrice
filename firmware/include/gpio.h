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

typedef enum {A = 0, B, C, D, E, F, G, H, I} gpio_port_name;

static gpio_port_t* const gpio_ports[] = {
    [A] = (gpio_port_t*) MM_GPIOA,
    [B] = (gpio_port_t*) MM_GPIOB,
    [C] = (gpio_port_t*) MM_GPIOC,
    [D] = (gpio_port_t*) MM_GPIOD,
    [E] = (gpio_port_t*) MM_GPIOE,
    [F] = (gpio_port_t*) MM_GPIOF,
    [G] = (gpio_port_t*) MM_GPIOG,
    [H] = (gpio_port_t*) MM_GPIOH,
    [I] = (gpio_port_t*) MM_GPIOI,
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
    AF0, 
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15,
} gpio_alternate_functions;

void gpio_init();
void gpio_init_pin(
        gpio_pin pin, 
        gpio_mode mode, 
        gpio_speed speed, 
        gpio_pull_up_down_state pull_state, 
        gpio_alternate_functions function
);

void write(gpio_pin pin, bool high);
bool read(gpio_pin pin);

#define A0  (gpio_pin){0, A}
#define A1  (gpio_pin){1, A}
#define A2  (gpio_pin){2, A}
#define A3  (gpio_pin){3, A}
#define A4  (gpio_pin){4, A}
#define A5  (gpio_pin){5, A}
#define A6  (gpio_pin){6, A}
#define A7  (gpio_pin){7, A}
#define A8  (gpio_pin){8, A}
#define A9  (gpio_pin){9, A}
#define A10 (gpio_pin){10, A}
#define A11 (gpio_pin){11, A}
#define A12 (gpio_pin){12, A}
#define A13 (gpio_pin){13, A}
#define A14 (gpio_pin){14, A}
#define A15 (gpio_pin){15, A}
#define B0  (gpio_pin){0, B}
#define B1  (gpio_pin){1, B}
#define B2  (gpio_pin){2, B}
#define B3  (gpio_pin){3, B}
#define B4  (gpio_pin){4, B}
#define B5  (gpio_pin){5, B}
#define B6  (gpio_pin){6, B}
#define B7  (gpio_pin){7, B}
#define B8  (gpio_pin){8, B}
#define B9  (gpio_pin){9, B}
#define B10 (gpio_pin){10, B}
#define B11 (gpio_pin){11, B}
#define B12 (gpio_pin){12, B}
#define B13 (gpio_pin){13, B}
#define B14 (gpio_pin){14, B}
#define B15 (gpio_pin){15, B}
#define C0  (gpio_pin){0, C}
#define C1  (gpio_pin){1, C}
#define C2  (gpio_pin){2, C}
#define C3  (gpio_pin){3, C}
#define C4  (gpio_pin){4, C}
#define C5  (gpio_pin){5, C}
#define C6  (gpio_pin){6, C}
#define C7  (gpio_pin){7, C}
#define C8  (gpio_pin){8, C}
#define C9  (gpio_pin){9, C}
#define C10 (gpio_pin){10, C}
#define C11 (gpio_pin){11, C}
#define C12 (gpio_pin){12, C}
#define C13 (gpio_pin){13, C}
#define C14 (gpio_pin){14, C}
#define C15 (gpio_pin){15, C}
#define D0  (gpio_pin){0, D}
#define D1  (gpio_pin){1, D}
#define D2  (gpio_pin){2, D}
#define D3  (gpio_pin){3, D}
#define D4  (gpio_pin){4, D}
#define D5  (gpio_pin){5, D}
#define D6  (gpio_pin){6, D}
#define D7  (gpio_pin){7, D}
#define D8  (gpio_pin){8, D}
#define D9  (gpio_pin){9, D}
#define D10 (gpio_pin){10, D}
#define D11 (gpio_pin){11, D}
#define D12 (gpio_pin){12, D}
#define D13 (gpio_pin){13, D}
#define D14 (gpio_pin){14, D}
#define D15 (gpio_pin){15, D}
#define E0  (gpio_pin){0, E}
#define E1  (gpio_pin){1, E}
#define E2  (gpio_pin){2, E}
#define E3  (gpio_pin){3, E}
#define E4  (gpio_pin){4, E}
#define E5  (gpio_pin){5, E}
#define E6  (gpio_pin){6, E}
#define E7  (gpio_pin){7, E}
#define E8  (gpio_pin){8, E}
#define E9  (gpio_pin){9, E}
#define E10 (gpio_pin){10, E}
#define E11 (gpio_pin){11, E}
#define E12 (gpio_pin){12, E}
#define E13 (gpio_pin){13, E}
#define E14 (gpio_pin){14, E}
#define E15 (gpio_pin){15, E}
#define F0  (gpio_pin){0, F}
#define F1  (gpio_pin){1, F}
#define F2  (gpio_pin){2, F}
#define F3  (gpio_pin){3, F}
#define F4  (gpio_pin){4, F}
#define F5  (gpio_pin){5, F}
#define F6  (gpio_pin){6, F}
#define F7  (gpio_pin){7, F}
#define F8  (gpio_pin){8, F}
#define F9  (gpio_pin){9, F}
#define F10 (gpio_pin){10, F}
#define F11 (gpio_pin){11, F}
#define F12 (gpio_pin){12, F}
#define F13 (gpio_pin){13, F}
#define F14 (gpio_pin){14, F}
#define F15 (gpio_pin){15, F}
#define G0  (gpio_pin){0, G}
#define G1  (gpio_pin){1, G}
#define G2  (gpio_pin){2, G}
#define G3  (gpio_pin){3, G}
#define G4  (gpio_pin){4, G}
#define G5  (gpio_pin){5, G}
#define G6  (gpio_pin){6, G}
#define G7  (gpio_pin){7, G}
#define G8  (gpio_pin){8, G}
#define G9  (gpio_pin){9, G}
#define G10 (gpio_pin){10, G}
#define G11 (gpio_pin){11, G}
#define G12 (gpio_pin){12, G}
#define G13 (gpio_pin){13, G}
#define G14 (gpio_pin){14, G}
#define G15 (gpio_pin){15, G}
#define H0  (gpio_pin){0, H}
#define H1  (gpio_pin){1, H}
#define H2  (gpio_pin){2, H}
#define H3  (gpio_pin){3, H}
#define H4  (gpio_pin){4, H}
#define H5  (gpio_pin){5, H}
#define H6  (gpio_pin){6, H}
#define H7  (gpio_pin){7, H}
#define H8  (gpio_pin){8, H}
#define H9  (gpio_pin){9, H}
#define H10 (gpio_pin){10, H}
#define H11 (gpio_pin){11, H}
#define H12 (gpio_pin){12, H}
#define H13 (gpio_pin){13, H}
#define H14 (gpio_pin){14, H}
#define H15 (gpio_pin){15, H}
#define I0  (gpio_pin){0, I}
#define I1  (gpio_pin){1, I}
#define I2  (gpio_pin){2, I}
#define I3  (gpio_pin){3, I}
#define I4  (gpio_pin){4, I}
#define I5  (gpio_pin){5, I}
#define I6  (gpio_pin){6, I}
#define I7  (gpio_pin){7, I}
#define I8  (gpio_pin){8, I}
#define I9  (gpio_pin){9, I}
#define I10 (gpio_pin){10, I}
#define I11 (gpio_pin){11, I}
#define I12 (gpio_pin){12, I}
#define I13 (gpio_pin){13, I}
#define I14 (gpio_pin){14, I}
#define I15 (gpio_pin){15, I}
