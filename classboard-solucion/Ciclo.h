#pragma once
#include "Curso.h"
#include "Lista.h"
#include<Windows.h>

class Ciclo {
private:
    int numero; // ciclo 1, ciclo 2, etc.
    Lista<Curso*>* cursos;

public:
    Ciclo(int num) {
        numero = num;
        cursos = new Lista<Curso*>();
    }
    ~Ciclo() {
        delete cursos;
    }

    Lista<Curso*>* getCursos() {
        return cursos;
    }
    void mostrarCursoEnCuadro(Curso* c, int x, int y) {

        cursor(x, y);     cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
        cursor(x, y + 1); cout << char(179) << c->getNombre();


        int len = c->getNombre().length();
        for (int i = len; i < 27; i++) cout << " ";

        cout << char(179);
        cursor(x, y + 2);     cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);

    }
    void agregarCurso(Curso* c) {
        cursos->agregarFinal(c);
    }
    // Muestra ciclo
    void mostrar() {
        int x = 5;   // posición horizontal inicial
        int y = 20;  // posición vertical inicial

        Nodo<Curso*>* actual = cursos->getInicio();
        while (actual != nullptr) {
            mostrarCursoEnCuadro(actual->valor, x, y);
            x += 35; // espacio entre cuadros
            actual = actual->siguiente;
        }
    }

    //RECURSIVIDAD
    //  Determinar ciclo actual a partir del año y semestre de ingreso 
    static int determinarCicloUsuario(int anioIngreso, int semestreIngreso, int anioActual = 2025, int semestreActual = 2) {

        if (anioIngreso == anioActual && semestreIngreso == semestreActual) // 1 + max(Interna IF, Interna Else)
            return 1; // ciclo actual, empieza en 1

        // si estamos en el primer semestre pasamos al segundo del mismo año
        if (semestreIngreso == 1) // 1 + max(Interna IF, Interna Else)
            return 1 + determinarCicloUsuario(anioIngreso, 2, anioActual, semestreActual); // 1

        // si estamos en el segundo semestre avanzamos al siguiente año semestre 1
        return 1 + determinarCicloUsuario(anioIngreso + 1, 1, anioActual, semestreActual); // 1
    }
    // tiempo detallado: 1 + 1 + 1 = 3
    // tiempo asintotico : O(3) -> constante

    void determinarCursos() {
        switch (this->numero) {
        case 1:
            cursos->agregarInicial(new Curso("1001", " Creatividad y liderazgo", new Profesor(), 4));
            cursos->agregarFinal(new Curso("1002", " Crítica y Comunicación", new Profesor(), 3));
            cursos->agregarFinal(new Curso("1003", " Introduccion Algoritmos", new Profesor(), 6));
            cursos->agregarFinal(new Curso("1004", " Matematica Basica", new Profesor(), 5));
            cursos->agregarFinal(new Curso("1005", " Etica y Ciudadania", new Profesor(), 5));
            cursos->agregarFinal(new Curso("1006", " Sistemas y Sociedad", new Profesor(), 3));
            break;
        case 2:
            cursos->agregarInicial(new Curso("2001", " Calculo I", new Profesor(), 6));
            cursos->agregarFinal(new Curso("2002", " Algoritmos", new Profesor(), 5));
            cursos->agregarFinal(new Curso("2003", " App. de ing de Software", new Profesor(), 4));
            cursos->agregarFinal(new Curso("2004", " Org y direc de empresas", new Profesor(), 3));
            cursos->agregarFinal(new Curso("2005", " Seminario Investigación I", new Profesor(), 3));
            break;
        case 3:
            cursos->agregarInicial(new Curso("3001", " Diseño, Patron de Software", new Profesor(), 4));
            cursos->agregarFinal(new Curso("3002", " Estructuras de Datos", new Profesor(), 5));
            cursos->agregarFinal(new Curso("3003", " Física I", new Profesor(), 4));
            cursos->agregarFinal(new Curso("3004", " Ingeniería de Requisitos", new Profesor(), 4));
            cursos->agregarFinal(new Curso("3005", " Matemática Discreta", new Profesor(), 5));
            break;
        case 4:
            cursos->agregarInicial(new Curso("4001", " Arq. de Computadoras", new Profesor(), 5));
            cursos->agregarFinal(new Curso("4002", " Base de Datos", new Profesor(), 4));
            cursos->agregarFinal(new Curso("4003", " Física II", new Profesor(), 4));
            cursos->agregarFinal(new Curso("4004", " HCI for UX Design", new Profesor(), 3));
            cursos->agregarFinal(new Curso("4005", " Matemática Computacional", new Profesor(), 5));
            break;
        case 5:
            cursos->agregarInicial(new Curso("5001", " Aplicaciones Web", new Profesor(), 4));
            cursos->agregarFinal(new Curso("5002", " Dessa. de app. Open Source", new Profesor(), 4));
            cursos->agregarFinal(new Curso("5003", " Calculo II", new Profesor(), 5));
            cursos->agregarFinal(new Curso("5004", " Sistemas Operativos", new Profesor(), 5));
            cursos->agregarFinal(new Curso("5005", " Electivo", new Profesor(), 0));
            break;
        case 6:
            cursos->agregarInicial(new Curso("6001", " Aplicaciones para Móviles", new Profesor(), 4));
            cursos->agregarFinal(new Curso("6002", " Complejidad Algorítmica", new Profesor(), 5));
            cursos->agregarFinal(new Curso("6003", " Estadística Aplicada I", new Profesor(), 4));
            cursos->agregarFinal(new Curso("6004", " Redes y comunicaciones", new Profesor(), 5));
            cursos->agregarFinal(new Curso("6005", " Electivo", new Profesor(), 0));
            break;
        case 7:
            cursos->agregarInicial(new Curso("7001", " Arquitecturas de Software", new Profesor(), 4));
            cursos->agregarFinal(new Curso("7002", " Dessa. de Soluciones IoT", new Profesor(), 4));
            cursos->agregarFinal(new Curso("7003", " Experimentos ing. de soft", new Profesor(), 4));
            cursos->agregarFinal(new Curso("7004", " Tec. e ing Financiera", new Profesor(), 3));
            cursos->agregarFinal(new Curso("7005", " Electivo", new Profesor(), 0));
            break;
        case 8:
            cursos->agregarInicial(new Curso("8001", " Arquitectura de Software", new Profesor(), 4));
            cursos->agregarFinal(new Curso("8002", " Investigación Académica", new Profesor(), 3));
            cursos->agregarFinal(new Curso("8003", " Gerencia de Proyectos", new Profesor(), 4));
            cursos->agregarFinal(new Curso("8004", " Investigación Aplicada", new Profesor(), 3));
            cursos->agregarFinal(new Curso("8005", " Electivo", new Profesor(), 0));
            break;
        case 9:
            cursos->agregarInicial(new Curso("9001", " Calidad de Software", new Profesor(), 4));
            cursos->agregarFinal(new Curso("9002", " Desarrollo Agile", new Profesor(), 4));
            cursos->agregarFinal(new Curso("9003", " TB de Investigación I", new Profesor(), 5));
            cursos->agregarFinal(new Curso("9004", " Electivo", new Profesor(), 0));
            cursos->agregarFinal(new Curso("9005", " Electivo", new Profesor(), 0));
            break;
        case 10:
            cursos->agregarInicial(new Curso("10001", " TB de Investigación II", new Profesor(), 6));
            cursos->agregarFinal(new Curso("10002", " Electivo", new Profesor(), 0));
            cursos->agregarFinal(new Curso("10003", " Electivo", new Profesor(), 0));
            cursos->agregarFinal(new Curso("10004", " Electivo", new Profesor(), 0));
            cursos->agregarFinal(new Curso("10005", " Electivo", new Profesor(), 0));
            break;
        }

        if (this->numero > 10 || this->numero < 1) {
            cout << "No hay cursos registrados para este ciclo." << endl;
            return;
        }

    }

    vector<Curso*> getCursosVector() const {
        vector<Curso*> vCursos;
        for (int i = 0; i < cursos->longitud(); i++) {
            vCursos.push_back(cursos->obtenerPos(i));
        }

        return vCursos;
    }

};
