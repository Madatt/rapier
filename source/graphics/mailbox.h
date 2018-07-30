#ifndef MAILBOX_H
#define MAILBOX_H

#include "../misc/types.h"
#include "../memory/mem.h"


#define PERIPHERAL_OFFSET 0x20000000
#define MAIL_START 0xB880
#define MAIL_WRITE 0x20
#define MAIL_READ 0x00
#define MAIL_READ_STATUS 0x18
#define MAIL_WRITE_STATUS 0x38
#define MAIL_FULL 0x80000000
#define MAIL_EMPTY 0x40000000

#define CHANNEL_FRAMEBUFFER 1
#define CHANNEL_PROPERTY 8


//extern void mailbox_write_msg(mailbox_msg_t msg);
extern void mailbox_write(u32 data, u32 channel);
extern u32 mailbox_read(u32 channel);
extern u32 mailbox_write_status();
extern u32 mailbox_read_status();

#endif
