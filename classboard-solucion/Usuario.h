#pragma once
#include <iostream>
using namespace std;

class Usuario {
protected:
	string idUsuario;
	string contraseña;
public:
	Usuario(string id, string c) : idUsuario(id), contraseña(c) {}
	~Usuario() {}

	void setIdUsuario(string id) {
		idUsuario = id;
	}

	void setContraseña(string c) {
		contraseña = c;
	}

	string getIdUsuario() const {
		return idUsuario;
	}

	string getContraseña() const {
		return contraseña;
	}


};