#pragma once
class Booking
{
private:
	double totalPrice;
	int bookingNumber = 0;

public:
	Booking(){}
	Booking(double _totalPrice, int _bookingNumber);
};