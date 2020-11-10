#include <msp430.h>
#include <stdio.h>
#include "lcd.h"

void main(){
    //uint8_t i = 0; char string[8];
   unsigned char nr;

    /* Configuração de hardware */
    WDTCTL = WDTPW | WDTHOLD;

#if defined (__MSP430FR2355__)
    /* Disable the GPIO power-on default high-impedance mode */
    PM5CTL0 &= ~LOCKLPM5;
#endif



    /* Inicializa hardare: veja lcd.h para configurar pinos */
    lcd_init_4bits();

    //iniciar teclado
    teclado_init();

    //mensagem linha 1
    lcd_send_data(LCD_LINE_0, LCD_CMD);
    lcd_write_string("KEYBOARD");
    _delay_cycles(100000);

    //mensgem linha 2
    lcd_send_data(LCD_LINE_1, LCD_CMD);
    lcd_write_string("MSP430");
    _delay_cycles(100000);


    while (1){
       // lcd_send_data(LCD_LINE_0, LCD_CMD);
       // snprintf(string, 8, "%d", i);

        nr = ler_teclado();
        lcd_send_data(LCD_LINE_1, LCD_CMD);
        lcd_write_string("READ");

        if (nr!=0xFF)
        {
            lcd_send_data(LCD_LINE_0, LCD_CMD);
            lcd_send_data(nr,1);

        }
       // lcd_write_string(string);
       // i++;

        _delay_cycles(10000);
    }




}
