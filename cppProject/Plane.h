#ifndef __PLANE_H
#define __PLANE_H
#include <string>
#include <iostream>
#include <sstream>
class Plane
{
public:
	static const int START_ID = 100;
	//c'tor
	Plane(int mChairNumber, const char* mModel);
	Plane(Plane& otherPlane);
	Plane(istream& in) {

		in >> *this;

	}
	Plane();


	//d'tor
	~Plane();

	//getters
	int getSerialNumber();
	int getChairNumber();
	char* getModel();

	//other methods
		//bool IsEqual(Plane& otherPlane);
	virtual void fromOs(istream& in) {};

	friend istream& operator>>(istream& in, Plane& p) {
		//if (typeid(in) == typeid(ifstream))
		p.model = new char[10];
		if (CurrentserialNumber == START_ID)
			in >> CurrentserialNumber >> p.serialNumber >> p.model >> p.chairNumber;
		else
			in >> p.serialNumber >> p.model >> p.chairNumber;

		//else {
		//	char delimiter;
		//	in >> delimiter >> c.name>>delimiter>>c.totalFlightTime>>delimiter;
		//}
		p.fromOs(in);
		return in;

	}
	bool operator==(Plane& other)
	{
		return other.getSerialNumber() == this->getSerialNumber()
			&&strcmp(other.getModel(),this->getModel())==0&& other.getChairNumber()== this->getChairNumber();
	}

	bool operator!=(Plane& other)
	{
		return !(this->operator==(other));
	}

	const Plane& operator=(const Plane& other);

	void print(ostream& out);

	friend ostream& operator<<(ostream& os, const Plane& data);

	// prefix increment
	const Plane& operator++() {
		chairNumber++;
		return *this;
	}

	// postfix increment
	Plane operator++(int)
	{

		Plane old(*this);
		chairNumber++;
		return old;
	}

	static void setCurrentserialNumber(int mCurrentserialNumber);

private:

	//attributes
	static int CurrentserialNumber;
	int serialNumber;
	int chairNumber;
	char* model;
};


#endif // !__PLANE_H


