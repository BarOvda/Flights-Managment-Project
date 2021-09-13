#ifndef __PILOT_H
#define __PILOT_H
#include <sstream>

#include "CrewMember.h"
#include "Address.h"


class Pilot : public CrewMember
{
public:
	//c'tor
	Pilot(const char* mName, bool isACapitan, Address* address = nullptr, int mTotalFlightTime = 0);
	Pilot(CrewMember& member);
	Pilot(Pilot& other);

	Pilot(std::istream& in) :CrewMember(in) {
		//TODOADD
		Address* ad = new Address(0, "");
		this->address = ad;
		fromOs(in);
	}

	//d'tor
	~Pilot();

	//other methods
	void operator=(const Pilot& other);
	bool operator==(const Pilot& other);
	bool operator!=(const Pilot& other);


	virtual void fromOs(std::istream& in) override {
		if (typeid(in) == typeid(ifstream)) {

			//address = &Address(in);

			char* hasAdd = new char[1];

			in >> hasAdd;
			stringstream is_add(hasAdd);

			int res_add;
			is_add >> res_add;
			if (res_add == 1) {

				char* city = new char[10];
				char* street = new char[10];
				int hose;


				//	in >> hose >> street >> city;
							//Address add = Address(hose, street, city);
					//this->address = &add;
				in >> *this->address;

				//*this->address = Address(hose, street, city);;



			}


			char* isCapt = new char[1];

			in >> isCapt;
			stringstream is_cap(isCapt);

			int res;
			is_cap >> res;

			if (res == 0) {
				isACapitan = false;
			}
			else {
				isACapitan = true;
			}
		}
		else {
			bool has_add;
			cout << "Enter Has Address: 0 - No 1 - Yes:" << endl;

			in >> has_add;
			if (has_add) {
				Address* h = new Address(0, "");;

				this->address = h;
				in >> *this->address;
			}
			cout << "Enter Is a captian: 0 - No 1 - Yes:" << endl;

			in >> this->isACapitan;
		}
	};
	//d'tor
//	~FlightCompany();
	virtual void toOs(ostream& os) const override;


	// Inherited via CrewMember
	virtual void getUniform() const override;
	virtual void takeOff(int flightTime) override;
	virtual void getPresent() const override;
	virtual void gotoSimulator();

private:
	//attributes
	bool isACapitan;
	Address* address;

};


#endif // !__PILOT_H

