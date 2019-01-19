/*
 * Project name:
     ADC Demo (Display the result of ADC on LEDs)
 * Copyright:
     (c) Mikroelektronika, 2012.
 * Revision History:
     20120810:
       - initial release (FJ);
 * Description:
      A simple example of using the ADC library.
      ADC results are displayed on PORTA.
 * Test configuration:
     MCU:             P32MX795F512L
                      http://ww1.microchip.com/downloads/en/DeviceDoc/61156F.pdf
     Dev.Board:       EasyPIC Fusion v7 - ac:ADC
                      http://www.mikroe.com/easypic-fusion/
     Oscillator:      XT-PLL, 80.0000MHz
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC32
                      http://www.mikroe.com/mikroc/pic32/
 * NOTES:
     - Turn on PORTD LEDs on SW15. (board specific)
     - To simulate analog input on ADC channel 0, use on-board potentiometer P1
       by connecting jumper J8 (board specific) to RB0 (ADC channel 0 input).
 */

#include <built_in.h>

unsigned long adc_result = 0;

void main() {
  int x = 0;
  AD1PCFG = 0xFFFE;              // Configure AN pins as digital I/O, PORTB.B0 as analog
  JTAGEN_bit = 0;                // Disable JTAG port
  LATE = 0;
  TRISE = 0;                     // Set PORTD as output

  ADC1_Init();                   // Initialize ADC module
  Delay_ms(100);

  while(1) {
    TRISE = ~TRISE;
    if (TRISE == 1) {
       LATB = PORTEbits.RE0 + (PORTEbits.RE2 << 1) + (PORTEbits.RE4 << 2) + (PORTEbits.RE6 << 3) + (PORTEbits.RE7 << 4) + (PORTEbits.RE5 << 5) + (PORTEbits.RE3 << 6) + (PORTEbits.RE1 << 7);
    }
    else {
       LATE = LATB;
    }
    Delay_ms(50);
  }
}