#include "../../include/periph/thermistor.h"

// Constructor
Thermistor::Thermistor(PinName analogPin) : 
	_analogIn(analogPin) {}

float Thermistor::getFahrenheit(void) {
	//TODO
	return -1;
}
