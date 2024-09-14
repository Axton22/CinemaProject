#include "Seat.h"

Seat::Seat()
{
	seatNumber = 0;
	isAvailable = false;
}

Seat::Seat(int _seatNumber, bool _availability)
{
	this->seatNumber = _seatNumber;
	this->isAvailable = _availability;
}

void Seat::seatsManager(Room& room, int setNumber)
{
    bool seatFound = false;

    for (int i = 0; i < room.getSize(); ++i) {
        for (int j = 0; j < room.getSize(); ++j) {
            if (room.getSeats(i, j) == setNumber)
            {
                room.setSeat(i, j, 0);  
                setIsAvailable(true);   
                seatFound = true;     
                break; 
            }
        }
        if (seatFound) break; 
    }

    if (!seatFound) {
        cout << "The seat number " << setNumber << " is not available or you put a incorrect seat." << endl;
        setIsAvailable(false); 
    }
}

void Seat::setIsAvailable(bool _isAvailable)
{
	this->isAvailable = _isAvailable;
}

bool Seat::getIsAvailable()
{
	return isAvailable;
}

