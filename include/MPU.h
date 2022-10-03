/**
 * @file MPU.h
 * @author William Catzin 
 * @brief 
 */

#ifndef MPU_H
#define MPU_H

#include <inttypes.h>

// The MPU6050 will come up in sleep mode upon power-up.
// The device must be woken up

constexpr uint16_t MPU_ID1 = 0x68;        // Default I2C address
constexpr uint16_t MPU_ID2 = 0x69;


// Register 25 – Sample Rate Divider (SMPRT_DIV)
constexpr uint8_t MPU_SMPRT_DIV = 0x19;

// Register 35 – FIFO Enable (FIFO_EN)
constexpr uint8_t MPU_FIFO_EN = 0x23;

// Registers 37 to 39 – I2C Slave 0 Control

constexpr uint8_t MPU_I2C_SLV0_ADDR = 0x25;     // I2C_SLV0_ADDR 

constexpr uint8_t MPU_I2C_SLV0_REG = 0x26;      // I2C_SLV0_REG

constexpr uint8_t MPU_I2C_SLV0_CTRL = 0x27;     // I2C_SLV0_CTRL

// Registers 59 to 64 – Accelerometer Measurements

constexpr uint8_t MPU_ACCEL_XOUT_H = 0x3B;      // ACCEL_XOUT_H 

constexpr uint8_t MPU_ACCEL_XOUT_L = 0x3C;      // ACCEL_XOUT_L

constexpr uint8_t MPU_ACCEL_YOUT_H = 0x3D;      // ACCEL_YOUT_H 
 
constexpr uint8_t MPU_ACCEL_YOUT_L = 0x3E;      // ACCEL_YOUT_L 

constexpr uint8_t MPU_ACCEL_ZOUT_H = 0x3F;      // ACCEL_ZOUT_H 

constexpr uint8_t MPU_ACCEL_ZOUT_L = 0x40;      // ACCEL_ZOUT_L

// Registers 67 to 72 – Gyroscope Measurements

constexpr uint8_t MPU_GYRO_XOUT_H = 0x43;       // GYRO_XOUT_H

constexpr uint8_t MPU_GYRO_XOUT_L = 0x44;       // GYRO_XOUT_L

constexpr uint8_t MPU_GYRO_YOUT_H = 0x45;       // GYRO_YOUT_H

constexpr uint8_t MPU_GYRO_YOUT_L = 0x46;       // GYRO_YOUT_L

constexpr uint8_t MPU_GYRO_ZOUT_H = 0x47;       // GYRO_ZOUT_H

constexpr uint8_t MPU_GYRO_ZOUT_L = 0x48;       // GYRO_ZOUT_L

// Register 106 – User Control (USER_CTRL)
constexpr uint8_t MPU_USER_CTRL = 0x6A;

//Register 107 – Power Management 1 PWR_MGMT_1
constexpr uint8_t MPU_PWR_MGMT_1 = 0x6B;

// Register 117 – Who Am I WHO_AM_I
constexpr uint8_t MPU_WHO_AM_I = 0x75;





class MPU6050
{
    public:
        MPU6050();

        //void MPU_setAddress(uint8_t address);
        //void MPU_gyroConfig();
        //void MPU_accelConfig();
        uint8_t MPU_calibrate(void);

        int MPU_accel_offset[3];
        int MPU_gyro_offset[3];

    private:
};

#endif

