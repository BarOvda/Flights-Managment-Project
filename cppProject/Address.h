#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>

class Address
{
public:

	//c'tors
	Address(int mHouseNumber, const char* mStreet, const char* mCity = "Tel Aviv");
	Address(const Address& other);

	//d'tor
	~Address();

	//getters
	int getHouseNumber();
	char* getStreet();
	char* getCity();

	//setters
	void UpdateAddress(int mHouseNumber, const char* mStreet, const char* mCity);

	// more methods
	void print(std::ostream& out);

	friend std::ostream& operator<<(std::ostream& os, const Address& data);

	friend std::istream& operator>>(std::istream& in, Address& data);

	bool operator==(Address& other)
	{

		return strcmp(other.getCity(), this->getCity()) && other.houseNumber == this->houseNumber
			&& strcmp(other.getStreet(), this->getStreet());
	}

	bool operator!=(Address& other)
	{
		return !(this->operator==(other));
	}

	Address GetCurrentAddress();
private:

	//attributes
	char* city;
	char* street;
	int houseNumber;

};

#endif // !__ADDRESS_H

