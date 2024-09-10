#include "CinemaManager.h";
using namespace std;


CinemaManager::CinemaManager()
{
	index = 0;
	movieSet = false;
	roomSet = false;
	scheduleSet = false;
}

CinemaManager::~CinemaManager()
{
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
			else if (opc == 2)
			{
				exit;
			}
		}

		else if (opc == 2)
		{
			do {
				cout << "[1] Movies " << endl;
				cout << "[2] Rooms " << endl;
				cout << "[3] Schedule " << endl;
				cout << "[4] Save and return " << endl;
				cout << "[5] Exit " << endl;
				cout << "Choose an option to continue: ";
				cin >> opc;

				if (opc == 1)
				{
					currentMovie = addMovie();
					movieSet = true;
				}
				else if (opc == 2)
				{
					currentRoom = enableRoom();
					roomSet = true;
				}
				else if (opc == 3)
				{
					currentSchedule = movieSchedule();
					scheduleSet = true;
				}
				else if (opc == 4)
				{
					movieSessionKeeper();
					exit;
				}
			} while (opc != 5);
		}

		else if (opc == 3)
		{
			do {
				cout << "[1] Movies " << endl;
				cout << "[2] Exit " << endl;
				cin >> opc;
				if (opc == 1)
				{
					showMoviesAvailable();
				}
			} while (opc != 2);
		}

		else if (opc == 4)
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


	cout << "Enter the name of the movie you want to add: ";
	cin >> name;
	currentMovie.setName(name);

	cout << "Enter the country of the movie you want to add: ";
	cin >> country;
	currentMovie.setCountry(country);

	cout << "Enter the year of the movie you want to add: ";
	cin >> year;
	currentMovie.setYear(year);

	cout << "Enter the duration of the movie you want to add: ";
	cin >> time;
	currentMovie.setTime(time);

	cout << "Enter the reviews of the movie you want to add: ";
	cin >> reviews;
	currentMovie.setReviews(reviews);

	return currentMovie;
}

Room CinemaManager::enableRoom()
{
	int roomNumber = 0;
	int seats = 0;
	float price = 0;

	cout << " Enter the number of the room: ";
	cin >> roomNumber;
	currentRoom.setRoomNumber(roomNumber);

	cout << " Enter the number of seats in the room: ";
	cin >> seats;

	int** roomSeats = new int* [seats];
	for (int i = 0; i < seats; i++)
	{
		roomSeats[i] = new int[seats];
	}
	for (int i = 0; i < seats; i++)
	{
		for (int j = 0; j < seats; j++)
		{
			cin >> roomSeats[i][j];
		}
	}
	currentRoom.setRoomSeats(roomSeats, seats);

	cout << " Enter the price of the room: ";
	cin >> price;
	currentRoom.setPrice(price);

	return currentRoom;
}

Schedule CinemaManager::movieSchedule()
{
	string date;
	int startHour = 0;
	int endHour = 0;

	cout << " Enter the date of the movie: ";
	cin >> date;
	currentSchedule.setDate(date);

	cout << " Enter what time the movie starts: ";
	cin >> startHour;
	currentSchedule.setStartHour(startHour);

	cout << " Enter what time the movie ends: ";
	cin >> endHour;
	currentSchedule.setEndHour(endHour);

	return currentSchedule;
}

void CinemaManager::movieSessionKeeper()
{
	if (movieSet && roomSet && scheduleSet) {

		if (index < 5)
		{
			MovieSessions session(currentMovie, currentRoom, currentSchedule);
			movieSessions[index] = session;
			index++;
		}
	}
	movieSet = false;
	roomSet = false;
	scheduleSet = false;
}

void CinemaManager::showMoviesAvailable()
{
	for (int i = 0; i < index; i++)
	{
		Movie movie = movieSessions[i].getMovie();
		cout << "Movie name: " << movie.getName() << endl;
	}
}