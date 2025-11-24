#pragma once
#include "Perfil.h"
#include "Dataset-Estudiantes.h"

class Profesor : public Perfil {
private:
	vector<Alumno*> grupoAlumnos;
	int seccion;
public:
	Profesor(string n = "", string a = "") : Perfil(n, a) {
		
		//numero de seccion de salon random
		int random = 1000 + rand() % (9999 - 1000 + 1);
		seccion = random;

		//se obtiene el data set generado para los alumnos random
		Dataset_Alumnos* data = new Dataset_Alumnos();
		grupoAlumnos = data->generarDatos();

		//se asigna la seccion del profesor a los alumnos
		for (int i = 0; i < grupoAlumnos.size(); i++) {
			grupoAlumnos[i]->setSeccion(seccion);
		}

	}
	~Profesor() {}

	void verAlumnos() {
		for (const Alumno* i : grupoAlumnos) {
			cout << "Nombre: " << i->getNombre() << "\n";
			cout << "Edad: " << i->getEdad() << "\n";
			cout << "Seccion: " << i->getSeccion() << "\n";
		}
	}

};