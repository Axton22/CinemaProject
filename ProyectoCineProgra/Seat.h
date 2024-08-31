#pragma once

#include <iostream>
#include<string>

using namespace std;

class Seat {
private:
	int seatNumber = 0;
	string availability;

public:
	Seat(){}
	Seat(int _seatNumber, string _availability);

};
