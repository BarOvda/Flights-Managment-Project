#pragma once
#include "CrewMember.h"
#include "Address.h"
class Pilot :
    public CrewMember
{
public:
	//c'tor
	Pilot(const char* name,bool isCaptian,const Address* address);
	Pilot(const char* name, bool isCaptian);
	const bool operator+=(int minutes)
	{
		if (minutes > 0) {

			totalFlightTime += minutes;
			if (isCaptian)
				totalFlightTime += (minutes / 10);
		}
		return true;
	}
	//d'tor
//	~FlightCompany();

	//getters
	/*char* getCompanyName();
	Plane& GetPlane(int i);
	Flight* GetFlight(int f_number);
	CrewMember* GetCrew(int c_number);*/

	//setters
	//void setName(const char* mName);

	//other methods
	void print(std::ostream& out);
	/*void Print(ostream& out);
	bool AddCrewMember(CrewMember& crewMember);
	bool AddPlane(Plane& plane);
	bool AddFlight(Flight& flight);
	void AddCrewToFlight(int f_number, int crew_member_number);*/

private:
	Address adderss;
	bool isCaptian;
	

};

