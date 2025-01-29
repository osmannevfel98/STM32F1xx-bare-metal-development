#include "stm32f10x.h"

void delay(long delay);
void RCC_Config(void);

int main(void)
{
    RCC_Config();
    
    while (1)
    {
     
    }
}

void RCC_Config(void)
{

    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY)); 

    FLASH->ACR |= FLASH_ACR_LATENCY_2;

    RCC->CFGR |= RCC_CFGR_PLLSRC; 
    RCC->CFGR |= RCC_CFGR_PLLMULL9; 

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY)); 

    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); 

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; 
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 
}

void delay(long delay)
{
	while(delay--);
}

