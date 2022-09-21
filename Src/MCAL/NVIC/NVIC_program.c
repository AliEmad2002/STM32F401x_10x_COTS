/*
 * NVIC_program.c
 *
 *  Created on:	Aug 6, 2022
 *  Author:		Ali Emad Ali
 *	
 *	Resources:
 *		*
 *
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "SCB_interface.h"


void MNVIC_voidEnableInterrupt(MNVIC_INTERRUPT_t interrupt)
{
	NVIC_ISER[interrupt/32] = (1 << interrupt%32);
}

void MNVIC_voidDisbleInterrupt(MNVIC_INTERRUPT_t interrupt)
{
	NVIC_ICER[interrupt/32] = (1 << interrupt%32);
}

void MNVIC_voidSetPendingFlag(MNVIC_INTERRUPT_t interrupt)
{
	NVIC_ISPR[interrupt/32] = (1 << interrupt%32);
}

void MNVIC_voidClearPendingFlag(MNVIC_INTERRUPT_t interrupt)
{
	NVIC_ICPR[interrupt/32] = (1 << interrupt%32);
}

b8 MNVIC_b8GetActiveFlag(MNVIC_INTERRUPT_t interrupt)
{
	return GET_BIT(NVIC_IABR[interrupt/32], interrupt%32);
}

void MNVIC_voidSetInterruptPriority(MNVIC_INTERRUPT_t interrupt, u8 group, u8 sub)
{
	// read current priority grouping settings:
	u8 priGroupSettings = MSCB_enumGetPriorityGroupsAndSubGroupsNumber();

	// calculate binary point:
	u8 binPoint;

	switch(priGroupSettings)
	{
	case MSCB_PRIGROUP_group16_sub0:
		binPoint = group;
		break;

	case MSCB_PRIGROUP_group8_sub2:
		binPoint = sub | (group << 1);
		break;

	case MSCB_PRIGROUP_group4_sub4:
		binPoint = sub | (group << 2);
		break;

	case MSCB_PRIGROUP_group2_sub8:
		binPoint = sub | (group << 3);
		break;

	case MSCB_PRIGROUP_group0_sub16:
		binPoint = sub;
		break;
	}

	switch (interrupt)
	{
	case MNVIC_INTERRUPT_MemManage:
		MSCB_voidSetCorePeripheralPriority(4, binPoint);
		break;

	case MNVIC_INTERRUPT_BusFault:
		MSCB_voidSetCorePeripheralPriority(5, binPoint);
		break;

	case MNVIC_INTERRUPT_UsageFault:
		MSCB_voidSetCorePeripheralPriority(6, binPoint);
		break;

	case MNVIC_INTERRUPT_SVCall:
		MSCB_voidSetCorePeripheralPriority(11, binPoint);
		break;

	case MNVIC_INTERRUPT_PendSV:
		MSCB_voidSetCorePeripheralPriority(14, binPoint);
		break;

	case MNVIC_INTERRUPT_Systick:
		MSCB_voidSetCorePeripheralPriority(15, binPoint);
		break;

	default:
		// write it on IPR:
		NVIC_IPR[interrupt] = (binPoint << 4);
	}
}










