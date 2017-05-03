#ifndef MACHINE_EVENTDATA_H_
#define MACHINE_EVENTDATA_H_

// Allows us to share data across the state machine.
// Doing it like this is required with some sort of
// RTOS. Virtual functions usually are implemented
// by the classes that inherit it.
class EventData {
	public:
		virtual ~EventData() {};
};

#endif
