#pragma once

#include <string>
using namespace std;

class Schedule {
private:
	string date;
	int startHour;
	int endHour;

public:
	Schedule() {
	};
	Schedule(string _date, int _startHour, int _endHour);
};