#ifndef __CREW_MEMBER
#define __CREW_MEMBER

#include <string>
#include <iostream>


class CrewMember
{
public:
	//static const int START_ID = 0;

	//c'tor
	CrewMember();
	CrewMember(const char* mName, int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);

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
