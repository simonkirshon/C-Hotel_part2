#ifndef Spa_H_
#define Spa_H_

#include <string.h>
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class Spa
{
private:
	char* spaName;

public:
	Spa(const char* spaName);
	~Spa();
	Spa(const Spa&) = delete;

	void relax() const;
	void swim() const;
};

#endif /*Spa_H*/_ 
