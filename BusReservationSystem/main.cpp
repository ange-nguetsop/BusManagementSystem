
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Bus.h"

using namespace std;
void BusInformation(vector<Bus>& data);
void ShowInformation(vector<Bus>& data);
void Reservation(vector<Bus>& data);
char choice = 'c';

int main()
{

	vector<Bus> Data;
	int index = 0;
	while (choice != 'e' && choice != 'E' && choice != '4')
	{
	cout << "\t*********************************************************************" << endl;
	cout << "\t                     Bus Management System                              " << endl;
	cout << "\t*********************************************************************" << endl <<endl;
	cout << "\t1--> Add Bus Informations" << endl;
	cout << "\t2--> Reservation" << endl;
	cout << "\t3--> Show Informations" << endl;
	cout << "\t4--> Exit" << endl <<endl;

	cout << "Your choice: ";
	cin >> choice;
	cin.ignore();


		switch (choice)
		{
		case '1':
			BusInformation(Data);
			// system("cls");
			break;
		case '2':
			Reservation(Data);
			// system("cls");
			break;
		case '3':
			ShowInformation(Data);
			// system("cls");
			break;
		case '4':
			cout << endl << "Auf Wiedersehen!" << endl;
			break;
		default:
			cout << "Du hast einen Fehler bei der Auswahl gemacht" << endl;
			cout << "Bitte versuch noch mal" << endl;
			system("cls");
		}
	}
}

void BusInformation(vector<Bus>& data)
{
	Bus b;
	string tmp, tmp1;
	int no = 0, dno = 0;
	cout << endl << endl << "============ Add Bus Informations==============" << endl << endl;
	cout << "Enter Driver's name: ";
	getline(cin, tmp);
	b.setDriver(tmp);
	cout << "Enter Bus number: ";
	cin >> no;
	cin.ignore();
	b.setBusnumber(no);
	cout << "Enter Departure City: ";
	getline(cin, tmp);
	b.setDC(tmp);
	cout << "Enter Arrival City: ";
	getline(cin, tmp);
	b.setAC(tmp);
	cout << "Enter number of Bus' seats: ";
	cin >> no;
	cin.ignore();

	cout << "Departure and Arrival Time: " << endl;
	cout << ">---------------------------------------------<" << endl;
	cout << "How many departures? ";
	cin >> dno;
	b.set_departure_no(dno);
	cin.ignore();

	for (int i = 0; i < dno; i++)
	{
		cout << "Enter Departure Time " << i + 1 << " with the format hh:mm >> ";
		getline(cin, tmp);
		cout << "Enter Arrival Time " << i + 1 << " with the format hh:mm >> ";
		getline(cin, tmp1);
		b.setBusSubInfo(tmp,tmp1,no,i);
	}

	data.push_back(b);
	cout << endl << "Continue? e -> 'Exit' c -> 'Continue' >> ";
	cin >> choice;
	system("cls");
}


void ShowInformation(vector<Bus>& data)
{
	cout << "---------------------------------------------------------------------------" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		data[i].printBusInfo();
	}
	cout << endl;
	cout << endl << "Continue? e -> 'Exit' c -> 'Continue' >> ";
	cin >> choice;
	system("cls");
}

void Reservation(vector<Bus>& data)
{
	string depCity, arCity;
	string time;
	int bno, sno;

	cout << "Departure City: ";
	getline(cin, depCity);
	cout << endl << "Arrival City: ";
	getline(cin, arCity);
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].getDC()== depCity)
		{
			if (data[i].getAC() == arCity)
			{
				data[i].printBusInfo();
			}
		}
	}

	cout << "Enter your departure time with the format hh:mm >> ";
	getline(cin, time);

	cout << "For your departure time these busses are available: " << endl;

	for (int i = 0; i < data.size(); i++)
	{
		vector<BusSubInfo> tmp = data[i].getBusSubInfo();
		for (int j = 0; j < tmp.size(); j++)
		{
			if (data[i].getDC() == depCity)
			{
				if (data[i].getAC() == arCity)
				{
					if (tmp[j].departureTime.substr(0, 2) == time.substr(0, 2))
					{
						data[i].printBusSeatStatus(tmp[j].index);
					}
				}
			}

		}
	}

	cout << endl;
	cout << "Enter the Bus' number you want to take:  ";
	cin >> bno;
	cout << endl << "Enter the Seat's number you want to reserve:  ";
	cin >> sno;
	for (int i = 0; i < data.size(); i++)
	{

		if (data[i].getBusnumber() == bno)
		{
			vector<BusSubInfo> tmp = data[i].getBusSubInfo();
			for (int j = 0; j < tmp.size(); j++)
			{
				if (data[i].getDC() == depCity)
				{
					if (data[i].getAC() == arCity)
					{
						if (tmp[j].departureTime.substr(0, 2) == time.substr(0, 2))
						{
							data[i].setBusSeatStatus(tmp[j].index, sno, true);
							data[i].printBusSeatStatus(tmp[j].index);
						}
					}
				}

			}

		}
	}

	cout << endl << "Continue? e -> 'Exit' c -> 'Continue' >> ";
	cin >> choice;
	system("cls");
}