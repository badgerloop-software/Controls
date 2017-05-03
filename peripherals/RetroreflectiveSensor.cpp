#include "RetroreflectiveSensor.h"

// Attaches handler to sensor
RetroSensor::RetroSensor(PinName pin) : _interrupt(pin), _pStatus(new StatusData) {
	_interrupt.rise(callback(this, &RetroSensor::stripHandler));
	_pStatus->statusMessage = "Retro Watchdog Timeout";		// only eventData that we'd send
}

void RetroSensor::stripHandler() {
	// interrupt hug so the filling doesn't get messy 
	__disable_irq();
	_timer.stop();
	incrementCount();
	__enable_irq();
}

void RetroSensor::watchdogHandler() {
	stateMachine->callFault(_pStatus);
}

void RetroSensor::incrementCount() { _count++; }

int RetroSensor::getCount() { return _count; }

int RetroSensor::getDistance() { return _count * 100; }

//TODO
int RetroSensor::getSpeed() { return -1; }

void RetroSensor::attachWatchdog() { _watchdog.attach(callback(this, &RetroSensor::watchdogHandler), MAX_RETRO_TIMEOUT_S); }

