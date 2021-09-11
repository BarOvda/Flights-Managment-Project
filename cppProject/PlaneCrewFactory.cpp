#include "PlaneCrewFactory.h"



PlaneType PlaneCrewFactory::GetPlaneType(const Plane* pPlane)
{
    return PlaneType();
}

CrewType PlaneCrewFactory::GetCrewType(const CrewMember* pCrew)
{
    return CrewType();
}

void PlaneCrewFactory::GetCompanyDataFromUser(FlightCompany& comp)
{
}

Plane* PlaneCrewFactory::GetPlaneFromUser()
{
    return nullptr;
}

CrewMember* PlaneCrewFactory::GetCrewFromUser()
{
    return nullptr;
}

CrewMember* PlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile)
{
    return nullptr;
}

Plane* PlaneCrewFactory::GetPlaneFromFile(ifstream& inFile)
{
    return nullptr;
}
