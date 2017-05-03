#include "includes\StateMachine.h"

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
// external event functions //TODO
void StateMachine::callFault(StatusData* pStatusData) {
	pc.printf(pStatusData->statusMessage.c_str());
	BEGIN_TRANSITION_MAP											// state table
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)		// Fault
		TRANSITION_MAP_ENTRY (FAULT)						// Idle
		TRANSITION_MAP_ENTRY (FAULT)						// Ready
		TRANSITION_MAP_ENTRY (FAULT)						// Pushing
		TRANSITION_MAP_ENTRY (FAULT)						// Coast
		TRANSITION_MAP_ENTRY (FAULT)						// Brake
	END_TRANSITION_MAP(pStatusData)
}


// state functions //TODO
// What happens to 
void StateMachine::fault(StatusData* pStatusData) {

}

// Initial state. Setup connection to network and send
// heartbeats. Close braking valves and solenoids. Verify
// line pressure, verify propulsion pressure, verify doors
// are closed. Verify battery voltage and current.
// wait for dashboard being ready. We do not fault in
// this state.
void StateMachine::idle() {

}

// Entered from idle. Wait for limit switch to be pressed
// by pusher and acceleration to be positive
void StateMachine::ready() {

}

// Retro timer starts. Fault if we don't see a retro
// right away. Navigation starts. Enter coast after
// limit switch opens.
void StateMachine::pushing() {

}

// Open the propulsion valves. Fault if no retro. 
// brake under a certain time or signal.
void StateMachine::coast() {
}

// Close propulsion valves. Open braking valves.
// wait for velocity == 0 for 5 seconds then depress.
void StateMachine::braking() {

}
