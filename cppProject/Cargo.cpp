#include <iostream>
using namespace std;
#pragma warning (disable: 4996)


#include "Cargo.h"
#include <string.h>
#include "FlightCompException.h"

Cargo::Cargo(int mChairNumber, const char* mModel, float maxWeight, float maxVolume) throw(CompStringException) : Plane(mChairNumber, mModel)
{
	if (maxVolume < 0)
		throw CompStringException("max volume cannot be a negative value");
	else
		this->maxVolume = maxVolume;

	if (maxWeight < 0)
		throw CompStringException("max weight cannot be a negative value");
	else
		this->maxWeight = maxWeight;

	this->currentVolume = 0;
	this->currentWeight = 0;
}

Cargo::Cargo(Cargo& other) : Plane(other.chairNumber, other.model)
{
	if (other.maxVolume < 0)
		throw CompStringException("max volume cannot be a negative value");
	else
		this->maxVolume = other.maxVolume;

	if (other.maxWeight < 0)
		throw CompStringException("max weight cannot be a negative value");
	else
		this->maxWeight = other.maxWeight;

	this->currentVolume = 0;
	this->currentWeight = 0;
}

Cargo::~Cargo()
{
}

void Cargo::operator=(const Cargo& other)
{
	Plane::operator=(other);

	this->maxVolume = other.maxVolume;
	this->maxWeight = other.maxWeight;
	this->currentVolume = other.currentVolume;
	this->currentWeight = other.currentWeight;
}

bool Cargo::operator==(const Cargo& other)
{
	return Plane::operator==(other);
}

bool Cargo::operator!=(const Cargo& other)
{
	return !(*this == other);
}

void Cargo::toOs(ostream& os) const
{
	os << "Cargo M_vol"
		<< this->maxVolume
		<< " M_Kg "
		<< this->maxWeight
		<< " C_vol "
		<< this->currentVolume
		<< " C_Kg "
		<< this->currentWeight
		<< endl;
}

bool Cargo::Load(float weight, float volume)
{
	float totalVolume = this->currentVolume + volume;
	float totalWeight = this->currentWeight + weight;

	if (totalVolume < this->maxVolume && totalWeight < this->maxWeight) {
		currentVolume = totalVolume;
		currentWeight = totalWeight;
		return true;
	}
	return false;
}

void Cargo::takeOff(int flightTime) throw(CompStringException)
{
	if (flightTime < 0)
		throw CompStringException("Cargo plane cannot add negative flight time");

	cout << "Need to add " << flightTime << " to my log book" << endl;
}
