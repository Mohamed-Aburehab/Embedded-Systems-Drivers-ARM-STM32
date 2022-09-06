/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : NVIC                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


/* NVIC group sub priorites distribution */
#define MNVIC_GROUP_4_SUB_0                     0x05FA0300
#define MNVIC_GROUP_3_SUB_1                     0x05FA0400
#define MNVIC_GROUP_2_SUB_2                     0x05FA0500
#define MNVIC_GROUP_1_SUB_3                     0x05FA0600
#define MNVIC_GROUP_0_SUB_4                     0x05FA0700

/* NVIC Peripherals Macros */
#define MNVIC_PERIPHERAL_WWDG              0   // Window watchdog interrupt 
#define MNVIC_PERIPHERAL_PVD               1   // PVD through EXTI Line detection interrupt
#define MNVIC_PERIPHERAL_TAMPER            2   // Tamper interrupt 
#define MNVIC_PERIPHERAL_RTC               3   // RTC global interrupt 
#define MNVIC_PERIPHERAL_FLASH             4   // Flash global interrupt 
#define MNVIC_PERIPHERAL_RCC               5   // RCC global interrupt 
#define MNVIC_PERIPHERAL_EXTI0             6   // EXTI Line0 interrupt 
#define MNVIC_PERIPHERAL_EXTI1             7   // EXTI Line1 interrupt 
#define MNVIC_PERIPHERAL_EXTI2             8   // EXTI Line2 interrupt 
#define MNVIC_PERIPHERAL_EXTI3             9   // EXTI Line3 interrupt 
#define MNVIC_PERIPHERAL_EXTI4             10  // EXTI Line4 interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel1     11  // DMA1 Channel1 global interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel2     12  // DMA1 Channel2 global interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel3     13  // DMA1 Channel3 global
#define MNVIC_PERIPHERAL_DMA1_Channel4     14  // DMA1 Channel4 global interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel5     15  // DMA1 Channel5 global interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel6     16  // DMA1 Channel6 global interrupt 
#define MNVIC_PERIPHERAL_DMA1_Channel7     17  // DMA1 Channel7 global interrupt 
#define MNVIC_PERIPHERAL_ADC1_2            18  // ADC1 and ADC2 global interrupt 
#define MNVIC_PERIPHERAL_USB_HP_CAN_TX     19  // USB High Priority or CAN TX interrupts 
#define MNVIC_PERIPHERAL_USB_LP_CAN_RX0    20  // USB Low Priority or CAN RX0 interrupts 
#define MNVIC_PERIPHERAL_CAN_RX1           21  // CAN RX1 interrupt 
#define MNVIC_PERIPHERAL_CAN_SCE           22  // CAN SCE interrupt 
#define MNVIC_PERIPHERAL_EXTI9_5           23  // EXTI Line[9:5] interrupts 
#define MNVIC_PERIPHERAL_TIM1_BRK          24  // TIM1 Break interrupt 
#define MNVIC_PERIPHERAL_TIM1_UP           25  // TIM1 Update interrupt 
#define MNVIC_PERIPHERAL_TIM1_TRG_COM      26  // TIM1 Trigger and Commutation interrupts 
#define MNVIC_PERIPHERAL_TIM1_CC           27  // TIM1 Capture Compare interrupt 
#define MNVIC_PERIPHERAL_TIM2              28  // TIM2 global interrupt 
#define MNVIC_PERIPHERAL_TIM3              29  // TIM3 global interrupt 
#define MNVIC_PERIPHERAL_TIM4              30  // TIM4 global interrupt 
#define MNVIC_PERIPHERAL_I2C1_EV           31  // I2C1 event interrupt 
#define MNVIC_PERIPHERAL_I2C1_ER           32  // I2C1 error interrupt 
#define MNVIC_PERIPHERAL_I2C2_EV           33  // I2C2 event interrupt 
#define MNVIC_PERIPHERAL_I2C2_ER           34  // I2C2 error interrupt 
#define MNVIC_PERIPHERAL_SPI1              35  // SPI1 global interrupt 
#define MNVIC_PERIPHERAL_SPI2              36  // SPI2 global interrupt 
#define MNVIC_PERIPHERAL_USART1            37  // USART1 global interrupt 
#define MNVIC_PERIPHERAL_USART2            38  // USART2 global interrupt 
#define MNVIC_PERIPHERAL_USART3            39  // USART3 global interrupt 
#define MNVIC_PERIPHERAL_EXTI15_10         40  // EXTI Line[15:10] interrupts 
#define MNVIC_PERIPHERAL_RTCAlarm          41  // RTC alarm through EXTI line interrupt 
#define MNVIC_PERIPHERAL_USBWakeup         42  // USB wakeup from suspend through EXTI line interrupt 
#define MNVIC_PERIPHERAL_TIM8_BRK          43  // TIM8 Break interrupt 
#define MNVIC_PERIPHERAL_TIM8_UP           44  // TIM8 Update interrupt 
#define MNVIC_PERIPHERAL_TIM8_TRG_COM      45  // TIM8 Trigger and Commutation interrupts 
#define MNVIC_PERIPHERAL_TIM8_CC           46  // TIM8 Capture Compare interrupt 
#define MNVIC_PERIPHERAL_ADC3              47  // ADC3 global interrupt 
#define MNVIC_PERIPHERAL_FSMC              48  // FSMC global interrupt 
#define MNVIC_PERIPHERAL_SDIO              49  // SDIO global interrupt 
#define MNVIC_PERIPHERAL_TIM5              50  // TIM5 global interrupt 
#define MNVIC_PERIPHERAL_SPI3              51  // SPI3 global interrupt 
#define MNVIC_PERIPHERAL_UART4             52  // UART4 global interrupt 
#define MNVIC_PERIPHERAL_UART5             53  // UART5 global interrupt 
#define MNVIC_PERIPHERAL_TIM6              54  // TIM6 global interrupt 
#define MNVIC_PERIPHERAL_TIM7              55  // TIM7 global interrupt 

/**
 * @brief it initializes the NVIC.
 */
void MNVIC_voidInit();

/**
 * @brief It enables the interrupt number that is passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to enable.
 * 
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);

/**
 * @brief It disables the interrupt number that is passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to disable.
 * 
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

/**
 * @brief It sets the pending flag of the interrupt number that is passed to it.
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to set pending flag for.
 */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);

/**
 * @brief It clears the pending flag of the interrupt number passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to clear its pending flag.
 */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

/**
 * @brief It returns the state of the active flag of the interrupt number passed to it
 * 
 * @param Copy_u8IntNumber The number of the interrupt you want to get its active flag value.
 * 
 * @return Active flag value for the passed interrupt number
 */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

/**
 * @brief It sets group priority and the subgroup priority by taking the interrupt ID, 
 * the group priority and the subgroup priority and writes them to the appropriate register
 * 
 * @param Copy_u8InterruptID The interrupt number you want to set the priority for.
 * @param Copy_u8GroupPriority The priority of the group.
 * @param Copy_u8SubGroupPriority The priority of the interrupt within the group.
 */
void MNVIC_voidSetPriority(u8 Copy_u8InterruptID,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority);


#endif