#include "Room.h"
using namespace std;

Room::Room()
{
	price = 0;
	roomNumber = 0;
	roomSeats = nullptr;
	size = 0;
}

Room::Room(int _roomNumber, float _price, int _size)
{
	this->price = _price;
	this->roomNumber = _roomNumber;
	this->roomSeats = nullptr;
	this->size = _size;
}

Room::~Room()
{
	if (roomSeats != nullptr) {
		for (int i = 0; i < size; i++) {
			delete[] roomSeats[i];
		}
		delete[] roomSeats;
		roomSeats = nullptr;
	}
}

void Room::setRoomNumber(int _roomNumber)
{
	this->roomNumber = _roomNumber;
}

int Room::getRoomNumber()
{
	return roomNumber;
}


void Room::setRoomSeats(int** seats, int numSeats) {
	roomSeats = seats;
	size = numSeats;
}

int** Room::getRoomSeats()
{
	return roomSeats;
}

void Room::setPrice(float _price)
{
	this->price = _price;
}

float Room::getPrice()
{
	return price;
}
