#include "CinemaManager.h"
using namespace std;


CinemaManager::CinemaManager()
{
	index = 0;
	movieSet = false;
	roomSet = false;
	scheduleSet = false;
	numberOfBooking = 0;
	isAvailable = false;
	voucherGenerated = false;
	customerId = 0;
	customerCardNumber = 0;
	saleSuccessful = false;
	totalPrice = 0;
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

void CinemaManager::setVoucherGenerated(bool _voucherGenerated)
{
	this->voucherGenerated = _voucherGenerated;
}

bool CinemaManager::getVoucherGenerated()
{
	return voucherGenerated;
}

void CinemaManager::setSaleSuccessful(bool _saleSuccessful)
{
	this->saleSuccessful = _saleSuccessful;
}

bool CinemaManager::getSalesSuccessful()
{
	return saleSuccessful;
}

void CinemaManager::setTotalPrice(int _totalPrice)
{
	this->totalPrice = _totalPrice;
}

int CinemaManager::getTotalPrice()
{
	return totalPrice;
}

void CinemaManager::menu()
{
	int opc = 0;
	do {
		cout << "                                              Welcome to NUEVA CINEMA SA " << endl << endl;
		cout << "[1] File " << endl;
		cout << "[2] Maintenance " << endl;
		cout << "[3] Booking " << endl;
		cout << "[4] Sale " << endl;
		cout << "[5] Exit " << endl;
		cout << "Choose an option to continue: ";
		cin >> opc;

		if (opc == 1)
		{
			cout << "[1] About " << endl;
			cout << "[2] Exit " << endl;
			cout << "Choose an option to continue: ";
			cin >> opc;

			do {
				if (opc == 1)
				{
					cout << " \nI am Axton Urbina Perez, the owner of the system and a former student at Harvard University. A few weeks ago, I heard the announcement, and it caught my attention, so I decided to participate in the draw." << endl << endl;
					break;
				}
			} while (opc != 2);
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
			do {
				cout << "[1] Movies " << endl;
				cout << "[2] Exit " << endl;
				cin >> opc;
				if (opc == 1)
				{
					saleManager();
				}
			} while (opc != 2);
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

	char rowLetter = 'A';  
	for (int i = 0; i < currentRoom.getSize(); ++i) {
		for (int j = 0; j < currentRoom.getSize(); ++j) {
			string seatID = string(1, rowLetter) + to_string(j + 1);
			currentRoom.setSeat(i, j, seatID);  
		}
		rowLetter++;  
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
	int startMinutes = 0;
	int endHour = 0;
	int endMinutes = 0;

	cout << " Enter the date of the movie: ";
	cin >> date;
	currentSchedule.setDate(date);

	cout << " Enter what time the movie starts (hour): ";
	cin >> startHour;
	currentSchedule.setStartHour(startHour);

	cout << " Enter what time the movie starts (minutes): ";
	cin >> startMinutes;
	currentSchedule.setStartMinutes(startMinutes);

	cout << " Enter what time the movie ends (hours): ";
	cin >> endHour;
	currentSchedule.setEndHour(endHour);

	cout << " Enter what time the movie ends (minutes): ";
	cin >> endMinutes;
	currentSchedule.setEndMinutes(endMinutes);

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
		cout << "Choose the movie that you want to reserve: " << endl;
		cin >> movieSelection;

		movieSelection -= 1;

		int book = 0;
		if (movieSelection >= 0 && movieSelection < index)
		{
			numberOfBooking++;
			setNumberOfBooking(numberOfBooking);
			Room& selectedRoom = movieSessions[movieSelection].getRoom();
			cout << "\nRoom: " << selectedRoom.getRoomNumber() << endl;

			Schedule selectedSchedule = movieSessions[movieSelection].getSchedule();
			cout << "Date of the movie: " << selectedSchedule.getDate() << endl;
			cout << "Starts at: " << selectedSchedule.getStartHour() << ":" << selectedSchedule.getStartMinutes() << endl;
			cout << "Ends at: " << selectedSchedule.getEndHour() << ":" << selectedSchedule.getEndMinutes() << endl;

			cout << "\nHow many seats do you want to book? Max: 3" << endl;
			cin >> book;

			int count = 0;
			int seatPrice = selectedRoom.getPrice();

			if (book > 0 && book <= 3)
			{
				do {
					string seat;
					cout << "\nSeats available: " << endl;
					showRoomSeats(selectedRoom);
					cout << "Choose the seat that you want: " << endl;
					cin >> seat;
					seatsManager(selectedRoom, seat);
					movieSessions[movieSelection].setRoom(selectedRoom);
					totalPrice += seatPrice;
					setTotalPrice(totalPrice);
					count++;
				} while (count < book);
			}

			Movie selectedMovie = movieSessions[movieSelection].getMovie();
			if (selectedRoom.getIsAvailable())
			{
				voucher(selectedMovie, selectedRoom, selectedSchedule);
				setVoucherGenerated(true);
			}

		}
}

void CinemaManager::showRoomSeats(const Room room)
{
	cout << "\nIs reserve:  R" << endl;
	cout << "Is sold: S\n" << endl;

	for (int i = 0; i < room.getSize(); ++i) {
		for (int j = 0; j < room.getSize(); ++j) {
			cout << room.getSeats(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void CinemaManager::seatsManager(Room& room, const string& _seatID)
{
	bool seatFound = false;

	for (int i = 0; i < room.getSize(); ++i) {
		for (int j = 0; j < room.getSize(); ++j) {
			if (room.getSeats(i, j) == _seatID)
			{
				if (getSalesSuccessful()) {
					room.setSeat(i, j, "[S]");
				}
				else {
					room.setSeat(i, j,"[R]");
				}
				room.setIsAvailable(!getSalesSuccessful());
				seatFound = true;
				break;
			}
		}
		if (seatFound) break;
	}

	if (!seatFound) {
		cout << "The seat number " << _seatID << " is not available or you entered an incorrect seat." << endl;
		room.setIsAvailable(false);
	}
}

void CinemaManager::voucher(Movie movie, Room room, Schedule schedule)
{
			cout << "\n==========================================" << endl;
			cout << "                CINEMA VOUCHER             " << endl;
			cout << "==========================================" << endl;

			cout << "Voucher Number: " << getNumberOfBooking() << endl;

			cout << "Movie Title: " << movie.getName() << endl;
			
			cout << "Movie date: " << schedule.getDate() << endl;

			cout << "Movie starts at: " << schedule.getStartHour() << endl;

			cout << "Price: " << getTotalPrice() << endl;

			cout << "==========================================" << endl;

			cout << "\nIMPORTANT: Reserved tickets can only be purchased up to 30 minutes before the movie starts. After this time, they cannot be sold. " << endl << endl;

			setTotalPrice(0);
}

void CinemaManager::saleManager()
{
	if (getVoucherGenerated())
	{
		cout << "Your voucher number is: " << getNumberOfBooking() << endl;

		cout << "Enter your ID number: ";
		cin >> customerId;

		cout << "\nEnter your card number: ";
		cin >> customerCardNumber;

		for (int i = 0; i < index; i++)
		{
				Room& room = movieSessions[i].getRoom();
				for (int row = 0; row < room.getSize(); ++row) {
					for (int col = 0; col < room.getSize(); ++col) {
						if (room.getSeats(row, col) == "[R]") {
							room.setSeat(row, col, "[S]");
						}
					}
				}
				movieSessions[i].setRoom(room);
		}

		cout << "\nYour purchase is successful, Thank you and enjoy the movie!!" << endl;
		setSaleSuccessful(true);
	}
	setSaleSuccessful(false);
}

