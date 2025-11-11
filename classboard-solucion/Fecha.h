#pragma once


class Fecha {
	int dia;
	int mes;
	int anio;

public:
	Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

	void setDia(int d) {
		dia = d;
	}

	void setMes(int m) {
		mes = m;
	}

	void setAnio(int a) {
		anio = a;
	}

	int getDia() const {
		return dia;
	}

	int getMes() const {
		return mes;
	}

	int getAnio() const {
		return anio;
	}

	string getFechaString() const {
		return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
	}
};