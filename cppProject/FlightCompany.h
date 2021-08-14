#ifndef __FLIGHT_COMPANY
#define __FLIGHT_COMPANY
#define MAX_CREWS 100
#define MAX_PLANES 50
#define MAX_FLIGHT 25


class FlightCompany
{
public:
//c'tor
	FlightCompany(const char* mCompanyName/*,const CrewMember** crewMembers*/);
	FlightCompany(FlightCompany& otherCompany);

//d'tor
	~FlightCompany();

//getters
	char* getCompanyName();

//setters
	void setName(const char* mName);

//other methods
	void print(ostream& out);
	//void AddCrewMember(CrewMember crewMember);
	//void AddPlane(Plane plane);
	//void AddFlight(FlightInfo flight);
	

private:
//attributes
	char* companyName;
	//CrewMember crewMembers[MAX_CREWS];
	//Plane planes[MAX_PLANES];
	//FlightInfo flights[MAX_FLIGHT];
};

#endif // !__FLIGHT_COMPANY

