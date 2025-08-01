#include <mega8.h>

#ifndef F_CPU
#define F_CPU 8000000UL // 16 MHz clock speed 

#endif

#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    DDRD.2 = 0;
    DDRD.3 = 1;  
   
    while(1)
    {                    
      if(PIND.2==1)   
      {   
          PORTD.3 = 0x00;
          delay_ms(500);       
          PORTD.3 = 0xff;
          delay_ms(500);
      }             
      else if(PIND.2==0)
      {
          PORTD.3 = 0;
      }
     
         
    }
}