#define vector = PORT1_VECTOR
__interrupt void p1ch (void)
{
            P1OUT &= ~BIT5;

        hand();
        P1OUT |= BIT5;
}

#define vector = PORT2_VECTOR, TIMERA1_VECTOR,TIMERA0_VECTOR, NMI_VECTOR, WDT_VECTOR
__interrupt void Trap_ISR(void)
{
  while(1);
}
void InitializeClocks();

void InitializeClocks();
