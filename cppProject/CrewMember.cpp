#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "CrewMember.h"
#include "Host.h"

int CrewMember::START_ID = 1000;


CrewMember::CrewMember(const char* mName, int mTotalFlightTime)
{
	this->name = new char[strlen(mName) + 1];
	strcpy(this->name, mName);

	this->totalFlightTime = mTotalFlightTime;
	

}

CrewMember::CrewMember(CrewMember& otherMember)
{
	this->name = new char[strlen(otherMember.getName()) + 1];
	strcpy(this->name, otherMember.getName());

	this->totalFlightTime = otherMember.getTotalFlightTime();
	

}



CrewMember::~CrewMember()
{
	delete[]this->name;
}

int CrewMember::getTotalFlightTime()
{
	return this->totalFlightTime;
}

char* CrewMember::getName()
{
	if(this)
		return this->name;
}



void CrewMember::setName(const char* mName)
{
	if (strlen(this->name) < strlen(mName))
		this->name = new char[strlen(mName) + 1];

	strcpy(this->name, mName);
}

bool CrewMember::UpdateMinutes(int minutes)
{
	if (minutes > 0) {
		this->totalFlightTime += minutes;
		return true;
	}
	return false;
}

bool CrewMember::IsEqual(CrewMember& otherMember)
{
	if (strcmp(this->name, otherMember.getName()) == 0)
		return true;
	return false;
}


void CrewMember::Print(ostream& out)
{
	//out << "crew member " << this->name << " minutes " << this->totalFlightTime;
		this->toOs(out);
}

void CrewMember::operator=(const CrewMember& other)
{
	if (*this != other) {
		this->totalFlightTime = other.totalFlightTime;

		delete[]name;
		this->name = strdup(other.name);
	}
}

bool CrewMember::operator==(const CrewMember& other)
{
	if (strcmp(this->name,other.name) == 0)
		return true;
	return false;
}

bool CrewMember::operator!=(const CrewMember& other)
{
	return !(*this == other);
}

bool CrewMember::operator+=(int minutes)
{
	if (minutes > 0) {
		this->totalFlightTime += minutes;
		return true;
	}
	return false;
}

void CrewMember::toOs(ostream& os) const
{
}

void CrewMember::getPresent() const
{
	cout << this->name << " thanking the company for receiving the holiday gift." << endl;
}

ostream& operator<<(ostream& os, const CrewMember& other)
{
	other.toOs(os);
	return os;
}
