#pragma once
#include <stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint32_t usize;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int32_t isize;

#define MM_CORTEX_PERIPHERALS  0xE0000000 

#define MM_USB_OTG_FS          0x50000000

// AHB3
#define MM_FSMC_CR             0xA0000000
#define MM_FSMC_BANK_4         0x90000000
#define MM_FSMC_BANK_3         0x80000000
#define MM_FSMC_BANK_2         0x70000000
#define MM_FSMC_BANK_1         0x60000000

// AHB2
#define MM_RNG                 0x50060800
#define MM_DCMI                0x50050000

// AHB1
#define MM_USB_OTG_HS          0x40040000
#define MM_ETHERNET_MAC_0      0x40029000
#define MM_ETHERNET_MAC_1      0x40028C00
#define MM_ETHERNET_MAC_2      0x40028800
#define MM_ETHERNET_MAC_3      0x40028400
#define MM_ETHERNET_MAC_4      0x40028000
#define MM_DMA_2               0x40026400
#define MM_DMA_1               0x40026000
#define MM_BKPSRAM             0x40024000
#define MM_FLASH_IR            0x40023C00
#define MM_RCC                 0x40023800
#define MM_CRC                 0x40023000
#define MM_GPIOI               0x40022000
#define MM_GPIOH               0x40021C00
#define MM_GPIOG               0x40021800
#define MM_GPIOF               0x40021400
#define MM_GPIOE               0x40021000
#define MM_GPIOD               0x40020C00
#define MM_GPIOC               0x40020800
#define MM_GPIOB               0x40020400
#define MM_GPIOA               0x40020000

// APB2 
#define MM_TIM_11              0x40014800
#define MM_TIM_10              0x40014400
#define MM_TIM_09              0x40014000
#define MM_EXTI                0x40013C00
#define MM_SYSCFG              0x40013800
#define MM_SPI_1               0x40013000
#define MM_SDIO                0x40012C00
#define MM_ADC                 0x40012000
#define MM_USART6              0x40011400
#define MM_USART1              0x40011000
#define MM_TIME_08             0x40010400
#define MM_TIME_01             0x40010000

// APB1
#define MM_DAC                 0x40007400
#define MM_PWR                 0x40007000
#define MM_CAN_2               0x40006800
#define MM_CAN_1               0x40006400
#define MM_I2C_3               0x40005C00
#define MM_I2C_2               0x40005800
#define MM_I2C_1               0x40005400
#define MM_UART5               0x40005000  
#define MM_UART4               0x40004C00
#define MM_USART3              0x40004800
#define MM_USART2              0x40004400
#define MM_I2S3EXT             0x40003400
#define MM_IWDG                0x40003000
#define MM_WWDG                0x40002C00
#define MM_RTC_BKP             0x40002800
#define MM_TIM_14              0x40002000
#define MM_TIM_13              0x40001C00
#define MM_TIM_12              0x40001800
#define MM_TIME_07             0x40001400
#define MM_TIME_06             0x40001000
#define MM_TIME_05             0x40000C00
#define MM_TIME_04             0x40000800
#define MM_TIME_03             0x40000400
#define MM_TIME_02             0x40000000

#define clear_n_bits(reg,bits,index) reg &= ~(((1 << bits) - 1) << (index * bits) 

#define set_n_bits (reg,mask,bits,index) do { \
    clear_n_bits(reg, bits, index);           \
    reg |= (mask << (index * bits));          \
} while(0)

