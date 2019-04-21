#include "Service.h"


Service::Service(const char* serviceName, int price)
{
	delete[] this->serviceName;
	this->serviceName = new char[strlen(serviceName) + 1];
	strcpy(this->serviceName, serviceName);
	this->price = price;
}

Service::~Service()
{
	if (!(serviceName == nullptr))
		delete[]serviceName;
}

void Service::activateService(const int roomNumber) const
{
	std::cout << "Starting " << serviceName << " at room " << roomNumber << std::endl;
}


//ADDED NOW

const char* Service::getServiceName() const
{
	return this->serviceName;
}
const int Service::getServicePrice() const
{
	return this->price;
}



