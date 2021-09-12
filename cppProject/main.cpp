#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

#include "Plane.h"
#include "FlightInfo.h"
#include "CrewMember.h"
#include "Flight.h"
#include "FlightCompany.h"
#include "address.h"
#include "Pilot.h"
#include "Cargo.h"
#include "Host.h"
#include "FlightCompException.h"
#include "PlaneCrewFactory.h"

//const int CM_COUNT = 5;
//const int PLANE_COUNT = 4;
//const int FLIGHT_COUNT = 4;

void main()
{

	FlightCompany* pDelta = NULL;
	try
	{

		pDelta = new FlightCompany("Delta.txt", 0);
		cout << "This was in file " << endl;
		pDelta->Print(cout);

	}
	catch (const FlightCompException& e) {
		e.Show();
		pDelta = new FlightCompany("Delta");
	}
	//
	//	//Checking some of the exception put try and catch for each section	

	/*Plane p1(-34, "AirBus");
	Cargo c1(45, "Jumbo", -560, 200);
	Cargo c2(45, "Jumbo", 560, -200);
	FlightInfo f1("London", -23, 120, 5000);
	FlightInfo f2("LondonVeryLong", 23, 120, 5000);
	FlightInfo f3("London", 23, -120, 5000);
	FlightInfo f4("London", 23, 120, -5000);
	CrewMember* pC1 = pDelta->GetCrewMember(-1);

	CrewMember* pC2 = pDelta->GetCrewMember(0);
	(*pC2) += -4;
	Plane p0 = (*pDelta)[9];*/
	//
	//
	//
	//	//call a static function that get plane or customer from user.
	//
	PlaneCrewFactory::GetCompanyDataFromUser(*pDelta);
	//
	//
	FlightInfo Info("Paris", 343, 320, 5000);
	Flight flight1(Info, &(*pDelta)[0]);
	pDelta->AddFlight(flight1);

	Flight* pF = pDelta->GetFlightByNum(343);
	CrewMember* pCmTemp;
	if (pF != NULL) {
		cout << "flight 343 was found " << endl;
		for (int i = 0; i < pDelta->GetCrewCount(); i++) {
			pCmTemp = pDelta->GetCrewMember(i);
			*pF + pCmTemp;
		}
	}


	try
	{
		//
		pDelta->SaveToFile("Delta_o.txt");

	}
	catch (const FlightCompException& e) {
		e.Show();
	}
	//
	//
	delete pDelta;





	system("pause");
}