#include "Customer.h"
int Customer::customerCounter = 0;
Customer::Customer(const char* customerName)
{
	delete[]this->customerName;
	this->customerName = new char[strlen(customerName) + 1];
	strcpy(this->customerName, customerName);
	customerCounter += 1;
	customerId = customerCounter;
}

Customer::~Customer()
{
	if (!(customerName == nullptr))
		delete[] customerName;
}

const int Customer::getCustomerId() const
{
	return this->customerId;
}

const char* Customer::getCustomerName() const
{
	return this->customerName;
}
void Customer::addReservation(Reservation* reservation)
{
	this->reservation = reservation;
}

Reservation* Customer::getReservation() const
{
	return this->reservation;
}
