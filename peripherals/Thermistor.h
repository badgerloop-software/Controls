#ifndef PERIPHERALS_THERMISTOR_H_
#define PERIPHERALS_THERMISTOR_H_

#include "mbed.h"
#include <vector>

class Thermistor {
	public:
    /**
    * Constructor.
    *
    * @param analogOut - mbed pin to use for thermistor
    */
		Thermistor(PinName analogPin);
	
    /**
    * Gets temperature in fahrenheit
    *
    * @param analogOut - mbed pin to use for thermistor
    */		
		float getFahrenheit(void);
	
		static std::vector<Thermistor*> getSensors(void);
	
	private:
		AnalogIn analogIn;
		static std::vector<Thermistor*> sensors;
};




#endif