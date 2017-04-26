
#ifndef ANALOG_SENSOR_READ_H
#define ANALOG_SENSOR_READ_H
#include "mbed.h"

/*
* Summary:
*   Returns analog reading of IR sensor converted to readable measurement
*   Parameters:
*     double irsensorvalue = the value retrieved from the IR sensor
*     int sensorNumber = for specifying which IR sensor to read from
*   Return:
*     double reading = The value of the IR sensor in a readable unit
*/

double irRead(double analogIRvalue, int sensorNumber);


/**
* Summary:
* Used to determine the temperature in fahrenheit of every thermistor in the pod
* @param PinName thermPin
* @return double temperature = The temperature reading in fahrenheit from the
*                          thermistor

*/
void readAllThermistors(void);  //this one reads all the thermistors

//these are two helper methods for readAllThermistors()
int thermistorRead(PinName thermPin);
double Thermistor(int RawADC);

/*
* Summary:
*   Checks the PSI of the pressurized lines, mostly used in propulsion
*   Parameters:
*     double analogPressureLine = value returned from the pressure sensor in
*                                 the line
*   Return:
*     double pressure = The pressure reading in PSI
*/
int pressureLineRead(int sensorNumber);



#endif

