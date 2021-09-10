#include "PlaneCrewFactory.h"

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane* pPlane)
{
    return PlaneType();
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember* pCrew)
{
    return CrewType();
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp)
{
}

CPlane* CPlaneCrewFactory::GetPlaneFromUser()
{
    return nullptr;
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser()
{
    return nullptr;
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile)
{
    return nullptr;
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& inFile)
{
    return nullptr;
}
