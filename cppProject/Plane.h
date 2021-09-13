#ifndef __PLANE_H
#define __PLANE_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Plane
{
public:
	//c'tor
	Plane(int mChairNumber, const char* mModel);
	Plane(Plane& otherPlane);
	Plane(istream& in) {

		in >> *this;

	}

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
		if (typeid(in) == typeid(std::ifstream)) {
			p.model = new char[10];
			if (currentSerialNumber == 100)
				in >> currentSerialNumber >> p.serialNumber >> p.model >> p.chairNumber;
			else
				in >> p.serialNumber >> p.model >> p.chairNumber;
		}
		else {
			cout << "Enter model:" << endl;

			in >> p.model;
			cout << "Enter Current Searial Number:" << endl;

			in >> currentSerialNumber;
			cout << "Enter serial number:" << endl;

			in >> p.serialNumber;

			cout << "Enter number of chairs:" << endl;

			in >> p.chairNumber;
		}
		p.fromOs(in);
		return in;

	}
		
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


