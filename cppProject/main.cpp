#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Plane.h"
#include "FlightInfo.h"
#include "CrewMember.h"
#include "FlightCompany.h"
#include "Address.h"


void main()
{

	cout << endl << "Checking CFlightCompany" << endl;

	FlightCompany* pDelta = new FlightCompany("Delta");
	cout << endl << "First company" << endl;
	pDelta->print(cout);

	pDelta->setName("AA");
	cout << endl << "After change name" << endl;
	pDelta->print(cout);

	FlightCompany* pComp2 = new FlightCompany(*pDelta);
	cout << endl << "two companies has the same name" << endl;
	pComp2->print(cout);

	delete pDelta;
	delete pComp2;

	cout << endl << "Checking CCrewMembwe " << endl;

	CrewMember* pCm1 = new CrewMember("Momo", 125);
	cout << endl << "first Crew Member" << endl;
	pCm1->print(cout);

	CrewMember* pCm2 = new CrewMember("Gogo");
	cout << endl << "second Crew Member" << endl;
	pCm2->print(cout);

	if (!pCm2->UpdateMinutes(-14))
		cout << "error update minutes" << endl;

	if (!pCm2->UpdateMinutes(200))
		cout << "error update minutes" << endl;

	{ //dont remove!!!
		cout << endl << "two same crewmembers" << endl;
		CrewMember temp(*pCm1);
		temp.print(cout);
		if (temp.IsEqual(*pCm1))
			cout << "*****  EQUALS *****" << endl;
		else
			cout << "*****  NOT EQUALS *****" << endl;

		cout << "*****  Checking Address *****" << endl;
		Address a(23, "Alenbi");
		Address b(34, "Jafa", "Jerusalem");
		a.print(cout);
		b.print(cout);
		b.UpdateAddress(55, "KG", "Haifa");
		b.print(cout);

	}


	{
		CrewMember temp = *pCm2;
		temp.print(cout);
		if (temp.IsEqual(*pCm1))
			cout << "*****  EQUALS *****" << endl;
		else
			cout << "*****  NOT EQUALS *****" << endl;
	}

	delete pCm1;
	delete pCm2;


	cout << endl << "Checking CFlightInfo" << endl;
	FlightInfo fInfo1("Paris", 343, 320, 5000);
	FlightInfo fInfo2("Rome", 506, 220, 4000);

	fInfo1.print(cout);
	fInfo2.print(cout);

	fInfo2.setDest("London");
	cout << "Info after change destination" << endl;
	fInfo2.print(cout);


	cout << endl << "Checking CPlane" << endl;

	Plane p1(101, 200, "Jumbo");
	Plane p2(p1);
	Plane p3 = p1;

	p1.print(cout);
	p2.print(cout);
	p3.print(cout);

	if (p1.IsEqual(p2))
		cout << "*****  EQUALS *****" << endl;
	else
		cout << "*****  NOT EQUALS *****" << endl;

	system("pause");
}

