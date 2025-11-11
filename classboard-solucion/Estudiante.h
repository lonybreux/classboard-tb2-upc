#pragma once
#include "Usuario.h"
#include "Perfil.h"
#include "Curso.h"
#include "Lista.h"
class Estudiante : public Usuario, public Perfil {
	string carrera;
	Lista<Curso*>* cursos;
	bool estadoMatricula;
public:
	Estudiante(string ca = "Ingenieria de Software", string id = "", string c = "", string n = "", string a = "") :
		Usuario(id, c), Perfil(n, a), carrera(ca), cursos(new Lista<Curso*>()), estadoMatricula(false) {
	}

	~Estudiante() {}

	void setCarrera(string c) {
		carrera = c;
	}

	string getCarrera() const {
		return carrera;
	}

	void setCursosSeleccionados(Lista<Curso*>* oL) {
		cursos = oL;
	}

	void setEstadoMatricula(bool e) {
		estadoMatricula = e;
	}

	bool getEstadoMatricula() const {
		return estadoMatricula;
	}

	Lista<Curso*>* getCursos() const { return cursos; }

	vector<Curso*> CursosEstudiantes() const {
		vector<Curso*> auxV;

		for (int i = 0; i < cursos->longitud(); i++) {
			auxV.push_back(cursos->obtenerPos(i));
		}

		return auxV;
	}
};
