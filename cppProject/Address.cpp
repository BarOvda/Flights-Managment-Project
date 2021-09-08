#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

#include <string.h>
#include "Address.h"

Address::Address(int mHouseNumber, const char* mStreet, const char* mCity) {
	this->houseNumber = mHouseNumber;
	if (mStreet != NULL) {
		this->street = new char[strlen(mStreet) + 1];
		strcpy(this->street, mStreet);
	}
	else {
		this->street = new char[20];
	}
	if (city != NULL) {
		this->city = new char[strlen(mCity) + 1];
		strcpy(this->city, mCity);
	}
	else {
		this->city = new char[20];
	}
}

Address::Address(const Address& other)
{
	this->houseNumber = other.houseNumber;
	if (other.street != NULL) {
		strcpy(this->street, other.street);
		this->street = new char[strlen(other.street) + 1];

	}
	if (other.city != NULL) {
		this->city = new char[strlen(other.city) + 1];

		strcpy(this->city, other.city);
	}
	
}

Address::~Address()
{
	delete[]this->street;
	delete[]this->city;
}

int Address::getHouseNumber()
{
	return this->houseNumber;
}

char* Address::getStreet()
{
	return this->street;
}

char* Address::getCity()
{
	return this->city;
}

void Address::UpdateAddress(int mHouseNumber, const char* mStreet, const char* mCity)
{
	this->houseNumber = mHouseNumber;
	if (strlen(this->street) < strlen(mStreet)) {
		this->street = new char[strlen(mStreet) + 1];
	}

	if (strlen(this->city) < strlen(mCity)) {
		this->city = new char[strlen(mCity) + 1];
	}

	strcpy(this->street, mStreet);
	strcpy(this->city, mCity);
}

void Address::print(ostream& out)
{
	out << this->street
		<< " "
		<< this->houseNumber
		<< ", "
		<< this->city
		<< endl;
}
Address Address::GetCurrentAddress()
{
	return *this;
}
ostream& operator<<(ostream& out, const Address& data) {
	out << data.street
		<< " "
		<< data.houseNumber
		<< ", "
		<< data.city
		<< endl;
	return out;
}
istream& operator>>(istream& in, Address& data) {
	cout << "Please enter house number street name and city name:" << endl;
	in >> data.houseNumber;
	in >> data.street;
	in >> data.city;

	return in;
}

