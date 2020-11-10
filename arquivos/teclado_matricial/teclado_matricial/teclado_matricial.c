/*
 * teclado_matricial.c
 *
 * Created: 22/03/2019 08:59:51
 *  Author: Tanaka
 */ 

#include "teclado_matricial.h"

void init_teclado_matricial()
{
	TECLADO_MATRICIAL->DDR = 0x0F;
	TECLADO_MATRICIAL->PORT = 0xFF;
}

uint8_t le_tecla()
{
	uint8_t i;
	
	for(i=0; i<4; i++)
	{
		LED_PORT->PORT = ();
	}
}