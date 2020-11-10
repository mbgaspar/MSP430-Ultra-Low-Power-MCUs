#include <msp430g2211.h>
// Timer A0 interrupt service routine
#define REA BIT1
#define REB BIT3

unsigned char count;
void main()
{
    static unsigned char oldstate;
    unsigned char port,state;
        if(P1IFG & 0x0A){
            __delay_cycles(6000);


            port = P1IN;

            state= (port & REB)>>3 | (port & REA);

            if(state==0x3){
            if(oldstate ==0x1)
                {
                    count++;
                    P1OUT ^=BIT0 ;
                }else if(oldstate == 0x2)
                {

                    count--;
                    P1OUT ^=BIT6 ;
                }
            }
            oldstate = state;




        }
        __delay_cycles(6000);
            P1IFG = 0x00;


    }



