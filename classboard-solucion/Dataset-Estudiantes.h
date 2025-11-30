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
	vector<int> notas;
	int promedioSimple;
public:

	Alumno(int e, string n, int s) {
		
		
		for (int i = 0; i < 5; i++) {
			int randNotas = 10 + rand() % (20 - 10 + 1);
			notas.push_back(randNotas);
		}

		promedioSimple = 0;
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
	vector<int> getNotas() const {
		return notas;
	}

	int getPromedioSimple() {
		for (int i = 0; i < 5; i++) {
			promedioSimple += notas[i];
		}

		return promedioSimple / 5;
	}

};


//Data set para el grupo de alumnos de un profesor
class Dataset_Alumnos {
private:

	//nombres para alumnos random
	

	vector<string> nombres = {
	"Alejandro", "Luis", "Carlos", "Miguel", "Javier", "Pedro", "Manuel", "Jose", "Juan", "Hernan", "Lucas", "Matias", "Santiago", "Andres", "Bruno", "Gabriel", "Hugo",
	"Daniel", "Pablo", "Nicolas", "Diego", "Ivan", "Esteban", "Cristian", "Raul",
	"Tomas", "Benjamin", "Damian", "Emilio", "Felipe", "Gonzalo", "Alvaro", "Mario",
	"Adrian", "Ricardo", "Victor", "Ramiro", "Ezequiel", "Mauricio", "Gerardo",
	"Simon", "Thiago", "Leo", "Marcos", "Rafael", "Joel", "Ismael", "Ruben",
	"Ana", "Maria", "Lucia", "Elena", "Rosa", "Isabel", "Laura", "Carla", "Valeria",
	"Sofia", "Camila", "Daniela", "Sara", "Clara", "Julia", "Marta", "Paula", "Celia",
	"Alicia", "Irene", "Gabriela", "Veronica", "Patricia", "Olivia", "Noelia", "Jimena",
	"Bianca", "Renata", "Andrea", "Lourdes", "Angela", "Eva", "Teresa", "Belen",
	"Nadia", "Carolina", "Florencia", "Ariadna", "Leticia", "Lorena", "Martina",
	"Oscar", "Eduardo", "Roberto", "Francisco", "Rodrigo",
	"Sebastian", "Mariano", "Brandon", "Kevin", "Jordan",
	"Aaron", "Dylan", "Henry", "Oliver", "Samuel",
	"Axel", "Cristobal", "Luciano", "Fabian", "Ulises", "Sergio", "Lisandro",
	"Monica", "Brenda", "Nicole", "Rocio", "Tamara",
	"Natalia", "Claudia", "Silvia", "Elisa", "Ariana",
	"Juliana", "Emilia", "Miranda", "Vanesa", "Melissa",
	"Naomi", "Alexandra", "Victoria","Max", "Alan", "Marco", "Franco", "Leonardo", "Emmanuel", "Felix", "Axel",
	"Alexis", "Cristian", "Guillermo", "Hector", "Marcelo", "Renzo", "Erik",
	"Adolfo", "Bruno", "Lukas", "Lucio", "Bastian", "Federico", "Franco","Diana", "Karen", "Caroline", "Alexia", "Denise", "Kiara", "Nicoletta",
	"Emma", "Mia", "Zoe", "Carina", "Tania", "Selena", "Ashley", "Allison",
	"Alexa", "Valery", "Ximena", "Samira", "Isabella", "Jazmin", "Camile"
	};

	int nAlumnos;

public:

	Dataset_Alumnos() {
		
		nAlumnos = 15;
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