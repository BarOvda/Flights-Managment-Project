#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#include <fstream>

#include <string.h>
#include "Flight.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"
#include "FlightCompException.h"


Flight::Flight(FlightInfo& info, Plane* plane) : info(info), plane(plane), numberOfMembers(0)
{
	this->isPlaneAssigned = this->plane == nullptr ? false : true;
}

Flight::Flight(const Flight& other) : info(other.info), plane(other.plane), numberOfMembers(0)
{
	this->isPlaneAssigned = this->plane == nullptr ? false : true;
}

Flight::Flight() : info(), plane(), numberOfMembers(0)
{
}

Flight::~Flight()
{
}

void Flight::SetPlane(Plane* plane)
{
	this->plane = plane;
	this->isPlaneAssigned = this->plane == nullptr ? false : true;
}

int Flight::GetFlightNumber()
{
	return info.GetFNum();
}

Plane* Flight::GetPlane()
{
	return this->plane;
}

FlightInfo& Flight::GetFlightInfo()
{
	return this->info;
}

void Flight::operator+(CrewMember* member)
{
	if (numberOfMembers < MAX_CREW) {
		for (int i = 0; i < numberOfMembers; i++)
		{
			if (strcmp((*this->members[i]).getName(), member->getName()) == 0) {
				return;
			}
		}
		this->members[numberOfMembers] = member;
		numberOfMembers++;
	}
}

void Flight::operator=(const Flight& other)
{
	if (*this != other) {
		this->info = other.info;
		this->plane = other.plane;
		this->numberOfMembers = other.numberOfMembers;
		this->isPlaneAssigned = other.isPlaneAssigned;

		for (int i = 0; i < other.numberOfMembers; i++)
		{
			this->members[i] = other.members[i];
		}
	}
}

bool Flight::operator==(const Flight& other)
{
	return (this->info == other.info);
}

bool Flight::operator!=(const Flight& other)
{
	return !(*this == other);
}

bool Flight::TakeOff() throw(CompStringException)
{
	if (typeid(this->plane) == typeid(Plane))
	{
		int pilots = 0;
		int superHost = 0;
		for (int i = 0; i < numberOfMembers; i++)
		{
			if (typeid(this->members[i]) == typeid(Pilot))
			{
				pilots++;
				if (pilots > 1)
				{
					throw CompStringException("Plane cannot have more than one pilot");
					return false;
				}
			}

			if (typeid(this->members[i]) == typeid(Host) && strcmp(((Host)*this->members[i]).getType(), "Super"))
			{
				superHost++;
				if (superHost > 1)
				{
					throw CompStringException("Plane cannot have more than one super host");
					return false;
				}
					
			}
			((Cargo*)this->plane)->takeOff(this->info.getFlightTime());
		}
	}
	else if (typeid(this->plane) == typeid(Cargo))
	{
		int pilots = 0;
		for (int i = 0; i < numberOfMembers; i++)
		{
			if (typeid(this->members[i]) == typeid(Pilot))
			{
				pilots++;
				if (pilots < 1)
				{
					throw CompStringException("Cargo Plane need at least one pilot");
					return false;
				}
					
			}
		}
	}

	for (int i = 0; i < numberOfMembers; i++)
	{
		this->members[i]->takeOff(this->info.getFlightTime());
	}

	return true;
}

ostream& operator<<(ostream& os, const Flight& other)
{
	if (typeid(os) == typeid(ofstream)) {
		os << other.info;

		if (other.isPlaneAssigned)
			os << " 1 "<<endl;
		else
			os << " 0 "<<endl;
		

		os << other.numberOfMembers << endl;

		for (size_t i = 0; i < other.numberOfMembers; i++)
		{
			os << *other.members[i] << endl;
		}

	}
	else {
		os << "Flight info: " << other.info;

		if (other.isPlaneAssigned)
			os << " plane: " << other.plane;
		else
			os << " No plane assign yet ";

		os << " There are " << other.numberOfMembers << " crew memebers in flight: " << endl;

		for (size_t i = 0; i < other.numberOfMembers; i++)
		{
			os << " member: " << *other.members[i] << endl;
		}

	}

	
	return os;
}
