#include <iostream>
#include <string>
#include <iomanip>
#include "Bus.h"

Bus::Bus(int bno, int dno, int sno, string _Driver, string dt, string at, string dc, string ac)
{
	BusNumber = bno;
	Driver = _Driver;
	departure_no = dno;
	departureCity = dc;
	arrivalCity = ac;
	busSubInfo[0].arrivalTime = at;
	busSubInfo[0].departureTime = dt;
	busSubInfo[0].seatNumber = sno;
	std::fill(busSubInfo[0].seatStatus, busSubInfo[0].seatStatus + sno, false);
}

void Bus::setBusInfo(int bno, int dno, int sno, string _Driver, string dt, string at, string dc, string ac)
{
	BusNumber = bno;
	Driver = _Driver;
	departureCity = dc;
	arrivalCity = ac;
	departure_no = dno;
	busSubInfo[0].arrivalTime = at;
	busSubInfo[0].departureTime = dt;
	busSubInfo[0].seatNumber = sno;
	std::fill(busSubInfo[0].seatStatus, busSubInfo[0].seatStatus + sno, false);
	delete[] busSubInfo[0].seatStatus;
}

void Bus::set_departure_no(int dno)
{
	departure_no = dno;
}

int Bus::get_departure_no()
{
	return departure_no;
}

void Bus::setBusnumber(int bno)
{
	BusNumber = bno;
}


void Bus::setDriver(string _driver)
{
	Driver = _driver;
}

void Bus::setBusSubInfo(string dt, string at, int sno, int index)
{
	BusSubInfo tmp = { index,sno,dt,at };
	for (int i = 0; i < 100; i++)
	{
		tmp.seatStatus[i] = false;
	}
	busSubInfo.push_back(tmp);
}

vector<BusSubInfo> Bus::getBusSubInfo()
{
	return busSubInfo;
}


void Bus::setDC(string dc)
{
	departureCity = dc;
}

void Bus::setAC(string ac)
{
	arrivalCity = ac;
}

int Bus::getBusnumber()
{
	return BusNumber;
}


string Bus::getDriver()
{
	return Driver;
}


string Bus::getDC()
{
	return departureCity;
}

string Bus::getAC()
{
	return arrivalCity;
}

void Bus::printBusInfo()
{
	int oqp = 0, frei = 0;
	cout << endl << endl;
	cout << "Bus number: " << BusNumber << endl;
	cout << "Driver's name: " << Driver << endl;
	cout << "Departure city: " << departureCity << endl;
	cout << "Arrival city: " << arrivalCity << endl;
	cout << "Departure time" << "\t\tArrival Time" << "\t\tFreie Plaetze" << "\t\tReservierte Plaetze" << endl;
	cout << "================================================================================================================" << endl;
	for (int i = 0; i < departure_no; i++)
	{

		cout << busSubInfo[i].departureTime << "\t\t          " << busSubInfo[i].arrivalTime;
		for (int j = 0; j < busSubInfo[i].seatNumber; j++)
		{

			if (busSubInfo[i].seatStatus[j] == false)
				frei++;
			else
				oqp++;
		}
		cout << "\t\t                " << frei;
		cout << "\t\t             " << oqp << endl;
		frei = oqp = 0;
	}
	cout << endl <<endl;
}

void Bus::printBusSeatStatus(int index)
{
	cout << endl << endl;
	int count = 0;
	cout << "Bus number: " << BusNumber << endl;
	cout << "Departure city: " << departureCity << endl;
	cout << "Arrival city: " << arrivalCity << endl;
	cout << "Departure time" << "\t\tArrival Time" << endl;
	cout << busSubInfo[index].departureTime << "\t\t          " << busSubInfo[index].arrivalTime << endl;
	cout << "Seat Status" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (int j = 0; j < busSubInfo[index].seatNumber; j++)
	{
		std::cout << std::setfill('0') << std::setw(2) << j + 1 << ":" << (busSubInfo[index].seatStatus[j] ? " reserviert\t" : " frei\t");
		count++;

		// Si 5 éléments ont été affichés, passez à une nouvelle ligne et réinitialisez le comptage
		if (count == 5)
		{
			cout << endl;
			count = 0;
		}
	}
	cout << endl << endl;
}

void Bus::setBusSeatStatus(int index, int seat_num, bool status)
{
	busSubInfo[index].seatStatus[seat_num - 1] = status;
}
