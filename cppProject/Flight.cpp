#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "Flight.h"

Flight::Flight() :info(), plane() {
	this->numberOfMembers = 0;
	isPlaneAssigned = false;
}
Flight::Flight(FlightInfo& info):info(info),plane(){
	this->info = info;
	this->numberOfMembers = 0;
	isPlaneAssigned = false;

}
Flight::Flight(FlightInfo& info, Plane& plane) :info(info), plane(plane) {
	this->info = info;
	this->numberOfMembers = 0;
	this->plane = plane;
	isPlaneAssigned = true;

}
Flight::Flight(Flight& flight) {
	this->info = flight.info;
	this->numberOfMembers = flight.numberOfMembers;
	this->plane = flight.plane;
	isPlaneAssigned = flight.isPlaneAssigned;
	for (int i = 0; i < numberOfMembers; i++) {
		this->crewMembers[i] = flight.crewMembers[i];
	}
	
}

Flight::~Flight() {
	for (int i = 0; i < numberOfMembers; i++) {
		crewMembers[i].~CrewMember();
	}
	
}
void Flight::SetPlane(Plane& plane)
{
	this->plane = plane;
	isPlaneAssigned = true;
}

void Flight::updatePlane(Plane& otherPlane)
{
	if (this->plane != otherPlane)
	{
		this->plane = otherPlane;
	}
	isPlaneAssigned = true;


}

void Flight::operator+(CrewMember& newMember)
{


	if (numberOfMembers > MAX_CREW)
		return;

	CrewMember* c = new CrewMember(newMember);
	crewMembers[numberOfMembers] = *c;
	numberOfMembers++;

	//if (this->numberOfMembers == 0)
//{
//	this->crewMembers[this->numberOfMembers] = newMember;
//	this->numberOfMembers++;
//}
//else
//{
//	if (this->numberOfMembers < MAX_CREW)
//	{
//		for (size_t i = 0; i < this->numberOfMembers; i++)
//		{
//			if (!strcmp(this->crewMembers[i].getName(), newMember.getName()))
//			{
//				this->crewMembers[this->numberOfMembers] = newMember;
//				this->numberOfMembers++;
//			}
//		}
//	}
//}

}

bool Flight::operator==(Flight& otherFlight)
{
		
	return this->info == otherFlight.info;
}

FlightInfo Flight::getFlightInfo()
{
	return this->info;
}


ostream& operator<<(ostream& os, const Flight& data)
{
	os << "Flight info: " << data.info;
	if(data.isPlaneAssigned)
	os <<" plane: " << data.plane;
	else
		os << " No plane assign yet " ;

		os << " There are " << data.numberOfMembers << " crew memebers in flight: " << endl;
	
	for (size_t i = 0; i <data.numberOfMembers; i++)
	{
		os << " member: " << data.crewMembers[i] << endl;
	}

	return os;
}
