#include "Hotel.h"

Hotel::Hotel(const char* hotelName, int maxRoomsNum, int maxReservationsNum) : numOfOccupiedRooms(INIT_NUM), numOfReservations(INIT_NUM), numOfServices(INIT_NUM), numOfRooms(INIT_NUM)
{
	delete[]this->hotelName;
	this->hotelName = new char[strlen(hotelName) + 1];
	strcpy(this->hotelName, hotelName);
	this->maxRoomsNum = maxRoomsNum;
	this->maxReservationsNum = maxReservationsNum;

	allRooms = new Room*[maxRoomsNum];
	allReservations = new Reservation*[maxReservationsNum];
	allServices = new Service*[DEDAULT_NUM_OF_SERVICES];

}

Hotel::~Hotel()
{
	if (!(hotelName == nullptr))
		delete[] hotelName;
	if (!(allRooms == nullptr))
		delete[] allRooms;
	if (!(allReservations == nullptr))
		delete[] allReservations;
	if (!(allServices == nullptr))
		delete[] allServices;
}

void Hotel::setNumOfOccupiedRooms(int num)
{
	this->numOfOccupiedRooms = num;
}

void Hotel::setSpa(Spa& spa)
{
	this->spa = &spa;
}

void Hotel::setDiningRoom(DiningRoom& diningRoom)
{
	this->diningRooom = diningRoom;
}

int Hotel::getNumOfRooms() const
{
	return this->numOfRooms;
}

int Hotel::getNumOfOccupiedRooms() const
{
	return this->numOfOccupiedRooms;
}

int Hotel::getNumOfReservations() const
{
	return this->numOfReservations;
}

int Hotel::getMaxReservationsNum() const
{
	return this->maxReservationsNum;
}
Room& Hotel::getAvailableRoom() const
{
	
	for (int i = 0; i < maxRoomsNum; i++)
	{
		if (!allRooms[i]->getIsOccupied())
			return *allRooms[i];
	}
	cout << "No available rooms. Returning a default room.";
	return *allRooms[0];
}

Reservation& Hotel::getReservation(int reservationId) const
{
	return *allReservations[reservationId]; 
}

const DiningRoom& Hotel::getDiningRoom() const 
{
	return diningRooom;
}

Service** Hotel::getAllServices() const
{
	return this->allServices;
}

const Spa& Hotel::getSpa() const
{
	return *this->spa;
}

void Hotel::setAllRooms(Room** allrooms)
{
	this->allRooms = allrooms;
	numOfRooms = sizeof(allrooms) / sizeof(allrooms[0]);
}





void Hotel::addRoom(Room& room) throw (const int)
{
	try
	{
		if (numOfRooms >= maxRoomsNum)
				throw numOfRooms;
		else {
			allRooms[numOfRooms++] = &room;
		}
	}
	catch (int numericError)
	{
		cout << "Current amount of rooms is " << numericError << "which is the limit." <<endl;
	}
}


void Hotel::addReservation(Reservation& reservation) throw (const int)
{
	try
	{
		if (numOfReservations >= maxReservationsNum)
			throw numOfReservations;
		else {
			allReservations[numOfReservations] = &reservation;
			numOfReservations += 1;
		}

	}
	catch (int numericError)
	{
		cout << "Current reservation num is " << numericError << "which is the limit." <<endl;
	}
}


void Hotel::addService(Service& service) throw (const char*)
{
	try
		{
			if (numOfServices >= DEDAULT_NUM_OF_SERVICES)
				throw numOfServices;
			else {
				allServices[numOfServices] = &service;
				numOfServices += 1;
			}

		}
	catch (int numericError)
	{
		cout << "Current add more services: " << numericError << "which is the limit." <<endl;
	}
}

Room& Hotel::operator[](int roomNumber) const
{
	return *this->allRooms[roomNumber];
}


//ADDED NOW

const char* Hotel::getHotelName() const
{
	return this->hotelName;
}

const int Hotel::getMaxRoomNumber() const
{
	return this->maxRoomsNum;
}

Reservation** Hotel::getAllReservations() const
{
	return this->allReservations;
}

int Hotel::getNumberOfServices() const
{
	return this->numOfServices;
}

int Hotel::getNumberOfReservations() const
{
	return this->numOfReservations;
}



ostream& operator<<(ostream& os, const Hotel& hotel)
{
	int numOfPensions = hotel.getDiningRoom().getAllPensionOptions()[0]->getNumOfPensions();
	int numOfServices = hotel.getNumberOfServices();
	int numOfReservations = hotel.getNumberOfReservations();
	
	os << "Hotel: " << hotel.getHotelName() << " Includes " << hotel.getMaxRoomNumber() << " Rooms, " << hotel.getMaxReservationsNum() << " Reservations, A Dining Room, Spa Rooms, Regular Rooms" << endl
		<< "Our Hotel Also Has A Variety Of Pension Options And Services" << endl << "Our Pensions: " << endl;
	
	for (int i = 0; i < numOfPensions; i++)
	{
		os << "{" << hotel.getDiningRoom().getAllPensionOptions()[i]->getPensionType() << "}" << " Price: " << hotel.getDiningRoom().getAllPensionOptions()[i]->getPrice() << endl;
	}
	
	os << endl << "Our Services At The Moment: " << endl;
	for (int i = 0; i < numOfServices; i++)
	{
		os << "Service Name: " << hotel.getAllServices()[i]->getServiceName() << " Price: " << hotel.getAllServices()[i]->getServicePrice() << endl;
	}

	os << endl << "Existing Reservations: " << hotel.getNumOfReservations() << endl;
	for (int i = 0; i < numOfReservations; i++)
	{
		os << (i+1) + ""<< endl << hotel.getReservation(i);
	}

	return os;
	
}




