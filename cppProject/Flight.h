#ifndef __FLIGHT_H
#define __FLIGHT_H

#include "FlightInfo.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"
#include <sstream>



#define MAX_CREW 20

class Plane;

class Flight
{
public:
	//c'tor

	
	Flight(istream& in):info(in) {

		in >> *this;

	}
	Flight(FlightInfo& info, Plane* plane = nullptr);
	Flight(const Flight& other);
	Flight();

	//d'tor
	~Flight();

	//other methods
	

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
			//if (t == 0) {
			//	//HOST
			//	f.crewMembers[i] = *new Host(in);
			//}
			//else {
			//	//PILOT
			//	f.crewMembers[i] = *new Pilot(in);

			//}
		}
		return in;
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
