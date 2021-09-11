#ifndef __PLANE_H
#define __PLANE_H
#include <string>
#include <iostream>
#include <sstream>
class Plane
{
public:
	//c'tor
	Plane(int mChairNumber, const char* mModel);
	Plane(Plane& otherPlane);
	Plane(istream& in) {

		in >> *this;

	}
	Plane();

	//d'tor
	virtual ~Plane();

	//getters
	virtual int getSerialNumber();
	virtual int getChairNumber();
	virtual char* getModel();

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

	bool IsEqual(Plane& otherPlane);
	void print(ostream& out);

	virtual void operator=(const Plane& other);
	virtual bool operator==(const Plane& other);
	virtual bool operator!=(const Plane& other);

	virtual const Plane& operator++();//prefix
	virtual Plane operator++(int);//postfix

	friend ostream& operator<<(ostream& os, const Plane& other);
	virtual void toOs(ostream& os) const;

protected:

	//attributes
	int serialNumber;
	int chairNumber;
	char* model;

	static int currentSerialNumber;
};

#endif // !__PLANE_H


