#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include "Cargo.h"

Cargo::Cargo(int mChairNumber, const char* mModel, float maxCargoWeight, float maxCargoVolume) : Plane(mChairNumber, mModel)
{
	this->maxCargoVolume = maxCargoVolume;
	this->maxCargoWeight = maxCargoWeight;
	this->currentVolume = 0;
	this->currentWeight = 0;
}

Cargo::Cargo(Cargo& other) : Plane(other)
{
	this->maxCargoVolume = other.maxCargoVolume;
	this->maxCargoWeight = other.maxCargoWeight;
	this->currentVolume = 0;
	this->currentWeight = 0;
}

Cargo::~Cargo()
{

}

bool Cargo::load(float volume, float weight)
{
	if (this->currentVolume < this->maxCargoVolume && this->currentWeight < this->maxCargoWeight) {
		float totalWeight = this->currentWeight + weight;
		float totalVolume = this->currentVolume + volume;

		if (totalVolume <= this->maxCargoVolume && totalWeight <= this->maxCargoWeight) {
			this->currentVolume += volume;
			this->currentWeight += weight;

			return true;
		}
	}

	return false;
}

const Cargo& Cargo::operator=(const Cargo& other)
{
	Plane::operator=(other);

	this->currentVolume = other.currentVolume;
	this->currentWeight = other.currentWeight;
	this->maxCargoVolume = other.maxCargoVolume;
	this->maxCargoWeight = other.maxCargoWeight;

	return *this;
}

void Cargo::takeOff(ostream& os, const int flightTime)
{
	os << "Need to add " << flightTime << " to my log book";
}

