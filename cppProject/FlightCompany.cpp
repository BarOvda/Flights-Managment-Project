#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#include <fstream>
#include <string.h>
#include "FlightCompany.h"
#include "Pilot.h"
#include "Host.h"
#include <sstream>


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

FlightCompany::FlightCompany(const char* filePath, int x)
{
	std::ifstream inFile(filePath);
	this->companyName = new char[128];
	/*inFile.getline(this->companyName, 6);*/
	inFile >> this->companyName;
	 
	inFile >> this->numOfCrewMembers;
	for (int i = 0; i < this->numOfCrewMembers; i++) {
		char* type = new char[1];
		inFile >> type;
		stringstream t_s(type);

		int t;
		t_s>>t;
		if (t==0) {
			//HOST
			this->crewMembers[i] = *new Host(inFile);
		}
		else {
			//PILOT
			this->crewMembers[i] = *new Pilot(inFile);

		}
 	}
	inFile >> this->numOfPlanes;
	for (int i = 0; i < this->numOfPlanes; i++) {
		char* type = new char[1];
		inFile >> type;
		stringstream t_s(type);

		int t;
		t_s >> t;
		if (t == 0) {
			//Regular

			this->Planes[i] = *new Plane(inFile);
		}
		else {
			//Cargo
			this->Planes[i] = *new Cargo(inFile);

		}
	}
	inFile >> this->numOfFlights;
	for (int i = 0; i < this->numOfFlights; i++) {

			this->flights[i] = *new Flight(inFile);
		
	}


}

FlightCompany::~FlightCompany()
{
	delete[]this->companyName;
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

		crewMembers[i].print(out);

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
	*(this->GetFlightByNum(f_number)) + *(this->GetCrewMember(crew_member_number));
}

int FlightCompany::GetCargoCount()
{
	int totalAmount = 0;

	for (int i = 0; i < this->numOfPlanes; i++)
	{
		if (typeid(this->Planes[i]) == typeid(Cargo)) 
		{
			totalAmount++;
		}
	}
	return totalAmount;
}


bool FlightCompany::TakeOff(int flightNumber)
{
	Flight* temp = this->GetFlightByNum(flightNumber);

	return temp->TakeOff();
}

bool FlightCompany::operator==(FlightCompany& other)
{
	return strcmp(this->companyName, other.companyName);
}

Flight* FlightCompany::GetFlightByNum(int f_number) {
	for (int i = 0; i < numOfFlights; i++) {
		if (this->flights[i].GetFlightInfo().GetFNum() == f_number)
			return &this->flights[i];
	}
}


//CrewMember* FlightCompany::GetCrew(int c_number) {
//	for (int i = 0; i < numOfCrewMembers; i++) {
//		if (this->crewMembers[i].getMemberNumber() == c_number)
//			return &this->crewMembers[i];
//	}
//}
CrewMember* FlightCompany::GetCrewMember(int index) {
	if (index < numOfCrewMembers)
		return &(this->crewMembers[index]);
	return NULL;
}
void FlightCompany::CrewGetPresent() {
	for (int i = 0; i < this->numOfCrewMembers; i++) {
		this->crewMembers[i].GetPresent();
		
	}
}

void FlightCompany::PilotsToSimulator()
{
	for (int i = 0; i < this->numOfCrewMembers; i++) {
		std::cout << (typeid(this->crewMembers[i])).name() << endl;
		if (strcmp(this->crewMembers[i].getType(), "Host") == 0) {
			std::cout << " I was not expecting it" << endl;

		}

	}
}

void FlightCompany::CrewGetUniform()
{
	for (int i = 0; i < this->numOfCrewMembers; i++) {
		std::cout << (typeid(this->crewMembers[i])).name() << endl;
		if (strcmp(this->crewMembers[i].getType(), "Host") == 0) {
			std::cout << " I was not expecting it" << endl;

		}

	}

}
