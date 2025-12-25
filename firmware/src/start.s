.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb

.extern _stack_start 
.extern _data_start
.extern _data_end
.extern _data_start_flash
.extern _bss_start
.extern _bss_end
.extern main

.section .vectors, "a", %progbits
.global g_Vectors
g_Vectors:
  .word _stack_start
  .word start

  .word NMI_Handler
  .word HardFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word 0
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler

  .word WWDG_IRQHandler
  .word PVD_VDDIO2_IRQHandler
  .word RTC_IRQHandler
  .word FLASH_IRQHandler
  .word RCC_CRS_IRQHandler
  .word EXTI0_1_IRQHandler
  .word EXTI2_3_IRQHandler
  .word EXTI4_15_IRQHandler
  .word TSC_IRQHandler
  .word DMA1_Channel1_IRQHandler
  .word DMA1_Channel2_3_IRQHandler
  .word DMA1_Channel4_5_6_7_IRQHandler
  .word ADC1_COMP_IRQHandler 
  .word TIM1_BRK_UP_TRG_COM_IRQHandler
  .word TIM1_CC_IRQHandler
  .word TIM2_IRQHandler
  .word TIM3_IRQHandler
  .word TIM6_DAC_IRQHandler
  .word TIM7_IRQHandler    
  .word TIM14_IRQHandler
  .word TIM15_IRQHandler
  .word TIM16_IRQHandler
  .word TIM17_IRQHandler
  .word I2C1_IRQHandler
  .word I2C2_IRQHandler
  .word SPI1_IRQHandler
  .word SPI2_IRQHandler
  .word USART1_IRQHandler
  .word USART2_IRQHandler
  .word USART3_4_IRQHandler 
  .word CEC_CAN_IRQHandler
  .word USB_IRQHandler

.section .text.start 
.thumb_func 
.global start 
start:
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
    bl main
loop:
    nop
    b loop

.weak NMI_Handler
.thumb_set NMI_Handler, loop
.weak HardFault_Handler
.thumb_set HardFault_Handler, loop
.weak SVC_Handler
.thumb_set SVC_Handler, loop
.weak PendSV_Handler
.thumb_set PendSV_Handler, loop
.weak SysTick_Handler
.thumb_set SysTick_Handler, loop
.weak WWDG_IRQHandler
.thumb_set WWDG_IRQHandler, loop
.weak PVD_VDDIO2_IRQHandler
.thumb_set PVD_VDDIO2_IRQHandler, loop
.weak RTC_IRQHandler
.thumb_set RTC_IRQHandler, loop
.weak FLASH_IRQHandler
.thumb_set FLASH_IRQHandler, loop
.weak RCC_CRS_IRQHandler
.thumb_set RCC_CRS_IRQHandler, loop
.weak EXTI0_1_IRQHandler
.thumb_set EXTI0_1_IRQHandler, loop
.weak EXTI2_3_IRQHandler
.thumb_set EXTI2_3_IRQHandler, loop
.weak EXTI4_15_IRQHandler
.thumb_set EXTI4_15_IRQHandler, loop
.weak TSC_IRQHandler
.thumb_set TSC_IRQHandler, loop
.weak DMA1_Channel1_IRQHandler
.thumb_set DMA1_Channel1_IRQHandler, loop
.weak DMA1_Channel2_3_IRQHandler
.thumb_set DMA1_Channel2_3_IRQHandler, loop
.weak DMA1_Channel4_5_6_7_IRQHandler
.thumb_set DMA1_Channel4_5_6_7_IRQHandler, loop
.weak ADC1_COMP_IRQHandler 
.thumb_set ADC1_COMP_IRQHandler, loop 
.weak TIM1_BRK_UP_TRG_COM_IRQHandler
.thumb_set TIM1_BRK_UP_TRG_COM_IRQHandler, loop
.weak TIM1_CC_IRQHandler
.thumb_set TIM1_CC_IRQHandler, loop
.weak TIM2_IRQHandler
.thumb_set TIM2_IRQHandler, loop
.weak TIM3_IRQHandler
.thumb_set TIM3_IRQHandler, loop
.weak TIM6_DAC_IRQHandler
.thumb_set TIM6_DAC_IRQHandler, loop
.weak TIM7_IRQHandler    
.thumb_set TIM7_IRQHandler, loop    
.weak TIM14_IRQHandler
.thumb_set TIM14_IRQHandler, loop
.weak TIM15_IRQHandler
.thumb_set TIM15_IRQHandler, loop
.weak TIM16_IRQHandler
.thumb_set TIM16_IRQHandler, loop
.weak TIM17_IRQHandler
.thumb_set TIM17_IRQHandler, loop
.weak I2C1_IRQHandler
.thumb_set I2C1_IRQHandler, loop
.weak I2C2_IRQHandler
.thumb_set I2C2_IRQHandler, loop
.weak SPI1_IRQHandler
.thumb_set SPI1_IRQHandler, loop
.weak SPI2_IRQHandler
.thumb_set SPI2_IRQHandler, loop
.weak USART1_IRQHandler
.thumb_set USART1_IRQHandler, loop
.weak USART2_IRQHandler
.thumb_set USART2_IRQHandler, loop
.weak USART3_4_IRQHandler 
.thumb_set USART3_4_IRQHandler, loop 
.weak CEC_CAN_IRQHandler
.thumb_set CEC_CAN_IRQHandler, loop
.weak USB_IRQHandler
.thumb_set USB_IRQHandler, loop
