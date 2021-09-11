#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

#include <string.h>

#include "Pilot.h"


Pilot::Pilot(const char* mName, bool isACapitan, Address* address, int mTotalFlightTime): CrewMember(mName, mTotalFlightTime)
{
	this->isACapitan = isACapitan;
	this->address = address;
}

Pilot::Pilot(CrewMember& member): CrewMember(member)
{
	isACapitan = false;
}

Pilot::Pilot(Pilot& other): CrewMember(other)
{
	this->isACapitan = other.isACapitan;
	this->address = other.address;
}

Pilot::~Pilot()
{
}

void Pilot::operator=(const Pilot& other)
{
	CrewMember::operator=(other);

	this->isACapitan = other.isACapitan;
	this->address = other.address;
}

bool Pilot::operator==(const Pilot& other)
{
	if (CrewMember::operator==(other) && this->address == other.address)
		return true;
	return false;
}

bool Pilot::operator!=(const Pilot& other)
{
	return !(*this == other);
}

void Pilot::toOs(ostream& os) const
{
	os << "Pilot " << this->name << " minutes " << this->totalFlightTime << " ";

	if (this->address != nullptr)
		os << &this->address << endl;
		
	if (this->isACapitan)
		os << " a Captian";
	else
		os << " not a Captian";

	os << endl;
}

void Pilot::getUniform() const
{
	cout << this->name <<" this is the fifth time I get a new uniform – this is a waste of money!" << endl;
}

void Pilot::takeOff(int flightTime)
{
	UpdateMinutes(flightTime + (flightTime * 0.1));
}

void Pilot::getPresent() const
{
	CrewMember::getPresent();
}

void Pilot::gotoSimulator()
{
	cout << "Pilot " << this->name << " got the message will come soon" << endl;
}


