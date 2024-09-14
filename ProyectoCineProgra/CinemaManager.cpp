#include "CinemaManager.h";
using namespace std;


CinemaManager::CinemaManager()
{
	index = 0;
	movieSet = false;
	roomSet = false;
	scheduleSet = false;
	numberOfBooking = 0;
}

CinemaManager::~CinemaManager()
{
}

void CinemaManager::setNumberOfBooking(int _numberOfBooking)
{
	this->numberOfBooking = _numberOfBooking;
}

int CinemaManager::getNumberOfBooking()
{
	return numberOfBooking;
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
				cout << "[0] Exit " << endl;
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
			} while (opc != 0);
		}

		else if (opc == 3)
		{
			do {
				cout << "[1] Movies " << endl;
				cout << "[2] Exit " << endl;
				cin >> opc;
				if (opc == 1)
				{
					bookingManager();
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

	int value = 1;
	for (int i = 0; i < currentRoom.getSize(); ++i) {
		for (int j = 0; j < currentRoom.getSize(); ++j) {
			currentRoom.setSeat(i, j, value++);
		}
	}
	
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

void CinemaManager::bookingManager()
{
	cout << "Movies Available" << endl;

	for (int i = 0; i < index; i++)
	{
		Movie movie = movieSessions[i].getMovie();
		cout << "[" << i + 1 << "] " << movie.getName() << endl;
	}

	int movieSelection;
	cout << "Choose the movie that you want to reserve: ";
	cin >> movieSelection;

	movieSelection -= 1;

	if (movieSelection >= 0 && movieSelection < index)
	{
		numberOfBooking++;
		setNumberOfBooking(numberOfBooking);
		Room& selectedRoom = movieSessions[movieSelection].getRoom();
		cout << "Room: " << selectedRoom.getRoomNumber() << endl;

		Schedule selectedSchedule = movieSessions[movieSelection].getSchedule();
		cout << "Date of the movie: " << selectedSchedule.getDate() << endl;
		cout << "Starts at: " << selectedSchedule.getStartHour() << endl;
		cout << "Ends at: " << selectedSchedule.getEndHour() << endl;

		Seat seatSelected;
		int seatNumber = 0;
		cout << "Seats available: " << endl;
		showRoomSeats(selectedRoom);
		cout << "Choose the seat that you want: " << endl;
		cin >> seatNumber;
		seatSelected.seatsManager(selectedRoom, seatNumber);

		movieSessions[movieSelection].setRoom(selectedRoom);

		Movie selectedMovie = movieSessions[movieSelection].getMovie();
		if (seatSelected.getIsAvailable() == true)
		{
			voucher(selectedMovie, selectedRoom, selectedSchedule);
		}
	}
}

void CinemaManager::showRoomSeats(const Room room)
{
	cout << "\nIs reserve:  0" << endl;
	cout << "Is sold: -1\n" << endl;

	for (int i = 0; i < room.getSize(); ++i) {
		for (int j = 0; j < room.getSize(); ++j) {
			cout << room.getSeats(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void CinemaManager::voucher(Movie movie, Room room, Schedule schedule)
{
			cout << "==========================================" << endl;
			cout << "                CINEMA VOUCHER             " << endl;
			cout << "==========================================" << endl;

			cout << "Voucher Number: " << getNumberOfBooking() << endl;

			cout << "Movie Title: " << movie.getName() << endl;

			cout << "Movie date: " << schedule.getDate() << endl;

			cout << "Movie starts at: " << schedule.getStartHour() << endl;

			cout << "Price: " << room.getPrice() << endl;
}

