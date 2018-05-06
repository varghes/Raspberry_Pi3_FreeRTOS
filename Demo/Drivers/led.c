/**
 *	UART
 *
 *	
 **/
#include "led.h"


void initLedRequest(struct mailbox_msg* msg, uint32_t val) {
    msg->msg_size = sizeof(struct mailbox_msg);
    msg->request_code = 0x0;
    msg->tag.tag_id = 0x00038041;
    msg->tag.buffer_size = 0x8;
    msg->tag.data_size = 0x0;
    msg->tag.dev_id = 130;
    msg->tag.val = val;
    msg->end_tag = 0x0; 
}

void wait_mailbox_write(Mailbox *m) {
    while (m->status & MBOX_FULL) 
        nop();
}

void wait_mailbox_read(Mailbox *m) {
    while (m->status & MBOX_EMPTY) 
        nop();
}


void writeMailbox0(uint32_t data, uint8_t channel) {
    wait_mailbox_write(MAILBOX0);
    MAILBOX0->write = (data & ~0xf) | (uint32_t) (channel & 0xf);
}

void readMailbox0(uint8_t channel) {
    uint32_t res;
    uint8_t read_channel;
    wait_mailbox_read(MAILBOX0);

    do {
        res = MAILBOX0->read;
        read_channel = res & 0xf;
    } while (read_channel != channel);
}

void led(uint32_t onoff) {
    struct mailbox_msg local;
    initLedRequest(&local, onoff);
    writeMailbox0((uint32_t)&local, 8);
    readMailbox0(8);
}


