#include "MPU9250.hpp"

//Constructor
MPU9250::MPU9250(PinName sda, PinName scl) : connection(sda, scl) {

    //Disable sleep mode right away
    this->setSleepMode(false);

    //Initialize both accel and gyro to smallest range (most sensitive)
    currentGyroRange = MPU9250_GYRO_RANGE_250;
    currentAcceleroRange = MPU9250_ACCELERO_RANGE_2G;
}

//----------------------------------------------------
//General (YOU SHOULDNT HAVE TO CALL THESE DIRECTLY)--
//----------------------------------------------------

void MPU9250::write(char address, char data) {
    char temp[2];
    temp[0]=address;
    temp[1]=data;

    connection.write(MPU9250_ADDRESS * 2,temp,2);
}

char MPU9250::read(char address) {
    char retval;
    connection.write(MPU9250_ADDRESS * 2, &address, 1, true);
    connection.read(MPU9250_ADDRESS * 2, &retval, 1);
    return retval;
}

void MPU9250::read(char address, char *data, int length) {
    connection.write(MPU9250_ADDRESS * 2, &address, 1, true);
    connection.read(MPU9250_ADDRESS * 2, data, length);
}

void MPU9250::setSleepMode(bool state) {
    char temp;
    temp = this->read(MPU9250_PWR_MGMT_1_REG);
    if (state == true)
        temp |= 1<<MPU9250_SLP_BIT;
    if (state == false)
        temp &= ~(1<<MPU9250_SLP_BIT);
    this->write(MPU9250_PWR_MGMT_1_REG, temp);
}

bool MPU9250::testConnection( void ) {
    char temp;
    temp = this->read(MPU9250_WHO_AM_I_REG);
    return (temp == (MPU9250_ADDRESS & 0xFE));
}

void MPU9250::setBW(char BW) {
    char temp;
    BW=BW & 0x07;
    temp = this->read(MPU9250_CONFIG_REG);
    temp &= 0xF8;
    temp = temp + BW;
    this->write(MPU9250_CONFIG_REG, temp);
}

void MPU9250::setI2CBypass(bool state) {
    char temp;
    temp = this->read(MPU9250_INT_PIN_CFG);
    if (state == true)
        temp |= 1<<MPU9250_BYPASS_BIT;
    if (state == false)
        temp &= ~(1<<MPU9250_BYPASS_BIT);
    this->write(MPU9250_INT_PIN_CFG, temp);
}

//--------------------------------------------------
//----------------Accelerometer---------------------
//--------------------------------------------------

void MPU9250::setAccelRange( char range ) {
    char temp;
    range = range & 0x03;
    currentAcceleroRange = range;

    temp = this->read(MPU9250_ACCELERO_CONFIG_REG);
    temp &= ~(3<<3);
    temp = temp + (range<<3);
    this->write(MPU9250_ACCELERO_CONFIG_REG, temp);
}

float MPU9250::getAccelX( bool scale ) {
    float retval;
    char data[2];
    this->read(MPU9250_ACCEL_XOUT_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    if(scale) {
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_2G) {
          retval=(float)retval / 16384.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_4G){
          retval=(float)retval / 8192.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_8G){
          retval=(float)retval / 4096.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_16G){
          retval=(float)retval / 2048.0 * 9.81;
        }
    }
    return retval;
}

float MPU9250::getAccelY( bool scale ) {
    float retval;
    char data[2];
    this->read(MPU9250_ACCEL_YOUT_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    if(scale) {
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_2G) {
          retval=(float)retval / 16384.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_4G){
          retval=(float)retval / 8192.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_8G){
          retval=(float)retval / 4096.0 * 9.81;
        }
        if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_16G){
          retval=(float)retval / 2048.0 * 9.81;
        }
    }
    return retval;
}

float MPU9250::getAccelZ( bool scale ) {
  float retval;
  char data[2];
  this->read(MPU9250_ACCEL_ZOUT_H_REG, data, 2);
  retval = (data[0]<<8) + data[1];
  if(scale) {
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_2G) {
        retval=(float)retval / 16384.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_4G){
        retval=(float)retval / 8192.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_8G){
        retval=(float)retval / 4096.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_16G){
        retval=(float)retval / 2048.0 * 9.81;
      }
  }
  return retval;
}

void MPU9250::getAccelAll(float *data , bool scale ) {
    char temp[6];
    this->read(MPU9250_ACCEL_XOUT_H_REG, temp, 6);
    data[0] = (float)((temp[0]<<8) + temp[1]);
    data[1] = (float)((temp[2]<<8) + temp[3]);
    data[2] = (float)((temp[4]<<8) + temp[5]);

    if(scale) {
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_2G) {
          data[0]=data[0] / 16384.0 * 9.81;
          data[1]=data[1] / 16384.0 * 9.81;
          data[2]=data[2] / 16384.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_4G){
          data[0]=data[0] / 8192.0 * 9.81;
          data[1]=data[1] / 8192.0 * 9.81;
          data[2]=data[2] / 8192.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_8G){
          data[0]=data[0] / 4096.0 * 9.81;
          data[1]=data[1] / 4096.0 * 9.81;
          data[2]=data[2] / 4096.0 * 9.81;
      }
      if (currentAcceleroRange == MPU9250_ACCELERO_RANGE_16G){
          data[0]=data[0] / 2048.0 * 9.81;
          data[1]=data[1] / 2048.0 * 9.81;
          data[2]=data[2] / 2048.0 * 9.81;
      }
    }

}

//--------------------------------------------------
//------------------Gyroscope-----------------------
//--------------------------------------------------
void MPU9250::setGyroRange( char range ) {
    char temp;
    currentGyroRange = range;
    range = range & 0x03;
    temp = this->read(MPU9250_GYRO_CONFIG_REG);
    temp &= ~(3<<3);
    temp = temp + range<<3;
    this->write(MPU9250_GYRO_CONFIG_REG, temp);
}

int MPU9250::getGyroRawX( void ) {
    short retval;
    char data[2];
    this->read(MPU9250_GYRO_XOUT_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    return (int)retval;
}

int MPU9250::getGyroRawY( void ) {
    short retval;
    char data[2];
    this->read(MPU9250_GYRO_YOUT_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    return (int)retval;
}

int MPU9250::getGyroRawZ( void ) {
    short retval;
    char data[2];
    this->read(MPU9250_GYRO_ZOUT_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    return (int)retval;
}

void MPU9250::getGyroRawAll( int *data ) {
    char temp[6];
    this->read(MPU9250_GYRO_XOUT_H_REG, temp, 6);
    data[0] = (int)(short)((temp[0]<<8) + temp[1]);
    data[1] = (int)(short)((temp[2]<<8) + temp[3]);
    data[2] = (int)(short)((temp[4]<<8) + temp[5]);
}

void MPU9250::getGyroScaledAll( float *data ) {
    int temp[3];
    this->getGyroRawAll(temp);
    if (currentGyroRange == MPU9250_GYRO_RANGE_250) {
        data[0]=(float)temp[0] / 7505.7;
        data[1]=(float)temp[1] / 7505.7;
        data[2]=(float)temp[2] / 7505.7;
        }
    if (currentGyroRange == MPU9250_GYRO_RANGE_500){
        data[0]=(float)temp[0] / 3752.9;
        data[1]=(float)temp[1] / 3752.9;
        data[2]=(float)temp[2] / 3752.9;
        }
    if (currentGyroRange == MPU9250_GYRO_RANGE_1000){
        data[0]=(float)temp[0] / 1879.3;;
        data[1]=(float)temp[1] / 1879.3;
        data[2]=(float)temp[2] / 1879.3;
        }
    if (currentGyroRange == MPU9250_GYRO_RANGE_2000){
        data[0]=(float)temp[0] / 939.7;
        data[1]=(float)temp[1] / 939.7;
        data[2]=(float)temp[2] / 939.7;
        }
}
//--------------------------------------------------
//-------------------Temperature--------------------
//--------------------------------------------------
int MPU9250::getTempRaw( void ) {
    short retval;
    char data[2];
    this->read(MPU9250_TEMP_H_REG, data, 2);
    retval = (data[0]<<8) + data[1];
    return (int)retval;
}

float MPU9250::getTempScaled( void ) {
    float retval;
    retval=(float)this->getTempRaw();
    retval=(retval+521.0)/340.0+35.0;
    return retval;
}

