#ifndef __FLIGHT_H
#define __FLIGHT_H

#include "FlightInfo.h"
#include "CrewMember.h"
#include "Plane.h"



#define MAX_CREW 20

class Plane;

class Flight
{
public:
	//c'tor
	Flight(FlightInfo& info, Plane* plane = nullptr);
	Flight(const Flight& other);
	Flight();

	//d'tor
	~Flight();

	//other methods
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
