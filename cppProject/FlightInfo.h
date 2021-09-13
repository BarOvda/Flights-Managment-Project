
#ifndef __FLIGHT_INFO_H
#define __FLIGHT_INFO_H

#define MAX 100
#include <string>
#include <iostream>
#include <typeinfo>

#include <fstream>


class FlightInfo
{
public:
	//c'tor
	FlightInfo(const char* mDestination, int mFlightNumber, int mFlightTime, int mFlightLength);
	FlightInfo(const FlightInfo& other);
	FlightInfo(std::istream& in) {
		in >> *this;
	}
	FlightInfo();

	//d'tor
	~FlightInfo();

	//getters
	int GetFNum();


	friend istream& operator>>(istream& in, FlightInfo& f) {
		if (typeid(in) == typeid(std::ifstream)) {
			in >> f.destination >> f.flightNumber >> f.flightTime >> f.flightLength;
		}
		else {
			cout << "Enter destination" << endl;

			in >> f.destination;
			cout << "Enter flight Number" << endl;
			in >> f.flightNumber;
			cout << "Enter flightTime" << endl;

			in >> f.flightTime;
			cout << "Enter flightLength" << endl;
			in >> f.flightLength;
		}
		return in;
	}


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

