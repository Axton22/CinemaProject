#include "Room.h"
using namespace std;

Room::Room()
{
	price = 0;
	roomNumber = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			roomSeats[i][j] = 0;
		}
	}

}

Room::Room(int _roomNumber, int _price)
{
	this->price = _price;
	this->roomNumber = _roomNumber;
}

Room::~Room()
{
}

void Room::setRoomNumber(int _roomNumber)
{
	this->roomNumber = _roomNumber;
}

int Room::getRoomNumber()
{
	return roomNumber;
}

int Room::getSize()
{
	return size;
}

void Room::setSeat(int row, int col, int value)
{
	if (row >= 0 && row < size && col >= 0 && col < size) {
		roomSeats[row][col] = value;
	}
}

int Room::getSeats(int row, int col) const
{
	if (row >= 0 && row < size && col >= 0 && col < size) {
		return roomSeats[row][col];
	}
}

void Room::setPrice(int _price)
{
	this->price = _price;
}

int Room::getPrice() const
{
	return price;
}
