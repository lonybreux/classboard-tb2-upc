#pragma once
#include <iostream>
using namespace std;

class Perfil {
	string nombre;
	string apellido;

public:
	Perfil(string n, string a) : nombre(n), apellido(a) {}
	~Perfil() {}

	void setNombre(string n) {
		nombre = n;
	}

	void setApellido(string a) {
		apellido = a;
	}

	string getNombre() const {
		return nombre;
	}

	string getApellido() const {
		return nombre;
	}

	string getInfo() const {
		return nombre + " " + apellido;
	}
};