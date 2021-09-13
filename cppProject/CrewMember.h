#ifndef __CREW_MEMBER
#define __CREW_MEMBER
using namespace std;
#include <string>
#include <iostream>
#include <typeinfo>

#include <fstream>


class CrewMember
{
public:
	static int START_ID;

	//c'tor
	CrewMember(const char* mName = "", int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);
	CrewMember(istream& in) {

		in >> *this;
	}

	//d'tor
	virtual ~CrewMember();

	//getters
	int getTotalFlightTime();
	char* getName();

	//setters
	void setName(const char* mName);

	//other methods
	virtual bool UpdateMinutes(int minutes);
	bool IsEqual(CrewMember& otherMember);
	void Print(ostream& out);

	virtual void operator=(const CrewMember& other);
	virtual bool operator==(const CrewMember& other);
	virtual bool operator!=(const CrewMember& other);
	virtual bool operator+=(int minutes);

	virtual void fromOs(istream& in) {};
	friend istream& operator>>(istream& in, CrewMember& c) {
		if (typeid(in) == typeid(ifstream)) {
			c.name = new char[5];
			in >> c.name >> c.totalFlightTime;
		}
		else {
			cout << "Enter Name" << endl;

			in >> c.name;
			cout << "Enter FlightTime" << endl;
			in >> c.totalFlightTime;;
		}
		c.fromOs(in);
		return in;
	}


	friend ostream& operator<<(ostream& os, const CrewMember& other);
	virtual void toOs(ostream& os) const;

	virtual void getUniform() const = 0;
	virtual void takeOff(int flightTime) = 0;
	virtual void getPresent() const = 0;

protected:
	//attributes
	char* name;
	int totalFlightTime;

};


#endif // !__CREW_MEMBER
