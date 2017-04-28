#ifndef PERIPHERALS_LINEPRESSURE_H_
#define PERIPHERALS_LINEPRESSURE_H_

#include "mbed.h"
#include <vector>

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
    */
		int getPascals(void);
	
    /**
    * Gets pressure in PSI
    */
		int getPSI(void);
	
	private:
		AnalogIn analogIn;
};

#endif

