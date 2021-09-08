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
	std::cout << this->name << " thanking the company for receiving the holiday gift" << endl;
	std::cout << " I was not expecting it" << endl;

}

std::ostream& operator<<(std::ostream& out, const Host& data)
{
	out << "Host ";
	switch (data.type)
	{
	case Host::Type::eRegular:
		out << "Regular ";
		break;
	case Host::Type::eSuper:
		out << "Super ";
		break;
	case Host::Type::eCalcelan:
		out << "Calcelan ";
		break;
	default:
		break;
	}
	out << data.name << " minutes " << data.totalFlightTime << endl;
	return out;
}
