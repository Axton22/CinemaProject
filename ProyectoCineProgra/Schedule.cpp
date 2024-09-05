#include "Schedule.h"


Schedule::Schedule()
{
	startHour = 0;
	endHour = 0;
}

Schedule::Schedule(string _date, int _startHour, int _endHour)
{
	this->date = _date;
	this->startHour = _startHour;
	this->endHour = _endHour;
}

void Schedule::setDate(string _date)
{
	this->date = _date;
}

string Schedule::getDate()
{
	return date;
}

void Schedule::setStartHour(int _startHour)
{
	this->startHour = _startHour;
}

int Schedule::getStartour()
{
	return startHour;
}

void Schedule::setEndHour(int _endHour)
{
	this->endHour = _endHour;
}

int Schedule::getEndHour()
{
	return endHour;
}
