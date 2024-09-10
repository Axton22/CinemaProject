#include "MovieSessions.h"

MovieSessions::MovieSessions(Movie _movie, Room _room, Schedule _schedule)
{
	this->movie = _movie;
	this->room = _room;
	this->schedule = _schedule;
}

void MovieSessions::setMovie(Movie _movie)
{
	this->movie = _movie;
}

void MovieSessions::setRoom(Room _room)
{
	this->room = _room;
}

void MovieSessions::setSchedule(Schedule _schedule)
{
	this->schedule = _schedule;
}

Movie MovieSessions::getMovie() const
{
	return movie;
}

Room MovieSessions::getRoom() const
{
	return room;
}

Schedule MovieSessions::getSchedule() const
{
	return schedule;
}
