#pragma once
#include <string>
using namespace std;


class Room {
private:
	int roomNumber;
	static const int size = 5;
	string roomSeats[size][size];
	int price;
	string seatID;
	bool isAvailable;

public:
	Room();
	Room(int _roomNumber, int _price);
	~Room();

	void setRoomNumber(int _roomNumber);
	int getRoomNumber();
	
	static int getSize();
	void setSeat(int row, int column, string _seatID);
	string getSeats(int row, int col) const;

	void setPrice(int _price);
	int getPrice() const;

	void setIsAvailable(bool _isAvailable);
	bool getIsAvailable();
};