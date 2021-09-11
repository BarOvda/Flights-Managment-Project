
#ifndef __FLIGHT_INFO_H
#define __FLIGHT_INFO_H

#define MAX 100


class FlightInfo
{
public:
	//c'tor
	FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength);
	FlightInfo(const FlightInfo& other);
	FlightInfo(FlightInfo& otherFlightInfo);
	FlightInfo(std::istream& in) {
		getInfo(in);
	}
	FlightInfo();

	//d'tor
	~FlightInfo();

	//getters
	int GetFNum();

	void getInfo(std::istream& in) {
		in>>destination>>flightNumber>>flightTime>>flightLength;

	};

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

	void operator=(const FlightInfo& other);
	bool operator==(const FlightInfo& other);
	bool operator!=(const FlightInfo& other);
	friend ostream& operator<<(ostream& os, const FlightInfo& other);
	operator int();

private:

	//attributes
	int flightNumber;
	char destination[MAX];
	int flightTime; // minutes
	int flightLength; // km

};


#endif // !__FLIGHT_INFO_H

