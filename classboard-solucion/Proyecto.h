#pragma once
#include "Evaluacion.h"
#include "Fecha.h"
#include <iostream>
using namespace std;



class Proyecto : public Evaluacion {
private:
	Fecha* fechaInicio;
	Fecha* fechaFinal;
public:
	Proyecto(int nEva,int n, double p, Fecha* inicio, Fecha* fin) :Evaluacion(nEva,n, p), fechaInicio(inicio), fechaFinal(fin) {}

	void setFechaInicio(Fecha* o) {
		fechaInicio = 0;
	}
	void setFechaFin(Fecha* o) {
		fechaFinal = o;
	}

	Fecha* getFechaInicio() const {
		return fechaInicio;
	}

	Fecha* getFechaFinal() const {
		return fechaFinal;
	}


};