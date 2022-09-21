/*
 * NVIC_interface.h
 *
 *  Created on:	Aug 6, 2022
 *  Author:		Ali Emad Ali
 *	
 *	Resources:
 *		*
 *
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum{
	MNVIC_INTERRUPT_WWDG				= 0,
	MNVIC_INTERRUPT_EXTI16_PVD			= 1,
	MNVIC_INTERRUPT_EXTI21_TAMP_STAMP	= 2,
	MNVIC_INTERRUPT_EXTI22_RTC_WKUP		= 3,
	MNVIC_INTERRUPT_FLASH				= 4,
	MNVIC_INTERRUPT_RCC					= 5,
	MNVIC_INTERRUPT_EXTI0				= 6,
	MNVIC_INTERRUPT_EXTI1				= 7,
	MNVIC_INTERRUPT_EXTI2				= 8,
	MNVIC_INTERRUPT_EXTI3				= 9,
	MNVIC_INTERRUPT_EXTI4				= 10,
	MNVIC_INTERRUPT_DMA1_Stream0		= 11,
	MNVIC_INTERRUPT_DMA1_Stream1		= 12,
	MNVIC_INTERRUPT_DMA1_Stream2		= 13,
	MNVIC_INTERRUPT_DMA1_Stream3		= 14,
	MNVIC_INTERRUPT_DMA1_Stream4		= 15,
	MNVIC_INTERRUPT_DMA1_Stream5		= 16,
	MNVIC_INTERRUPT_DMA1_Stream6		= 17,
	MNVIC_INTERRUPT_ADC					= 18,
	MNVIC_INTERRUPT_EXTI5To9			= 23,
	MNVIC_INTERRUPT_TIM1BRK_TIM9		= 24,
	MNVIC_INTERRUPT_TIM1UP_TIM10		= 25,
	MNVIC_INTERRUPT_TIM1TRG_COM_TIM11	= 26,
	MNVIC_INTERRUPT_TIM1CC				= 27,
	MNVIC_INTERRUPT_TIM2				= 28,
	MNVIC_INTERRUPT_TIM3				= 29,
	MNVIC_INTERRUPT_TIM4				= 30,
	MNVIC_INTERRUPT_I2C1EV				= 31,
	MNVIC_INTERRUPT_I2C1ER				= 32,
	MNVIC_INTERRUPT_I2C2EV				= 33,
	MNVIC_INTERRUPT_I2C2ER				= 34,
	MNVIC_INTERRUPT_SPI1				= 35,
	MNVIC_INTERRUPT_SPI2				= 36,
	MNVIC_INTERRUPT_USART1				= 37,
	MNVIC_INTERRUPT_USART2				= 38,
	MNVIC_INTERRUPT_EXTI10To15			= 40,
	MNVIC_INTERRUPT_EXTI17_RTCalarm		= 41,
	MNVIC_INTERRUPT_EXTI18_OTGWKUP		= 42,
	MNVIC_INTERRUPT_DMA1_Stream7		= 47,
	MNVIC_INTERRUPT_SDIO				= 49,
	MNVIC_INTERRUPT_TIM5				= 50,
	MNVIC_INTERRUPT_SPI3				= 51,
	MNVIC_INTERRUPT_DMA2_Stream0		= 56,
	MNVIC_INTERRUPT_DMA2_Stream1		= 57,
	MNVIC_INTERRUPT_DMA2_Stream2		= 58,
	MNVIC_INTERRUPT_DMA2_Stream3		= 59,
	MNVIC_INTERRUPT_DMA2_Stream4		= 60,
	MNVIC_INTERRUPT_OTGFS				= 67,
	MNVIC_INTERRUPT_DMA2_Stream5		= 68,
	MNVIC_INTERRUPT_DMA2_Stream6		= 69,
	MNVIC_INTERRUPT_DMA2_Stream7		= 70,
	MNVIC_INTERRUPT_USART6				= 71,
	MNVIC_INTERRUPT_I2C3EV				= 72,
	MNVIC_INTERRUPT_I2C3ER				= 73,
	MNVIC_INTERRUPT_FPU					= 81,
	MNVIC_INTERRUPT_SPI4				= 84,
	/*	CORE	*/
	MNVIC_INTERRUPT_HardFault,
	MNVIC_INTERRUPT_MemManage,
	MNVIC_INTERRUPT_BusFault,
	MNVIC_INTERRUPT_UsageFault,
	MNVIC_INTERRUPT_SVCall,
	MNVIC_INTERRUPT_Debug_Monitor,
	MNVIC_INTERRUPT_PendSV,
	MNVIC_INTERRUPT_Systick
}MNVIC_INTERRUPT_t;

void MNVIC_voidEnableInterrupt(MNVIC_INTERRUPT_t interrupt);

void MNVIC_voidDisbleInterrupt(MNVIC_INTERRUPT_t interrupt);

void MNVIC_voidSetPendingFlag(MNVIC_INTERRUPT_t interrupt);

void MNVIC_voidClearPendingFlag(MNVIC_INTERRUPT_t interrupt);

b8 MNVIC_b8GetActiveFlag(MNVIC_INTERRUPT_t interrupt);

void MNVIC_voidSetInterruptPriority(MNVIC_INTERRUPT_t interrupt, u8 group, u8 sub);


#endif /* NVIC_INTERFACE_H_ */
