#include "LinePressure.h"

// Constructor
LinePressureSensor::LinePressureSensor(PinName analogPin, int type) : analogIn(analogPin),
																																						type(type)	{
	sensors.push_back(this);
}
	
int LinePressureSensor::getPascals(void) {
	//TODO
	return -1;
}

int LinePressureSensor::getPSI(void) {
	//TODO
	return -1;
}

std::vector<LinePressureSensor*> LinePressureSensor::getSensors(void) {
	return sensors;
}
