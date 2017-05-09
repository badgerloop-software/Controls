#ifndef PERIPHERALS_THERMISTOR_H_
#define PERIPHERALS_THERMISTOR_H_

#include "mbed.h"

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
	
	private:
		AnalogIn _analogIn;
};




#endif
