#include <iostream>
using namespace std;

#include <string.h>
#include "Pilot.h"

Pilot::Pilot(const char* name, bool isCaptian, Address* address) : adderss(adderss.getHouseNumber()
	,adderss.getStreet(),adderss.getCity()), CrewMember(name) {
	this->isCaptian = isCaptian;
	
}
Pilot::Pilot(const char* name, bool isCaptian) : adderss(adderss), CrewMember(name) {
	this->isCaptian = isCaptian;

}
void Pilot::GetPresent()
{
}
void Pilot::print(std::ostream& out)
{
	out << "Pilot  " << this->name << " minutes " << this->totalFlightTime ;
		 /*this->adderss.print(out);*/
	if(this->adderss.getStreet()!=NULL)
	out << this->adderss.getStreet()
		<< " "
		<< this->adderss.getHouseNumber()
		<< ", "
		<< this->adderss.getCity()
		<< endl;
	if (this->isCaptian)
		out << " a Captian"
		;
	else
		out << " not a Captian";
	
	out << endl;
}

std::ostream& operator<<(std::ostream& out, const Pilot& data)
{
	out << "Pilot  " << data.name << " minutes " << data.totalFlightTime;
	/*this->adderss.print(out);*/

	out << data.adderss;

	if (data.isCaptian)
		out << " a Captian"
		;
	else
		out << " not a Captian";

	out << endl;
	return out;
}