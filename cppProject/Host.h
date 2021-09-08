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
	Host(const char* name, Host::Type type);
	void print(std::ostream& out);
	void GetPresent();
	virtual const char* getType() const { return "Host"; }
	friend std::ostream& operator<<(std::ostream& out, const Host& data);

private:

	Type type;


};

