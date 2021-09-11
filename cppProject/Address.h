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
		/*	char* hose_num = new char[3];

			in >> hose_num;
			stringstream h_n(hose_num);

	void operator=(const Address& other);
	bool operator==(const Address& other);
	bool operator!=(const Address& other);
	
	friend ostream& operator<<(ostream& os, const Address& other);
	friend istream& operator>>(istream& in, Address& other);
			int hose;
			h_n >> hose;
			houseNumber = hose;
			in >> street;
			in >> city;*/
		
		}
		
	};
	friend std::ostream& operator<<(std::ostream& os, const Address& data);

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

