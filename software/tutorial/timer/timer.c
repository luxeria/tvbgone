#include <msp430g2553.h>
#include "hardware.h"

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR

unsigned int timerCtr = 0;

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	/* Watchdog off */
	LED_DIR |= (LED0 + LED1);	/* LEDs as output */
	LED_OUT &= ~(LED0 + LED1);	/* LEDs off */
	
	CCTL0 = CCIE;
	TACTL = TASSEL_2 + MC_2;	/* Timer A to continuous SMCLCK
					   and clear timer */

	__enable_interrupt();		/* enable all interrupts */

	__bis_SR_register(LPM0_bits + GIE);	/* LPM0 with */
						/* interrupts enabled */
}

/* Timer A0 ISR (interrupt service routine) */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
	timerCtr = (timerCtr + 1) % 8;
	if(timerCtr ==0)
		P1OUT ^= (LED0 + LED1);
}
