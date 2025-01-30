#ifndef INC_STM32L073XX_H_
#define INC_STM32L073XX_H_

#include <stdint.h>

#define __IO volatile
	
/*** Memory Base Address ***/
#define FLASH_PROG_BASE				(0x0008000UL)  /* Flash Program Memory Base Address */
#define SRAM_BASE							(0x20000000UL) /* SRAM Base Address 				*/

/*** Peripheral Base Address ***/
#define PERIPH_BASE						(0x4000000UL) 								/*  Base Address for peripherals 	*/
#define APB1_BASE							PERIPH_BASE  	 								/*  APB1 Bus Base Address 			*/
#define APB2_BASE							(PERIPH_BASE + 0x10000UL) 		/* APB2 Bus Base Address			*/
#define AHB_BASE							(PERIPH_BASE + 0x20000UL) 		/* AHB Bus Base Address				*/








#endif