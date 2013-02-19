/* Example-Code from http://wiki.ubuntuusers.de/MSP430-Toolchain */

#include  <msp430.h>

int main(void)
{
        WDTCTL = WDTPW + WDTHOLD;           /* Stop watchdog timer */
        P1DIR = 0x40;                       /* P1.6 output (green LED) */
        P1OUT = 0;                          /* LED off */

        for (;;)                            /* Loop forever */
        {
                volatile unsigned long i;
                P1OUT ^= 0x40;              /* Toggle P1.6 output with XOR */
                i = 99999;                  /* Delay */

                do (i--);                   /* busy waiting (bad) */
                while (i != 0);
        }
}
