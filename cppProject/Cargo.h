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
	Cargo(std::istream& in) :Plane(in) {
		fromOs(in);
	}
	//d'tor
	~Cargo();

	//other methods
	void operator=(const Cargo& other);
	bool operator==(const Cargo& other);
	bool operator!=(const Cargo& other);

	bool Load(float weight, float volume);

	virtual void toOs(ostream& os) const override;

	virtual void fromOs(std::istream& in) override {
		if (typeid(in) == typeid(ifstream)) {

			in >> maxVolume >> maxWeight >> currentVolume >> currentWeight;
		}
		else {

			cout << "Enter maxVolume:" << endl;

			in >> maxVolume;
			cout << "Enter maxWeight:" << endl;

			in >> maxWeight;
			cout << "Enter currentVolume:" << endl;

			in >> currentVolume;

			cout << "Enter currentWeight:" << endl;

			in >> currentWeight;
		}
	};

	virtual void takeOff(int flightTime);

private:
	//attributes
	float maxWeight;
	float maxVolume;
	float currentWeight;
	float currentVolume;

};

#endif // !__CARGO_H

