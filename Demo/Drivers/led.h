/**
 *	UART
 *
 *	
 **/

#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>

/* Mailbox 0 base address (Read by ARM) */
#define MBOX0_BASE      (IO_BASE + 0xB880)
/* Mailbox 1 base address (Read by GPU) */
#define MBOX1_BASE      (IO_BASE + 0xB8A0)
 
 
/* Status register value when mailbox is full/empty */
#define   MBOX_FULL     0x80000000      
#define   MBOX_EMPTY    0x40000000
 
#define MAILBOX0	((Mailbox *) MBOX0_BASE) 

typedef struct {
    volatile uint32_t read;
    volatile uint32_t rsvd[3];
    volatile uint32_t peek;
    volatile uint32_t sender;
    volatile uint32_t status;
    volatile uint32_t config;
    volatile uint32_t write;
} Mailbox;


struct msg_tag {
	volatile uint32_t tag_id;				// the message id
	volatile uint32_t buffer_size;			// size of the buffer (which in this case is always 8 bytes)
	volatile uint32_t data_size;				// amount of data being sent or received
	volatile uint32_t dev_id;				// the ID of the clock/voltage to get or set
	volatile uint32_t val;					// the value (e.g. rate (in Hz)) to set
};

struct mailbox_msg {
	volatile uint32_t msg_size;				// simply, sizeof(struct vc_msg)
	volatile uint32_t request_code;			// holds various information like the success and number of bytes returned (refer to mailboxes wiki)
	struct msg_tag tag;	            // the tag structure above to make
	volatile uint32_t end_tag;				// an end identifier, should be set to NULL
} __attribute__((aligned(16)));


/* Functions */

void led(uint32_t onoff);
#define nop()      asm volatile ("nop") 

// Raspberry pi 3 (bcm2837 SoC) IO peripherals base
#define IO_BASE       0x3F000000


#endif
