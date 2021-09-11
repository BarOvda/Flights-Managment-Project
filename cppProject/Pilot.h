#pragma once
#include "CrewMember.h"
#include "Address.h"
class Pilot :
    public CrewMember
{
public:
	//c'tor
	Pilot(const char* name,bool isCaptian, Address* address);
	Pilot(const char* name, bool isCaptian);
	Pilot(std::istream& in) :CrewMember(in),adderss(in) {
		fromOs(in);
	}
	const bool operator+=(int minutes)
	{
		if (minutes > 0) {

			totalFlightTime += minutes;
			if (isCaptian)
				totalFlightTime += (minutes / 10);
		}
		return true;
	}
	virtual bool operator==(Pilot& other)
	{

		return strcmp(other.getName(), this->getName()) == 0
			&&other.adderss==this->adderss;
	}
	void GetPresent();
	virtual void fromOs(std::istream& in) override {
		char* isCapt = new char[1];

		in >> isCapt;
		stringstream is_cap(isCapt);

		int res;
		is_cap >> res;
		if (res == 0) {
			isCaptian = false;
		}
		else {
			isCaptian = true;
		}
	};
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
	friend std::ostream& operator<<(std::ostream& out, const Pilot& data);
private:
	Address adderss;
	bool isCaptian;
	

};

