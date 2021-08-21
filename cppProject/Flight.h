#ifndef __FLIGHT_H
#define __FLIGHT_H

#define MAX_CREW 20

#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"


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
	FlightInfo getFlightInfo();
	//setters
	void SetPlane(Plane& plane);
	//other methods
	void updatePlane(Plane& otherPlane);

	void operator+(CrewMember& newMember);
	bool operator==(Flight& otherFlight);
	void operator=(Flight& other)
	{
		this->numberOfMembers = other.numberOfMembers;
		for (int i = 0; i < other.numberOfMembers; i++) {
			this->crewMembers[i] = other.crewMembers[i];
		}

		this->isPlaneAssigned = other.isPlaneAssigned;
		if (other.isPlaneAssigned)
			this->info = other.info;
		this->plane = other.plane;

	}
	friend ostream& operator<<(ostream& os, const Flight& data);

private:
	//attribuites
	FlightInfo info;
	Plane plane;
	CrewMember crewMembers[MAX_CREW];
	int numberOfMembers;
	bool isPlaneAssigned;
};




#endif // !__FLIGHT_H

