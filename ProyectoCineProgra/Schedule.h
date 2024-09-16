#pragma once

#include <string>
using namespace std;

class Schedule {
private:
	string date;
	int startHour;
	int startMinutes;
	int endHour;
	int endMinutes;

public:
	Schedule();
	Schedule(string _date, int _startHour, int _starMinutes, int _endHour, int _endMinutes);

	void setDate(string dat);
	string getDate();

	void setStartHour(int _strHour);
	int getStartHour();
	void setStartMinutes(int _strMin);
	int getStartMinutes();

	void setEndHour(int _endHo);
	int getEndHour();
	void setEndMinutes(int _endMin);
	int getEndMinutes();
};