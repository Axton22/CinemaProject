#include "CinemaManager.h";
using namespace std;

void CinemaManager::menu()
{
	int opc = 0;
	cout << "                                               Welcome to NUEVA CINEMA SA " << endl << endl;
	cout << "[1] File " << endl;
	cout << "[2] Maintenance " << endl;
	cout << "[3] Booking " << endl;
	cout << "[4] Sale " << endl;
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
		cout << "[1] Movies " << endl;
		cout << "[2] Rooms " << endl;
		cout << "[3] Schedule " << endl;
	}

	if (opc == 3)
	{
		cout << "[1] Movies " << endl;
	}

	if (opc == 4)
	{
		cout << "[1] Movies " << endl;
	}
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
	int roomSeats[10][10];
	float price = 0;

	Room room;

	cout << " Enter the number of the room";
	cin >> roomNumber;
	room.setRoomNumber(roomNumber);

	cout << " Enter the seats of the room";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> roomSeats[i][j];
		}
	}
	room.setRoomSeats(roomSeats);

	cout << " Enter the price of the room";
	cin >> price;
	room.setPrice(price);

}
