#pragma once

#include <iostream>
#include <stdlib.h>
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"

class CinemaManager {
private:
	Movie movie;
	Room room;
	Schedule schedule;
	bool movieSet;
	bool roomSet;
	bool scheduleSet;
	CinemaManager* movieSessions;
	int index;
	static const int maxSessions = 5;

public:
	CinemaManager();
	CinemaManager(Movie _movie, Room _room, Schedule _schedule);
	~CinemaManager();

	void menu();
	Movie addMovie();
	Room enableRoom();
	Schedule movieSchedule();

	void setMovieSession(Movie _movie, Room _room, Schedule _schedule);
	Movie getMovieOfTheSession();
	Room getRoomOfTheSession();
	Schedule getScheduleOfTheSession();
	CinemaManager movieSessionKeeper();

};