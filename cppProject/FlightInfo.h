
#ifndef __FLIGHT_INFO_H
#define __FLIGHT_INFO_H

#define MAX 100


class FlightInfo
{
public:
	//c'tor
	FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength);

	//d'tor
	~FlightInfo();

	//getters
	int getFlightNumber();
	int getFlightTime();
	int getFlightLength();
	char* getDestination();

	//setters
	void setFlightNumber(int mFlightNumber);
	void setFlightTime(int mFlightTime);
	void setFlightLength(int mFlightLength);
	void setDest(const char mDestination[]);

	//other methods
	bool isSameFlightNumber(int mFlightNumber);
	void print(ostream& out);

private:

	//attributes
	int flightNumber;
	char destination[MAX];
	int flightTime; // minutes
	int flightLength; // km

};


#endif // !__FLIGHT_INFO_H

