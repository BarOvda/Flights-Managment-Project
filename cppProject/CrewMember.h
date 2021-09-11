#ifndef __CREW_MEMBER
#define __CREW_MEMBER
using namespace std;
#include <string>
#include <iostream>
#include <typeinfo>



class CrewMember
{
public:
	//static const int START_ID = 0;

	//c'tor
	CrewMember(const char* mName, int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);
	CrewMember(istream& in) {

		in >> *this;

	}
	CrewMember();
	//d'tor
	~CrewMember();

	//getters
	int getTotalFlightTime();
	char* getName();
	//int getMemberNumber();

	//setters
	void setName(const char* mName);
	virtual void GetPresent();
	virtual const char* getType() const { return "CrewMember"; }
	//other methods
		//bool UpdateMinutes(int minutes);
	virtual const bool operator+=(int minutes)
	{
		if (minutes > 0) {
			totalFlightTime += minutes;

		}
		return true;
	}
	virtual bool operator==(CrewMember& other)
	{

		return strcmp(other.getName() , this->getName())==0
		;

	}
	void operator=(CrewMember& other)
	{
		//this->memberNumber = other.getMemberNumber();
		delete[]this->name;
		this->name = _strdup(other.getName());

		this->totalFlightTime = other.getTotalFlightTime();
	}
	virtual void fromOs(istream& in) {};
	friend istream& operator>>(istream& in, CrewMember& c) {
		//if (typeid(in) == typeid(ifstream))
		c.name = new char[5];
		in >> c.name >> c.totalFlightTime;
		//else {
		//	char delimiter;
		//	in >> delimiter >> c.name>>delimiter>>c.totalFlightTime>>delimiter;
		//}
		c.fromOs(in);
		return in;

	}
	bool IsEqual(CrewMember& otherMember);
	virtual void print(std::ostream& out);

	static void setCurrentMemberNumber(int mCurrentMemberNumber);
	 friend std::ostream& operator<<(std::ostream& os, const CrewMember& data);

protected:
	char* name;
	int totalFlightTime;
	//int memberNumber;
	//static int currentMemberNumber;



};


#endif // !__CREW_MEMBER
