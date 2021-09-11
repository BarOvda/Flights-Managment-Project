#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <sstream>

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
	Host(std::istream& in):CrewMember(in) {
		fromOs( in);
	}

	void print(std::ostream& out);
	void GetPresent();
	virtual const char* getType() const { return "Host"; }
	friend std::ostream& operator<<(std::ostream& out, const Host& data);
	virtual void fromOs(std::istream& in) override {
		char* mtype = new char[1];
		
		in >> mtype;
		stringstream t_s(mtype);

		int t;
		t_s >> t;
		if (t == 0) {
			type = eRegular;
		}
		else if (t == 1) {
			type = eSuper;
		}
		else if (t == 2) {
			type = eCalcelan;
		}
	};

private:

	Type type;


};

