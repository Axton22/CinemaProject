#pragma once

#include <iostream>
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"

class CinemaManager {
private:
	Movie moviesAvailable[6];
	Room roomAvailable[5];
	Schedule schedule;

public:
	void menu();
	Movie addMovie();
	Room enableRoom();
	Schedule movieSchedule();
};