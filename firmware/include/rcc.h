#pragma once
#include <stdbool.h>
#include "mmio.h"

typedef struct {
    volatile u32 cr;
    volatile u32 pllcfgr;
    volatile u32 cfgr;
    volatile u32 cir;
    volatile u32 ahb1rstr;
    volatile u32 ahb2rstr;
    volatile u32 apb1rstr;
    volatile u32 apb2rstr;
    volatile u32 __reseved1__;
    volatile u32 __reseved2__;
    volatile u32 ahb1enr;
    volatile u32 ahb2enr;
    volatile u32 ahb3enr;
    volatile u32 __reseved3__;
    volatile u32 apb1enr;
    volatile u32 apb2enr;
    volatile u32 __reseved4__;
    volatile u32 __reseved5__;
    volatile u32 ahb1lpenr;
    volatile u32 ahb2lpenr;
    volatile u32 ahb3lpenr;
    volatile u32 __reseved6__;
    volatile u32 apb1lpenr;
    volatile u32 apb2lpenr;
    volatile u32 __reseved7__;
    volatile u32 __reseved8__;
    volatile u32 bdcr;
    volatile u32 csr;
    volatile u32 __reseved9__;
    volatile u32 __reseved10__;
    volatile u32 sscgr;
    volatile u32 plli2scfgr;
} rcc_t;

extern volatile rcc_t* rcc;
void rcc_reset_clock_config();

// clock control
bool rcc_plli2s_is_ready();
bool rcc_pll_is_ready();
void rcc_enable_plli2s(bool state);
void rcc_enable_pll(bool state);

void rcc_enable_clock_security();
void rcc_enable_hse_bypass();
void rcc_enable_hse();
bool rcc_hse_is_ready();

u8 rcc_get_his_calibration();
void rcc_set_his_trim(u8 trim);
bool rcc_is_his_ready();
void rcc_enable_his();

// pll config 
typedef enum {
    RCC_PLL_HIS = 0, RCC_PLL_HSE = 1
} rcc_pll_src_t;

typedef enum {
    RCC_PLLP_2 = 0b00,
    RCC_PLLP_4 = 0b01,
    RCC_PLLP_6 = 0b10,
    RCC_PLLP_8 = 0b11,
} rcc_pll_pllp_t;

void rcc_pll_config(
        const u8 plln, 
        const u8 pllm, 
        const rcc_pll_pllp_t pllp, 
        const u8 pllq,
        const rcc_pll_src_t source
);

// cfgr

typedef enum {
    RCC_MCO1_HSI = 0b00,
    RCC_MCO1_LSE = 0b01,
    RCC_MCO1_HSE = 0b10,
    RCC_MCO1_PLL = 0b11,
} rcc_mco1_src_t;

typedef enum {
    RCC_MCO2_SYSCLK = 0b00,
    RCC_MCO2_PLLI2S = 0b01,
    RCC_MCO2_HSE    = 0b10,
    RCC_MCO2_PLL    = 0b11
} rcc_mco2_src_t;

typedef enum {
    RCC_MCO2_D1 = 0b000,
    RCC_MCO2_D2 = 0b100,
    RCC_MCO2_D3 = 0b101,
    RCC_MCO2_D4 = 0b110,
    RCC_MCO2_D5 = 0b111,
} rcc_mco_prescaler_t;

void rcc_mco1_config(
        rcc_mco1_src_t src,
        rcc_mco_prescaler_t div
);

void rcc_mco2_config(
        rcc_mco2_src_t src, 
        rcc_mco_prescaler_t div
);

typedef enum {
    RCC_I2S_PLLI2S = 0,
    RCC_I2S_EXTERN = 1,
} rcc_i2s_src_t;

void rcc_i2s_config(rcc_i2s_src_t src);

void rcc_rtc_config(u8 div);

typedef enum {
    RCC_APB_D1  = 0b000,
    RCC_APB_D2  = 0b100,
    RCC_APB_D4  = 0b101,
    RCC_APB_D8  = 0b110,
    RCC_APB_D16 = 0b111,
} rcc_apb_prescaler_t;

void rcc_apb_config(
        rcc_apb_prescaler_t low_speed,
        rcc_apb_prescaler_t high_speed
);

typedef enum {
    RCC_AHB_D1   = 0x0,
    RCC_AHB_D2   = 0x8,
    RCC_AHB_D4   = 0x9,
    RCC_AHB_D8   = 0xA,
    RCC_AHB_D16  = 0xB,
    RCC_AHB_D64  = 0xC,
    RCC_AHB_D128 = 0xD,
    RCC_AHB_D256 = 0xE,
    RCC_AHB_D512 = 0xF,
} rcc_ahb_prescaler_t;

void rcc_ahp_config(rcc_ahb_prescaler_t div);

typedef enum {
    RCC_STCLK_HSI = 0b00,
    RCC_STCLK_HSE = 0b01,
    RCC_STCLK_PLL = 0b10,
} rcc_stclk_src_t;

void rcc_set_stclk_src(rcc_stclk_src_t src);
rcc_stclk_src_t rcc_get_stclk_src();
