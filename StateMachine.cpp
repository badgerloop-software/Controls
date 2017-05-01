#include "StateMachine.h"

StateMachine::StateMachine() :
	currentState(IDLE),
	_isEventGenerated(false),
	_pEventData(NULL) {}

// generates external event. External events are
// events that do are called independent of
// the state machine. Only difference between
// internal and external is that external checks
// if state is possible.
void StateMachine::externalEvent(unsigned char newState,
																 EventData* pData) {
	if (newState == EVENT_IGNORED) {
		if (pData) delete pData;
	} else {
		internalEvent(newState, pData);
		StateEngine();
	}
}
																 
// internal events transition to a new state
void StateMachine::internalEvent(unsigned char newState,
																 EventData* pData) {
	_pEventData = pData;
	_isEventGenerated = true;
	currentState = newState;
}
																 
void StateMachine::StateEngine() {
	EventData* pDataTemp = NULL;
	// we set up like this so that we can deal with
	// concurrency without failure of the machine
	while (_isEventGenerated) {
		pDataTemp = _pEventData;
		_pEventData = NULL;
		_isEventGenerated = false;
		
		// with that state map, call the state
		const StateStruct* pStateMap = GetStateMap();
		(this->*pStateMap[currentState].pStateFunc)(pDataTemp);
		if (pDataTemp) {
			delete pDataTemp;
			pDataTemp = NULL;
		}
	}
}
// external event functions

// state functions //TODO
void StateMachine::fault() {}
void StateMachine::idle() {}
void StateMachine::ready() {}
void StateMachine::pushing() {}
void StateMachine::coast() {}
void StateMachine::braking() {}
