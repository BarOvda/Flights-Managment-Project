#ifndef __FLIGHT_COMPANY
#define __FLIGHT_COMPANY
#define MAX_CREWS 100
#define MAX_PLANES 50
#define MAX_FLIGHT 25

#include "Flight.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Cargo.h"


class FlightCompany
{
public:
	//c'tor
	FlightCompany(const char* name);
	FlightCompany(FlightCompany& other);

	//d'tor
	~FlightCompany();

	//getters
	char* getCompanyName();
	Plane& GetPlane(int i);
	Flight* GetFlight(int f_number);
	CrewMember* GetCrew(int c_number);

	//setters
	void setName(const char* mName);

	//other methods
	void Print(ostream& out);
	bool AddCrewMember(CrewMember& crewMember);
	bool AddPlane(Plane& plane);
	bool AddFlight(Flight& flight);
	void AddCrewToFlight(int f_number, int crew_member_number);
	int getAmountOfCargoPlanes();

	//void AddFlight(FlightInfo flight);
//Operators
	bool operator==(FlightCompany& other);

private:
	//attributes
	char* companyName;
	CrewMember crewMembers[MAX_CREWS];
	Plane Planes[MAX_PLANES];
	Flight flights[MAX_FLIGHT];
	int numOfCrewMembers;
	int numOfPlanes;
	int numOfFlights;

};

#endif // !__FLIGHT_COMPANY

