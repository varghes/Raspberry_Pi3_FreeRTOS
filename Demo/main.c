/*
    FreeRTOS V7.2.0 - Copyright (C) 2012 Real Time Engineers Ltd.
	

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************

*/


#include <FreeRTOS.h>
#include <task.h>
#include <stdint.h>
#include "Drivers/irq.h"
#include "Drivers/gpio.h"
#include "Drivers/uart.h"
#include "Drivers/led.h"


void task1(void *pParam) {
print(" task1 ");
	int i = 0;
	while(1) 
	{
		led(1);
		vTaskDelay(1000);
		led(0);
		vTaskDelay(1000);
		print(" task 1 run ");
	}
}

void task2(void *pParam) {

print(" task2 ");
	int i = 0;
	while(1) 
	{
		vTaskDelay(2000);
		print(" task2 run ");
	}
}


/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
void main (void)
{
	uart_init();
	led(1);
	xTaskCreate(task1, "LED_0", 128, NULL, 0, NULL);
	xTaskCreate(task2, "LED_1", 128, NULL, 0, NULL);
	vTaskStartScheduler();
	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}
