#include <iostream>
using namespace std;

#pragma warning (disable: 4996)
#include <string.h>
#include "FlightInfo.h"

FlightInfo::FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength)
{
	this->flightNumber = mFlightNumber;
	this->flightTime = mFlightTime;
	this->flightLength = mFlightLength;
	
	if (strlen(mDestination) < MAX)
		strcpy(this->destination, mDestination);
}

FlightInfo::~FlightInfo()
{
	delete []this->destination;
}

int FlightInfo::getFlightNumber()
{
	return this->flightNumber;
}

int FlightInfo::getFlightTime()
{
	return this->flightTime;
}

int FlightInfo::getFlightLength()
{
	return this->flightLength;
}

char* FlightInfo::getDestination()
{
	return this->destination;
}

void FlightInfo::setFlightNumber(int mFlightNumber)
{
	this->flightNumber = mFlightNumber;
}

void FlightInfo::setFlightTime(int mFlightTime)
{
	this->flightTime = mFlightTime;
}

void FlightInfo::setFlightLength(int mFlightLength)
{
	this->flightLength = mFlightLength;
}

void FlightInfo::setDest(const char mDestination[])
{
	if (strlen(mDestination) < MAX)
		strcpy(this->destination, mDestination);
}

bool FlightInfo::isSameFlightNumber(int mFlightNumber)
{
	if (this->flightNumber == mFlightNumber)
		return true;
	return false;
}

void FlightInfo::print(ostream& out)
{
	out << "Flight info dest: "
		<< this->destination
		<< " NUmber "
		<< this->flightNumber
		<< " minutes "
		<< this->flightTime
		<< " KM "
		<< this->flightLength;
}
