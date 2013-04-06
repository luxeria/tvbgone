/* Autor: 	Ervin Mazlagic
 * E-Mail:	nino.ninux@gmail.com
 * Sources: 
 * 	github.com/daniw/msp430helloworld
 * 	processors.wiki.ti.com/index.php/MSP430_LaunchPad_PushButton
 * */

#include <msp430g2553.h>
#include "hardware.h"

#define LED0 BIT0
#define LED1 BIT6
#define BUTTON BIT3

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	/* Watchdog off */

	P1DIR |= (LED0 + LED1);		/* LED-Pins as Output */
	P1OUT &= ~(LED0 + LED1);	/* Turn off LEDs */
	P1REN ^= BUTTON;

	P1IE |= BUTTON;			/* Enable Interrupt */
	P1IFG &= ~BUTTON;		/* Button IFG cleared */
	__enable_interrupt();		/* enable all interrupts */
	
	while(1){
	}
}

/* Port 1 interrupt service routine */
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	P1OUT ^= (LED0 + LED1);		/* toggle P1.0 */
	P1IFG &= ~BUTTON;		/* P1.3 IFG cleared */
}
