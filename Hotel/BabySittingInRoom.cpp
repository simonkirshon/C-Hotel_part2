#include "BabySittingInRoom.h"


BabySittingInRoom::BabySittingInRoom(const char* serviceName, int price, int maxNumOfChildren, int maxAge, int minAge, int hoursNum)
	:BabySitting(serviceName, price*hoursNum, maxNumOfChildren, maxAge, minAge) {}

