#pragma once
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"

class MovieSessions
{
private:
	Movie movie;
	Room room;
	Schedule schedule;

public:
	MovieSessions() {};
	MovieSessions(Movie _movie, Room _room, Schedule _schedule);

	void setMovie(Movie _movie);
	void setRoom(Room _room);
	void setSchedule(Schedule _schedule);

	Movie getMovie() const;
	Room getRoom() const;
	Schedule getSchedule() const;
};