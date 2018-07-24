#include "blink.h"
//ZAJEBANY KOD

void blink()
{
     unsigned int ra;

     ra=GET32(GPFSEL4);
     ra&=~(7<<21);
     ra|=1<<21;
     PUT32(GPFSEL4,ra);

     while(1)
     {
          PUT32(GPSET1,1<<(47-32));
          for(ra=0;ra<0x100000;ra++) dummy(ra);
          PUT32(GPCLR1,1<<(47-32));
          for(ra=0;ra<0x100000;ra++) dummy(ra);
     }
}
