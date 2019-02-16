#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define LED _BV(PB7)     // = (1 << PB0)
#define LED_DDR DDRB
#define LED_PORT PORTB

int main()
{
//while(1)
//{
    LED_DDR = LED;   // Set the LED pin as an output

    for(;;) {
      LED_PORT ^= LED;   // Toggles just the LED pin
      _delay_ms(600);
    }
//}
}
