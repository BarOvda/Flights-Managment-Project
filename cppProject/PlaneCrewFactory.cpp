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
#include "Flight.h"

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
    int numOfMembers,numOfPlanes,numofFlights;
    cout << "Enter Crew Members Number" << endl;

    std::cin >> numOfMembers;
    for (int i = 0; i < numOfMembers; i++) {
        cout << "Enter Details for Member Number "<<i+1 << endl;

        comp.AddCrewMember(*GetCrewFromUser());

    }
    cout << "Enter Planes Number" << endl;

    std::cin >> numOfPlanes;
    for (int i = 0; i < numOfPlanes; i++) {
        cout << "Enter Details for Plan Number " << i+1 << endl;

        comp.AddPlane(*GetPlaneFromUser());

    }
    cout << "Enter Flights Number" << endl;
    std::cin >> numofFlights;
    
    for (int i = 0; i < numofFlights; i++) {
        cout << "Enter Details for Flight Number " << i + 1 << endl;
        Flight* f = new Flight();
        cin >> *f;
        comp.AddFlight(*f);
    }


}

Plane* PlaneCrewFactory::GetPlaneFromUser()
{
    cout << "Enter Plan Type :" << endl;
    int type;

    std::cin >> type;
    if (type == 0) {
        Plane* p = new Plane(0, "");
        cin >> *p;
        return p;
    }
    else {
        Cargo* c = new Cargo(0, "", 0, 0);
        cin >> *c;
        return c;
    }
}

CrewMember* PlaneCrewFactory::GetCrewFromUser()
{
    cout << "Enter Crew Member Type :" << endl;
    
    int type;
            
    std::cin >> type;
    if (type == 0) {
        Host* h = new Host("",Host::eRegular);
        cin >>*h;
        return h;
    }
    else {
        Pilot* p = new Pilot("", false);
        cin >> *p;
        return p;
    }
}

CrewMember* PlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile)
{
    char* type = new char[1];
    inFile >> type;
    stringstream t_s(type);

    int t;
    t_s >> t;
    if (t == 0) {

        Host* h = new Host(inFile);
        return h;

    }
    else {


        Pilot* p = new Pilot(inFile);
        

        return p;

    }
}


Plane* PlaneCrewFactory::GetPlaneFromFile(ifstream& inFile)
{

    char* type = new char[1];
    inFile >> type;
    stringstream t_s(type);

    int t;
    t_s >> t;
 
    if (t == 0) {
        
        Plane* p = new Plane(inFile);

        return p;
    }
    else {
        
        Cargo* c = new Cargo(inFile);
        return c;
    }
}
