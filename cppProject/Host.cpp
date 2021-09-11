#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>

#include "Host.h"


Host::Host(const char* name, Host::eHostType type, int totalFlightTime) : CrewMember(name, totalFlightTime), type(type)
{
}

Host::Host(CrewMember& member) : CrewMember(member)
{
	this->type = eHostType::eRegular;
}

Host::Host(Host& other) : CrewMember(other)
{
	this->type = eHostType::eRegular;
}

Host::~Host()
{
}

void Host::operator=(const Host& other)
{
	if (*this != other) {
		this->totalFlightTime = other.totalFlightTime;

		delete[]name;
		this->name = strdup(other.name);
	}
}

bool Host::operator==(const Host& other)
{
	return CrewMember::operator==(other);
}

bool Host::operator!=(const Host& other)
{
	return !(*this == other);
}

void Host::toOs(ostream& os) const
{
	os << "Host ";
	switch (this->type)
	{
	case Host::eHostType::eRegular:
		os << "Regular ";
		break;
	case Host::eHostType::eSuper:
		os << "Super ";
		break;
	case Host::eHostType::eCalcelan:
		os << "Calcelan ";
		break;
	default:
		break;
	}
	os << this->name << " minutes " << this->totalFlightTime << endl;
}

const char* Host::getType()
{
	switch (this->type)
	{
	case Host::eHostType::eRegular:
		return "Regular";
		break;
	case Host::eHostType::eSuper:
		return "Super";
		break;
	case Host::eHostType::eCalcelan:
		return "Calcelan";
		break;
	default:
		break;
	}
}


void Host::getUniform() const
{
	cout << "I think the new uniform is very nice!" << endl;
}

void Host::takeOff(int flightTime)
{
	UpdateMinutes(flightTime);
}

void Host::getPresent() const
{
	CrewMember::getPresent();
	cout << "I wasn’t expecting it" << endl;
}

