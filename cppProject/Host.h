#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <sstream>

#ifndef __HOST_H
#define __HOST_H

#include "CrewMember.h"

class Host :
	public CrewMember
{
public:
	//enum
	enum eHostType { eRegular, eSuper, eCalcelan };

	Host(std::istream& in):CrewMember(in) {
		fromOs( in);
	}

	//c'tor
	Host(const char* mName, Host::eHostType type, int mTotalFlightTime = 0);
	Host(CrewMember& member);
	Host(Host& other);

	//d'tor
	~Host();
	//void print(std::ostream& out);
	
	virtual const char* getType() const { return "Host"; }
	//friend std::ostream& operator<<(std::ostream& out, const Host& data);
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



	//other methods
	void operator=(const Host& other);
	bool operator==(const Host& other);
	bool operator!=(const Host& other);

	virtual void toOs(ostream& os) const override;

	const char* getType();


	// Inherited via CrewMember
	virtual void getUniform() const override;
	virtual void takeOff(int flightTime) override;
	virtual void getPresent() const override;

private:
	//attributes
	eHostType type;


};

#endif // !__HOST_H

