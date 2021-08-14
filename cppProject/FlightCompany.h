#ifndef __FLIGHT_COMPANY
#define __FLIGHT_COMPANY

class FlightCompany
{
public:
//c'tor
	FlightCompany(const char* mCompanyName);
	FlightCompany(FlightCompany& otherCompany);

//d'tor
	~FlightCompany();

//getters
	char* getCompanyName();

//setters
	void setName(const char* mName);

//other methods
	void print(ostream& out);

private:
//attributes
	char* companyName;


};

#endif // !__FLIGHT_COMPANY

