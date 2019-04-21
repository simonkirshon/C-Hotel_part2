#ifndef Service_H_
#define Service_H_
#include <string.h>
#include <iostream>
#pragma warning(disable: 4996)

class Service
{
private:
	int		price;
	char*	serviceName;

public:
	Service(const char* serviceName = "", int price = 0); //ADDED "" AS THERE WAS NO DEFAULT CONSTRUCTOR
	Service(const Service&) = delete;
	~Service();

	virtual void activateService(const int roomNumber) const;

	//ADDED NOW

	const char* getServiceName() const;
	const int getServicePrice() const;
};
#endif /*Service_H_ */