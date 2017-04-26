#ifndef PERIPHERALS_LINEPRESSURE_H_
#define PERIPHERALS_LINEPRESSURE_H_

#include "mbed.h"

class LinePressureSensor {
	public:
		/**
    * Constructor.
    *
    * @param analogOut - mbed pin to use for thermistor
    */
		LinePressureSensor(PinName analogPin);
	
    /**
    * Gets pressure in Pascals
    *
    * @param analogOut - mbed pin to use for pressure
    */
		int getPascals(void);
	
	private:
		AnalogIn analogIn;
};

#endif

