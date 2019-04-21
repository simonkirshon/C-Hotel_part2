#include "DiningRoom.h"

int DiningRoom::currentAmountOfDiners = 0;
DiningRoom::DiningRoom(int maxNumOfDinners)
{
	this->maxNumOfDinners = maxNumOfDinners;
	currentAmountOfDiners = 0;

}



bool DiningRoom::startMeal(Reservation& res) const throw (const char*)
{
	try
	{
		if (res.getPension().getPensionType() == "No Meals")
			throw "This reservation is not allowed to eat in my hotel.";
		if (res.getDinerStatus())
			throw "Reservation is already dining";
		if (currentAmountOfDiners + res.getRoom().getNumOfBeds() > maxNumOfDinners)
			throw "The diner is currently full.";
		currentAmountOfDiners += res.getRoom().getNumOfBeds();
		res.setDinerStatus(true);
		return true;
	}
	catch (char* errMsg)
	{
		cout << errMsg;
		return false;
	}
}


void DiningRoom::endMeal(Reservation& res) const throw (const char*)
{
	try
	{
		if (!res.getDinerStatus())
			throw "Reservation is not in diner";
		currentAmountOfDiners -= res.getRoom().getNumOfBeds();
		res.setDinerStatus(false);
	}
	catch (char* errMsg)
	{
		cout << errMsg;
	}
}


Pension** DiningRoom::getAllPensionOptions() const
{
	return this->allPension;
}

void DiningRoom::setPensions(Pension** pensions)
{
	this->allPension = pensions;
}