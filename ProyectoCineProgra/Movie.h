#pragma once
#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
	string name;
	int year = 0;
	int time = 0;
	string country;
	int reviews = 0;



public:
	Movie() {};
	Movie(string _name, int _year, int _time, string _country, int _reviews);

	void setName(string nam);
	string getName();

	void setYear(int yea);
	int getYear();

	void setTime(int tim);
	int getTime();

	void setCountry(string coun);
	string getCountry();

	void setReviews(int rev);
	int getReviews();
};