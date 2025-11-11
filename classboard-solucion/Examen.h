#pragma once
#include "Evaluacion.h"
#include <iostream>
#include "Fecha.h"
using namespace std;

class Examen : public Evaluacion {
	string duracion;
	int cantidadPreguntas;
	Fecha* fechaInicio;
public:
	Examen(int nEva,int n, string d, int c, double p, Fecha* ini) :Evaluacion(nEva,n, p), duracion(d), cantidadPreguntas(c), fechaInicio(ini) {}

	void setDuracion(string d) {
		duracion = d;
	}
	void setCantidadPreguntas(int c) {
		cantidadPreguntas = c;
	}

	string getDuracion() const {
		return duracion;
	}

	int getCantidadPreguntas() const {
		return cantidadPreguntas;
	}

	void setFechaInicio(Fecha* o) {
		fechaInicio = o;
	}

	Fecha* getFechaInicio() const {
		return fechaInicio;
	}

	string getFechaString() const {
		return to_string(fechaInicio->getDia()) + "/" + to_string(fechaInicio->getMes()) + "/" + to_string(fechaInicio->getAnio());
	}
};