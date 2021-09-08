#ifndef __CREW_MEMBER
#define __CREW_MEMBER

#include <string>




class CrewMember
{
public:
	static const int START_ID = 0;

	//c'tor
	CrewMember();
	CrewMember(const char* mName, int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);

	//d'tor
	~CrewMember();

	//getters
	int getTotalFlightTime();
	char* getName();
	int getMemberNumber();

	//setters
	void setName(const char* mName);

	//other methods
		//bool UpdateMinutes(int minutes);
	const bool operator+=(int minutes)
	{
		if (minutes > 0) {
			totalFlightTime += minutes;

		}
		return true;
	}
	bool operator==(CrewMember& other)
	{

		return other.getMemberNumber() == this->getMemberNumber() && strcmp(other.getName() , this->getName())==0
			&& other.getTotalFlightTime() == this->getTotalFlightTime();
	}
	void operator=(CrewMember& other)
	{
		this->memberNumber = other.getMemberNumber();
		delete[]this->name;
		this->name = strdup(other.getName());

		this->totalFlightTime= other.getTotalFlightTime();
	}
	bool IsEqual(CrewMember& otherMember);
	void print(ostream& out);

	static void setCurrentMemberNumber(int mCurrentMemberNumber);
	friend ostream& operator<<(ostream& os, const CrewMember& data);
protected:
	char* name;
	int totalFlightTime;
	int memberNumber;
	static int currentMemberNumber;

	
	
};


#endif // !__CREW_MEMBER
