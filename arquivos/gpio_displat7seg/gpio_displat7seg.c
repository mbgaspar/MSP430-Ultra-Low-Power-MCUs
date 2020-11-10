/*
 * 01_main_simple_gpio.c
 *
 *  Created on: Aug 16, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

/* Bibliotecas C e AVR */
#include <avr/io.h>
#include <util/delay.h>

/* Bibliotecas customizadas */
#include "lib/avr_gpio.h"
#include "lib/bits.h"
#include "display/led_display.h"

#define LED_PORT GPIO_C
#define LED_PIN	PC1

#define BTN_PORT GPIO_C
#define BTN_PIN PC0

/**
 * @brief  Configura hardware.
 * @param	Nenhum
 *
 * @retval Nenhum.
 */
void hardware_init() {

	/* Acesso por struct:
	 * Vantagem da estrutura: agrupamento
	 * dos registradores do periférico */
	GPIO_C->DDR = (1<<PC1);    // porta saida
	GPIO_C->PORT = (1<<PC0);   //ativa pull up

}

int main() {
	volatile uint8_t cont = 0;

	/* Configura hardware do projeto */
	hardware_init();
	display_init();



	SET_BIT(PORTC, LED_PIN);

	/* Pisca LED: set/clear + delay */
	while (1) {
		display_write(cont);
		while (GPIO_PinTstBit(GPIO_C, PC0)) {
			//espera botao ser pressionado

		}
		if (GPIO_PortTstBit(GPIO_C, PC1))
			CLR_BIT(PORTC, LED_PIN);
		else
			SET_BIT(PORTC, LED_PIN);

		_delay_ms(100);
		if (cont>=9)
			cont=0;
		else
		  cont++;

	}

	return 0;

}
