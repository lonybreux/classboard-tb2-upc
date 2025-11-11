#pragma once
#include<iostream>

using namespace std;

class Pabellon
{
private:

	char tipoPabellon;

public:
	Pabellon(char tipoPab)
	{
		this->tipoPabellon = tipoPab;
	}
	~Pabellon();

	char getPabellon() { return tipoPabellon; }
};

