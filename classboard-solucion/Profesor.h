#pragma once
#include "Perfil.h"
#include "Dataset-Estudiantes.h"
#include "HashTabla.h"

void cursor(int x, int y);

int HashString(string s) {
	int c = 0;

	for (int i = 0; i < s.size(); i++) {
		c += int(s[i]);
	}

	return c;
}

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

	void verAlumnos(int x, int y) {
		int yAux = y;

		for (const Alumno* i : grupoAlumnos) {
			cursor(x, y);  cout << "Nombre: " << i->getNombre() << "\n";
			cursor(x, y + 1);  cout << "Edad: " << i->getEdad() << "\n";
			y += 7;

			if (y > 35) {
				y = yAux;
				x += 22;
			}
				
		}
	}

	vector<string> getNombreAlumnos() {
		vector<string> nombre;

		for (int i = 0; i < grupoAlumnos.size(); i++) {
			nombre.push_back(grupoAlumnos[i]->getNombre());
		}

		return nombre;
	}

	vector<Alumno*> getAlumnos() {
		return grupoAlumnos;
	}

	HashTabla<vector<int>>* getTablaAlumnos() {
		HashTabla<vector<int>>* tablaAlumnos = new HashTabla<vector<int>>();
		for (int i = 0; i < grupoAlumnos.size(); i++) {
			tablaAlumnos->insertar(HashString(grupoAlumnos[i]->getNombre()), grupoAlumnos[i]->getNotas());
		}

		return tablaAlumnos;
	}
};