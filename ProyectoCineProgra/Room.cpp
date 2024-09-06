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


void Room::setRoomSeats(int** _roomSeats, int _size)
{
	if (roomSeats != nullptr) {
		for (int i = 0; i < size; i++) {
			delete[] roomSeats[i];
		}
		delete[] roomSeats;
	}

	int numSeats = size;
	roomSeats = new int* [numSeats];
	for (int i = 0; i < numSeats; i++) {
		roomSeats[i] = new int[numSeats];
	}
}

int** Room::getRoomSeats()
{
	return roomSeats;
}

int Room::getSize()
{
	return size;
}

void Room::setPrice(float _price)
{
	this->price = _price;
}

float Room::getPrice()
{
	return price;
}
