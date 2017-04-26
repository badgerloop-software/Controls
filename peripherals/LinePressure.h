#ifndef PERIPHERALS_LINEPRESSURE_H_
#define PERIPHERALS_LINEPRESSURE_H_

#include "mbed.h"
#include <vector>

#define BRAKE_TYPE			0
#define PROPULSION_TYPE	1

class LinePressureSensor {
	public:
		/**
    * Constructor.
    *
    * @param analogOut - mbed pin to use for thermistor
    */
		LinePressureSensor(PinName analogPin, int type);
	
    /**
    * Gets pressure in Pascals
    */
		int getPascals(void);
	
    /**
    * Gets pressure in PSI
    */
		int getPSI(void);
	
		static std::vector<LinePressureSensor*> getSensors(void);
	
	private:
		AnalogIn analogIn;
		int type;
		static std::vector<LinePressureSensor*> sensors;
};

#endif

