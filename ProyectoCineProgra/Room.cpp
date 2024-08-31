#include "Room.h"

Room::Room()
{
	price = 0;
	roomNumber = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			roomSeats[i][j] = 0;
		}
	}

}

Room::Room(int _roomNumber, int _roomSeats[10][10], float _price)
{
	this->price = _price;
	this->roomNumber = _roomNumber;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->roomSeats[i][j] = _roomSeats[i][j];
		}
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


void Room::setRoomSeats(int _roomSeats[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->roomSeats[i][j] = _roomSeats[i][j];
		}
	}
}

int** Room::getRoomSeats()
{
	int** seats = new int* [10];
	for (int i = 0; i < 10; i++)
	{
		seats[i] = new int[10];
		for (int j = 0; j < 10; j++)
		{
			seats[i][j] = this->roomSeats[i][j];
		}
	}
	return seats;
}

void Room::setPrice(float _price)
{
	this->price = _price;
}

float Room::getPrice()
{
	return price;
}
