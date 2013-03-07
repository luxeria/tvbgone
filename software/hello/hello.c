/* Example-Code from http://wiki.ubuntuusers.de/MSP430-Toolchain */

#include  <msp430.h>

int main(void)
{
        WDTCTL = WDTPW + WDTHOLD;           /* Stop watchdog timer */
        DCOCTL    = CALDCO_16MHZ;           /* Initializes clock module */
        BCSCTL1   = XT2OFF|CALBC1_16MHZ;    
        BCSCTL2   = 0;           
        BCSCTL3   = 0;           
        P1DIR = BIT0 | BIT6;                /* P1.6 output (green LED) */
        P1OUT = BIT0;                       /* red LED */

        for (;;)                            /* Loop forever */
        {
                volatile unsigned long i;
                P1OUT ^= BIT0 | BIT6;       /* Toggle P1.0 and P1.6 output with XOR */
                i = 99999;                  /* Delay */

                do (i--);                   /* busy waiting (bad) */
                while (i != 0);
        }
}
