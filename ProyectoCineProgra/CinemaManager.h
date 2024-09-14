#pragma once

#include <iostream>
#include <stdlib.h>
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"
#include "MovieSessions.h"
#include "Seat.h"

class CinemaManager {
private:
	static const int maxSessions = 5;
	MovieSessions movieSessions[maxSessions];
	int index;
	bool movieSet;
	bool roomSet;
	bool scheduleSet;
	int numberOfBooking;

	Movie currentMovie;   
	Room currentRoom;  
	Schedule currentSchedule;

public:
	CinemaManager();
	~CinemaManager();

	void setNumberOfBooking(int _numberOfBooking);
	int getNumberOfBooking();

	void menu();
	Movie addMovie();
	Room enableRoom();
	Schedule movieSchedule();
	void movieSessionKeeper();
	void bookingManager();
	void showRoomSeats(const Room room);
	void voucher(Movie movie, Room room, Schedule schedule);
};