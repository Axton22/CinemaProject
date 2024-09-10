#pragma once

class Room {
private:
	int roomNumber;
	int **roomSeats;
	float price;
	int size;

public:
	Room();
	Room(int _roomNumber, float _price, int _size);
	~Room();

	void setRoomNumber(int _roomNumber);
	int getRoomNumber();


	void setRoomSeats(int** _roomSeats, int _size);
	int** getRoomSeats();

	void setPrice(float _price);
	float getPrice();
};