#include "Host.h"
using namespace std;
Host::Host(const char* name, Type type) :CrewMember(name) {
	this->type = type;
}
void Host::print(std::ostream& out)
{
	out << "Host " << this->name << " minutes " << this->totalFlightTime  << endl;
}