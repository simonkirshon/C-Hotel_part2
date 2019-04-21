#ifndef Customer_H_
#define Customer_H_

#include <string.h>
#pragma warning(disable:4996)
class Reservation;
class Customer
{
private:
	static int		customerCounter;
	int				customerId;
	char*			customerName;
	Reservation*	reservation;

public:
	Customer(const char* customerName);
	~Customer();
	Customer(const Customer&) = delete;

	const int getCustomerId() const;
	const char* getCustomerName() const;

	void addReservation(Reservation* reservation);
	Reservation* getReservation() const;
};

#endif /*Customer_H_ */