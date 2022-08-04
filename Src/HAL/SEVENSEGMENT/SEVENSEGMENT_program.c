/*
 * SEVENSEGMENT_program.c
 *
 *  Created on:	Jul 28, 2022
 *  Author:		Ali Emad
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include <stdlib.h>

#include "HAL/SEVENSEGMENT/SEVENSEGMENT_interface.h"

const u8 SEVENSEGMENT_PINSTATES[] = {
	0b00111111,	/*	0	*/
	0b00000110,	/*	1	*/
	0b01011011,	/*	2	*/
	0b01001111,	/*	3	*/
	0b01100110,	/*	4	*/
	0b01101101,	/*	5	*/
	0b01111101,	/*	6	*/
	0b00000111,	/*	7	*/
	0b01111111,	/*	8	*/
	0b01101111	/*	9	*/
};

void SEVENSEGMENT_voidInit(
	SEVENSEGMENT_t* ssPtr, SEVENSEGMENT_COMTYPE _comType,
	DIO_PIN pinArr[], SEVENSEGMENT_POINTCONNECTION _pointConnection,
	DIO_OUTPUTSPEED pinSpeed
	)
{
	/*	calculate and store pins and ports and init pins	*/
	if (_pointConnection == SEVENSEGMENT_POINTCONNECTION_connected)
	{
		ssPtr->portArr = malloc(8 * sizeof(DIO_PORT));
		ssPtr->pinArr = malloc(8 * sizeof(u8));

		ssPtr->portArr[7] = pinArr[7] / 16;
		ssPtr->pinArr[7] = pinArr[7] % 16;

		DIO_voidSetPinMode(ssPtr->portArr[7], ssPtr->pinArr[7], DIO_MODE_GPO);
		DIO_voidSetPinOutputType(ssPtr->portArr[7], ssPtr->pinArr[7], DIO_OUTPUTTYPE_pushPull);
		DIO_voidSetPinOutputSpeed(ssPtr->portArr[7], ssPtr->pinArr[7], pinSpeed);
	}
	else
	{
		ssPtr->portArr = malloc(7 * sizeof(DIO_PORT));
		ssPtr->pinArr = malloc(7 * sizeof(u8));
	}

	for (u8 i=0; i<7; i++)
	{
		ssPtr->portArr[i] = pinArr[i] / 16;
		ssPtr->pinArr[i] = pinArr[i] % 16;

		DIO_voidSetPinMode(ssPtr->portArr[i], ssPtr->pinArr[i], DIO_MODE_GPO);
		DIO_voidSetPinOutputType(ssPtr->portArr[i], ssPtr->pinArr[i], DIO_OUTPUTTYPE_pushPull);
		DIO_voidSetPinOutputSpeed(ssPtr->portArr[i], ssPtr->pinArr[i], pinSpeed);
	}
	/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/

	/*	store other parameters	*/
	ssPtr->comType = _comType;
	ssPtr->pointConnection = _pointConnection;
	/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/

	/*	initially turn the 7-segment element off	*/
	SEVENSEGMENT_voidTurnOff(ssPtr);
}

void SEVENSEGMENT_voidWrite(SEVENSEGMENT_t* ssPtr, u8 num, SEVENSEGMENT_POINTSTATE pointState)
{
	/*	range check	*/
	if (num > 9)
	{
		/*	wrong number	*/
		//while(1);
		return;
	}
	/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/

	/*	write number	*/
	u8 pinLevels = SEVENSEGMENT_PINSTATES[num];
	if (ssPtr->comType == SEVENSEGMENT_COMTYPE_anode)
		pinLevels = ~pinLevels;
	for (u8 i=0; i<7; i++)
		DIO_voidSetPinOutputLevel(ssPtr->portArr[i], ssPtr->pinArr[i], GET_BIT(pinLevels, i));
	if (ssPtr->pointConnection == SEVENSEGMENT_POINTCONNECTION_connected)
		DIO_voidSetPinOutputLevel(ssPtr->portArr[7], ssPtr->pinArr[7], GET_BIT(pinLevels, 7));
}

void SEVENSEGMENT_voidTurnOff(SEVENSEGMENT_t* ssPtr)
{
	DIO_OUTPUTLEVEL turnOffLevel = (ssPtr->comType == SEVENSEGMENT_COMTYPE_cathode) ? DIO_OUTPUTLEVEL_low : DIO_OUTPUTLEVEL_high;
	for (u8 i=0; i<7; i++)
		DIO_voidSetPinOutputLevel(ssPtr->portArr[i], ssPtr->pinArr[i], turnOffLevel);
	if (ssPtr->pointConnection == SEVENSEGMENT_POINTCONNECTION_connected)
		DIO_voidSetPinOutputLevel(ssPtr->portArr[7], ssPtr->pinArr[7], turnOffLevel);
}










