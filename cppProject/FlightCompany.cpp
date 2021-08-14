#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "FlightCompany.h"

FlightCompany::FlightCompany(const char* mCompanyName)
{
	this->companyName = new char[strlen(mCompanyName) + 1];
	strcpy(this->companyName, mCompanyName);
}

FlightCompany::FlightCompany(FlightCompany& otherCompany)
{
	this->companyName = new char[strlen(otherCompany.getCompanyName()) + 1];
	strcpy(this->companyName, otherCompany.getCompanyName());
}

FlightCompany::~FlightCompany()
{
	delete []this->companyName;
}

char* FlightCompany::getCompanyName()
{
	return this->companyName;
}

void FlightCompany::setName(const char* mName)
{
	if (strlen(this->companyName) < strlen(mName)) 
		this->companyName = new char[strlen(mName) + 1];
	
	strcpy(this->companyName, mName);
}

void FlightCompany::print(ostream& out)
{
	out << "Flight company: " << this->companyName;
}
