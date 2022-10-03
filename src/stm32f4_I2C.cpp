#include "stm32f4_I2C.h"

I2C::I2C()
{
    RCC->APB1ENR |= 1 << 21;    // enable I2C CLOCK

    RCC->AHB1ENR |= 1 << 1;     // Enable GPIOB CLOCK

    GPIOB->MODER |= 2 << 16;    // MODER8[1:0] = 10 --> Alternate Function for Pin PB8
    GPIOB->MODER |= 2 << 18;    // MODER9[1:0] = 10 --> Alternate Function for Pin PB9

    GPIOB->OTYPER |= 1 << 8;    //  Bit8=1 output open drain
    GPIOB->OTYPER |= 1 << 9;    //  Bit9=1 output open drain
    
    GPIOB->OSPEEDR |= 3 << 16;  // Bits (17:16)= 1:1 --> High Speed for PIN PB8 
    GPIOB->OSPEEDR |= 3 << 18;  // Bits (19:18)= 1:1 --> High Speed for PIN PB9

    GPIOB->PUPDR |= 1 << 16;  // Bits (17:16)= 0:1 --> Pull up for PIN PB8
    GPIOB->PUPDR |= 1 << 18;  // Bits (19:18)= 0:1 --> pull up for PIN PB9

    GPIOB->AFR[1] |= 4 << 0;  // Bits (3:2:1:0) = 0:1:0:0 --> AF4 for pin PB8
    GPIOB->AFR[1] |= 4 << 4;  // Bits (7:6:5:4) = 0:1:0:0 --> AF4 for pin PB9
}

uint8_t I2C::Controller_Write(uint8_t peripheral_addr, uint8_t *data, uint8_t size)
{
    I2C1->CR1 &= ~I2C_CR1_PE;       // Set I2C_CR1 bit0 = 0 (Peripheral Disable)


}