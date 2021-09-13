#ifndef __PILOT_H
#define __PILOT_H
#include <sstream>

#include "CrewMember.h"

class Address;

class Pilot : public CrewMember
{
public:
	//c'tor
	Pilot(const char* mName, bool isACapitan, Address* address = nullptr, int mTotalFlightTime = 0);
	Pilot(CrewMember& member);
	Pilot(Pilot& other);

	Pilot(std::istream& in) :CrewMember(in) {
		//TODOADD
		fromOs(in);
	}

	//d'tor
	~Pilot();

	//other methods
	void operator=(const Pilot& other);
	bool operator==(const Pilot& other);
	bool operator!=(const Pilot& other);

	
	virtual void fromOs(std::istream& in) override {
		char* isCapt = new char[1];

		in >> isCapt;
		stringstream is_cap(isCapt);

		int res;
		is_cap >> res;

		if (res == 0) {
			isACapitan = false;
		}
		else {
			isACapitan = true;
		}
	};
	//d'tor
//	~FlightCompany();
	virtual void toOs(ostream& os) const override;


	// Inherited via CrewMember
	virtual void getUniform() const override;
	virtual void takeOff(int flightTime) override;
	virtual void getPresent() const override;
	virtual void gotoSimulator();

private:
	//attributes
	bool isACapitan;
	Address* address;

};


#endif // !__PILOT_H

