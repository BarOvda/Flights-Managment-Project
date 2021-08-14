#ifndef __CREW_MEMBER
#define __CREW_MEMBER


class CrewMember
{
public:
//c'tor
	CrewMember(const char* mName, int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);

//d'tor
	~CrewMember();

//getters
	int getTotalFlightTime();
	char* getName();

//setters
	void setName(const char* mName);

//other methods
	bool UpdateMinutes(int minutes);
	bool IsEqual(CrewMember& otherMember);
	void print(ostream& out);

private:
//attributes
	char* name;
	int totalFlightTime;
};


#endif // !__CREW_MEMBER
