#ifndef __CARGO_H
#define __CARGO_H

#include <ostream>

#include "Plane.h"


class Cargo : public Plane
{
public:
	//c'tor
	Cargo(int mChairNumber, const char* mModel, float maxWeight, float maxVolume);
	Cargo(Cargo& other);

	//d'tor
	~Cargo();

	//other methods
	void operator=(const Cargo& other);
	bool operator==(const Cargo& other);
	bool operator!=(const Cargo& other);

	virtual void toOs(ostream& os) const override;

	bool Load(float weight, float volume);
	virtual void takeOff(int flightTime);

private:
	//attributes
	float maxWeight;
	float maxVolume;
	float currentWeight;
	float currentVolume;

};

#endif // !__CARGO_H

