#pragma once

class Room {
private:
	int roomNumber;
	int roomSeats[10][10];
	float price;

public:
	Room();
	Room(int _roomNumber, int _roomSeats[10][10], float _price);

	void setRoomNumber(int _roomNumber);
	int getRoomNumber();


	void setRoomSeats(int _roomSeats[10][10]);
	int** getRoomSeats();

	void setPrice(float _price);
	float getPrice();
};