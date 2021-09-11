#ifndef __FLIGHT_H
#define __FLIGHT_H

#define MAX_CREW 20

#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"
#include <sstream>


class Flight
{


public:
	//c'tor
	Flight(FlightInfo& info);

	Flight(FlightInfo& info, Plane& plane);
	Flight(Flight& flight);
	Flight(istream& in):info(in) {

		in >> *this;

	}
	Flight();


	//d'tor
	~Flight();

	//getters
	FlightInfo GetFlightInfo();
	//setters
	void SetPlane(Plane& plane);
	//other methods
	void updatePlane(Plane& otherPlane);
	friend istream& operator>>(istream& in, Flight& f) {
		//if (typeid(in) == typeid(ifstream))
		char* hasPlane = new char[1];

		in >> hasPlane;
		stringstream t_s(hasPlane);

		int t;
		t_s >> t;
		if (t == 0)
			f.isPlaneAssigned = false;
		else
			f.isPlaneAssigned = true;
		//else {
		//	char delimiter;
		//	in >> delimiter >> c.name>>delimiter>>c.totalFlightTime>>delimiter;
		//}
		//f.fromOs(in);
		in >> f.numberOfMembers; //TODO - check what the 100 mean
		in >> f.numberOfMembers;
		for (int i = 0; i < f.numberOfMembers; i++) {
			char* type = new char[1];
			in >> type;
			stringstream t_s(type);

			int t;
			t_s >> t;
			if (t == 0) {
				//HOST
				f.crewMembers[i] = *new Host(in);
			}
			else {
				//PILOT
				f.crewMembers[i] = *new Pilot(in);

			}
		}
		return in;

	}
	void operator+(CrewMember& newMember);
	bool operator==(Flight& otherFlight);
	void operator=(Flight& other);
	
	friend ostream& operator<<(ostream& os, const Flight& data);
	bool TakeOff();

private:
	//attribuites
	FlightInfo info;
	Plane plane;
	CrewMember crewMembers[MAX_CREW];
	int numberOfMembers;
	bool isPlaneAssigned;
};




#endif // !__FLIGHT_H

