/*
 * leddisplay.c
 *
 *  Created on: Aug 20, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/pgmspace.h>
#include <util/delay.h>

#include "../lib/avr_gpio.h"
#include "led_display.h"

/* Tabela de conversão em flash: Anodo comum */
#ifdef COM_ANODO
const uint8_t convTable[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
		0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};
#endif

/* Tabela de conversão em flash: Catodo comum */
#ifdef COM_CATODO
const uint8_t convTable[] PROGMEM = {0x3F, 0x06, 0x05B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
       0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
#endif


void display_init() {

	/* Configuração de portas */
	//DISPLAY_PORT->DDR = (...)
	DISPLAY_PORT->DDR = 0xFF;      // porta saida


}

void display_write(uint8_t data){

	/* Escreve no display */

	DISPLAY_PORT->PORT = pgm_read_byte(&convTable[data]);

}
