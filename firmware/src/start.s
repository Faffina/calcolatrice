.syntax unified
.cpu cortex-m4
.fpu fpv4-sp-d16
.thumb

.extern _stack_start 
.extern _data_start
.extern _data_end
.extern _data_start_flash
.extern _bss_start
.extern _bss_end
.extern systemInit
.extern main

.section .text.start, "a", %progbits
.thumb_func 
.global start 
start:
    ldr r0, =_stack_start
    mov sp, r0
    ldr r0, =_data_start
    ldr r1, =_data_end
    ldr r2, =_data_start_flash
data_loop:
    cmp r0, r1
    bhs data_copy_done
    ldr r3, [r2]
    str r3, [r0]
    adds r0, #4
    adds r2, #4
    b data_loop
data_copy_done:
    ldr r0, =_bss_start
    ldr r1, =_bss_end
    movs r2, #0
bss_loop:
    cmp r0, r1
    bhs bss_init_done
    str r2, [r0]
    adds r0, #4
    b bss_loop
bss_init_done:
    bl systemInit
    bl main
loop:
    b loop

.section .text.default_handle,"ax",%progbits
.global default_handle
default_handle:
    b default_handle

.section .vectors, "a", %progbits
.align 2
.global g_Vectors
g_Vectors:
  .word _stack_start
  .word start
  .word NMI_Handler
  .word HardFault_Handler
  .word MemManage_Handler
  .word BusFault_Handler
  .word UsageFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word DebugMon_Handler
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word WWDG_IRQHandler
  .word PVD_IRQHandler
  .word TAMP_STAMP_IRQHandler
  .word RTC_WKUP_IRQHandler
  .word FLASH_IRQHandler
  .word RCC_IRQHandler
  .word EXTI0_IRQHandler
  .word EXTI1_IRQHandler
  .word EXTI2_IRQHandler
  .word EXTI3_IRQHandler
  .word EXTI4_IRQHandler
  .word DMA1_Stream0_IRQHandler
  .word DMA1_Stream1_IRQHandler
  .word DMA1_Stream2_IRQHandler
  .word DMA1_Stream3_IRQHandler
  .word DMA1_Stream4_IRQHandler
  .word DMA1_Stream5_IRQHandler
  .word DMA1_Stream6_IRQHandler
  .word ADC_IRQHandler
  .word CAN1_TX_IRQHandler
  .word CAN1_RX0_IRQHandler
  .word CAN1_RX1_IRQHandler
  .word CAN1_SCE_IRQHandler
  .word EXTI9_5_IRQHandler
  .word TIM1_BRK_TIM9_IRQHandler
  .word TIM1_UP_TIM10_IRQHandler
  .word TIM1_TRG_COM_TIM11_IRQHandler
  .word TIM1_CC_IRQHandler
  .word TIM2_IRQHandler
  .word TIM3_IRQHandler
  .word TIM4_IRQHandler
  .word I2C1_EV_IRQHandler
  .word I2C1_ER_IRQHandler
  .word I2C2_EV_IRQHandler
  .word I2C2_ER_IRQHandler
  .word SPI1_IRQHandler
  .word SPI2_IRQHandler
  .word USART1_IRQHandler
  .word USART2_IRQHandler
  .word USART3_IRQHandler
  .word EXTI15_10_IRQHandler
  .word RTC_Alarm_IRQHandler
  .word OTG_FS_WKUP_IRQHandler
  .word TIM8_BRK_TIM12_IRQHandler
  .word TIM8_UP_TIM13_IRQHandler
  .word TIM8_TRG_COM_TIM14_IRQHandler
  .word TIM8_CC_IRQHandler
  .word DMA1_Stream7_IRQHandler
  .word FSMC_IRQHandler
  .word SDIO_IRQHandler
  .word TIM5_IRQHandler
  .word SPI3_IRQHandler
  .word UART4_IRQHandler
  .word UART5_IRQHandler
  .word TIM6_DAC_IRQHandler
  .word TIM7_IRQHandler
  .word DMA2_Stream0_IRQHandler
  .word DMA2_Stream1_IRQHandler
  .word DMA2_Stream2_IRQHandler
  .word DMA2_Stream3_IRQHandler
  .word DMA2_Stream4_IRQHandler
  .word ETH_IRQHandler
  .word ETH_WKUP_IRQHandler
  .word CAN2_TX_IRQHandler
  .word CAN2_RX0_IRQHandler
  .word CAN2_RX1_IRQHandler
  .word CAN2_SCE_IRQHandler
  .word OTG_FS_IRQHandler
  .word DMA2_Stream5_IRQHandler
  .word DMA2_Stream6_IRQHandler
  .word DMA2_Stream7_IRQHandler
  .word USART6_IRQHandler
  .word I2C3_EV_IRQHandler
  .word I2C3_ER_IRQHandler
  .word OTG_HS_EP1_OUT_IRQHandler
  .word OTG_HS_EP1_IN_IRQHandler
  .word OTG_HS_WKUP_IRQHandler
  .word OTG_HS_IRQHandler
  .word DCMI_IRQHandler
  .word CRYP_IRQHandler
  .word HASH_RNG_IRQHandler
  .word FPU_IRQHandler

.weak NMI_Handler
.thumb_set NMI_Handler, default_handle
.weak HardFault_Handler
.thumb_set HardFault_Handler, default_handle
.weak MemManage_Handler
.thumb_set MemManage_Handler, default_handle
.weak BusFault_Handler
.thumb_set BusFault_Handler, default_handle
.weak UsageFault_Handler
.thumb_set UsageFault_Handler, default_handle
.weak SVC_Handler
.thumb_set SVC_Handler, default_handle
.weak DebugMon_Handler
.thumb_set DebugMon_Handler, default_handle
.weak PendSV_Handler
.thumb_set PendSV_Handler, default_handle
.weak SysTick_Handler
.thumb_set SysTick_Handler, default_handle
.weak WWDG_IRQHandler
.thumb_set WWDG_IRQHandler, default_handle
.weak PVD_IRQHandler
.thumb_set PVD_IRQHandler, default_handle
.weak TAMP_STAMP_IRQHandler
.thumb_set TAMP_STAMP_IRQHandler, default_handle
.weak RTC_WKUP_IRQHandler
.thumb_set RTC_WKUP_IRQHandler, default_handle
.weak FLASH_IRQHandler
.thumb_set FLASH_IRQHandler, default_handle
.weak RCC_IRQHandler
.thumb_set RCC_IRQHandler, default_handle
.weak EXTI0_IRQHandler
.thumb_set EXTI0_IRQHandler, default_handle
.weak EXTI1_IRQHandler
.thumb_set EXTI1_IRQHandler, default_handle
.weak EXTI2_IRQHandler
.thumb_set EXTI2_IRQHandler, default_handle
.weak EXTI3_IRQHandler
.thumb_set EXTI3_IRQHandler, default_handle
.weak EXTI4_IRQHandler
.thumb_set EXTI4_IRQHandler, default_handle
.weak DMA1_Stream0_IRQHandler
.thumb_set DMA1_Stream0_IRQHandler, default_handle
.weak DMA1_Stream1_IRQHandler
.thumb_set DMA1_Stream1_IRQHandler, default_handle
.weak DMA1_Stream2_IRQHandler
.thumb_set DMA1_Stream2_IRQHandler, default_handle
.weak DMA1_Stream3_IRQHandler
.thumb_set DMA1_Stream3_IRQHandler, default_handle
.weak DMA1_Stream4_IRQHandler
.thumb_set DMA1_Stream4_IRQHandler, default_handle
.weak DMA1_Stream5_IRQHandler
.thumb_set DMA1_Stream5_IRQHandler, default_handle
.weak DMA1_Stream6_IRQHandler
.thumb_set DMA1_Stream6_IRQHandler, default_handle
.weak ADC_IRQHandler
.thumb_set ADC_IRQHandler, default_handle
.weak CAN1_TX_IRQHandler
.thumb_set CAN1_TX_IRQHandler, default_handle
.weak CAN1_RX0_IRQHandler
.thumb_set CAN1_RX0_IRQHandler, default_handle
.weak CAN1_RX1_IRQHandler
.thumb_set CAN1_RX1_IRQHandler, default_handle
.weak CAN1_SCE_IRQHandler
.thumb_set CAN1_SCE_IRQHandler, default_handle
.weak EXTI9_5_IRQHandler
.thumb_set EXTI9_5_IRQHandler, default_handle
.weak TIM1_BRK_TIM9_IRQHandler
.thumb_set TIM1_BRK_TIM9_IRQHandler, default_handle
.weak TIM1_UP_TIM10_IRQHandler
.thumb_set TIM1_UP_TIM10_IRQHandler, default_handle
.weak TIM1_TRG_COM_TIM11_IRQHandler
.thumb_set TIM1_TRG_COM_TIM11_IRQHandler, default_handle
.weak TIM1_CC_IRQHandler
.thumb_set TIM1_CC_IRQHandler, default_handle
.weak TIM2_IRQHandler
.thumb_set TIM2_IRQHandler, default_handle
.weak TIM3_IRQHandler
.thumb_set TIM3_IRQHandler, default_handle
.weak TIM4_IRQHandler
.thumb_set TIM4_IRQHandler, default_handle
.weak I2C1_EV_IRQHandler
.thumb_set I2C1_EV_IRQHandler, default_handle
.weak I2C1_ER_IRQHandler
.thumb_set I2C1_ER_IRQHandler, default_handle
.weak I2C2_EV_IRQHandler
.thumb_set I2C2_EV_IRQHandler, default_handle
.weak I2C2_ER_IRQHandler
.thumb_set I2C2_ER_IRQHandler, default_handle
.weak SPI1_IRQHandler
.thumb_set SPI1_IRQHandler, default_handle
.weak SPI2_IRQHandler
.thumb_set SPI2_IRQHandler, default_handle
.weak USART1_IRQHandler
.thumb_set USART1_IRQHandler, default_handle
.weak USART2_IRQHandler
.thumb_set USART2_IRQHandler, default_handle
.weak USART3_IRQHandler
.thumb_set USART3_IRQHandler, default_handle
.weak EXTI15_10_IRQHandler
.thumb_set EXTI15_10_IRQHandler, default_handle
.weak RTC_Alarm_IRQHandler
.thumb_set RTC_Alarm_IRQHandler, default_handle
.weak OTG_FS_WKUP_IRQHandler
.thumb_set OTG_FS_WKUP_IRQHandler, default_handle
.weak TIM8_BRK_TIM12_IRQHandler
.thumb_set TIM8_BRK_TIM12_IRQHandler, default_handle
.weak TIM8_UP_TIM13_IRQHandler
.thumb_set TIM8_UP_TIM13_IRQHandler, default_handle
.weak TIM8_TRG_COM_TIM14_IRQHandler
.thumb_set TIM8_TRG_COM_TIM14_IRQHandler, default_handle
.weak TIM8_CC_IRQHandler
.thumb_set TIM8_CC_IRQHandler, default_handle
.weak DMA1_Stream7_IRQHandler
.thumb_set DMA1_Stream7_IRQHandler, default_handle
.weak FSMC_IRQHandler
.thumb_set FSMC_IRQHandler, default_handle
.weak SDIO_IRQHandler
.thumb_set SDIO_IRQHandler, default_handle
.weak TIM5_IRQHandler
.thumb_set TIM5_IRQHandler, default_handle
.weak SPI3_IRQHandler
.thumb_set SPI3_IRQHandler, default_handle
.weak UART4_IRQHandler
.thumb_set UART4_IRQHandler, default_handle
.weak UART5_IRQHandler
.thumb_set UART5_IRQHandler, default_handle
.weak TIM6_DAC_IRQHandler
.thumb_set TIM6_DAC_IRQHandler, default_handle
.weak TIM7_IRQHandler
.thumb_set TIM7_IRQHandler, default_handle
.weak DMA2_Stream0_IRQHandler
.thumb_set DMA2_Stream0_IRQHandler, default_handle
.weak DMA2_Stream1_IRQHandler
.thumb_set DMA2_Stream1_IRQHandler, default_handle
.weak DMA2_Stream2_IRQHandler
.thumb_set DMA2_Stream2_IRQHandler, default_handle
.weak DMA2_Stream3_IRQHandler
.thumb_set DMA2_Stream3_IRQHandler, default_handle
.weak DMA2_Stream4_IRQHandler
.thumb_set DMA2_Stream4_IRQHandler, default_handle
.weak ETH_IRQHandler
.thumb_set ETH_IRQHandler, default_handle
.weak ETH_WKUP_IRQHandler
.thumb_set ETH_WKUP_IRQHandler, default_handle
.weak CAN2_TX_IRQHandler
.thumb_set CAN2_TX_IRQHandler, default_handle
.weak CAN2_RX0_IRQHandler
.thumb_set CAN2_RX0_IRQHandler, default_handle
.weak CAN2_RX1_IRQHandler
.thumb_set CAN2_RX1_IRQHandler, default_handle
.weak CAN2_SCE_IRQHandler
.thumb_set CAN2_SCE_IRQHandler, default_handle
.weak OTG_FS_IRQHandler
.thumb_set OTG_FS_IRQHandler, default_handle
.weak DMA2_Stream5_IRQHandler
.thumb_set DMA2_Stream5_IRQHandler, default_handle
.weak DMA2_Stream6_IRQHandler
.thumb_set DMA2_Stream6_IRQHandler, default_handle
.weak DMA2_Stream7_IRQHandler
.thumb_set DMA2_Stream7_IRQHandler, default_handle
.weak USART6_IRQHandler
.thumb_set USART6_IRQHandler, default_handle
.weak I2C3_EV_IRQHandler
.thumb_set I2C3_EV_IRQHandler, default_handle
.weak I2C3_ER_IRQHandler
.thumb_set I2C3_ER_IRQHandler, default_handle
.weak OTG_HS_EP1_OUT_IRQHandler
.thumb_set OTG_HS_EP1_OUT_IRQHandler, default_handle
.weak OTG_HS_EP1_IN_IRQHandler
.thumb_set OTG_HS_EP1_IN_IRQHandler, default_handle
.weak OTG_HS_WKUP_IRQHandler
.thumb_set OTG_HS_WKUP_IRQHandler, default_handle
.weak OTG_HS_IRQHandler
.thumb_set OTG_HS_IRQHandler, default_handle
.weak DCMI_IRQHandler
.thumb_set DCMI_IRQHandler, default_handle
.weak CRYP_IRQHandler
.thumb_set CRYP_IRQHandler, default_handle
.weak HASH_RNG_IRQHandler
.thumb_set HASH_RNG_IRQHandler, default_handle
.weak FPU_IRQHandler
.thumb_set FPU_IRQHandler, default_handle
