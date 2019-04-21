#include "Reservation.h"

int Reservation::amountOfReservations = 0;
Reservation::Reservation(Customer& customer, Room& room, Pension& pension, DateTime& startDate, DateTime& endDate, int startingPrice) :
	customer(&customer), room(&room), pension(&pension), startDate(&startDate), endDate(&endDate), price(startingPrice)
{
	reservationId = amountOfReservations++;
	numOfServices = 0;
	allServices = new Service*[DEDAULT_NUM_OF_SERVICES];

}

Reservation::~Reservation() //TODO AFTER THE DYNAMIC ALLOCATIONS
{
	if (!(allServices == nullptr))
		delete[] allServices;
}

void Reservation::setPension(Pension& pension)
{
	this->pension = &pension;
}

void Reservation::setPrice(int price)
{
	if (price < 0)
	{
		price = 0;
		cout << "Price cannot be negative - Setting price to 0";
	}
	this->price = price;
}

void Reservation::setStatus(eStatus status)
{
	this->status = status;
}

void Reservation::setStartDate(DateTime& date)
{
	this->startDate = &date;
}

void Reservation::setEndDate(DateTime& date)
{
	this->endDate = &date;
}

int Reservation::getReservationId() const
{
	return this->reservationId;
}

int Reservation::getTotalPrice() const
{
	return this->price;
}

DateTime& Reservation::getStartDate() const
{
	return *startDate;
}

DateTime& Reservation::getEndDate() const
{
	return *endDate;
}

Room& Reservation::getRoom() const
{
	return *room;
}

Customer& Reservation::getCustomer() const
{
	return *customer;
}

Pension& Reservation::getPension() const
{
	return *pension;
}

Service** Reservation::getAllServices() const
{
	return allServices;
}

const char* Reservation::getStatus() const
{
	return statuses[status];
}

void Reservation::setDinerStatus(bool status)
{
	this->dinerStatus = status;
}

const bool Reservation::getDinerStatus()
{
	return dinerStatus;
}

void Reservation::addService(Service& service) throw (const int)
{
	try
	{
		if (numOfServices >= DEDAULT_NUM_OF_SERVICES)
			throw numOfServices;
		else {
			allServices[numOfServices++] = &service;
		}

	}
	catch (int numericError)
	{
		cout << "Current add more services: " << numericError << "which is the limit." << endl;
	}
}

const Reservation& Reservation::operator+=(Service& service)
{
	this->addService(service);
	return *this;
}

ostream& operator<<(ostream& os, const Reservation& sreservation)
{
	os << "Customer " << sreservation.getCustomer().getCustomerName() << " in room 10" << sreservation.getRoom().getRoomNumber() << "." << endl;
	os << "Checked in at: " << sreservation.getStartDate().getDay() << "/" << sreservation.getStartDate().getMonth() << "/" << sreservation.getStartDate().getyear() << "." << endl;
	os << "Checks out at: " << sreservation.getEndDate().getDay() << "/" << sreservation.getEndDate().getMonth() << "/" << sreservation.getEndDate().getyear() << "." << endl;
	return os;
}