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


const int CM_COUNT = 5;
const int PLANE_COUNT = 4;
const int FLIGHT_COUNT = 4;

void main()
{
	FlightCompany Delta("Delta");
	Address ad1(34, "DZ");
	//Address ad2(ad1);

	CrewMember* cmArr[CM_COUNT];
	cmArr[0] = new Pilot("Soso", false, &ad1); 
	cmArr[1] = new Host("Momo", Host::eRegular);//name, type
	cmArr[2] = new Host("Lolo", Host::eSuper);
	cmArr[3] = new Host("Popo", Host::eCalcelan);
	cmArr[4] = new Pilot("Toto", true); //no address and min

	//Check updateTime
	for (int i = 0; i < CM_COUNT; i++)
		(*cmArr[i]) += (60);

	for (int i = 0; i < CM_COUNT; i++)
		cmArr[i]->print(cout);

	cout << endl << "******** Add CrewMember  *********" << endl;
	for (int i = 0; i < CM_COUNT; i++)
	{
		if (!Delta.AddCrewMember(*cmArr[i]))
			cout << "Problem adding CrewMember " << i << endl;
	}

	cout << endl << "******** Trying add same CrewMember *********" << endl;
	Host h1((Host&)(*cmArr[1])); //creating temp with different pointers.
	Pilot p1((Pilot&)(*cmArr[4]));
	if (!Delta.AddCrewMember(h1))
		cout << "Problem adding CrewMember h1" << endl;

	if (!Delta.AddCrewMember(p1))
		cout << "Problem adding CrewMember p1" << endl;

	cout << endl << "******** After adding CrewMember *********" << endl;
	Delta.Print(cout);

	cout << "********  *********" << endl;

	for (int i = 0; i < CM_COUNT; i++)
		delete cmArr[i];

	Plane* pArr[PLANE_COUNT];
	pArr[0] = new Plane(100, "Boing373"); //seats and degem
	pArr[1] = new Plane(50, "Boing373");
	pArr[2] = new Plane(1, "Boing3");
	pArr[3] = new Cargo(4, "Lift400", 4000, 5000); //seats, degem, max kg, max volume

	////checking load cargo
	if (!((Cargo*)pArr[3])->Load(1000, 1500))
		cout << "error1 loading plane " << (*pArr[3]) << endl;

	if (!((Cargo*)pArr[3])->Load(800, 2000))
		cout << "error2 loading plane " << (*pArr[3]) << endl;

	if (!((Cargo*)pArr[3])->Load(1800, 1000))
		cout << "error3 loading plane " << (*pArr[3]) << endl;


	if (!((Cargo*)pArr[3])->Load(800, 1200))
		cout << "error4 loading plane " << (*pArr[3]) << endl;


	for (int i = 0; i < PLANE_COUNT; i++)
		if (!Delta.AddPlane(*pArr[i]))
			cout << "Problem adding " << *pArr[i];

	for (int i = 0; i < PLANE_COUNT; i++)
		if (!Delta.AddPlane(*pArr[i]))
			cout << "Problem adding " << *pArr[i];


	cout << "******** After adding Planes *********" << endl;
	Delta.Print(cout);
	cout << "********  *********" << endl;

	for (int i = 0; i < PLANE_COUNT; i++)
		delete pArr[i];


	FlightInfo* fInfoArr[FLIGHT_COUNT];
	//const char* dest,int n,int min, int km
	fInfoArr[0] = new FlightInfo("Paris", 343, 320, 5000);
	fInfoArr[1] = new FlightInfo("Rome", 506, 220, 4000);
	fInfoArr[2] = new FlightInfo("London", 600, 400, 6000);
	fInfoArr[3] = new FlightInfo("Berlin", 706, 340, 4500);


	Flight* FArr[FLIGHT_COUNT];
	for (int i = 0; i < FLIGHT_COUNT; i++)
		FArr[i] = new Flight(*fInfoArr[i], Delta.GetPlane(i));

	for (int i = 0; i < FLIGHT_COUNT; i++)
		if (!Delta.AddFlight(*FArr[i]))
			cout << "Problem adding flight " << FArr[i]->GetFlightInfo();

	for (int i = 0; i < FLIGHT_COUNT; i++)
		if (!Delta.AddFlight(*FArr[i]))
			cout << "Problem adding flight " << FArr[i]->GetFlightInfo();

	cout << "******** After adding Flights *********" << endl;
	Delta.Print(cout);
	cout << "********  *********" << endl;

	for (int i = 0; i < FLIGHT_COUNT; i++) {
		delete fInfoArr[i];
		delete FArr[i];
	}

	Flight* pF2 = Delta.GetFlightByNum(706);

	CrewMember* pCmTemp;
	if (pF2 != NULL) {
		cout << "flight 706 was found\n" << endl;

		for (int i = 0; i < CM_COUNT / 2; i++) {
			pCmTemp = Delta.GetCrewMember(i);
			*pF2 + pCmTemp;
		}

		cout << "******** Take off *********" << endl;
		if (!pF2->TakeOff())
			cout << "error in take of flight 706" << endl;

	}
	else
		cout << "flight 706 was not found " << endl;

	pF2 = Delta.GetFlightByNum(343);
	if (pF2 != NULL) {
		cout << "flight 343 was found " << endl;
		for (int i = 0; i < CM_COUNT; i++) {
			pCmTemp = Delta.GetCrewMember(i);
			*pF2 + pCmTemp;
		}
		cout << "******** Take off *********" << endl;
		if (!pF2->TakeOff())
			cout << "error in take of flight 343" << endl;

	}
	else
		cout << "flight 343 was not found " << endl;

	cout << "******** Holiday Gift is now on *********" << endl;
	Delta.CrewGetPresent();
	cout << "********  *********" << endl;

	cout << "******** Simulator is on *********" << endl;
	Delta.PilotsToSimulator();
	cout << "********  *********" << endl;

	cout << "******** Uniform to all *********" << endl;
	Delta.CrewGetUniform();
	cout << "********  *********" << endl;

	cout << "******** Counting cargo planes *********" << endl;

	cout << "Delta has " << Delta.GetCargoCount() << " cargo planes" << endl;

	cout << "******** final flight company print *********" << endl;
	Delta.Print(cout);
	cout << "********  *********" << endl;



	system("pause");
}