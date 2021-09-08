#ifndef __CARGO
#define __CARGO

#include <string>
#include <iostream>

#include "Plane.h"

class Cargo : protected Plane
{

public:

	//c'tor
	Cargo(int mChairNumber, const char* mModel, float maxCargoWeight, float maxCargoVolume);
	Cargo(Cargo& other);

	//d'tor
	~Cargo();

	//more methods

	bool load(float volume, float weight);
	const Cargo& operator=(const Cargo& other);
	void takeOff(ostream& os, const int flightTime);


private:

	//attributes
	float maxCargoWeight;
	float maxCargoVolume;
	float currentWeight;
	float currentVolume;
};

#endif // !__CARGO
