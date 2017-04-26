#include "Thermistor.h"

// Constructor
Thermistor::Thermistor(PinName analogPin) : analogIn(analogPin) {
	// adds all instances to object list.
	sensors.push_back(this);
}

std::vector<Thermistor*> Thermistor::getSensors(void) {
	return sensors;
}

float Thermistor::getFahrenheit(void) {
	//TODO
	return -1;
}