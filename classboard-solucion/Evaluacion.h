#pragma once

class Evaluacion {
protected:
	int nota;
	double peso;
	int nEvaluacion;
public:
	Evaluacion(int nEva,int nota, double peso) : nota(nota), peso(peso),nEvaluacion(nEva) {}

	void setNota(int nota) {
		this->nota = nota;
	}
	void setPeso(double p) {
		peso = p;
	}

	int getNota() const {
		return nota;
	}

	double getPeso() const {
		return peso;
	}

	int getNumeroEvaluacion() const {
		return nEvaluacion;
	}

};