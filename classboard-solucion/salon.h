#pragma once
#include<iostream>
#include"Pabellon.h"

using namespace std;

class Salon
{
private:

	int nPiso;
	int nSalon;
	Pabellon* oPab;

public:
	Salon(int nPiso, int nsalon, Pabellon* oPab = nullptr)
	{
		this->nPiso = nPiso;
		this->nSalon = nsalon;
		this->oPab = oPab;
	}
	~Salon();

	int getNSalon() { return nSalon; }
	int getNPiso() { return nPiso; }
	Pabellon* getPab() { return oPab; }


};


