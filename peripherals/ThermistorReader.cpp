#include "mbed.h"
#include <math.h>
#include "AnalogSensorRead.hpp"
#include "analogin_api.h"
#include "UART.hpp"

#define NUM_THERMISTORS 6


//IMPORTANT!: ONLY WORKS WHEN FED 3.3V, NOT 5V!
void readAllThermistors() {
  //Starts serial communication with the PC
  int thermistorReading;

  PinName thermistors[NUM_THERMISTORS] = {A0, A1, A2, A3, A4, A5};
  while(1){
    for (int i = 0; i < NUM_THERMISTORS; i++){
      thermistorReading = thermistorRead(thermistors[i]);
      pc.printf("Thermistor %d: %d\n",i+1,thermistorReading);
    }
  pc.printf("\n");
  wait(1);
  }
}


int temperature;
unsigned short thermVolt;
int thermistorRead(PinName thermPin){
  AnalogIn therm(thermPin);
  thermVolt = therm.read_u16(); //Reads the thermistor
  temperature = (int)(Thermistor(thermVolt)); //Returns the temp in fahrenheit
  return temperature;
}


double Temp;
double Thermistor(int RawADC){
  //Equation for converting value to Kelvin
  Temp = log(10000.0*((65535.0/RawADC-1))) ;
  Temp = 1/(0.001129148 + (0.000234125 + (0.0000000876741 * Temp) * Temp) * Temp);

  Temp = (Temp - 273.15); //Converts Kelvin to Celcius
  Temp = (Temp * 9.0)/5.0 + 32.0; //Converts celcius temp to fahrenheit
  return Temp;
}

