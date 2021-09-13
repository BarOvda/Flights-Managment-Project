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
#include "FlightCompException.h"

FlightCompany::FlightCompany(const char* mCompanyName) : numberOfCrews(0), numberOfPlanes(0), numberOfFlights(0)
{
	this->companyName = new char[strlen(mCompanyName) + 1];

	strcpy(this->companyName, mCompanyName);
}

FlightCompany::FlightCompany(FlightCompany& otherCompany) : numberOfCrews(0), numberOfPlanes(0), numberOfFlights(0)
{
	this->companyName = new char[strlen(otherCompany.getCompanyName()) + 1];
	strcpy(this->companyName, otherCompany.getCompanyName());
}

FlightCompany::FlightCompany(const char* filePath, int x)
{
	std::ifstream inFile(filePath);
	this->companyName = new char[128];
	/*inFile.getline(this->companyName, 6);*/
	inFile >> this->companyName;

	inFile >> this->numberOfCrews;
	for (int i = 0; i < this->numberOfCrews; i++) {
		char* type = new char[1];
		inFile >> type;
		stringstream t_s(type);

		int t;
		t_s >> t;
		if (t == 0) {
			//HOST
			this->members[i] = new Host(inFile);
		}
		else {
			//PILOT
			this->members[i] = new Pilot(inFile);

		}
	}
	inFile >> this->numberOfCrews;
	for (int i = 0; i < this->numberOfCrews; i++) {
		char* type = new char[1];
		inFile >> type;
		stringstream t_s(type);

		int t;
		t_s >> t;
		if (t == 0) {
			//Regular

			this->planes[i] = new Plane(inFile);
		}
		else {
			//Cargo
			this->planes[i] = new Cargo(inFile);

		}
	}
	inFile >> this->numberOfFlights;
	for (int i = 0; i < this->numberOfFlights; i++) {

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

Flight* FlightCompany::GetFlightByNum(int number)
{
	for (int i = 0; i < numberOfFlights; i++)
	{
		if (this->flights[i].GetFlightNumber() == number) {
			return &this->flights[i];
		}
	}
}

CrewMember* FlightCompany::GetCrewMember(int index) throw(CompLimitException)
{
	if (index <= numberOfCrews) {
		return this->members[index];
	}
	else
	{
		throw CompLimitException(numberOfCrews);
		return nullptr;
	}

}

Plane* FlightCompany::GetPlane(int index) throw(CompLimitException)
{
	if (index <= numberOfPlanes) {
		if (this->planes[index] != 0)
			return this->planes[index];
	}
	else
	{
		throw CompLimitException(numberOfPlanes);
		return nullptr;
	}

}

int FlightCompany::GetCargoCount()
{
	int counter = 0;
	for (int i = 0; i < numberOfPlanes; i++)
	{
		if (typeid(this->planes[i]) == typeid(Cargo))
			counter++;
	}
	return counter;
}

void FlightCompany::setName(const char* mName)
{
	if (strlen(this->companyName) < strlen(mName))
		this->companyName = new char[strlen(mName) + 1];

	strcpy(this->companyName, mName);
}

void FlightCompany::Print(ostream& out) throw(CompStringException)
{
	if (!this->companyName)
		throw CompStringException("company dont has a name");
	else {

		out << "Flight company: " << this->companyName << endl;
		out << "There are " << numberOfCrews << "  Crew members:" << endl;
		if (numberOfCrews > 0) {
			for (int i = 0; i < numberOfCrews; i++)
			{
				this->members[i]->toOs(out);
			}
		}

		out << "There are " << numberOfPlanes << "  Planes:" << endl;
		if (numberOfPlanes > 0) {
			for (int i = 0; i < numberOfPlanes; i++)
			{
				this->planes[i]->toOs(out);
			}
		}

		out << "There are " << numberOfFlights << "  Flights:" << endl;
		if (numberOfFlights > 0) {
			for (int i = 0; i < numberOfFlights; i++)
			{
				out << this->flights[i] << endl;
			}
		}
	}
}

bool FlightCompany::AddCrewMember(CrewMember& other)
{
	if (this->numberOfCrews < MAX_CREWS) {
		for (int i = 0; i < numberOfCrews; i++)
		{
			if (*this->members[i] == other) {
				return false;
			}
		}
		this->members[numberOfCrews] = &other;
		numberOfCrews++;
		return true;
	}
	return false;
}

bool FlightCompany::AddPlane(Plane& other)
{
	if (this->numberOfPlanes < MAX_PLANES) {
		for (int i = 0; i < numberOfPlanes; i++)
		{
			if (*this->planes[i] == other) {
				return false;
			}
		}
		this->planes[numberOfPlanes] = &other;
		numberOfPlanes++;
		return true;
	}
	return false;
}

bool FlightCompany::AddFlight(Flight& other)
{
	if (this->numberOfFlights < MAX_FLIGHT) {
		for (int i = 0; i < numberOfFlights; i++)
		{
			if (this->flights[i] == other) {
				return false;
			}
		}
		this->flights[numberOfFlights] = other;
		numberOfFlights++;
		return true;
	}
	return false;
}

void FlightCompany::AddCrewToFlight(int flightNum, int memberNum)
{
	*this->GetFlightByNum(flightNum) + this->GetCrewMember(memberNum);
}

void FlightCompany::PilotsToSimulator()
{
	for (int i = 0; i < numberOfCrews; i++)
		if (typeid(this->members[i]) == typeid(Pilot))
			((Pilot)*this->members[i]).gotoSimulator();
}

void FlightCompany::CrewGetPresent()
{
	for (int i = 0; i < numberOfCrews; i++)
		this->members[i]->getPresent();
}

void FlightCompany::CrewGetUniform()
{
	for (int i = 0; i < numberOfCrews; i++)
		this->members[i]->getUniform();
}

void FlightCompany::TakeOff(int flightNumber) throw(CompStringException)
{
	Flight flight = *GetFlightByNum(flightNumber);

	if (flight.GetFlightNumber() != flightNumber)
		throw CompStringException("there is no such flight");
	else
		flight.TakeOff();

}

Plane& FlightCompany::operator[](int index) throw(CompLimitException)
{
	if (index < numberOfPlanes)
		return *this->planes[index];
	else
		throw CompLimitException(numberOfPlanes);
}
