#include "PlaneCrewFactory.h"
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#include <fstream>
#include <string.h>
#include "FlightCompany.h"
#include "Cargo.h"
#include "Pilot.h"
#include "Host.h"
#include <sstream>



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
    cout << "Enter Name" << endl;
    char* compName = new char[10];
    std::cin >> compName;
    comp.setName(compName);
    cout << "Enter Crew Members Number" << endl;
    int numOfMembers,numOfPlanes;
    std::cin >> numOfMembers;
    for (int i = 0; i < numOfMembers; i++) {
        cout << "Enter Crew Member Number: "<<i << endl;

        comp.AddCrewMember(*GetCrewFromUser());

    }
    std::cin >> numOfPlanes;
    for (int i = 0; i < numOfPlanes; i++) {
        comp.AddPlane(*GetPlaneFromUser());

    }
}

Plane* PlaneCrewFactory::GetPlaneFromUser()
{
    return nullptr;
}

CrewMember* PlaneCrewFactory::GetCrewFromUser()
{
    cout << "Enter Crew Member Type :" << endl;

    int type;
    CrewMember* crew;
    std::cin >> type;
    if (type == 0) {
        *crew = Host(std::cin);
        return(crew);
    }
    else {
        *crew = Pilot(std::cin);
        return(crew);
    }
}

CrewMember* PlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile)
{
    return nullptr;
}

Plane* PlaneCrewFactory::GetPlaneFromFile(ifstream& inFile)
{
    return nullptr;
}
