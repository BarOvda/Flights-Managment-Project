#ifndef __FLIGHT_H
#define __FLIGHT_H

#define MAX_CREW 20

class FlightInfo;
class Plane;
class CrewMember;


class Flight
{
	//attribuites
	FlightInfo& info;
	Plane& plane;
	CrewMember& crewMembers[MAX_CREW];
	int numberOfMembers;

public:
	//c'tor
	Flight(FlightInfo* mInfo, Plane* mPlane);

	//d'tor
	~Flight();

	//getters
	FlightInfo getFlightInfo();
	

	//other methods
	void updatePlane(Plane& otherPlane);

	void operator+(CrewMember& newMember);
	bool operator==(Flight& otherFlight);
	
	friend ostream& operator<<(ostream& os, const Flight& data);

private:

};

#endif // !__FLIGHT_H

