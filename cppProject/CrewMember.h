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
	int getMemberNumber();

	//setters
	void setName(const char* mName);

	//other methods
		//bool UpdateMinutes(int minutes);
	const CrewMember& operator+=(int minutes)
	{
		if (minutes > 0) {
			totalFlightTime += minutes;

		}
		return *this;
	}

	bool IsEqual(CrewMember& otherMember);
	void print(ostream& out);

	static void setCurrentMemberNumber(int mCurrentMemberNumber);

private:
	//attributes
	char* name;
	int totalFlightTime;
	int memberNumber;
	static int currentMemberNumber;
};


#endif // !__CREW_MEMBER
