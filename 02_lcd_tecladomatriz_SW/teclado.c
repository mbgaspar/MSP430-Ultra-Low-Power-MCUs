/*####################################################
 * Sub-rotina para o trabalho com um teclado com 16 teclas
 * (4 colunas e 4 linhas) organizados como:
                        C1 C2 C3 C4
                         x  x  x  x    L1
                         x  x  x  x    L2
                         x  x  x  x    L3
                         x  x  x  x    L4
onde se deve empregar um único P3.x acionado.

 ####################################################*/

#include <msp430.h>
#include "teclado.h"
#include "lcd.h"
#include "bits.h"

/* Matriz de decodificação do teclado, essa estrutura
 * foi selecionada como um facilitador
 * mas sua utilização não é obrigatória */
 char keypad[4][4] = {
    {'1','2','3','F'},
    {'4','5','6','E'},
    {'7','8','9','D'},
    {'A','0','B','C'}};



void teclado_init()
{
    /*Verifica se tem corrente*/
    P3DIR |= COLUNA;
    /*Envio de corrente*/
    P3REN = LINHA;
    //Configurando em pull up
    P3OUT = LINHA;
/*
 * DDRB = 0xFF; //LCD esta no PORTB
DDRD = 0x0F; //definições das entradas e saídas para o teclado
PORTD= 0xFF; //habilita os pull-ups do PORTD e coloca colunas em 1
UCSR0B = 0x00; //para uso dos PORTD no Arduino

 */




}

 unsigned char ler_teclado(){
    char n,j, tecla = 0xFF,verifica_linha;


    /*A verificação é feita coluna por coluna* e então linha por linha*/
    for(n=0;n<4;n++)
    {

        //apaga o bit da coluna (varredura)
        CLR_BIT(P3DIR,n);

        _delay_cycles(100000); //necessario!!!


        /*Verificação de qual linha recebeu * alteração no nível lógico*/
        verifica_linha = LINHA >> 4;


        for(j=0;j<4;j++) //teste linha
        {

            /*Verifica se foi pressionado ou não*/
            if(!TST_BIT(verifica_linha,j))
            {
                tecla = keypad[j][n];

                while(!TST_BIT(verifica_linha>>4,j)); /*para esperar soltar a tecla, caso
                desejado, descomentar essa linha*/
            }

         }
        /*Bit voltando ao estado original*/
        SET_BIT(P3DIR,n);//ativa o bit zerado anteriormente
      }

      return tecla; //retorna o valor 0xFF se nenhuma tecla foi pressionada

    }


