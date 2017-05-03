#ifndef PERIPHERALS_RETROREFLECTIVESENSOR_H_
#define PERIPHERALS_RETROREFLECTIVESENSRO_H_

#include "mbed.h"
#include "machine\includes\StateMachine.h"
#include "globals.h"

class RetroSensor {
	public:
		RetroSensor(PinName);
		void stripHandler();
		void watchdogHandler();
		void incrementCount();
		int getDistance();
		int getSpeed();
		int getCount();
		void attachWatchdog();
		
	private:
		InterruptIn _interrupt;
		volatile int _count;
		Ticker _watchdog;
		Timer _timer;
		int _speed;
		StatusData* _pStatus;
};
#endif
