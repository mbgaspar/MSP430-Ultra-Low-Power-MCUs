void InitializeClocks() {
    WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
    P1SEL = 0x00;
    P1DIR = 0xE5;               //P1,P3,P4 input reset out
    P1REN = 0xA;
    P1IE = 0xA;
    P1IES = 0x00;
    P1OUT = 0x0B;
    InitializeClocks();

    __enable_interrupt();
    //__bis_SR_register(GIE);
    while(1)
    {

    }

}

void InitializeClocks()
{

  BCSCTL1 = RSEL0 +RSEL1+RSEL2+RSEL3;                    // Set range
  DCOCTL = DCO0+DCO1 + MOD0+MOD1+MOD2+MOD4; //tune to  F Average = 16Mhz
  BCSCTL2 = SELM_0 ;

}

