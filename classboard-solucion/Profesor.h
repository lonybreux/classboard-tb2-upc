#pragma once
#include "Perfil.h"

class Profesor : public Perfil {
public:
	Profesor(string n = "", string a = "") : Perfil(n, a) {}
	~Profesor() {}

};