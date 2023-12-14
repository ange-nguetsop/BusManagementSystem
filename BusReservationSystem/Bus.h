#include <vector>
#pragma once
using namespace std;

struct BusSubInfo 
{
	int index;
	int seatNumber;
	std::string departureTime;
	std::string arrivalTime;
	bool seatStatus[100];
};

class Bus
{
private:
	int BusNumber;
	int departure_no;
	string Driver;
	string departureCity;
	string arrivalCity;
	vector<BusSubInfo> busSubInfo;

public:
	Bus() = default;
	Bus(int bno, int dno, int sno, string _Driver, string dt, string at, string dc, string ac);
	void setBusInfo(int bno, int dno, int sno, string _Driver, string dt, string at, string dc, string ac);
	~Bus() = default;
	void set_departure_no(int dno);
	int get_departure_no();
	void setBusnumber(int bno);
	void setDriver(string _driver);
	void setBusSubInfo(string dt, string at, int sno,int index);
	vector<BusSubInfo> getBusSubInfo();
	void setDC(string dc);
	void setAC(string ac);
	int getBusnumber();
	string getDriver();
	string getDC();
	string getAC();
	void printBusInfo();
	void printBusSeatStatus(int index);
	void setBusSeatStatus(int index, int seat_num, bool status);
};

