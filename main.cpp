#pragma warning( disable : 4290 )

#include "Hotel.h"
#include "SpaRoom.h"
#include "BabySittingInRoom.h"
#define NUM_OF_SERVICES 5
#define NUM_OF_PENSIONS 4
#define NUM_OF_ROOMS 10
using namespace std;

char hotelName[] = "S&D";
char spaName[] = "S&D Spa";
int munNumOfDiners = 50;
int maxRoomsNum = 50;
int maxReservationsNum = 100;
int price = 120;
int maxNumOfChildren = 6;
int maxAge = 11;
int minAge = 2;
DateTime* startDate;
DateTime* endDate;
DateTime* newDate;
Reservation* r;
Pension* breakfastPension;
Service** services;
Pension** pensions;
Room** rooms;

void initRooms(Hotel& hotel);
void initPensions(DiningRoom& diningRoom);
Room** createRooms(int numOfRooms);
Service** createServices(int numOfServies);
Pension** createPensions(int numOfPensions);
int makeReservation(Customer& customer, Hotel& hotel);
void updateReservation(int reservationId, Hotel& hotel);
void checkIn(int reservationId, Hotel& hotel);
void checkOut(int reservationId, Hotel& hotel);
void getBabySittingService(int reservationId, Hotel& hotel, BabySitting& babySitting);
void getRoomService(int reservationId, Hotel& hotel, RoomService& roomService);
void eatInDiningRoom(int reservationId, Hotel& hotel);
void printHotel(Hotel& hotel);
void deleteObjects();

void newTerminate()
{
	cout << "\nEror.try to catch this exception.\n";
	exit(1);
}

int main()
{
	set_terminate(newTerminate);

						// init customer 
	Customer customer("koko"); 


	Customer customer2("Momo"); //ADDED FOR TESTING NOW



						// init hotel
	Hotel hotel(hotelName, maxRoomsNum, maxReservationsNum); 
	initRooms(hotel);

						// init spa
	Spa spa(spaName); 
	hotel.setSpa(spa); 

					   // init dining room 
	DiningRoom diningRoom(munNumOfDiners); 
	initPensions(diningRoom); 
	hotel.setDiningRoom(diningRoom); 

								 // main functionalities
	int reservationId = makeReservation(customer, hotel);



	int reservationId2 = makeReservation(customer2, hotel);//ADDED FOR TESTING NOW




	checkIn(reservationId, hotel);
	updateReservation(reservationId, hotel);
	eatInDiningRoom(reservationId, hotel);

	RoomService* roomeService = new RoomService("breakfast in room");
	hotel.addService(*roomeService);
	getRoomService(reservationId, hotel, *roomeService);

	BabySitting* babySittingService = new BabySitting("basic babySitting", price, maxNumOfChildren, maxAge, minAge);
	hotel.addService(*babySittingService);
	getBabySittingService(reservationId, hotel, *babySittingService);

	checkOut(reservationId, hotel);
	cout << endl;
	printHotel(hotel);
	system("pause");
	deleteObjects();
	return 0;
}

// init
void initRooms(Hotel& hotel)
{
	// init rooms
	Room** rooms = createRooms(NUM_OF_ROOMS);
	//ADDED
	hotel.setAllRooms(rooms);
	//Needs Changing .
	/*
	for (int i = 0; i < numOfRooms; i++)
		hotel.addRoom(*rooms[i]);*/
}

void initPensions(DiningRoom& diningRoom)
{
	// init pensions in dining room
	Pension** pensions = createPensions(NUM_OF_PENSIONS);
	diningRoom.setPensions(pensions);
}

// main functionalities
/*void printHotel(Hotel& hotel)
{
	cout << "My Hotel: \n" << hotel << endl << endl;
}*/

void eatInDiningRoom(int reservationId, Hotel& hotel)
{
	hotel.getDiningRoom().startMeal(hotel.getReservation(reservationId));
	hotel.getDiningRoom().endMeal(hotel.getReservation(reservationId));
}

void getRoomService(int reservationId, Hotel& hotel, RoomService& roomService)
{
	//add service to reservation and activate it
	Reservation& r = hotel.getReservation(reservationId);
	r.addService(roomService);
	roomService.activateService(r.getRoom().getRoomNumber());
}

void getBabySittingService(int reservationId, Hotel& hotel, BabySitting& babySitting)
{
	int numOfChildren = 3;
	int age1 = 2;
	int age2 = 4;
	int age3 = 3;

	//add service to reservation and actuvate it
	Reservation& r = hotel.getReservation(reservationId);
	r.addService(babySitting);
	if (babySitting.initService(numOfChildren, age1, age2, age3))
		babySitting.activateService(r.getRoom().getRoomNumber());
}

void checkOut(int reservationId, Hotel& hotel)
{
	hotel.getReservation(reservationId).setStatus(Reservation::FINISHED);
}

void checkIn(int reservationId, Hotel& hotel)
{
	hotel.getReservation(reservationId).setStatus(Reservation::PAID_CHECKED_IN);
}

void updateReservation(int reservationId, Hotel& hotel)
{
	newDate = new DateTime(2, 2, 2019);
	hotel.getReservation(reservationId).setStartDate(*newDate);
}

int makeReservation(Customer& customer, Hotel& hotel)
{
	// make reservation
	startDate = new DateTime(1, 2, 2019);
	endDate = new DateTime(5, 2, 2019);
	int startingPrice = 500;

	breakfastPension = hotel.getDiningRoom().getAllPensionOptions()[1];
	try {
		Room& room = hotel.getAvailableRoom();
		r = new Reservation(customer, room, *breakfastPension, *startDate, *endDate, startingPrice);
		hotel.addReservation(*r);
		customer.addReservation(r);
		room.setIsOccupied(true);
		return r->getReservationId();
	}
	catch(char* msg){
		cout << "There are no available rooms at this moment." <<endl << msg << endl;
		return 0;
	}	
	
}

Room** createRooms(int numOfRooms)
{
	int i;
	int regulatBedsNum = 2;
	int spaRoomBedsNum = 3;
	int numOfOils = 3;

	rooms = new Room*[numOfRooms];

	try
	{
		for (i = 0; i < numOfRooms - 2; i++)
			rooms[i] = new Room(regulatBedsNum);

		rooms[i] = new SpaRoom(spaRoomBedsNum);
		i++;
		rooms[i] = new SpaRoom(spaRoomBedsNum);
	}
	catch (const char* errMessage)
	{
		cout << "Could not create room " << i << ":" << endl << errMessage << endl << endl;
		rooms[i] = nullptr;
		numOfRooms = i;
	}

	return rooms;
}

Service** createServices(int numOfServies) //This is not used in the code at all
{
	int price = 120;
	int maxNumOfCHildren = 6;
	int maxAge = 11;
	int minAge = 2;
	int hoursNum = 4;

	services = new Service*[numOfServies];

	services[0] = new Service("towls in room");
	services[1] = new Service("room cleaning");
	services[2] = new RoomService("breakfast in room");
	services[3] = new BabySitting("basic babySitting", price, maxNumOfCHildren, maxAge, minAge);
	services[4] = new BabySittingInRoom("room babySitting", price, maxNumOfCHildren, maxAge, minAge, hoursNum);

	return services;
}

Pension** createPensions(int numOfPensions)
{
	pensions = new Pension*[numOfPensions];
	pensions[0] = new Pension(Pension::NO_MEALS);
	pensions[1] = new Pension(Pension::BREAKFAST, 100);
	pensions[2] = new Pension(Pension::BREAKFAST, 100, true);
	pensions[3] = new Pension(Pension::BREAKFAST_AND_DINNER, 200, true);

	return pensions;
}

void printHotel(Hotel& hotel)
{
	cout << hotel;
}



void deleteObjects() //Please note that some methods that are written in the main are not used.
{                    //Therefore, I am not adding them to this function. This function was not made by the owner.
	for (int i = 0; i < NUM_OF_PENSIONS; i++)
		delete pensions[i];
	delete[] pensions;

	for (int i = 0; i < NUM_OF_ROOMS - 2; i++)
		delete rooms[i];
	//delete[] rooms; This one is deleted in the hotel.
	
	delete r;
	delete newDate;
	delete endDate;
	delete startDate;

}