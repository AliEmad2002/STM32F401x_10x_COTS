/*
 * GPIO_private.h
 *
 *  Created on:	Jul 27, 2022
 *  Author:		Ali Emad Ali
 *
 *  References:
 *  	STM RM0368:	2.3 		Memory map
 *  	STM RM0368:	8.4.11 		GPIO register map
 */

#ifndef 	GPIO_PRIVATE_H_
#define		GPIO_PRIVATE_H_


/*	GPIOA	registers	*/
#define GPIOA_BASE_ADD				((u32)(0x40020000))

#define	GPIOA_MODER					(*(volatile u32*)(GPIOA_BASE_ADD + 0x00))
#define	GPIOA_OTYPER				(*(volatile u32*)(GPIOA_BASE_ADD + 0x04))
#define	GPIOA_OSPEEDR				(*(volatile u32*)(GPIOA_BASE_ADD + 0x08))
#define	GPIOA_PUPDR					(*(volatile u32*)(GPIOA_BASE_ADD + 0x0C))
#define	GPIOA_IDR					(*(volatile u32*)(GPIOA_BASE_ADD + 0x10))
#define	GPIOA_ODR					(*(volatile u32*)(GPIOA_BASE_ADD + 0x14))
#define	GPIOA_BSRR					(*(volatile u32*)(GPIOA_BASE_ADD + 0x18))
#define	GPIOA_BSRRL					(*(volatile u16*)(GPIOA_BASE_ADD + 0x18))
#define	GPIOA_BSRRH					(*(volatile u16*)(GPIOA_BASE_ADD + 0x1A))
#define	GPIOA_LCKR					(*(volatile u32*)(GPIOA_BASE_ADD + 0x1C))
#define	GPIOA_AFR					(*(volatile u64*)(GPIOA_BASE_ADD + 0x20))
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/

/*	GPIOB	registers	*/
#define GPIOB_BASE_ADD				((u32)(0x40020400))

#define	GPIOB_MODER					(*(volatile u32*)(GPIOB_BASE_ADD + 0x00))
#define	GPIOB_OTYPER				(*(volatile u32*)(GPIOB_BASE_ADD + 0x04))
#define	GPIOB_OSPEEDR				(*(volatile u32*)(GPIOB_BASE_ADD + 0x08))
#define	GPIOB_PUPDR					(*(volatile u32*)(GPIOB_BASE_ADD + 0x0C))
#define	GPIOB_IDR					(*(volatile u32*)(GPIOB_BASE_ADD + 0x10))
#define	GPIOB_ODR					(*(volatile u32*)(GPIOB_BASE_ADD + 0x14))
#define	GPIOB_BSRR					(*(volatile u32*)(GPIOB_BASE_ADD + 0x18))
#define	GPIOB_BSRRL					(*(volatile u16*)(GPIOB_BASE_ADD + 0x18))
#define	GPIOB_BSRRH					(*(volatile u16*)(GPIOB_BASE_ADD + 0x1A))
#define	GPIOB_LCKR					(*(volatile u32*)(GPIOB_BASE_ADD + 0x1C))
#define	GPIOB_AFR					(*(volatile u64*)(GPIOB_BASE_ADD + 0x20))
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/

/*	GPIOC	registers	*/
#define GPIOC_BASE_ADD				((u32)(0x40020800))

#define	GPIOC_MODER					(*(volatile u32*)(GPIOC_BASE_ADD + 0x00))
#define	GPIOC_OTYPER				(*(volatile u32*)(GPIOC_BASE_ADD + 0x04))
#define	GPIOC_OSPEEDR				(*(volatile u32*)(GPIOC_BASE_ADD + 0x08))
#define	GPIOC_PUPDR					(*(volatile u32*)(GPIOC_BASE_ADD + 0x0C))
#define	GPIOC_IDR					(*(volatile u32*)(GPIOC_BASE_ADD + 0x10))
#define	GPIOC_ODR					(*(volatile u32*)(GPIOC_BASE_ADD + 0x14))
#define	GPIOC_BSRR					(*(volatile u32*)(GPIOC_BASE_ADD + 0x18))
#define	GPIOC_BSRRL					(*(volatile u16*)(GPIOC_BASE_ADD + 0x18))
#define	GPIOC_BSRRH					(*(volatile u16*)(GPIOC_BASE_ADD + 0x1A))
#define	GPIOC_LCKR					(*(volatile u32*)(GPIOC_BASE_ADD + 0x1C))
#define	GPIOC_AFR					(*(volatile u64*)(GPIOC_BASE_ADD + 0x20))
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/


#endif	/*	GPIO_PRIVATE_H_	*/








