#include "rcc.h"

volatile rcc_t* rcc = (volatile rcc_t*) MM_RCC;

void rcc_reset_clock_config() {
    rcc_enable_hse();
    while (!rcc_hse_is_ready());
    rcc_ahp_config(RCC_AHB_D1);
    rcc_apb_config(RCC_APB_D4, RCC_APB_D2);
    volatile u32* flash_acr = (volatile u32*) MM_FLASH_IR;
    *flash_acr =
    (5 << 0) |   
    (1 << 8) |  
    (1 << 9) | 
    (1 << 10);
    rcc_enable_pll(false);
    while (rcc_pll_is_ready());
    rcc_pll_config(168, 4, RCC_PLLP_2, 7, RCC_PLL_HSE);
    rcc_enable_pll(true);
    while(!rcc_pll_is_ready());
    rcc_set_stclk_src(RCC_STCLK_PLL);
    while(rcc_get_stclk_src() != RCC_STCLK_PLL);
}

// clock control
bool rcc_plli2s_is_ready(){
    return (rcc->cr & (1 << 27)) > 0;
}

bool rcc_pll_is_ready() {
    return (rcc->cr & (1 << 25)) > 0;
}

void rcc_enable_plli2s(bool state) {
    if (state) 
        rcc->cr |= (1 << 26);
    else
        rcc->cr &= ~(1 << 26);
}

void rcc_enable_pll(bool state) {
    if (state) 
        rcc->cr |= (1 << 24);
    else
        rcc->cr &= ~(1 << 24);
}

bool rcc_hse_is_ready() {
    return (rcc->cr & (1 << 17)) > 0;
}

void rcc_enable_hse(){
    rcc->cr |= (1 << 16);
}

bool rcc_is_his_ready() {
    return (rcc->cr & (1 << 1)) > 0;
}

void rcc_enable_his() {
    rcc->cr |= 1;
}

// pll config 
void rcc_pll_config(
        const u8 plln, 
        const u8 pllm, 
        const rcc_pll_pllp_t pllp, 
        const u8 pllq,
        const rcc_pll_src_t source
) {
    rcc->pllcfgr =
    (pllm) |
    (plln << 6) |
    (pllp << 16) |
    (source << 22) |
    (pllq << 24);

}

void rcc_apb_config(
        rcc_apb_prescaler_t low_speed,
        rcc_apb_prescaler_t high_speed
) {
    rcc->cfgr &= ~0xFC00;
    rcc->cfgr |= low_speed << 10;
    rcc->cfgr |= high_speed << 13;
}

void rcc_ahp_config(rcc_ahb_prescaler_t div) {
    rcc->cfgr &= ~0xF0;
    rcc->cfgr |= div << 4;
}

void rcc_set_stclk_src(rcc_stclk_src_t src) {
    rcc->cfgr &= ~0x3;
    rcc->cfgr |= src;
}

rcc_stclk_src_t rcc_get_stclk_src() {
    return (rcc->cfgr >> 2) & 0x3;
}
