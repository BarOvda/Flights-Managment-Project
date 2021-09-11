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
	Address(std::istream& in) {
		getAdd(in);
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
		/*	char* hose_num = new char[3];

			in >> hose_num;
			stringstream h_n(hose_num);

			int hose;
			h_n >> hose;
			houseNumber = hose;
			in >> street;
			in >> city;*/
		
		}
		
	};
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

