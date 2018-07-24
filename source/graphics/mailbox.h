#ifndef MAILBOX_H
#define MAILBOX_H

#include "../misc/types.h"
#include "../memory/mem.h"

#define PERIPHERAL_OFFSET 0x20000000
#define MAIL_START 0xB880
#define MAIL_WRITE 0x20
#define MAIL_READ 0x00
#define MAIL_WRITE_STATUS 0x18

#define CHANNEL_FRAMEBUFFER 1

typedef struct
{
     u32 channel: 4;
     u32 data: 28;

}mailbox_msg_t;




//extern void mailbox_write_msg(mailbox_msg_t msg);
extern void mailbox_write(u32 data, u32 channel);
extern u32 mailbox_read(u32 channel);
extern u32 mailbox_write_status();

#endif
