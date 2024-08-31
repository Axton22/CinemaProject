#include "Schedule.h"

Schedule::Schedule(string _date, int _startHour, int _endHour)
{
	this->date = _date;
	this->endHour = _endHour;
	this->startHour = _startHour;
}
