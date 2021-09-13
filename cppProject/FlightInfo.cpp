#include <iostream>
using namespace std;

#pragma warning (disable: 4996)
#include <string.h>
#include "FlightInfo.h"
#include "FlightCompException.h"

FlightInfo::FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength)
{
	this->setDest(mDestination);
	this->setFlightLength(mFlightLength);
	this->setFlightNumber(mFlightNumber);
	this->setFlightTime(mFlightTime);
}

FlightInfo::FlightInfo(const FlightInfo& other)
{
	this->setDest(other.destination);
	this->setFlightLength(other.flightLength);
	this->setFlightNumber(other.flightNumber);
	this->setFlightTime(other.flightTime);
}

FlightInfo::FlightInfo()
{
}

FlightInfo::~FlightInfo()
{

}

int FlightInfo::GetFNum()
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

void FlightInfo::setFlightNumber(int mFlightNumber) throw(CompStringException)
{
	if (mFlightNumber < 0)
		throw CompStringException("Flight Number cannot have a negative value");
	else
		this->flightNumber = mFlightNumber;
}

void FlightInfo::setFlightTime(int mFlightTime) throw(CompStringException)
{
	if (mFlightTime < 0)
		throw CompStringException("Flight Time cannot have a negative value");
	else
		this->flightTime = mFlightTime;
}

void FlightInfo::setFlightLength(int mFlightLength) throw(CompStringException)
{
	if (mFlightLength < 0)
		throw CompStringException("Flight Length cannot have a negative value");
	else
		this->flightLength = mFlightLength;
}

void FlightInfo::setDest(const char mDestination[]) throw(CompStringException)
{
	if (strlen(mDestination) < MAX)
		strcpy(this->destination, mDestination);
	else
		throw CompStringException("destination value is too long");
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

void FlightInfo::operator=(const FlightInfo& other)
{
	if (*this != other) {
		this->flightNumber = other.flightNumber;
		this->flightTime = other.flightTime;
		this->flightLength = other.flightLength;

		if (strlen(other.destination) < MAX)
			strcpy(this->destination, other.destination);
	}
}

bool FlightInfo::operator==(const FlightInfo& other)
{
	if (this->flightNumber == other.flightNumber)
		return true;
	return false;
}

bool FlightInfo::operator!=(const FlightInfo& other)
{
	return !(*this == other);
}

FlightInfo::operator int()
{
	return this->flightTime;
}

ostream& operator<<(ostream& os, const FlightInfo& other)
{
	os << "Flight info dest: "
		<< other.destination
		<< " Number "
		<< other.flightNumber
		<< " minutes "
		<< other.flightTime
		<< " KM "
		<< other.flightLength;
	return os;
}
