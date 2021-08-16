#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "Flight.h"

void Flight::updatePlane(Plane& otherPlane)
{
	if (this->plane != otherPlane)
	{
		this->plane = otherPlane;
	}
}

void Flight::operator+(CrewMember& newMember)
{
	if (this->numberOfMembers == 0)
	{
		this->crewMembers[this->numberOfMembers] = newMember;
		this->numberOfMembers++;
	}
	else
	{
		if (this->numberOfMembers < MAX_CREW)
		{
			for (size_t i = 0; i < this->numberOfMembers; i++)
			{
				if (!strcmp(this->crewMembers[i].getName(), newMember.getName()))
				{
					this->crewMembers[this->numberOfMembers] = newMember;
					this->numberOfMembers++;
				}
			}
		}
	}
}

bool Flight::operator==(Flight& otherFlight)
{
	return this->info == otherFlight.getFlightInfo();
}

FlightInfo Flight::getFlightInfo()
{
	return this->info;
}

ostream& operator<<(ostream& os, const Flight& data)
{
	os << "Flight info: " << info << " plane: " << plane << endl;
	for (size_t i = 0; i <data.numberOfMembers; i++)
	{
		os << " member: " << data.crewMembers[i] << endl;
	}

	return os;
}
