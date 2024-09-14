#pragma once

#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Seat {
private:
	int seatNumber;
	bool isAvailable;

public:
	Seat();
	Seat(int _seatNumber, bool _isAvailable);

	void seatsManager(Room& room, int setNumber);

	void setIsAvailable(bool _isAvailable);
	bool getIsAvailable();

};
