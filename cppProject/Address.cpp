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

	if (mStreet != NULL) {
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
	this->street = new char[strlen(other.street) + 1];
	this->city = new char[strlen(other.city) + 1];
	strcpy(this->street, other.street);
	strcpy(this->city, other.city);
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

void Address::operator=(const Address& other)
{
	if (*this != other) {
		this->houseNumber = other.houseNumber;

		delete[]this->street;
		delete[]this->city;

		this->street = strdup(other.street);
		this->city = strdup(other.city);
	}
}

bool Address::operator==(const Address& other)
{
	if (strcmp(this->city, other.city) 
		&& strcmp(this->street, other.street) 
		&& this->houseNumber == other.houseNumber)
		return true;
	return false;
}

bool Address::operator!=(const Address& other)
{
	return !(*this == other);
}

Address& Address::GetCurrentAddress()
{
	return *this;
}

ostream& operator<<(ostream& os, const Address& other)
{
	os << other.street
		<< " "
		<< other.houseNumber
		<< ", "
		<< other.city
		<< endl;

	return os;
}

istream& operator>>(istream& in, Address& other)
{
	cout << "Please enter house number street name and city name:" << endl;

	in >> other.houseNumber >> other.street >> other.city;
	return in;
}
