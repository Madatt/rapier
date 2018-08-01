#include "lib.h"

void itoa(u32 in, u8 * ch)
{
     u32 i = 0;
     u32 ln = 0;
     u32 tmp = in;

     while(tmp != 0)
     {
          tmp /= 10;
          ln +=1 ;
     }

     tmp = in;

     while(tmp != 0)
     {
          ch[ln - i - 1] = (u8)((tmp%10) + '0');
          tmp /= 10;
          i +=1 ;
     }

     ch[i] = '\0';

}

void hexstring(u32 in, u8 * ch)
{
     u32 i = 0;
     u32 ln = 0;
     u32 tmp = in;

     while(tmp != 0)
     {
          tmp /= 16;
          ln +=1 ;
     }

     tmp = in;

     while(tmp != 0)
     {
          u8 t = (u8)(tmp%16);
          if(t>9)
               t+=7;
          t+='0';
          ch[ln - i - 1] = t;
          tmp /= 16;
          i +=1 ;
     }
     ch[i] = '\0';
}
