#include "stm32f100xx.h"

void RCC_EnableClock(void) {
  RCC->APB2ENR |= (1 << 2);  // Enable GPIOA Clock
}

void GPIOA_SetPinOutput(uint8_t pin) {
  GPIOA->CRL &= ~(0xF << (pin * 4));
  GPIOA->CRL |= (0x3 << (pin * 4));
}

void GPIOA_SetPinHigh(uint8_t pin) {
  GPIOA->BSRR = (1 << pin);
}

void GPIOA_SetPinLow(uint8_t pin) {
  GPIOA->BRR = (1 << pin);
}

void USART1_Init(uint32_t baudrate) {
  RCC->APB2ENR |= (1 << 14);
  USART1->BRR = 72000000 / baudrate;
  USART1->CR1 = (1 << 13) | (1 << 3) | (1 << 2);
}

void USART1_SendChar(char c) {
  while (!(USART1->SR & (1 << 7)));
  USART1->DR = c;
}

void USART1_SendString(char *str) {
  while (*str) USART1_SendChar(*str++);
}

void TIM2_Init(uint16_t prescaler, uint16_t arr) {
  RCC->APB1ENR |= (1 << 0);
  TIM2->PSC = prescaler - 1;
  TIM2->ARR = arr - 1;
  TIM2->CR1 |= (1 << 0);
}

void Delay_ms(uint32_t ms) {
  TIM2->CNT = 0;
  while (TIM2->CNT < ms);
}

void ADC1_Init(void) {
  RCC->APB2ENR |= (1 << 9);
  ADC1->CR2 |= (1 << 0);
  ADC1->SMPR2 |= (7 << 0);
}

uint16_t ADC1_Read(void) {
  ADC1->CR2 |= (1 << 22);
  while (!(ADC1->SR & (1 << 1)));
  return (uint16_t)ADC1->DR;
}
