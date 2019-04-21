#ifndef __HOTEL_H
#define __HOTEL_H

#include "Spa.h"
#include "DiningRoom.h"
#include "Room.h"
#include "Reservation.h"
#include "Customer.h"
#include "Service.h"

using namespace std;


#define INIT_NUM 0
#define DEDAULT_NUM_OF_SERVICES 100

class Hotel
{
private:
	char*				hotelName; 

	int					maxRoomsNum; 
	int					maxReservationsNum; 
	int					numOfRooms;
	int					numOfOccupiedRooms;
	int					numOfReservations;
	int					numOfServices; 

	Spa*				spa;
	DiningRoom			diningRooom;
	Room**				allRooms;
	Service**			allServices;
	Reservation**		allReservations;


public:
	Hotel(const char* hotelName, int maxRoomsNum, int maxReservationsNum);
	~Hotel();

	void Hotel::addRoom(Room& room) throw (const int);
	void addReservation(Reservation& reservation) throw (const int);
	void addService(Service& service) throw (const char*);

	// setters
	void setNumOfOccupiedRooms(int num);
	void setSpa(Spa& spa);
	void setDiningRoom(DiningRoom& diningRoom);

	// getters
	int getNumOfRooms() const;
	int getNumOfOccupiedRooms() const;
	int getNumOfReservations() const;
	int getMaxReservationsNum() const;
	Room& getAvailableRoom() const;
	Reservation& getReservation(int reservationId) const;
	const DiningRoom& getDiningRoom() const;
	Service** getAllServices() const;
	const Spa& getSpa() const;

	// operators 
	Room& operator[](int roomNumber) const;						// get room by room number
	friend ostream& operator<<(ostream& os, const Hotel& hotel);

	// delete
	Hotel(const Hotel&) = delete;
	const Hotel& operator=(const Hotel& hotel) = delete;

	
	//ADDED NOW
	void setAllRooms(Room** allrooms);
	const char* getHotelName() const;
	const int getMaxRoomNumber() const;
	Reservation** getAllReservations() const;
	int getNumberOfServices() const;
	int getNumberOfReservations() const;

};

#endif /*__HOTEL_H*/
