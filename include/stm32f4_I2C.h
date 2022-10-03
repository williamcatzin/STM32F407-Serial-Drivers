#ifndef STM32F4_I2C_H
#define STM32F4_I2C_H

#include <stm32f407xx.h>

/*
STM32 I2C Master Mode

In Master mode, the I2C interface initiates a data transfer and generates the clock signal. A
serial data transfer always begins with a Start condition and ends with a Stop condition.
Master mode is selected as soon as the Start condition is generated on the bus with a
START bit.

The following is the required sequence in master mode.

• Program the peripheral input clock in I2C_CR2 register in order to generate correct timings
• Configure the clock control registers
• Configure the rise time register
• Program the I2C_CR1 register to enable the peripheral
• Set the START bit in the I2C_CR1 register to generate a Start condition

*/

// I2C pins

class I2C
{
    public:
        I2C();

        // Write to peripheral device
        uint8_t Controller_Write(uint8_t peripheral_address, uint8_t *data, uint8_t size);
        // Read from peripheral device
        uint8_t Controller_Read(uint16_t peripheral_address);

};
#endif