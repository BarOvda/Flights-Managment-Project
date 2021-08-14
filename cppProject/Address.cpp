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
	
	//
	//
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
	delete []this->street;
	delete []this->city;
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
 ostream& operator<<(ostream& os, const Address& data) {
	 os << data.street
		 << " "
		 << data.houseNumber
		 << ", "
		 << data.city
		 << endl;
	 return os;
}
  istream& operator>>(istream& in, Address& data) {

	  in.getline(data.street, sizeof(data.street));
	  in.getline(data.city, sizeof(data.city));
	  in >> data.houseNumber;

	 return in;
 }

