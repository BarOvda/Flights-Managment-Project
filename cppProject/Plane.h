#ifndef __PLANE_H
#define __PLANE_H

class Plane
{
public:
//c'tor
	Plane(int mSerialNumber, int mChairNumber, const char* mModel);

//d'tor
	~Plane();

//getters
	int getSerialNumber();
	int getChairNumber();
	char* getModel();

//other methods
	bool IsEqual(Plane& otherPlane);
	void print(ostream& out);

private:

//attributes
	int serialNumber;
	int chairNumber;
	char* model;
};

#endif // !__PLANE_H


