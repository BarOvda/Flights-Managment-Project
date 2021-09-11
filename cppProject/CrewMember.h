#ifndef __CREW_MEMBER
#define __CREW_MEMBER


class CrewMember
{
public:
	static int START_ID;

	//c'tor
	CrewMember(const char* mName = "", int mTotalFlightTime = 0);
	CrewMember(CrewMember& otherMember);

	//d'tor
	virtual ~CrewMember();

	//getters
	int getTotalFlightTime();
	char* getName();
	//int GetMemberID();

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

	friend ostream& operator<<(ostream& os, const CrewMember& other);
	virtual void toOs(ostream& os) const;

	virtual void getUniform() const = 0;
	virtual void takeOff(int flightTime) = 0;
	virtual void getPresent() const = 0;

protected:
	//attributes
	char* name;
	int totalFlightTime;

	//int memberId;
	//static int currentMemberId;
};


#endif // !__CREW_MEMBER
