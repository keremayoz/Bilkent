/* 
 * Project name:
     Led_Blinking (The simplest simple example)
 * Copyright:
     (c) Mikroelektronika, 2012.
 * Revision History:
     20120810:
       - initial release (FJ);
 * Description:
     Simple "Hello world" example for the world of PIC32 MCUs;
 * Test configuration:
     MCU:             P32MX795F512L
                      http://ww1.microchip.com/downloads/en/DeviceDoc/61156F.pdf
     Dev.Board:       EasyPIC Fusion v7 - ac:LED
                      http://www.mikroe.com/easypic-fusion/
     Oscillator:      XT-PLL, 80.0000MHz
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC32
                      http://www.mikroe.com/mikroc/pic32/
 * NOTES:
     - Turn ON PORTA, B, C, D, F & G LEDS at SW15. (board specific)
 */

void main() {
  AD1PCFG = 0xFFFF;      // Configure AN pins as digital I/O
  JTAGEN_bit = 0;        // Disable JTAG

  TRISA = 0;             // Initialize PORTA as output
  

  LATA = 119;            // Set LATA to 0x10001000
  LATB = 119;            // To save the last value while entering frozen state
  
  while(1) {
     if (PORTF.F1 == 1) {  // EN==1, rotate and display the value
       if (LATA == 255) {  //If we have entered the frozen state, restore the last value
          LATA = LATB;     //Display the last value
       }
       else if (PORTF.F2 == 1) {   // DIR==1
           LATA = ((LATA << 1) | (LATA >> (7))); //Rotate left by 1
       }
       else if (PORTF.F2 == 0) {   // DIR==0
           LATA = ((LATA << 7) | (LATA >> 1));  //Rotate right by 1
       }
     }
     else {                // EN=0, frozen state and displaying 0
          if (LATA != 255) //Save the last value in LATB
             LATB = LATA;
          LATA = 255;
     }
    Delay_ms(1000);
  }
}