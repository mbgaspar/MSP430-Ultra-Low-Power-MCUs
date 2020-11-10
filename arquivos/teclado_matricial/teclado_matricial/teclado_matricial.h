/*
 * teclado_matricial.h
 *
 * Created: 22/03/2019 08:59:13
 *  Author: Tanaka
 */ 


#ifndef TECLADO_MATRICIAL_H_
#define TECLADO_MATRICIAL_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>

#include "avr_gpio.h"
#include "bits.h"

#define TECLADO_MATRICIAL	GPIO_D


/**
  * @brief  Configura hardware.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void init_teclado_matricial();

/**
  * @brief  Leitura do teclado matricial.
  * @param	Nenhum
  *
  * @retval Valor da tecla precionada.
  */
uint8_t le_tecla();


#endif /* TECLADO_MATRICIAL_H_ */