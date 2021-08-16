#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

#include <string.h>
#include "Plane.h"

int Plane::CurrentserialNumber = 100;

Plane::Plane(int mChairNumber, const char* mModel)
{

	this->serialNumber = ++CurrentserialNumber;
	this->chairNumber = mChairNumber;

	this->model = new char[strlen(mModel)];
	strcpy(this->model, mModel);
}
Plane::Plane(Plane& otherPlane)
{
	this->serialNumber = otherPlane.serialNumber;
	this->serialNumber = otherPlane.chairNumber;

	this->model = new char[strlen(otherPlane.getModel()) + 1];
	strcpy(this->model, otherPlane.getModel());
}
Plane::~Plane()
{
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

//bool Plane::IsEqual(Plane& otherPlane)
//{
//	if (this->serialNumber == otherPlane.getSerialNumber())
//		return true;
//	return false;
//}

void Plane::print(ostream& out)
{
	out << "Plane "
		<< this->serialNumber
		<< " degem "
		<< this->model
		<< " seats "
		<< this->chairNumber;
}

void Plane::setCurrentserialNumber(int mCurrentserialNumber)
{
	Plane::CurrentserialNumber = mCurrentserialNumber;
}

ostream& operator<<(ostream& os, const Plane& data) {
	os << "Plane "
		<< data.serialNumber
		<< " degem "
		<< data.model
		<< " seats "
		<< data.chairNumber;
	return os;
}

