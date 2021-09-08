#ifndef __FLIGHT_H
#define __FLIGHT_H

#define MAX_CREW 20

#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"


class Flight
{


public:
	//c'tor
	Flight(FlightInfo& info);

	Flight(FlightInfo& info, Plane& plane);
	Flight(Flight& flight);

	Flight();


	//d'tor
	~Flight();

	//getters
	FlightInfo GetFlightInfo();
	//setters
	void SetPlane(Plane& plane);
	//other methods
	void updatePlane(Plane& otherPlane);

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

