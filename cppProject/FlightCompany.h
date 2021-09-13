#ifndef __FLIGHT_COMPANY
#define __FLIGHT_COMPANY

#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"

#define MAX_CREWS 20
#define MAX_PLANES 20
#define MAX_FLIGHT 20

class FlightCompany
{
public:
	//c'tor
	FlightCompany(const char* name);
	FlightCompany(FlightCompany& other);
	FlightCompany(const char* filePath, int x);

	//d'tor
	~FlightCompany();

	//getters
	char* getCompanyName();
	Flight* GetFlightByNum(int number);
	CrewMember* GetCrewMember(int index);
	Plane* GetPlane(int index);
	int GetCargoCount();

	//setters
	void setName(const char* mName);

	//other methods
	void SaveToFile(const char* filePath);
	void Print(ostream& out);
	bool AddCrewMember(CrewMember& other);
	bool AddPlane(Plane& other);
	bool AddFlight(Flight& other);
	void AddCrewToFlight(int flightNum, int memberNum);
	void PilotsToSimulator();
	void CrewGetPresent();
	void CrewGetUniform();
	void TakeOff(int flightNumber);
	int GetCrewCount();

	Plane& operator[](int index);

private:
	//attributes
	char* companyName;
	CrewMember* members[MAX_CREWS];
	Plane* planes[MAX_PLANES];
	Flight flights[MAX_FLIGHT];
	int numberOfCrews;
	int numberOfPlanes;
	int numberOfFlights;
};

#endif // !__FLIGHT_COMPANY

