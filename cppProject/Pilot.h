#ifndef __PILOT_H
#define __PILOT_H

#include "CrewMember.h"

class Address;

class Pilot : public CrewMember
{
public:
	//c'tor
	Pilot(const char* mName, bool isACapitan, Address* address = nullptr, int mTotalFlightTime = 0);
	Pilot(CrewMember& member);
	Pilot(Pilot& other);
	Pilot(const char* name,bool isCaptian, Address* address);
	Pilot(const char* name, bool isCaptian);
	Pilot(std::istream& in) :CrewMember(in),adderss(in) {
		fromOs(in);
	}
	const bool operator+=(int minutes)
	{
		if (minutes > 0) {

	//d'tor
	~Pilot();

	//other methods
	void operator=(const Pilot& other);
	bool operator==(const Pilot& other);
	bool operator!=(const Pilot& other);
		return strcmp(other.getName(), this->getName()) == 0
			&&other.adderss==this->adderss;
	}
	void GetPresent();
	virtual void fromOs(std::istream& in) override {
		char* isCapt = new char[1];

		in >> isCapt;
		stringstream is_cap(isCapt);

		int res;
		is_cap >> res;
		if (res == 0) {
			isCaptian = false;
		}
		else {
			isCaptian = true;
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

