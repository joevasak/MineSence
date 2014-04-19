// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <string.h>

#include "Given.h"
#include "DomainObject.h"
#include "GarageOpenerState.h"
#include "GarageOpener.h"
#include "OpenState.h"
#include "OpeningState.h"
#include "CloseState.h"
#include "ClosingState.h"
#include "OnState.h"

using namespace std;
int data[] ={100,101,105,210,100,102,110,150,100};

int main(int argc, char* argv[])
{
	GarageOpener* garage = new GarageOpener(OnState("OnState"));
	cout << garage->getState().getName() << endl;
	garage->setData(data);
	CSensor sensor = garage->getCSensor();
	sensor.setDataLenght(9);
	garage->setCSensor(sensor);

	if(garage->getState().getName() == "OnState")
	{
		CDoorLatch latch =  garage->getCDoorLatch();
		latch.setLatchState(true);
		latch.printStatus();
		garage->setCDoorLatch(latch);
		OnState on = OnState("OnState");

		if(on.Calibrate(garage))
		{
			garage->getCSensor().printSensorStatus();
			on.DoorLatch(garage);
			cout << garage->getState().getName() << endl;
	
			if(garage->getState().getName() == "OpenState")
			{
				OpenState open = OpenState("OpenState");
				open.ReadData(garage);
				garage->getCSensor().printDistanceStatus();
				cout << garage->getState().getName() << endl;
			}
			else if(garage->getState().getName() == "CloseState")
			{
				CloseState close = CloseState("CloseState");
				close.ReadData(garage);
				garage->getCSensor().printDistanceStatus();
				cout << garage->getState().getName() << endl;
			}

			if(garage->getState().getName() == "OpeningState")
			{
				OpeningState opening = OpeningState("OpeningState");
				opening.MoveMoter(garage);
				cout << garage->getState().getName() << endl;
			}
		}
		else {garage->getCSensor().printSensorStatus();}
	}
	else{cout << "Error: System is not truned On" << endl;}
	return 0;
}
