#pragma once

class Room {
private:
	int roomNumber;
	static const int size = 5;
	int roomSeats[size][size];
	int price;

public:
	Room();
	Room(int _roomNumber, int _price);
	~Room();

	void setRoomNumber(int _roomNumber);
	int getRoomNumber();
	
	static int getSize();
	void setSeat(int row, int column, int value);
	int getSeats(int row, int col) const;

	void setPrice(int _price);
	int getPrice() const;
};