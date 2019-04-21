#ifndef Reservation_H_
#define  Reservation_H_

#include "DateTime.h"
#include "Customer.h"
#include "Pension.h"
#include "Room.h"
#include "Service.h"
#include <iostream>
#define STATES 4
#define DEDAULT_NUM_OF_SERVICES 100
using namespace std;

class Reservation
{
public:
	enum eStatus { RESERVED, PAID_CHECKED_IN, FINISHED, CANCELLED };
	const char* statuses[STATES] = { "Reserved","PaidCheckedIn","Finished","Cancelled" };

	Reservation(Customer& customer, Room& room, Pension& pension, DateTime& startDate, DateTime& endDate, int startingPrice);
	Reservation(Reservation&) = delete;
	~Reservation();

	// setters
	void setPension(Pension& pension);
	void setPrice(int price);
	void setStatus(eStatus status);
	void setStartDate(DateTime& date);
	void setEndDate(DateTime& date);

	//getters
	int  getReservationId() const;
	int  getTotalPrice() const;

	DateTime& getStartDate() const;
	DateTime& getEndDate() const;

	Room& getRoom() const;
	Customer& getCustomer() const;
	Pension& getPension() const;
	Service** getAllServices() const;
	const char* getStatus() const; /*{ return statuses[status]; }*/

								   // operators
	const Reservation& operator+=(Service& service);
	friend ostream& operator<<(ostream& os, const Reservation& sreservation);

	const bool getDinerStatus();
	void setDinerStatus(bool status);

	void addService(Service& service) throw (const int);

private:
	int					reservationId;
	int			        numOfServices;
	int					price;
	static int			amountOfReservations;
	bool                dinerStatus;

	eStatus			    status;
	DateTime*			startDate;
	DateTime*			endDate;
	DateTime*			reserveDate;

	Room*				room;
	Customer*			customer;
	Pension* 			pension;
	Service**			allServices;
};

#endif /*Reservation_H_ */



