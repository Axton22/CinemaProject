#include "CinemaManager.h";
using namespace std;

CinemaManager::CinemaManager()
{
	movieSet = false;
	roomSet = false;
	scheduleSet = false;
	index = 0;

	movieSessions = new CinemaManager[maxSessions];
	for (int i = 0; i < maxSessions; ++i) {
		movieSessions[i] = CinemaManager();
	}
}

CinemaManager::CinemaManager(Movie _movie, Room _room, Schedule _schedule)
{
	this->movie = _movie;
	this->room = _room;
	this->schedule = _schedule;
}

CinemaManager::~CinemaManager()
{
	delete[] movieSessions;
}

void CinemaManager::menu()
{
	int opc = 0;
	do {
		cout << "                                               Welcome to NUEVA CINEMA SA " << endl << endl;
		cout << "[1] File " << endl;
		cout << "[2] Maintenance " << endl;
		cout << "[3] Booking " << endl;
		cout << "[4] Sale " << endl;
		cout << "[5] Exit " << endl;
		cout << "Choose an option to continue: ";
		cin >> opc;

		if (opc == 1)
		{
			int opc = 0;
			cout << "[1] About " << endl;
			cout << "[2] Exit " << endl;
			cout << "Choose an option to continue: ";
			cin >> opc;

			if (opc == 1)
			{
				cout << " I am Axton Urbina Perez, the owner of the system and a former student at Harvard University. A few weeks ago, I heard the announcement, and it caught my attention, so I decided to participate in the draw.";
			}
			if (opc == 2)
			{
				exit;
			}
		}

		if (opc == 2)
		{
			do {
				cout << "[1] Movies " << endl;
				cout << "[2] Rooms " << endl;
				cout << "[3] Schedule " << endl;
				cout << "[4] Exit" << endl;
				cout << "Choose an option to continue: ";
				cin >> opc;

				if (opc == 1)
				{
					addMovie();
					movieSet = true;
				}
				else if (opc == 2)
				{
					enableRoom();
					roomSet = true;
				}
				else if (opc == 3)
				{
					movieSchedule();
					scheduleSet = true;
				}
			} while (opc != 4);
		}

		if (opc == 3)
		{
			cout << "[1] Movies " << endl;
		}

		if (opc == 4)
		{
			cout << "[1] Movies " << endl;
		}
	} while (opc != 5);
}

Movie CinemaManager::addMovie()
{
	string name;
	string country;
	int year = 0;
	int time = 0;
	int reviews = 0;

	Movie movie;

	cout << "Enter the name of the movie you want to add: ";
	cin >> name;
	movie.setName(name);

	cout << "Enter the country of the movie you want to add: ";
	cin >> country;
	movie.setCountry(country);

	cout << "Enter the year of the movie you want to add: ";
	cin >> year;
	movie.setYear(year);

	cout << "Enter the duration of the movie you want to add: ";
	cin >> time;
	movie.setTime(time);

	cout << "Enter the reviews of the movie you want to add: ";
	cin >> reviews;
	movie.setReviews(reviews);
	
	return movie;
}

Room CinemaManager::enableRoom()
{
	int roomNumber = 0;
	int seats = 0;
	float price = 0;

	Room room;

	cout << " Enter the number of the room: ";
	cin >> roomNumber;
	room.setRoomNumber(roomNumber);

	cout << " Enter the number of seats in the room: ";
	cin >> seats;

	int** roomSeats = new int*[seats];
	for (int i = 0; i < seats; i++)
	{
		roomSeats[i] = new int[seats];
	}
	room.setRoomSeats(roomSeats, seats);

	for (int i = 0; i < seats; i++) {
		delete[] roomSeats[i];
	}
	delete[] roomSeats;

	cout << " Enter the price of the room: ";
	cin >> price;
	room.setPrice(price);

	return room;
}

Schedule CinemaManager::movieSchedule()
{
	string date;
	int startHour = 0;
	int endHour = 0;

	Schedule schedule;

	cout << " Enter the date of the movie: ";
	cin >> date;
	schedule.setDate(date);

	cout << " Enter what time the movie starts: ";
	cin >> startHour;
	schedule.setStartHour(startHour);

	cout << " Enter what time the movie ends: ";
	cin >> endHour;
	schedule.setEndHour(endHour);

	return schedule;
}


void CinemaManager::setMovieSession(Movie _movie, Room _room, Schedule _schedule)
{
	this->movie = _movie;
	this->room = _room;
	this->schedule = _schedule;
}

Movie CinemaManager::getMovieOfTheSession()
{
	return movie;
}

Room CinemaManager::getRoomOfTheSession()
{
	return room;
}

Schedule CinemaManager::getScheduleOfTheSession()
{
	return schedule;
}

CinemaManager CinemaManager::movieSessionKeeper()
{

	if (movieSet && roomSet && scheduleSet == true) {


		if (index < 5)
		{
			CinemaManager ses;

			Movie movie = ses.addMovie();

			Room room = ses.enableRoom();

			Schedule schedule = ses.movieSchedule();

			movieSessions[index].movie = movie;
			movieSessions[index].room = room;
			movieSessions[index].schedule = schedule;
			return movieSessions[index++];
		}
	}
	return CinemaManager();
}


