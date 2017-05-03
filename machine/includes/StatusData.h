#ifndef MACHINE_STATUSDATA_H_
#define MACHINE_STATUSDATA_H_

#include "EventData.h"
#include <string>

struct StatusData : public EventData {
	std::string statusMessage;
};

#endif
