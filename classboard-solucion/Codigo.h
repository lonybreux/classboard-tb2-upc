#pragma once
#include <iostream>
#include "Ciclo.h"
#include "Curso.h"
using namespace std;

class Codigo {
private:
    long long codigo;

    int anioRecursivo(long long n) {
        if (n <= 9999)
            return (int)n;
        else
            return anioRecursivo(n / 10);
    }

    //RECURSIVIDAD
    int semestreRecursivo(long long n, int contador = 0) { 

        if (contador == 4) // -> 1 + (4)
            return (int)(n % 10); // -> 1
        else
            return semestreRecursivo(n / 10, contador + 1); // -> 4
    }

    //Tiempo detallado: 1 + (4) = 5
    //tiempo asintotico: O(1)

public:

    Codigo(long long c) {
        codigo = c;
    }

    int getAnio() {
        long long num = codigo;
        if (num < 0) num = -num;
        return anioRecursivo(num);
    }

    //RECURSIVIDAD
    int getSemestre() { 
        long long num = codigo; 
        if (num < 0) 
            num = -num; 

        if (num < 10000) 
            return 0;

        return semestreRecursivo(num); 
    }

    int getNivelEstudio() {
        return Ciclo::determinarCicloUsuario(getAnio(), getSemestre());
    }

    void mostrarInterpretacion() {
        int anio = getAnio();
        int semestre = getSemestre();
        int cicloActual = Ciclo::determinarCicloUsuario(anio, semestre);
    }
};