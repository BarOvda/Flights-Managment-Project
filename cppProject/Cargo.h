#ifndef __CARGO
#define __CARGO

#include <string>
#include <iostream>

#include "Plane.h"

class Cargo : public Plane
{

public:

	//c'tor
	Cargo(int mChairNumber, const char* mModel, float maxCargoWeight, float maxCargoVolume);
	Cargo(Cargo& other);
	Cargo(std::istream& in) :Plane(in) {
		fromOs(in);
	}
	//d'tor
	~Cargo();

	//more methods

	bool load(float volume, float weight);
	const Cargo& operator=(const Cargo& other);
	void takeOff(ostream& os, const int flightTime);
	virtual void fromOs(std::istream& in) override {
		char* tt = new char[10];
		in >> tt;
		//in >> maxCargoVolume >> maxCargoWeight >> currentVolume>>currentWeight;
	};

private:

	//attributes
	float maxCargoWeight;
	float maxCargoVolume;
	float currentWeight;
	float currentVolume;
};

#endif // !__CARGO
