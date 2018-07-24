#include "mailbox.h"
#include "../misc/blink.h"

void mailbox_write(u32 address, u32 channel)
{
     u32 data = address + GPU_OFFSET;
     data = data & 0xFFFFFFF0;
     data = data | channel;

     while((mailbox_write_status() & 0x80000000)){}

     memory_barrier();
     memory_write_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_WRITE), data);


}

u32 mailbox_write_status()
{
     memory_barrier();
     return memory_read_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_WRITE_STATUS));
}

u32 mailbox_read(u32 channel)
{
     u32 data = 0;

     while(1)
     {
          while(memory_read_u32((PERIPHERAL_OFFSET + MAIL_START + MAIL_WRITE_STATUS)) & 0x40000000){}

          memory_barrier();
          data = memory_read_u32(PERIPHERAL_OFFSET + MAIL_START + MAIL_READ);
          memory_barrier();

          if((data & 0xF) == channel)
               break;

     }
     
     return ((data & 0xFFFFFFF0) - GPU_OFFSET);
}
