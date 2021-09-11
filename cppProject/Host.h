#ifndef __HOST_H
#define __HOST_H

#include "CrewMember.h"


class Host : public CrewMember
{
public:
	//enum
	enum eHostType { eRegular, eSuper, eCalcelan };

	//c'tor
	Host(const char* mName, Host::eHostType type, int mTotalFlightTime = 0);
	Host(CrewMember& member);
	Host(Host& other);

	//d'tor
	~Host();

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

