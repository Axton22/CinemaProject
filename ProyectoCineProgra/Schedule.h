#pragma once

#include <string>
using namespace std;

class Schedule {
private:
	string date;
	int startHour;
	int endHour;

public:
	Schedule();
	Schedule(string _date, int _startHour, int _endHour);

	void setDate(string dat);
	string getDate();

	void setStartHour(int _strHour);
	int getStartour();

	void setEndHour(int _endHo);
	int getEndHour();
};