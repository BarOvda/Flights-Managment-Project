#include "Host.h"
using namespace std;
Host::Host(const char* name, Type type) :CrewMember(name) {
	this->type = type;
}
void Host::print(std::ostream& out)
{
	out << "Host ";
	switch (this->type)
	{
	case eRegular:
		out << "Regular ";
		break;
	case eSuper:
		out << "Super ";
		break;
	case eCalcelan:
		out << "Calcelan ";
		break;
	default:
		break;
	}
	out<< this->name << " minutes " << this->totalFlightTime << endl;
}

void Host::GetPresent()
{
	std::cout << " I was not expecting it" << endl;

}
