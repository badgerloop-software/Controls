#ifndef MPU9250_H
#define MPU9250_H

/**
 * Includes
 */
#include "mbed.h"


/**
 * Defines
 */
#ifndef MPU9250_ADDRESS
    #define MPU9250_ADDRESS             0x68 //This could be 0x69 in some cases
#endif

#ifdef MPU9250_ES
        #define DOUBLE_ACCELERO
#endif

/**
 * Registers
 */
 #define MPU9250_CONFIG_REG         0x1A
 #define MPU9250_GYRO_CONFIG_REG    0x1B
 #define MPU9250_ACCELERO_CONFIG_REG    0x1C

 #define MPU9250_INT_PIN_CFG        0x37

 #define MPU9250_ACCEL_XOUT_H_REG   0x3B
 #define MPU9250_ACCEL_YOUT_H_REG   0x3D
 #define MPU9250_ACCEL_ZOUT_H_REG   0x3F

 #define MPU9250_TEMP_H_REG         0x41

 #define MPU9250_GYRO_XOUT_H_REG    0x43
 #define MPU9250_GYRO_YOUT_H_REG    0x45
 #define MPU9250_GYRO_ZOUT_H_REG    0x47



 #define MPU9250_PWR_MGMT_1_REG     0x6B
 #define MPU9250_WHO_AM_I_REG       0x75



 /**
  * Definitions
  */
#define MPU9250_SLP_BIT             6
#define MPU9250_BYPASS_BIT         1

#define MPU9250_BW_256              0
#define MPU9250_BW_188              1
#define MPU9250_BW_98               2
#define MPU9250_BW_42               3
#define MPU9250_BW_20               4
#define MPU9250_BW_10               5
#define MPU9250_BW_5                6

#define MPU9250_ACCELERO_RANGE_2G   0
#define MPU9250_ACCELERO_RANGE_4G   1
#define MPU9250_ACCELERO_RANGE_8G   2
#define MPU9250_ACCELERO_RANGE_16G  3

#define MPU9250_GYRO_RANGE_250      0
#define MPU9250_GYRO_RANGE_500      1
#define MPU9250_GYRO_RANGE_1000     2
#define MPU9250_GYRO_RANGE_2000     3


/** MPU9250 IMU library.
  *
  * Example:
  * @code
  * Later, maybe
  * @endcode
  */
class MPU9250 {
    public:
     /**
     * Constructor.
     *
     * Sleep mode of MPU9250 is immediatly disabled
     *
     * @param sda - mbed pin to use for the SDA I2C line.
     * @param scl - mbed pin to use for the SCL I2C line.
     */
     MPU9250(PinName sda, PinName scl);


     /**
     * Tests the I2C connection by reading the WHO_AM_I register.
     *
     * @return True for a working connection, false for an error
     */
     bool testConnection( void );

     /**
     * Sets the bandwidth of the digital low-pass filter
     *
     * Macros: MPU9250_BW_256 - MPU9250_BW_188 - MPU9250_BW_98 - MPU9250_BW_42 - MPU9250_BW_20 - MPU9250_BW_10 - MPU9250_BW_5
     * Last number is the gyro's BW in Hz (accelero BW is virtually identical)
     *
     * @param BW - The three bits that set the bandwidth (use the predefined macros)
     */
     void setBW( char BW );

     /**
     * Sets the auxiliary I2C bus in bypass mode to read the sensors behind the MPU9250 (useful for eval board, otherwise just connect them to primary I2C bus)
     *
     * @param state - Enables/disables the I2C bypass mode
     */
     void setI2CBypass ( bool state );

     /**
     * Sets the Accelero full-scale range
     *
     * Macros: MPU9250_ACCELERO_RANGE_2G - MPU9250_ACCELERO_RANGE_4G - MPU9250_ACCELERO_RANGE_8G - MPU9250_ACCELERO_RANGE_16G
     *
     * @param range - The two bits that set the full-scale range (use the predefined macros)
     */
     void setAccelRange(char range);

     /**
     * Reads the accelero x-axis.
     *
     * @return 16-bit signed integer x-axis accelero data
     */
     float getAccelX( bool scale );

     /**
     * Reads the accelero y-axis.
     *
     * @return 16-bit signed integer y-axis accelero data
     */
     float getAccelY( bool scale );

     /**
     * Reads the accelero z-axis.

     * @return 16-bit signed integer z-axis accelero data
     */
     float getAccelZ( bool scale);

     /**
     * Reads all accelero data.
     *
     * @param data - pointer to signed integer array with length three: data[0] = X, data[1] = Y, data[2] = Z
     */
     void getAccelAll( float *data, bool scale );

     /**
     * Sets the Gyro full-scale range
     *
     * Macros: MPU9250_GYRO_RANGE_250 - MPU9250_GYRO_RANGE_500 - MPU9250_GYRO_RANGE_1000 - MPU9250_GYRO_RANGE_2000
     *
     * @param range - The two bits that set the full-scale range (use the predefined macros)
     */
     void setGyroRange(char range);

     /**
     * Reads the gyro x-axis.
     *
     * @return 16-bit signed integer x-axis gyro data
     */
     int getGyroRawX( void );

     /**
     * Reads the gyro y-axis.
     *
     * @return 16-bit signed integer y-axis gyro data
     */
     int getGyroRawY( void );

     /**
     * Reads the gyro z-axis.
     *
     * @return 16-bit signed integer z-axis gyro data
     */
     int getGyroRawZ( void );

     /**
     * Reads all gyro data.
     *
     * @param data - pointer to signed integer array with length three: data[0] = X, data[1] = Y, data[2] = Z
     */
     void getGyroRawAll( int *data );

     /**
     * Reads all gyro data, gives the gyro in rad/s
     *
     * Function uses the last setup value of the full scale range, if you manually set in another range, this won't work.
     *
     * @param data - pointer to float array with length three: data[0] = X, data[1] = Y, data[2] = Z
     */
     void getGyroScaledAll( float *data);

     /**
     * Reads temperature data.
     *
     * @return 16 bit signed integer with the raw temperature register value
     */
     int getTempRaw( void );

     /**
     * Returns current temperature
     *
     * @returns float with the current temperature
     */
     float getTempScaled( void );

     /**
     * Sets the sleep mode of the MPU9250
     *
     * @param state - true for sleeping, false for wake up
     */
     void setSleepMode( bool state );


     /**
     * Writes data to the device, could be private, but public is handy so you can transmit directly to the MPU.
     *
     * @param adress - register address to write to
     * @param data - data to write
     */
     void write( char address, char data);

     /**
     * Read data from the device, could be private, but public is handy so you can transmit directly to the MPU.
     *
     * @param adress - register address to write to
     * @return - data from the register specified by RA
     */
     char read( char adress);

     /**
     * Read multtiple regigsters from the device, more efficient than using multiple normal reads.
     *
     * @param adress - register address to write to
     * @param length - number of bytes to read
     * @param data - pointer where the data needs to be written to
     */
     void read( char adress, char *data, int length);

     private:

     I2C connection;
     char currentAcceleroRange;
     char currentGyroRange;


};



#endif

