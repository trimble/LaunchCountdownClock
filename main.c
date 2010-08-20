
#include "io430.h"

void med_delay(void)
{
   for(int i = 0; i < 20000; i++);
}

void short_delay(void)
{
   for(int i = 0; i < 500; i++);
}

const char A[8] = {0xF8,
                   0xFC,
                   0x36,
                   0x33,
                   0x33,
                   0x36,
                   0xFC,
                   0xF8
};

const char O[8] = {0x3C,
                   0x7E,
                   0xC3,
                   0xC3,
                   0xC3,
                   0xC3,
                   0x7E,
                   0x3C
};

const char P[8] = {0xFF,
                   0xFF,
                   0x1B,
                   0x1B,
                   0x1B,
                   0x0E,
                   0x00,
                   0x00
};

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = 0xFF;
  P2DIR = 0xFF;

  P2OUT = 0x00;

//  while(1)
//  {
//     for(int i = 0; i < 8; i++)
//     {
//        P2OUT = 1 << i;
//
//        for(int j = 0; j < 8; j++)
//        {
//           P1OUT = 1 << j;
//           med_delay();
//        }
//     }
//  }
  while(1)
  {
     for(int i = 0; i < 8; i++)
     {
        P2OUT = 1 << i;

        P1OUT = P[i];

        short_delay();
     }
  }

  P2OUT = 0x00;

  return 0;
}
