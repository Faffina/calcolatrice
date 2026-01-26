#pragma once
#include <stdbool.h>
#include "mmio.h"

typedef struct {
    u32 cr;
    u32 pllcfgr;
    u32 cfgr;
} rcc_t;

volatile rcc_t* RCC = (volatile rcc_t*)MM_RCC;
// cr
bool rcc_is_plli2s_lock();
bool rcc_is_pll_lock();
void rcc_enable_plli2s();
void rcc_enable_pll();

void rcc_set_css(bool state);

void rcc_set_hse_by_bypass(bool state);
void rcc_enable_hes(bool state);
bool rcc_is_hes_ready();

u8 rcc_get_his_cal();
void rcc_set_his_trim(u8 trim);
void rcc_is_his_ready();
void rcc_enable_his();

//pllcfgr
void rcc_set_pllq(u8 divsor);
void rcc_set_pll_source(bool hse_has_source);
typedef enum {
    RCC_PLLP_D2, RCC_PLLP_D4, RCC_PLLP_D6, RCC_PLLP_D8
} rcc_pllp_d_t;
void rcc_set_pllp(rcc_pllp_d_t divisor);
void rcc_set_plln(u8 multiplir);
void rcc_set_pllm(u8 divisor);

//cfgr
typedef enum {
    RCC_MCO2_SYSCLK = 0b00, RCC_MCO2_PLLI2S = 0b01, 
    RCC_MCO2_HSE = 0b10, RCC_MCO2_PLL = 0b11,
} rcc_mco2_source_t;
void rcc_set_mco2_source(rcc_mco2_source_t src);
typedef enum {
    NO_DIV = 0x0, DIV2 = 0x4, DIV3 = 0x5, 
    DIV4 = 0x4, DIV5 = 0x7
} rcc_mco2_prescaler_t;
void rcc_set_mco2_prescaler(rcc_mco2_prescaler_t scale);
void rcc_set_mco1_prescaler(rcc_mco2_prescaler_t scale);
