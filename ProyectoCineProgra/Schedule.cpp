#include "Schedule.h"


Schedule::Schedule()
{
	startHour = 0;
	startMinutes = 0;
	endHour = 0;
	endMinutes = 0;
}

Schedule::Schedule(string _date, int _startHour,int _starMinutes, int _endHour, int _endMinutes)
{
	this->date = _date;
	this->startHour = _startHour;
	this->startMinutes = _starMinutes;
	this->endHour = _endHour;
	this->endMinutes = _endMinutes;
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

int Schedule::getStartHour()
{
	return startHour;
}

void Schedule::setStartMinutes(int _strMin)
{
	this->startMinutes = _strMin;
}

int Schedule::getStartMinutes()
{
	return startMinutes;
}

void Schedule::setEndHour(int _endHour)
{
	this->endHour = _endHour;
}

int Schedule::getEndHour()
{
	return endHour;
}

void Schedule::setEndMinutes(int _endMin)
{
	this->endMinutes = _endMin;
}

int Schedule::getEndMinutes()
{
	return endMinutes;
}
