#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "CrewMember.h"

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
	delete []this->name;
}

int CrewMember::getTotalFlightTime()
{
	return this->totalFlightTime;
}

char* CrewMember::getName()
{
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

void CrewMember::print(ostream& out)
{
	out << "crew member " << this->name << " minutes " << this->totalFlightTime;
}
