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
	Address& GetCurrentAddress();

	void operator=(const Address& other);
	bool operator==(const Address& other);
	bool operator!=(const Address& other);
	
	friend ostream& operator<<(ostream& os, const Address& other);
	friend istream& operator>>(istream& in, Address& other);

private:

	//attributes
	char* city;
	char* street;
	int houseNumber;

};

#endif // !__ADDRESS_H

