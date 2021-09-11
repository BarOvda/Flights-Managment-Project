#ifndef __PLANE_H
#define __PLANE_H

class Plane
{
public:
	//c'tor
	Plane(int mChairNumber, const char* mModel);
	Plane(const Plane& other);

	//d'tor
	virtual ~Plane();

	//getters
	virtual int getSerialNumber();
	virtual int getChairNumber();
	virtual char* getModel();

	//other methods
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


