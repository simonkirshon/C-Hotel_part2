#include "Spa.h"

Spa::Spa(const char* spaName)
{
	delete[]this->spaName;
	this->spaName = new char[strlen(spaName) + 1];
	strcpy(this->spaName, spaName);
}

Spa::~Spa()
{
	if (!(spaName == nullptr)) 
		delete[]spaName;
}

void Spa::relax() const
{
	std::cout << "Relaxing" << std::endl;
}

void Spa::swim() const
{
	std::cout << "Swimming" << std::endl;
}
