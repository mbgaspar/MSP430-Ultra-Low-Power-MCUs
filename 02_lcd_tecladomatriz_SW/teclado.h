
#ifndef _TECLADO_H
#define _TECLADO_H

#include <msp430.h>
#include <stdint.h>

#include "lcd.h"
#include "bits.h"

#define COLUNA BIT0 | BIT1| BIT2 | BIT3
#define LINHA  BIT4| BIT5 | BIT6 | BIT7

void teclado_init();

unsigned char ler_teclado();


#endif
