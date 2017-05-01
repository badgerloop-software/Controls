#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "mbed.h"

// Forward declaration probably should have used multiple
// files
class StateMachine;

// Allows us to share data across the state machine.
// Doing it like this is required with some sort of
// RTOS. Virtual functions usually are implemented
// by the classes that inherit it.
class EventData {
	public:
		virtual ~EventData() {};
};


// Found this treat using preprocessor directives.
// Allows to create the GetStateMap() function
// or its individual members (transition map) The '\' 
// needs to be the last char on each line so we can 
// have multi-line define statements. Creates null
// terminated array
#define BEGIN_TRANSITION_MAP \
		static const unsigned char TRANSITIONS[] = { \
#define TRANSITION_MAP_ENTRY(entry) \
			entry,
#define END_TRANSITION_MAP(data) \
			0 \
		}; \
	ExternalEvent(TRANSITIONS[currentState], data);

// State machine functions are of this type. Eventually
// will use this type for an array of pointers
// of this type
typedef void (StateMachine::*StateFunc)(EventData *);

// struct of state functions
struct StateStruct {
	StateFunc pStateFunc;
};

class StateMachine {
	public:
		StateMachine();
		~StateMachine();
		// External events here
		// e.g. a low battery would need an event func
	
	protected:
		enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN};
		unsigned char currentState;
		void externalEvent(unsigned char, EventData* = NULL);
		void internalEvent(unsigned char, EventData* = NULL);
		
	private:
		// state machine functions. May need EventData
		void fault();
		void idle();
		void ready();
		void pushing();
		void coast();
		void braking();
		
		// state map
		const StateStruct* GetStateMap() {
			static const StateStruct stateMap[] = {
				{(StateFunc)&StateMachine::fault},
				{(StateFunc)&StateMachine::idle},
				{(StateFunc)&StateMachine::ready},
				{(StateFunc)&StateMachine::pushing},
				{(StateFunc)&StateMachine::coast},
				{(StateFunc)&StateMachine::braking},	
				{NULL}
			};
			return &stateMap[0];
		}
	
		enum States {
			FAULT = 0,
			IDLE,
			READY,
			PUSHING,
			COAST,
			BRAKING
		};
	
		// normal fields. StateEngine is called after
		// any event occurs. _eventGenerated is a flag
		// that is required if we want to RTOS it.
		bool _isEventGenerated;
		EventData* _pEventData;
		void StateEngine();
};

#endif
