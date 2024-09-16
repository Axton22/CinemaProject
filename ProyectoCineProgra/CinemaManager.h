#pragma once

#include <iostream>
#include <stdlib.h>
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"
#include "MovieSessions.h"

class CinemaManager {
private:
	static const int maxSessions = 5;
	MovieSessions movieSessions[maxSessions];
	int index;
	bool movieSet;
	bool roomSet;
	bool scheduleSet;
	int numberOfBooking;
	bool isAvailable;
	bool voucherGenerated;
	int customerId;
	int customerCardNumber;
	bool saleSuccessful;
	int totalPrice;

	Movie currentMovie;
	Room currentRoom;
	Schedule currentSchedule;

public:
	CinemaManager();
	~CinemaManager();

	void setNumberOfBooking(int _numberOfBooking);
	int getNumberOfBooking();
	void setVoucherGenerated(bool _voucherGenerated);
	bool getVoucherGenerated();
	void setSaleSuccessful(bool _saleSuccessful);
	bool getSalesSuccessful();
	void setTotalPrice(int _totalPrice);
	int getTotalPrice();

	void menu();
	Movie addMovie();
	Room enableRoom();
	Schedule movieSchedule();
	void movieSessionKeeper();
	void bookingManager();
	void showRoomSeats(const Room room);
	void seatsManager(Room& room, const string& _seatID);
	void voucher(Movie movie, Room room, Schedule schedule);
	void saleManager();
};