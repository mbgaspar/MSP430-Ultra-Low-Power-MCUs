/*
 * 02_main_display_7_seg.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


#include <msp430.h>

/* Tipos uint16_t, uint8_t, ... */
#include <stdint.h>

#include "led_display.h"

/*##########################################
     * DEFINE p1.0 e p1.1
     * ##########################################*/
#define contro_01 BIT0;
#define contro_02 BIT1;

void main(void)
{
    /* Para o watchdog timer
     * Necessário para código em depuração */
    WDTCTL = WDTPW | WDTHOLD;


    /*##########################################
     * IMPLEMENTADO saida p1.0 e p1.1 resto entrada
     * ##########################################*/
        P1DIR |= contro_01 |  contro_02;


#if defined (__MSP430FR2355__)
    /* Disable the GPIO power-on default high-impedance mode */
    PM5CTL0 &= ~LOCKLPM5;
#endif

    volatile uint16_t i;
	uint8_t x = 0;

	/* Inicializa displays */
	display_init();

	while(1)
	{
		display_write(x);
		for(i=1000; i>0; i--);
		/* escrever no display e Delay *///OBS: 24hz == 41.7milisegundos

		SET();//?

		x++;
		x = x & 0xf;
		/* Incrementa e limita valor de x ate 0x0f */



	}
}
