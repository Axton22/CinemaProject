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

	Movie currentMovie;   
	Room currentRoom;  
	Schedule currentSchedule;

public:
	CinemaManager();
	~CinemaManager();

	void movieSessionKeeper();
	void showMoviesAvailable();

	void menu();
	Movie addMovie();
	Room enableRoom();
	Schedule movieSchedule();
};