#pragma once
#include "Login.h"
#include "Codigo.h"
#include "Ciclo.h"
#include "Global.h"
#include "BlackBoard.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include "Estudiante.h"
#include <string>
#include"menu.h"
#include "HashTabla.h"

using namespace std;

#define NOMBRE_COLA "cola_matricula.txt"


void ingresarCola(Estudiante* oE) {
    ofstream colaMatricula;

    colaMatricula.open(NOMBRE_COLA, ios::app);

    colaMatricula << oE->getIdUsuario() << endl;

    colaMatricula.close();
}

vector<string> leerCola() {
    ifstream colaMatricula;

    colaMatricula.open(NOMBRE_COLA, ios::in);
    string usuarioEnCola;
    vector<string>colaDeUsuarios;
    
    if (colaMatricula.is_open()) {
        while (getline(colaMatricula, usuarioEnCola))
        {
            colaDeUsuarios.push_back(usuarioEnCola);
        }
    }
    colaMatricula.close();

    
    return colaDeUsuarios;
}

vector<string> leerRegistrados() {
    ifstream arc;
    string linea;
    vector<string>registrados;
    arc.open(NOMBRE_ARCHIVO, ios::in);

    if (arc.is_open()) {
        while (getline(arc, linea)) { // mientras se este leyendo las lineas del archivo
            string USER_r, contraseña_r;
            stringstream ss(linea);// stringstream ss: variable 
            //que recorre un string y lo descompone en partes, podemos sacar partes de un string, 
           // aqui le decimos que agarre linea que ya esta seteado con getline 

            getline(ss, USER_r, ','); // le decimos que agarre ese string    
            // descompuesto y que guarde lo que haya hasta que encuentre una coma en variable USER

            registrados.push_back(USER_r);
        }
    }

    return registrados;
}


// Función para seleccionar subcurso vertical
Curso* seleccionarSubCursoHorizontal(vector<Curso*> subCursos, int xBase, int yBase) {
    if (subCursos.empty()) return nullptr;

    int index = 0;
    bool seleccionando = true;

    while (seleccionando) {
        // Dibujar subcursos
        for (int i = 0; i < subCursos.size(); i++) {
            Curso* c = subCursos[i];
            int yPos = 10;
            int xPos = 29;
            xPos = (xPos * (i + 1));
            if (i == index)
                Console::ForegroundColor = ConsoleColor::Yellow;
            else
                Console::ForegroundColor = ConsoleColor::White;

            cursor(xPos, yBase);     cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
            cursor(xPos, yBase + 1); cout << char(179) << " NRC: " << c->getNRC() << "             " << char(179);
            cursor(xPos, yBase + 2); cout << char(179) << " HoraIni: " << c->getHorario()->getHoraInicio() << "       " << char(179);
            cursor(xPos, yBase + 3); cout << char(179) << " HoraFin: " << c->getHorario()->getHoraFin() << "       " << char(179);
            cursor(xPos, yBase + 4); cout << char(179) << " Profesor: " << c->getProfesor()->getInfo() << "" << char(179);
            cursor(xPos, yBase + 5); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);;


        }

        if (_kbhit()) {
            char tecla = tolower(_getch());
            switch (tecla) {
            case 'a': if (index > 0) index--; break;
            case 'd': if (index < subCursos.size() - 1) index++; break;
            case 32:
            {
                return subCursos[index];

            }
            }
        }

    }

    return nullptr;
}
void marcoMatricula()
{
    cursor(0, 0);
    cout << char(201);
    cursor(0, 39);
    cout << char(200);
    for (int i = 1; i < 144; i++)
    {
        cursor(i, 0);
        cout << char(205);
        cursor(i, 39);
        cout << char(205);
    }

    cursor(144, 0);
    cout << char(187);
    cursor(144, 39);
    cout << char(188);

    for (int j = 1; j < 39; j++)
    {
        cursor(144, j);
        cout << char(186);
        cursor(0, j);
        cout << char(186);
    }
}

void marcoOpcion(int x, int y, int z, int k, int largo, int ancho)
{

    //Horizontal
    cursor(x - 1, y); cout << char(201);
    cursor(x - 1, y + ancho + 1); cout << char(200);
    for (int j = 0; j < largo; j++)
    {
        cursor(x, y); cout << char(205);
        cursor(x, y + ancho + 1); cout << char(205);
        x++;
    }
    cursor(x, y); cout << char(187);
    cursor(x, y + ancho + 1); cout << char(188);

    //vertical
    for (int i = 0; i < ancho; i++)
    {

        cursor(z - 1, k); cout << char(186);
        cursor(z + largo, k); cout << char(186);
        k++;
    }

}
void rayita(int x, int y)
{
    cursor(x - 1, y); cout << char(200);
    for (int i = 0; i < 20; i++)
    {

        cursor(x, y); cout << char(205);
        x++;
    }
    cursor(x, y); cout << char(188);
}


void menuMatricula() {

    system("cls");
    Console::ForegroundColor = ConsoleColor::White;
    Estudiante* oEstudiante = getEstudiante();
    vector<string> colaEstudiantes = leerCola();
    vector<string> usuariosRegistrados = leerRegistrados();

    //Verifica que el usuario este registrado -- validación
    for (const auto& i : usuariosRegistrados) {
        if (i == oEstudiante->getIdUsuario()) {
            if (!oEstudiante->getEstadoMatricula()) {
                oEstudiante->setEstadoMatricula(true);
                break;
            }
        }
    }

    //Verifica que si ese estudiante ya está en la cola
    for (const auto& i : colaEstudiantes) {
        if (i == oEstudiante->getIdUsuario()) {
            oEstudiante->setEstadoMatricula(false);
        }
    }

    //Si no está en la cola, se agrega ese usuario a la cola
    if (oEstudiante->getEstadoMatricula()) {
        ingresarCola(oEstudiante);
    }


    vector<string>colaUsuarios = leerCola();
    int w = 1;
    for (const auto& i : colaUsuarios) {
        Console::ForegroundColor = ConsoleColor::DarkGray;
        cursor(120, w + 10); cout << w << ".- " << i << "\n";
        w++;

    }
    Console::ForegroundColor = ConsoleColor::White;

    Codigo codigo(codigoUsuarioActual);
    int cicloUsuario = codigo.getNivelEstudio();
    Ciclo ciclo(cicloUsuario);
    ciclo.determinarCursos();

    cursor(45, 5); cout << " __  __    _  _____ ____  ___ ____ _   _ _        _    ";
    cursor(45, 6); cout << "|  \\/  |  / \\|_   _|  _ \\|_ _/ ___| | | | |      / \\   ";
    cursor(45, 7); cout << "| |\\/| | / _ \\ | | | |_) || | |   | | | | |     / _ \\  ";
    cursor(45, 8); cout << "| |  | |/ ___ \\| | |  _ < | | |___| |_| | |___ / ___ \\ ";
    cursor(45, 9); cout << "|_|  |_/_/   \\_\\_| |_| \\_\\___\\____|\\___/|_____/_/   \\_\\";

    marcoMatricula();
    marcoOpcion(5, 2, 5, 3, 20, 1);
    cursor(6, 3); cout << "Ciclo: " << codigo.getNivelEstudio();
    marcoOpcion(119, 2, 119, 3, 20, 1);
    cursor(120, 3); cout << "Codigo: " << to_string(codigoUsuarioActual);
    Console::ForegroundColor = ConsoleColor::DarkGray;
    marcoOpcion(119, 10, 119, 11, 21, w - 1); //Descripcion de la cola
    Console::ForegroundColor = ConsoleColor::White;
    marcoOpcion(119, 8, 119, 9, 21, 1);
    cursor(120, 9); cout << "Cola de estudiantes";

    //Cursos matriculados
    marcoOpcion(5, 8, 5, 9, 20, 1);
    cursor(6, 9); cout << "Lista cursos";

    //Marco de Guardar
    marcoOpcion(119, 35, 119, 36, 20, 1);
    cursor(120, 36); cout << "Guardar";

    cursor(30, 25); cout << "SELECCION DE CURSOS";
    for (int i = 0; i < 25; i++)
    {
        Console::ForegroundColor = ConsoleColor::DarkGray;
        cursor(i + 30, 26); cout << char(196);
        Console::ForegroundColor = ConsoleColor::White;
    }

    // Guardar subcursos seleccionados
    vector<Curso*> seleccionados;

    // Recolectar todos los cursos principales en vector seguro
    vector<Curso*> cursosPrincipales;
    Nodo<Curso*>* actual = ciclo.getCursos()->getInicio();

    int y = 11;
    int l = 0;

    while (actual) {
        cursosPrincipales.push_back(actual->valor);
        actual = actual->siguiente;
    }
    int j = 0;
    for (int i = 0; i < cursosPrincipales.size(); i++) {
        Curso* principal = cursosPrincipales[i];
        if (!principal) continue;

        int xBase = 40;
        int yBase = 17;

        // Mostrar cursos principales

        if (j == i)
            Console::ForegroundColor = ConsoleColor::Yellow;
        else
            Console::ForegroundColor = ConsoleColor::White;
        ////5 + j * 28 
        ciclo.mostrarCursoEnCuadro(cursosPrincipales[j], 55, 12);

        // Crear subcursos de ejemplo, luego le ponemos a cada curso mas subcursos 
        vector<Curso*> subCursos;
        System::Random r;
        string NRCr_A = to_string(r.Next(100, 1000));
        string NRCr_B = to_string(r.Next(100, 1000));
        string NRCr_C = to_string(r.Next(100, 1000));

        int credA = r.Next(3, 7);
        int credB = r.Next(3, 7);
        int credC = r.Next(3, 7);
        
        char rPab_A = char(r.Next(65, 68));
        char rPab_B = char(r.Next(65, 68));
        char rPab_C = char(r.Next(65, 68));

        int pisoA = r.Next(1, 9);
        int pisoB = r.Next(1, 9);
        int pisoC = r.Next(1, 9);

        int salonA = r.Next(1, 16);
        int salonB = r.Next(1, 16);
        int salonC = r.Next(1, 16);

        subCursos.push_back(new Curso(NRCr_A, principal->getNombre() + " ", new Profesor("Mario", "Lopez"), credA, new Horario("10:00", "12:00"), new Salon(pisoA, salonA, new Pabellon(rPab_A))));
        subCursos.push_back(new Curso(NRCr_B, principal->getNombre() + " ", new Profesor("Elena", "Perez"), credB, new Horario("20:00", "21:00"), new Salon(pisoB, salonB, new Pabellon(rPab_B))));
        subCursos.push_back(new Curso(NRCr_C, principal->getNombre() + " ", new Profesor("Robert", "Cruz"), credC, new Horario("07:00", "09:00"), new Salon(pisoC, salonC, new Pabellon(rPab_C))));



        // Seleccionar subcurso
        Curso* subSeleccionado = seleccionarSubCursoHorizontal(subCursos, xBase, yBase);

        if (subSeleccionado) {
            seleccionados.push_back(subSeleccionado);
            Console::ForegroundColor = ConsoleColor::White;
            cursor(30, 27 + seleccionados.size() + l);
            cout << i + 1 << ".- " << subSeleccionado->getNombre();

            Console::ForegroundColor = ConsoleColor::White;
            cursor(5, y);     cout << i + 1 << ". NRC: " << subSeleccionado->getNRC();
            cursor(5, y + 1); cout << "   HoraIni: " << subSeleccionado->getHorario()->getHoraInicio();
            cursor(5, y + 2); cout << "   HoraFin: " << subSeleccionado->getHorario()->getHoraFin();
            cursor(5, y + 3); cout << "   Profesor: " << subSeleccionado->getProfesor()->getNombre();

            Console::ForegroundColor = ConsoleColor::DarkGray;

            marcoOpcion(5, y - 1, 5, y, 20, 4);

            if (y > 15)
            {
                Console::ForegroundColor = ConsoleColor::DarkGray;
                rayita(5, y - 1);
            }
            else
            {
                Console::ForegroundColor = ConsoleColor::White;
                rayita(5, y - 1);
            }
            Console::ForegroundColor = ConsoleColor::White;

           /* if (seleccionados.size() >= 1) {
                cursor(30, 38); cout << "Ya agregaste un curso";
                cursor(30, 36); cout << seleccionados.size();
                char t = _getch();

                if (t == '1') {
                    cursor(70, 38); cout << "Oprimio tecla 1";
                    break;
                }
            }*/
        }
        l = l + 1;
        y = y + 5;

        j++;

    }

    //Marco de Guardar
    Console::ForegroundColor = ConsoleColor::Yellow;
    marcoOpcion(119, 35, 119, 36, 20, 1);
    cursor(120, 36); cout << "Guardar";


    Lista<Curso*>* listaCursos = new Lista<Curso*>();
    HashTabla<vector<Curso*>>* tablaDeEstudiantes = new HashTabla<vector<Curso*>>();

    for (int i = 0; i < seleccionados.size(); i++) {
        if (listaCursos->esVacia()) {
            listaCursos->agregarInicial(seleccionados[i]);
        }
        else {
            listaCursos->agregarFinal(seleccionados[i]);
        }

    }

    oEstudiante->setCursosSeleccionados(listaCursos);

    //Se obtiene el id del usuario del momento string -> int
    int auxIDEstudiante = stoi(oEstudiante->getIdUsuario());

    //Se inserta el id del usuario como clave y sus cursos como valor
    tablaDeEstudiantes->insertar(auxIDEstudiante, oEstudiante->CursosEstudiantes());




    Console::ForegroundColor = ConsoleColor::White;
    verificar(BLACK);
    system("pause>0");
    system("cls");
}
