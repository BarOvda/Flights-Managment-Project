#include "Host.h"
Host::Host(const char* name, Type type) :CrewMember(name) {
	this->type = type;
}