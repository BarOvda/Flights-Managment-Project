#pragma once
#include "CrewMember.h"
class Host :
    public CrewMember
{
public:
	enum Type {
		eRegular, eSuper
		, eCalcelan
	};
	Host(const char* name,Host::Type type);



private:

	Type type;


};

