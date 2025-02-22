#include "stm32f100xx.h"

#define ADC_BUFFER_SIZE 100  

volatile uint16_t adc_buffer[ADC_BUFFER_SIZE];  
volatile uint8_t buffer_index = 0;  

void delay(long delay);
void RCC_Config(void);

int main(void) {
  RCC_EnableClock();
  GPIOA_SetPinOutput(5);
  USART1_Init(115200);
  ADC1_Init();
  TIM2_Init(7200, 10);  

  USART1_SendString("Hello, USART1!\r\n");

  while (1) {
    GPIOA_SetPinHigh(5);
    Delay_ms(500);
    GPIOA_SetPinLow(5);
    Delay_ms(500);
    
    uint16_t value = ADC1_Read();

    // Save ADC data to memory
    if (buffer_index < ADC_BUFFER_SIZE) {
      adc_buffer[buffer_index++] = value;
    } else {
      buffer_index = 0;
    }

    // Send ADC value as two bytes via USART
    USART1_SendChar((value >> 8) & 0xFF);
    USART1_SendChar(value & 0xFF);
    
    Delay_ms(500);
  }
}
