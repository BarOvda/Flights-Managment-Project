#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "FlightCompany.h"




FlightCompany::FlightCompany(const char* name)
{

	this->companyName = new char[strlen(name) + 1];
	strcpy(this->companyName, name);
	this->numOfCrewMembers = 0;
	this->numOfPlanes = 0;
	this->numOfFlights = 0;

}
FlightCompany::FlightCompany(FlightCompany& other) {

	this->companyName = new char[strlen(other.companyName) + 1];
	strcpy(this->companyName, other.companyName);
	this->numOfCrewMembers = other.numOfCrewMembers;
	this->numOfPlanes = other.numOfPlanes;
	this->numOfFlights = other.numOfFlights;
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		AddCrewMember(other.crewMembers[i]);
	}
	for (int i = 0; i < numOfPlanes; i++)
	{
		AddPlane(other.Planes[i]);
	}
	for (int i = 0; i < numOfFlights; i++)
	{
		AddFlight(other.flights[i]);
	}


}

FlightCompany::~FlightCompany()
{
	delete []this->companyName;
}

char* FlightCompany::getCompanyName()
{
	return this->companyName;
}
Plane& FlightCompany::GetPlane(int i) {
	return this->Planes[i];
}
void FlightCompany::setName(const char* mName)
{
	if (strlen(this->companyName) < strlen(mName)) 
		this->companyName = new char[strlen(mName) + 1];
	
	strcpy(this->companyName, mName);
}

void FlightCompany::Print(ostream& out)
{
	out << "Flight company: " << this->companyName << endl
		<< "There are " << numOfCrewMembers << " Crew members : " << endl;
	for (int i = 0; i < numOfCrewMembers; i++) {
		out << crewMembers[i] << endl;

	}

	out << "There are " << numOfPlanes << " Planes:" << endl;
	for (int i = 0; i < numOfPlanes; i++) {
		out << Planes[i] << endl;

	}
	out
		<< "There are " << numOfFlights << " Flights:" << endl;
	for (int i = 0; i < numOfFlights; i++) {
		out << flights[i] << endl;

	}
	out
		<< endl;
}
bool FlightCompany::AddCrewMember(CrewMember& crewMember) {
	if (numOfCrewMembers > MAX_CREWS)
		return false;
	for (int i = 0; i < numOfCrewMembers; i++)
	{
		if (this->crewMembers[i] == crewMember) {
			return false;
		}
	}

	crewMembers[numOfCrewMembers] = crewMember;
	numOfCrewMembers++;
	return true;
}

bool FlightCompany::AddPlane(Plane& plane) {
	if (numOfPlanes > MAX_PLANES)
		return false;
	for (int i = 0; i < numOfPlanes; i++)
	{
		if (this->Planes[i] == plane) {
			return false;
		}
	}
	//Plane* p = new Plane(plane);
	//this->Planes[numOfCrewMembers] = *p;
	Planes[numOfPlanes] = plane;
	numOfPlanes++;
	return true;
}
bool FlightCompany::AddFlight(Flight& flight) {
	if (numOfFlights > MAX_FLIGHT)
		return false;
	for (int i = 0; i < numOfFlights; i++)
	{
		if (this->flights[i] == flight) {
			return false;
		}
	}
	
	flights[numOfFlights] = flight;
	numOfFlights++;
	return true;
}

void FlightCompany::AddCrewToFlight(int f_number, int crew_member_number) {
	*(this->GetFlight(f_number)) + *(this->GetCrew(crew_member_number));
}
Flight* FlightCompany::GetFlight(int f_number) {
	for (int i = 0; i < numOfFlights; i++) {
		if (this->flights[i].getFlightInfo().GetFNum() == f_number)
			return &this->flights[i];
	}
}
CrewMember* FlightCompany::GetCrew(int c_number) {
	for (int i = 0; i < numOfCrewMembers; i++) {
		if (this->crewMembers[i].getMemberNumber() == c_number)
			return &this->crewMembers[i];
	}
}
