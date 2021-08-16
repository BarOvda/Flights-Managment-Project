#ifndef __PLANE_H
#define __PLANE_H

class Plane
{
public:
	//c'tor
	Plane(int mChairNumber, const char* mModel);
	Plane(Plane& otherPlane);


	//d'tor
	~Plane();

	//getters
	int getSerialNumber();
	int getChairNumber();
	char* getModel();

	//other methods
		//bool IsEqual(Plane& otherPlane);

	bool operator==(Plane& other)
	{
		return other.getSerialNumber() == this->getSerialNumber();
	}

	bool operator!=(Plane& other)
	{
		return !(this->operator==(other));
	}

	void operator=(Plane& other);

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

	static void setCurrentserialNumber(int mCurrentserialNumber);

private:

	//attributes
	static int CurrentserialNumber;
	int serialNumber;
	int chairNumber;
	char* model;
};


#endif // !__PLANE_H


