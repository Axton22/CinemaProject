#pragma once
#include "Seat.h"
#include "Room.h"
#include "CinemaManager.h"

class Booking
{
private:
	double totalPrice;
	int bookingNumber = 0;

public:
	Booking(){}
	Booking(double _totalPrice, int _bookingNumber);

};