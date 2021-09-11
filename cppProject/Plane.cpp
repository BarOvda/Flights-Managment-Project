#include <iostream>
using namespace std;

#pragma warning (disable: 4996)
#include <fstream>

#include <string.h>
#include "Plane.h"

int Plane::currentSerialNumber = 100;

Plane::Plane(int mChairNumber, const char* mModel): model(nullptr)
{
	this->serialNumber = currentSerialNumber++;
	this->chairNumber = mChairNumber;

	this->model = new char[strlen(mModel)];
	strcpy(this->model, mModel);
}

Plane::Plane(Plane& otherPlane)
	: model(nullptr)
{
	this->serialNumber = otherPlane.serialNumber;
	this->chairNumber = otherPlane.chairNumber;

	delete[]this->model;
	this->model = strdup(otherPlane.model);
}

Plane::~Plane()
{
	this->model = nullptr;
	delete[]this->model;
}

int Plane::getSerialNumber()
{
	return this->serialNumber;
}

int Plane::getChairNumber()
{
	return this->chairNumber;
}

char* Plane::getModel()
{
	return this->model;
}

bool Plane::IsEqual(Plane& otherPlane)
{
	if (this->serialNumber == otherPlane.getSerialNumber())
		return true;
	return false;
}

void Plane::print(ostream& out)
{
	out << "Plane "
		<< this->serialNumber
		<< " degem "
		<< this->model
		<< " seats "
		<< this->chairNumber;
}

void Plane::operator=(const Plane& other)
{
	if (*this != other) {
		this->model = nullptr;
		this->serialNumber = other.serialNumber;
		this->chairNumber = other.chairNumber;

		delete[]this->model;
		this->model = strdup(other.model);
	}
}

bool Plane::operator==(const Plane& other)
{
	if (this->serialNumber == other.serialNumber)
		return true;
	return false;
}

bool Plane::operator!=(const Plane& other)
{
	return !(*this == other);
}

const Plane& Plane::operator++()
{
	this->chairNumber++;
	return *this;
}

Plane Plane::operator++(int)
{
	Plane temp(*this);
	chairNumber++;
	return temp;
}

void Plane::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream)) {
		os << " "
			<<this->currentSerialNumber<<" "
			<< this->serialNumber
			<< " "
			<< this->model
			<< " seats "
			<< this->chairNumber
			<< endl;
	}
	else {
		os << "Plane "
			<< this->serialNumber
			<< " degem "
			<< this->model
			<< " seats "
			<< this->chairNumber
			<< endl;
	}

	
}

ostream& operator<<(ostream& os, const Plane& other)
{
	other.toOs(os);
	return os;
}
