#pragma once
#include <iostream>
#include <vector>
using namespace std;

// clase alumno simple
class Alumno {
private:
	int edad;
	string nombre;
	int seccion;

public:

	Alumno(int e, string n, int s) {
		edad = e;
		nombre = n;
		seccion = s;
	}

	~Alumno() {}

	int getEdad() const {
		return edad;
	}

	string getNombre() const {
		return nombre;
	}

	int getSeccion() const {
		return seccion;
	}

	void setSeccion(int s) {
		seccion = s;
	}
};


//Data set para el grupo de alumnos de un profesor
class Dataset_Alumnos {
private:

	//nombres para alumnos random
	vector<std::string> nombres = {
		"Alejandro", "Luis", "Carlos", "Miguel", "Javier", "Pedro", "Manuel", "Jose", "Juan",
		"Hernan", "Lucas", "Matias", "Santiago", "Andres", "Bruno", "Gabriel", "Hugo",
		"Daniel", "Pablo", "Nicolas", "Diego", "Ivan", "Esteban", "Cristian", "Raul",
		"Tomas", "Benjamin", "Damian", "Emilio", "Felipe", "Gonzalo", "Alvaro", "Mario",
		"Adrian", "Ricardo", "Victor", "Ramiro", "Ezequiel", "Mauricio", "Gerardo",
		"Simon", "Thiago", "Leo", "Marcos", "Rafael", "Joel", "Ismael", "Ruben",
		"Ana", "Maria", "Lucia", "Elena", "Rosa", "Isabel", "Laura", "Carla", "Valeria",
		"Sofia", "Camila", "Daniela", "Sara", "Clara", "Julia", "Marta", "Paula", "Celia",
		"Alicia", "Irene", "Gabriela", "Veronica", "Patricia", "Olivia", "Noelia", "Jimena",
		"Bianca", "Renata", "Andrea", "Lourdes", "Angela", "Eva", "Teresa", "Belen",
		"Nadia", "Carolina", "Florencia", "Ariadna", "Leticia", "Lorena", "Martina"
	};

	int nAlumnos;

public:

	Dataset_Alumnos() {
		//numero de alumnos random
		int random = 10 + rand() % (15 - 10 + 1);
		nAlumnos = random;
	}


	vector<Alumno*> generarDatos() {
		//vector que retorna lista de alumnos random
		vector<Alumno*> aux;

		for (int i = 0; i < nAlumnos; i++) {
			int randEdad = 18 + rand() % (25 - 18 + 1);
			aux.push_back(new Alumno(randEdad,nombres[rand() % nombres.size()], 0));
		}

		return aux;
	}
};