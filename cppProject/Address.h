#ifndef __ADDRESS_H
#define __ADDRESS_H

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
	void print(ostream& out);
	friend ostream& operator<<(ostream& os, const Address& data);

	friend istream& operator>>(istream& in, Address& data);
	bool operator==( Address& other)
	{

		return other.getCity() == this->getCity() && other.houseNumber== this->houseNumber
			&&other.getStreet() == this->getStreet();
	}
	bool operator!=( Address& other)
	{
		return !(this->operator==(other));
	}
private:

//attributes
	char* city;
	char* street;
	int houseNumber;

};

#endif // !__ADDRESS_H

