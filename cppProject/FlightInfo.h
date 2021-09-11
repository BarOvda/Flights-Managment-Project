
#ifndef __FLIGHT_INFO_H
#define __FLIGHT_INFO_H

#define MAX 100


class FlightInfo
{
public:
	//c'tor
	FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength);
	FlightInfo(FlightInfo& otherFlightInfo);
	FlightInfo(std::istream& in) {
		getInfo(in);
	}
	FlightInfo();

	//d'tor
	~FlightInfo();

	//getters

	void getInfo(std::istream& in) {
		in >> destination >> flightNumber >> flightTime >> flightLength;

	};

	int getFlightTime();
	int getFlightLength();
	char* getDestination();
	int GetFNum();
	//setters
	void setFlightNumber(int mFlightNumber);
	void setFlightTime(int mFlightTime);
	void setFlightLength(int mFlightLength);
	void setDest(const char mDestination[]);

	//other methods
	bool isSameFlightNumber(int mFlightNumber);
	void print(ostream& out);
	friend ostream& operator<<(ostream& os, const FlightInfo& data);

	bool operator==(const FlightInfo& other) const
	{
		return flightNumber == other.flightNumber
			&& flightTime == other.flightTime
			&& flightLength == other.flightLength
			&& strcmp(destination , other.destination);
	}

	bool operator!=(const FlightInfo& other) const
	{
		return !(*this == other);
	}

	operator int() const
	{
		return flightTime;
	}

private:

	//attributes
	int flightNumber;
	char destination[MAX];
	int flightTime; // minutes
	int flightLength; // km

};


#endif // !__FLIGHT_INFO_H

