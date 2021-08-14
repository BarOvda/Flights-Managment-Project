#ifndef __PLANE_H
#define __PLANE_H

class Plane
{
public:
//c'tor
	Plane(int mSerialNumber, int mChairNumber, const char* mModel);
	Plane(Plane& otherPlane);


//d'tor
	~Plane();

//getters
	int getSerialNumber();
	int getChairNumber();
	char* getModel();

//other methods
	bool IsEqual(Plane& otherPlane);
	void print(ostream& out);
	friend ostream& operator<<(ostream& os, const Plane& data);
	// prefix increment
	const Plane& operator++() {
		this->chairNumber++;
		return *this;
	}
	// postfix increment
	Plane operator++(int)
	{
		Plane old = *this;
		this->chairNumber++;
		return old;
	}

private:

//attributes
	int serialNumber;
	int chairNumber;
	char* model;
};

#endif // !__PLANE_H


