#ifndef __FLIGHT_H
#define __FLIGHT_H

#include "FlightInfo.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"
#include "PlaneCrewFactory.h"

#include <sstream>


#define MAX_CREW 20

class Plane;

class Flight
{
public:

	//c'tor
	Flight(istream& in) :info(in) {

		in >> *this;
	}

	Flight(FlightInfo& info, Plane* plane = nullptr);
	Flight(const Flight& other);
	Flight();

	//d'tor
	~Flight();

	//other methods

	virtual void fromOS(std::istream& in) {
		in >> this->isPlaneAssigned;
		char* b = new char[100];
		in >> b;
		in >> this->numberOfMembers;

		for (int i = 0; i < this->numberOfMembers; i++) {
			char* type = new char[1];
			in >> type;
			stringstream t_s(type);

			int t;
			t_s >> t;
			if (t == 0) {
				//HOST
				this->members[i] = new Host(in);
			}
			else {
				//PILOT
				this->members[i] = new Pilot(in);
			}
		}
	};
	friend istream& operator>>(istream& in, Flight& f) {
		if (typeid(in) == typeid(ifstream)) {
			char* hasPlane = new char[1];

			in >> hasPlane;
			stringstream t_s(hasPlane);

			int t;
			t_s >> t;
			if (t == 0)
				f.isPlaneAssigned = false;
			else
				f.isPlaneAssigned = true;

			in >> f.numberOfMembers; //TODO - check what the 100 mean
			in >> f.numberOfMembers;
			for (int i = 0; i < f.numberOfMembers; i++) {
				char* type = new char[1];
				in >> type;
				stringstream t_s(type);

				int t;
				t_s >> t;
				if (t == 0) {
					f.members[i] = new Host(in);
				}
				else {
					f.members[i] = new Pilot(in);
				}
			}
		}
		else {
			in >> f.info;
			cout << "Enter if assign" << endl;
			in >> f.isPlaneAssigned;
		}
		return in;
	}

	bool AddCrewMember(CrewMember& other)
	{
		if (this->numberOfMembers < MAX_CREW) {
			this->members[numberOfMembers] = &other;
			return true;
		}
		return false;
	}

	void SetPlane(Plane* plane);
	int GetFlightNumber();
	Plane* GetPlane();
	FlightInfo& GetFlightInfo();

	void operator+(CrewMember* member);
	void operator=(const Flight& other);
	bool operator==(const Flight& other);
	bool operator!=(const Flight& other);

	friend ostream& operator<<(ostream& os, const Flight& other);

	bool TakeOff();

private:
	//attributes
	FlightInfo info;
	Plane* plane;
	CrewMember* members[MAX_CREW];
	int numberOfMembers;
	bool isPlaneAssigned;
};

#endif // !__FLIGHT_H
