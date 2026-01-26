#pragma once
#include "gpio.h"
void delay(u32 time) {
    for (; time > 0; time--) {
        __asm__ volatile ("nop");
    }
}

void blink(u32 first, u32 second, gpio_pin led1, gpio_pin led2) {

    gpio_clear(led1);
    gpio_clear(led2);
    delay(1000000);
    gpio_set(led1);
    gpio_set(led2);
    delay(1000000);

    for (; first > 0; first --){
        gpio_clear(led1);
        delay(1000000);
        gpio_set(led1);
        delay(1000000);
    }

    for (; second > 0; second--){
        gpio_clear(led2);
        delay(1000000);
        gpio_set(led2);
        delay(1000000);
    }

    gpio_clear(led1);
    gpio_clear(led2);
    delay(1000000);
    gpio_set(led1);
    gpio_set(led2);
    delay(1000000);
}

void show_code(u32 a, u32 b) {
    gpio_pin led1 = gpio_get_pin(GPIO_A, 6);
    gpio_pin led2 = gpio_get_pin(GPIO_A, 7);
    gpio_init(GPIO_A);
    gpio_init_pin(led1, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW, GPIO_NO_PULL, GPIO_AF0);
    gpio_init_pin(led2, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW, GPIO_NO_PULL, GPIO_AF0);
    while (1) 
        blink(a, b, led1, led2);
}

void show_code_once(u32 a, u32 b) {
    gpio_pin led1 = gpio_get_pin(GPIO_A, 6);
    gpio_pin led2 = gpio_get_pin(GPIO_A, 7);
    gpio_init(GPIO_A);
    gpio_init_pin(led1, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW, GPIO_NO_PULL, GPIO_AF0);
    gpio_init_pin(led2, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW, GPIO_NO_PULL, GPIO_AF0);
    blink(a, b, led1, led2);
}

void NMI_Handler(void)                    { show_code( 1,  1); }
void HardFault_Handler(void)              { show_code( 1,  2); }
void MemManage_Handler(void)              { show_code( 1,  3); }
void BusFault_Handler(void)               { show_code( 1,  4); }
void UsageFault_Handler(void)             { show_code( 1,  5); }
void SVC_Handler(void)                    { show_code( 1,  6); }
void DebugMon_Handler(void)               { show_code( 1,  7); }
void PendSV_Handler(void)                 { show_code( 1,  8); }
void SysTick_Handler(void)                { show_code( 1,  9); }
void WWDG_IRQHandler(void)                { show_code( 1, 10); }
void PVD_IRQHandler(void)                 { show_code( 2,  1); }
void TAMP_STAMP_IRQHandler(void)          { show_code( 2,  2); }
void RTC_WKUP_IRQHandler(void)            { show_code( 2,  3); }
void FLASH_IRQHandler(void)               { show_code( 2,  4); }
void RCC_IRQHandler(void)                 { show_code( 2,  5); }
void EXTI0_IRQHandler(void)               { show_code( 2,  6); }
void EXTI1_IRQHandler(void)               { show_code( 2,  7); }
void EXTI2_IRQHandler(void)               { show_code( 2,  8); }
void EXTI3_IRQHandler(void)               { show_code( 2,  9); }
void EXTI4_IRQHandler(void)               { show_code( 2, 10); }
void DMA1_Stream0_IRQHandler(void)        { show_code( 3,  1); }
void DMA1_Stream1_IRQHandler(void)        { show_code( 3,  2); }
void DMA1_Stream2_IRQHandler(void)        { show_code( 3,  3); }
void DMA1_Stream3_IRQHandler(void)        { show_code( 3,  4); }
void DMA1_Stream4_IRQHandler(void)        { show_code( 3,  5); }
void DMA1_Stream5_IRQHandler(void)        { show_code( 3,  6); }
void DMA1_Stream6_IRQHandler(void)        { show_code( 3,  7); }
void ADC_IRQHandler(void)                 { show_code( 3,  8); }
void CAN1_TX_IRQHandler(void)             { show_code( 3,  9); }
void CAN1_RX0_IRQHandler(void)            { show_code( 3, 10); }
void CAN1_RX1_IRQHandler(void)            { show_code( 4,  1); }
void CAN1_SCE_IRQHandler(void)            { show_code( 4,  2); }
void EXTI9_5_IRQHandler(void)             { show_code( 4,  3); }
void TIM1_BRK_TIM9_IRQHandler(void)       { show_code( 4,  4); }
void TIM1_UP_TIM10_IRQHandler(void)       { show_code( 4,  5); }
void TIM1_TRG_COM_TIM11_IRQHandler(void)  { show_code( 4,  6); }
void TIM1_CC_IRQHandler(void)             { show_code( 4,  7); }
void TIM2_IRQHandler(void)                { show_code( 4,  8); }
void TIM3_IRQHandler(void)                { show_code( 4,  9); }
void TIM4_IRQHandler(void)                { show_code( 4, 10); }
void I2C1_EV_IRQHandler(void)             { show_code( 5,  1); }
void I2C1_ER_IRQHandler(void)             { show_code( 5,  2); }
void I2C2_EV_IRQHandler(void)             { show_code( 5,  3); }
void I2C2_ER_IRQHandler(void)             { show_code( 5,  4); }
void SPI1_IRQHandler(void)                { show_code( 5,  5); }
void SPI2_IRQHandler(void)                { show_code( 5,  6); }
void USART1_IRQHandler(void)              { show_code( 5,  7); }
void USART2_IRQHandler(void)              { show_code( 5,  8); }
void USART3_IRQHandler(void)              { show_code( 5,  9); }
void EXTI15_10_IRQHandler(void)           { show_code( 5, 10); }
void RTC_Alarm_IRQHandler(void)           { show_code( 6,  1); }
void OTG_FS_WKUP_IRQHandler(void)         { show_code( 6,  2); }
void TIM8_BRK_TIM12_IRQHandler(void)      { show_code( 6,  3); }
void TIM8_UP_TIM13_IRQHandler(void)       { show_code( 6,  4); }
void TIM8_TRG_COM_TIM14_IRQHandler(void)  { show_code( 6,  5); }
void TIM8_CC_IRQHandler(void)             { show_code( 6,  6); }
void DMA1_Stream7_IRQHandler(void)        { show_code( 6,  7); }
void FSMC_IRQHandler(void)                { show_code( 6,  8); }
void SDIO_IRQHandler(void)                { show_code( 6,  9); }
void TIM5_IRQHandler(void)                { show_code( 6, 10); }
void SPI3_IRQHandler(void)                { show_code( 7,  1); }
void UART4_IRQHandler(void)               { show_code( 7,  2); }
void UART5_IRQHandler(void)               { show_code( 7,  3); }
void TIM6_DAC_IRQHandler(void)            { show_code( 7,  4); }
void TIM7_IRQHandler(void)                { show_code( 7,  5); }
void DMA2_Stream0_IRQHandler(void)        { show_code( 7,  6); }
void DMA2_Stream1_IRQHandler(void)        { show_code( 7,  7); }
void DMA2_Stream2_IRQHandler(void)        { show_code( 7,  8); }
void DMA2_Stream3_IRQHandler(void)        { show_code( 7,  9); }
void DMA2_Stream4_IRQHandler(void)        { show_code( 7, 10); }
void ETH_IRQHandler(void)                 { show_code( 8,  1); }
void ETH_WKUP_IRQHandler(void)            { show_code( 8,  2); }
void CAN2_TX_IRQHandler(void)             { show_code( 8,  3); }
void CAN2_RX0_IRQHandler(void)            { show_code( 8,  4); }
void CAN2_RX1_IRQHandler(void)            { show_code( 8,  5); }
void CAN2_SCE_IRQHandler(void)            { show_code( 8,  6); }
void OTG_FS_IRQHandler(void)              { show_code( 8,  7); }
void DMA2_Stream5_IRQHandler(void)        { show_code( 8,  8); }
void DMA2_Stream6_IRQHandler(void)        { show_code( 8,  9); }
void DMA2_Stream7_IRQHandler(void)        { show_code( 8, 10); }
void USART6_IRQHandler(void)              { show_code( 9,  1); }
void I2C3_EV_IRQHandler(void)             { show_code( 9,  2); }
void I2C3_ER_IRQHandler(void)             { show_code( 9,  3); }
void OTG_HS_EP1_OUT_IRQHandler(void)      { show_code( 9,  4); }
void OTG_HS_EP1_IN_IRQHandler(void)       { show_code( 9,  5); }
void OTG_HS_WKUP_IRQHandler(void)         { show_code( 9,  6); }
void OTG_HS_IRQHandler(void)              { show_code( 9,  7); }
void DCMI_IRQHandler(void)                { show_code( 9,  8); }
void CRYP_IRQHandler(void)                { show_code( 9,  9); }
void HASH_RNG_IRQHandler(void)            { show_code( 9, 10); }
void FPU_IRQHandler(void)                 { show_code(10,  1); }
