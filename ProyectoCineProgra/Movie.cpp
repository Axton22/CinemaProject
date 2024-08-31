#include "Movie.h"


Movie::Movie(string _name, int _year, int _time, string _country, int _reviews)
{
	this->name = _name;
	this->year = _year;
	this->time = _time;
	this->country = _country;
	this->reviews = _reviews;
}

void Movie::setName(string nam)
{
	this->name = nam;
}

string Movie::getName()
{
	return name;
}

void Movie::setYear(int yea)
{
	this->year = yea;
}

int Movie::getYear()
{
	return year;
}

void Movie::setTime(int tim)
{
	this->time = tim;
}

int Movie::getTime()
{
	return time;
}

void Movie::setCountry(string coun)
{
	this->country = coun;
}

string Movie::getCountry()
{
	return country;
}

void Movie::setReviews(int rev)
{
	this->reviews = rev;
}

int Movie::getReviews()
{
	return reviews;
}
