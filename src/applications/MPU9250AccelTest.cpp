#include "MPU9250AccelTest.hpp"

//Serial Communication with PC so we can send it data
Serial pc(SERIAL_TX, SERIAL_RX);

//Object of MPU9250 class
//I2C1 is located at port PB_9 and PB_8 on the Nucleo microcontroller
MPU9250 mpu9250(PB_9,PB_8);

int main()
{
    //Set the range of the acceleration to 2G's. We will never exceed this in
    //badgerloop so this is a good range. Can also do 4, 8, or 16 G's but with
    //less sensitivity. This range has a sensitivity of 16384 ticks per G.
    mpu9250.setAccelRange(MPU9250_ACCELERO_RANGE_2G);

    //Holds the x, y, and z axis variables
    float accelXYZ[3];

    //Read the MPU9250 forever
    while(1) {

        //Get all the acceleration data scaled to m/s^2 and send it to PC
        mpu9250.getAccelAll(accelXYZ, true);
        pc.printf("Accel X = %f\nAccel Y = %f\nAccel Z = %f\n\n",accelXYZ[0],
          accelXYZ[1], accelXYZ[2]);

        wait(.5); //Wait .5 seconds before taking next measurement
    }
}
