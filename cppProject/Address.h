#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
#include <sstream>


class Address
{
public:

	//c'tors
	Address(int mHouseNumber, const char* mStreet, const char* mCity = "Tel Aviv");
	Address(const Address& other);
	Address(std::istream& in)
	{
		this->city = new char[10];
		this->street = new char[10];
		this->houseNumber = 0;
	}

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
	Address& GetCurrentAddress();

	void getAdd(std::istream& in) {
		char* hasAdd = new char[1];

		in >> hasAdd;
		stringstream h_a(hasAdd);

		int t;
		h_a >> t;
		if (t != 0) {
			street = new char[10];
			city = new char[10];
			in >> houseNumber >> street >> city;
		}
	};

	friend std::ostream& operator<<(std::ostream& os, Address& data);

	friend std::istream& operator>>(std::istream& in, Address& data);

	void operator=(const Address& other);
	bool operator==(const Address& other);
	bool operator!=(const Address& other);


private:

	//attributes
	char* city;
	char* street;
	int houseNumber;

};

#endif // !__ADDRESS_H

