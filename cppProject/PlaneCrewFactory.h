#pragma once


typedef enum PlaneType
{
	eRegular,
	eCargo,
	nofPlaneType
};

typedef enum CrewType
{
	eHost,
	ePilot,
	nofCrewType
};
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;


const string PlaneType_TITLE[nofPlaneType] = { "Regular","Cargo" };
const string CrewType_TITLE[nofCrewType] = { "Host","Pilot" };


class Plane;
class CrewMember;
class FlightCompany;
class Address;

class PlaneCrewFactory
{
public:

	static PlaneType GetPlaneType(const Plane* pPlane);
	static CrewType GetCrewType(const CrewMember* pCrew);
	static void GetCompanyDataFromUser(FlightCompany& comp);
	static Plane* GetPlaneFromUser();
	static CrewMember* GetCrewFromUser();

	static CrewMember* GetCrewMemberFromFile(ifstream& inFile);
	static Plane* GetPlaneFromFile(ifstream& inFile);


private:
	PlaneCrewFactory(void) { ; }
};
