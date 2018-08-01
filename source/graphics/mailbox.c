#include "mailbox.h"



u32 mailbox_write_status()
{
     return memory_read_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_WRITE_STATUS));
}

u32 mailbox_read_status()
{
     return memory_read_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_READ_STATUS));
}


void mailbox_write(u32 address, u32 channel)
{
     u32 data = address;
     data = data & 0xFFFFFFF0;
     data = data | channel;

     while((mailbox_write_status() & MAIL_FULL)){}

     memory_barrier();
     memory_write_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_WRITE), data);


}

u32 mailbox_read(u32 channel)
{
     u32 data = 0;

     while(1)
     {
          while(mailbox_read_status() & MAIL_EMPTY){}

          memory_barrier();
          data = memory_read_u32(PERIPHERAL_OFFSET + MAIL_START + MAIL_READ);


          if((data & 0xF) == channel)
               break;

     }

     return (data & 0xFFFFFFF0);
}
