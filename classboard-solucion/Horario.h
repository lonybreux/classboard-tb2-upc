#pragma once

class Horario {
	string horaInicio;
	string horaFin;

public:
	Horario(string ini, string fin) : horaInicio(ini), horaFin(fin) {}

	string getHoraInicio() const {
		return horaInicio;
	}

	string getHoraFin() const {
		return horaFin;
	}

	void getInfo() const {
		cout << "\nHora de inicio: " << horaInicio;
		cout << "\nHora de fin: " << horaFin;
		cout << "\n";

	}
};