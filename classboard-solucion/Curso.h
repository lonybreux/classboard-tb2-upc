#pragma once
#include <vector>
#include <string>
#include "Profesor.h"
#include "Horario.h"
#include "Login.h"
#include "Pila.h"
#include "Evaluacion.h"
#include "Examen.h"
#include "Proyecto.h"
#include "salon.h"
#include "Cola.h"

void cursor(int x, int y);


class Curso {
private:

    string nrc;
    string nombre;
    Profesor* oProfesor;
    int creditos;
    Horario* horario;
    Salon* salon;

    Pila<Examen*>* examenes;
    Pila<Proyecto*>* proyectos;
    Cola<Fecha*>* fechasOrdenadas;

public:
    Curso(string nrc_, string nombre_, Profesor* oP, int creditos_, Horario* oh = nullptr, Salon* oS = nullptr) {
        nrc = nrc_;
        nombre = nombre_;
        oProfesor = oP;
        creditos = creditos_;
        horario = oh;
        salon = oS;

        examenes = new Pila<Examen*>();
        proyectos = new Pila<Proyecto*>();
        fechasOrdenadas = new Cola<Fecha*>();

        srand(time(NULL));
        System::Random r;
        int NOTAr;
        int PREGUNTASr;
        string DURACIONr;
        int DIAr;
        int MESr;
        int DIAFINALr;
        int MESFINALr;

        for (int i = 0; i < 3; i++) {
            NOTAr = r.Next(8, 21);
            PREGUNTASr = r.Next(5, 21);
            DURACIONr = to_string(r.Next(1, 3));
            DIAr = r.Next(1, 31);
            MESr = r.Next(8, 12);

            examenes->apilar(new Examen(i + 1, NOTAr, DURACIONr + ":00", PREGUNTASr, 0.10, new Fecha(DIAr, MESr, 2025)));
        }

        for (int i = 0; i < 2; i++) {
            NOTAr = r.Next(8, 21);
            PREGUNTASr = r.Next(5, 21);
            DURACIONr = to_string(r.Next(1, 3));
            DIAr = r.Next(1, 15);
            MESr = r.Next(8, 11);
            DIAFINALr = r.Next(15, 32);
            MESFINALr = r.Next(10, 13);

            proyectos->apilar(new Proyecto(i + 1, NOTAr, 0.35, new Fecha(DIAr, MESr, 2025), new Fecha(DIAFINALr, MESFINALr, 2025)));
        }

    }

    void mostrarCurso(int x, int y) {

        System::Console::SetCursorPosition(x, y + 1);           System::Console::ForegroundColor = System::ConsoleColor::White; cout << "NRC: ";
        System::Console::SetCursorPosition(x, y + 2);       System::Console::ForegroundColor = System::ConsoleColor::White; cout << "Profesor: ";
        System::Console::SetCursorPosition(x, y + 3);       System::Console::ForegroundColor = System::ConsoleColor::White; cout << "Creditos: ";
        System::Console::SetCursorPosition(x, y + 4);       System::Console::ForegroundColor = System::ConsoleColor::White; cout << "Hora: ";
        System::Console::SetCursorPosition(x, y + 5);       System::Console::ForegroundColor = System::ConsoleColor::White; cout << "Salon: ";
        System::Console::SetCursorPosition(x + 5, y + 1);      System::Console::ForegroundColor = System::ConsoleColor::DarkGray; cout << nrc << endl;
        System::Console::SetCursorPosition(x + 10, y + 2); System::Console::ForegroundColor = System::ConsoleColor::DarkGray; cout << oProfesor->getInfo() << endl;
        System::Console::SetCursorPosition(x + 10, y + 3); System::Console::ForegroundColor = System::ConsoleColor::DarkGray; cout << creditos << endl;
        System::Console::SetCursorPosition(x + 6, y + 4); System::Console::ForegroundColor = System::ConsoleColor::DarkGray; cout << horario->getHoraInicio() << " - " << horario->getHoraFin() << endl;
        System::Console::SetCursorPosition(x + 7, y + 5); System::Console::ForegroundColor = System::ConsoleColor::DarkGray; cout << "S" << salon->getPab()->getPabellon() << salon->getNPiso() << endl;

        if (salon->getNSalon() < 10)
        {
            System::Console::SetCursorPosition(x + 10, y + 5); cout << "0" << salon->getNSalon();
        }
        else
        {
            System::Console::SetCursorPosition(x + 10, y + 5); cout << salon->getNSalon();
        }

        System::Console::ForegroundColor = System::ConsoleColor::White;
    }

    string getNRC() const { return nrc; }
    string getNombre() const { return nombre; }
    Profesor* getProfesor() const { return oProfesor; }
    int getCreditos() const { return creditos; }
    Horario* getHorario() const { return horario; }

    void getExamenesToString(int x, int y) const {

        vector<Examen*> aux;

        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i));
        }


        for (const Examen* i : aux) {
            cursor(x, y + 2); cout << "Nota: " << i->getNota();
            cursor(x, y + 3); cout << "Peso: " << i->getPeso();
            cursor(x, y + 4); cout << "Duracion examen: " << i->getDuracion();
            cursor(x, y + 5); cout << "Cantidad de preguntas: " << i->getCantidadPreguntas();
            cursor(x, y + 6); cout << "Fecha: " << i->getFechaInicio()->getFechaString();

            x += 38;
        }

        cursor(33, 15); cout << "Examen " << 1;
        cursor(71, 15); cout << "Examen " << 2;
        cursor(109, 15); cout << "Examen " << 3;

    }

    void getProyectosToString(int x, int y) const {

        vector<Proyecto*> aux;

        for (int i = 0; i < proyectos->longitud(); i++) {
            aux.push_back(proyectos->obtenerPosicion(i));
        }

        for (const Proyecto* i : aux) {
            cursor(x, y + 2); cout << "Nota:" << i->getNota();
            cursor(x, y + 3); cout << "Peso: " << i->getPeso();
            cursor(x, y + 4); cout << "Fecha de inicio: " << i->getFechaInicio()->getFechaString();
            cursor(x, y + 5); cout << "Fecha de fin: " << i->getFechaFinal()->getFechaString();

            x += 38;
        }

        cursor(33, 27); cout << "Proyecto " << 1;
        cursor(71, 27); cout << "Proyecto " << 2;
    }

    vector<int> getNotasCursos() const {
        vector<int> notas;
        vector<Examen*> aux;
        vector<Proyecto*> aux_2;

        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i));

        }
        for (int i = 0; i < proyectos->longitud(); i++) {
            aux_2.push_back(proyectos->obtenerPosicion(i));
        }


        for (int i = 0; i < aux.size(); i++) {
            notas.push_back(aux[i]->getNota());
        }
        for (int i = 0; i < aux_2.size(); i++) {
            notas.push_back(aux_2[i]->getNota());
        }

        return notas;
    }

    vector<Fecha*> ordenadoPorFechaInicio() const{
        vector<Fecha*> aux;

        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i)->getFechaInicio());
        }
        for (int i = 0; i < proyectos->longitud(); i++) {
            aux.push_back(proyectos->obtenerPosicion(i)->getFechaInicio());
        }

        return aux;
    }

    vector<Examen*> getVectorExamenes() {
        vector<Examen*> aux;

        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i));
        }

        return aux;
    }

    vector<Proyecto*> getVectorProyectos() {
        vector<Proyecto*> aux;

        for (int i = 0; i < proyectos->longitud(); i++) {
            aux.push_back(proyectos->obtenerPosicion(i));
        }

        return aux;
    }

    void getCantidadPreguntasToString(int x, int y) const{

        vector<Examen*> aux;
        vector<int> auxPreguntas;
        int temp = y;
        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i));
            auxPreguntas.push_back(aux[i]->getCantidadPreguntas());
        }

        //BUBBLE SORT

        auto bubbleSort = [](vector<int>& v) {

            int n = v.size();

            bool ordenado;

            for (int i = 0; i < n - 1; i++) {

                ordenado = true;
                for (int k = 0; k < n - (i + 1); k++) {
                    if (v[k] > v[k + 1]) {
                        int temp = v[k];
                        v[k] = v[k + 1];
                        v[k + 1] = temp;
                        ordenado = false;
                    }
                }

                if (ordenado) break;
            }

            };

        bubbleSort(auxPreguntas);

        int k = 0;

        for (const Examen* i : aux) {
            if (i->getCantidadPreguntas() == auxPreguntas[0]) {
                cursor(x, y + 2); cout << "Nota: " << i->getNota();
                cursor(x, y + 3); cout << "Peso: " << i->getPeso();
                cursor(x, y + 4); cout << "Duracion examen: " << i->getDuracion();
                cursor(x, y + 5); cout << "Cantidad de preguntas: " << i->getCantidadPreguntas();
                cursor(x, y + 6); cout << "Fecha: " << i->getFechaInicio()->getFechaString();

            }
        }
        y = temp;
        x += 38;
        for (const Examen* i : aux) {
            if (i->getCantidadPreguntas() == auxPreguntas[1]) {
                cursor(x, y + 2); cout << "Nota: " << i->getNota();
                cursor(x, y + 3); cout << "Peso: " << i->getPeso();
                cursor(x, y + 4); cout << "Duracion examen: " << i->getDuracion();
                cursor(x, y + 5); cout << "Cantidad de preguntas: " << i->getCantidadPreguntas();
                cursor(x, y + 6); cout << "Fecha: " << i->getFechaInicio()->getFechaString();

            }
        }

        y = temp;
        x += 38;
        for (const Examen* i : aux) {
            if (i->getCantidadPreguntas() == auxPreguntas[2]) {
                cursor(x, y + 2); cout << "Nota: " << i->getNota();
                cursor(x, y + 3); cout << "Peso: " << i->getPeso();
                cursor(x, y + 4); cout << "Duracion examen: " << i->getDuracion();
                cursor(x, y + 5); cout << "Cantidad de preguntas: " << i->getCantidadPreguntas();
                cursor(x, y + 6); cout << "Fecha: " << i->getFechaInicio()->getFechaString();

            }
        }

        cursor(40, 14); cout << "Menor cantidad";
        cursor(116, 14); cout << "Mayor cantidad";


    }

    void getFechaString(int x, int y) const{
        vector<Examen*> aux;
        vector<Proyecto*>aux2;
        vector<Fecha*> auxFechas;
        vector<int> dias;
        vector<int> meses;
        map<int, int> fechas;

        

        for (int i = 0; i < examenes->longitud(); i++) {
            aux.push_back(examenes->obtenerPosicion(i));
            auxFechas.push_back(aux[i]->getFechaInicio());
        }
       
        for (int i = 0; i < proyectos->longitud(); i++) {
            aux2.push_back(proyectos->obtenerPosicion(i));
            auxFechas.push_back(aux2[i]->getFechaInicio());
        }

        for (const Fecha* i : auxFechas) {
            
            dias.push_back(i->getDia());
            meses.push_back(i->getMes());
        }

       
        for (int i = 0; i < auxFechas.size() - 1; i++) {
            for (int j = i + 1; j < auxFechas.size(); j++) {
                if (auxFechas[i]->getMes() > auxFechas[j]->getMes() || (auxFechas[i]->getMes() == auxFechas[j]->getMes() && auxFechas[i]->getDia() > auxFechas[j]->getDia())) {
                   
                    swap(auxFechas[i], auxFechas[j]);
                    fechasOrdenadas->encolar(auxFechas[i]);
                }
            }
        }

        for (const Fecha* j : auxFechas) {
            for (int i = 0; i < aux.size(); i++) {
                if (aux[i]->getFechaInicio() == j) {
                    cursor(x, y + 2); cout << "Nota: " << aux[i]->getNota();
                    cursor(x, y + 3); cout << "Peso: " << aux[i]->getPeso();
                    cursor(x, y + 4); cout << "Duracion examen: " << aux[i]->getDuracion();
                    cursor(x, y + 5); cout << "Cantidad de preguntas: " << aux[i]->getCantidadPreguntas();
                    cursor(x, y + 6); cout << "Fecha: " << aux[i]->getFechaInicio()->getFechaString();
                    x += 38;
                }
            }    
        }

        y += 16;
        x -= 114;

        for (const Fecha* j : auxFechas) {
            for (int i = 0; i < aux2.size(); i++) {
                if (aux2[i]->getFechaInicio() == j) {
                    cursor(x, y + 2); cout << "Nota:" << aux2[i]->getNota();
                    cursor(x, y + 3); cout << "Peso: " << aux2[i]->getPeso();
                    cursor(x, y + 4); cout << "Fecha de inicio: " << aux2[i]->getFechaInicio()->getFechaString();
                    cursor(x, y + 5); cout << "Fecha de fin: " << aux2[i]->getFechaFinal()->getFechaString();

                    x += 38;
                }
            }
        }
       
    }





};