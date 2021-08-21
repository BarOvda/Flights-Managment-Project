#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "CrewMember.h"

int CrewMember::currentMemberNumber = CrewMember::START_ID;
CrewMember::CrewMember() {
	//this->name = new char[1];

}

CrewMember::CrewMember(const char* mName, int mTotalFlightTime)
{
	this->name = new char[strlen(mName) + 1];
	strcpy(this->name, mName);

	this->totalFlightTime = mTotalFlightTime;
	this->memberNumber = currentMemberNumber++;
}

CrewMember::CrewMember(CrewMember& otherMember)
{
	this->name = new char[strlen(otherMember.getName()) + 1];
	strcpy(this->name, otherMember.getName());

	this->totalFlightTime = otherMember.getTotalFlightTime();
	this->memberNumber = otherMember.getMemberNumber();
}

CrewMember::~CrewMember()
{
	try {
		delete[]this->name;
		//delete this;
	}
	catch (exception ex) {
		cout << ex.what();
	}
}

int CrewMember::getTotalFlightTime()
{
	return this->totalFlightTime;
}

char* CrewMember::getName()
{
	return this->name;
}

int CrewMember::getMemberNumber()
{
	return this->memberNumber;
}

void CrewMember::setName(const char* mName)
{
	if (strlen(this->name) < strlen(mName))
		this->name = new char[strlen(mName) + 1];

	strcpy(this->name, mName);
}

//bool CrewMember::UpdateMinutes(int minutes)
//{
//	if (minutes > 0) {
//		this->totalFlightTime += minutes;
//		return true;
//	}
//	return false;
//}

bool CrewMember::IsEqual(CrewMember& otherMember)
{
	if (this->memberNumber == otherMember.getMemberNumber())
		return true;
	return false;
}

void CrewMember::print(ostream& out)
{
	out << "crew member " << this->name << " minutes " << this->totalFlightTime;
}

void CrewMember::setCurrentMemberNumber(int mCurrentMemberNumber)
{
	CrewMember::currentMemberNumber = mCurrentMemberNumber;
}

 ostream& operator<<(ostream& os, const CrewMember& data) {
	os << "Name "
		<< data.name
		<< " Member Number "
		<< data.memberNumber
		<< " Total Flight Time "
		<< data.totalFlightTime;
	return os;
}
