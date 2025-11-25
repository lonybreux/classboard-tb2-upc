#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <map>
#include <string>
#include "Estudiante.h"
#include <sstream>
#include "Global.h"  


#define NOMBRE_ARCHIVO "registro.csv"
#define NOMBRE_COLA "cola_matricula.txt"

using namespace std;

Estudiante* oEstudiante = new Estudiante();

vector<string> leerColaLogin() {
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

void cursor(int x, int y) {
    System::Console::SetCursorPosition(x, y);
}

void registroUSER(Usuario* oEstudiante) {
    ofstream arc;

    arc.open(NOMBRE_ARCHIVO, ios::app);

    arc << oEstudiante->getIdUsuario() << "," << oEstudiante->getContraseña() << endl;

    arc.close();
}

bool inicioUSER(string u, string c) {
    ifstream arc;

    arc.open(NOMBRE_ARCHIVO, ios::in);
    vector<string> vCola = leerColaLogin();
    string linea;
    map<string, string>verificacion; //Guarda clave - valor
    bool encontrado = false;

    if (arc.is_open()) {
        while (getline(arc, linea)) { // mientras se este leyendo las lineas del archivo
            string USER_r, contraseña_r;
            stringstream ss(linea);// stringstream ss: variable 
            //que recorre un string y lo descompone en partes, podemos sacar partes de un string, 
           // aqui le decimos que agarre linea que ya esta seteado con getline 

            getline(ss, USER_r, ','); // le decimos que agarre ese string    
            // descompuesto y que guarde lo que haya hasta que encuentre una coma en variable USER
            getline(ss, contraseña_r, ',');


            verificacion[USER_r] = contraseña_r;
        }
    }

    arc.close();

    for (const auto& i : verificacion) { //se recorre el mapa, se toma valores por referencia para optimizar el uso de memoria, const porque los valores no se modificarán
        if (u == i.first && c == i.second) { //si el user ingresado es igual a la clave user y si la contraseña ingresada es igual a valor contraseña
            codigoUsuarioActual = stoll(u);
            System::Console::ForegroundColor = System::ConsoleColor::Green;
            cursor(62, 37); cout << "Inicio de sesion exitosa...";
            encontrado = true;

            break;
        }
    }

    oEstudiante->setIdUsuario(u);
    oEstudiante->setContraseña(c);



    if (!encontrado) {
        System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
        cursor(58, 37); cout << "Usuario o contrasena incorrectas";
    }
    return encontrado;
}
void nombreProgramaYlogo()
{
    System::Console::ForegroundColor = System::ConsoleColor::White;
    cursor(27, 4); cout << ".______    __          ___       ______  __  ___ .______     ______	     ___      .______    _______     ";
    cursor(27, 5); cout << "|   _  \\  |  |        /   \\     /      ||  |/  / |   _  \\   /  __  \\     /   \\     |   _  \\  |       \\ ";
    cursor(27, 6); cout << "|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /  |  |_)  | |  |  |  |   /  ^  \\    |  |_)  | |  .--.  |";
    cursor(27, 7); cout << "|   _  <  |  |      /  /_\\  \\  |  |     |    <   |   _  <  |  |  |  |  /  /_\\  \\   |      /  |  |  |  |";
    cursor(27, 8); cout << "|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\  |  |_)  | |  `--'  | /  _____  \\  |  |\\  \\  |  '--'  |";
    cursor(27, 9); cout << "|______/  |_______/__/     \\__\\ \\______||__|\\__\\ |______/   \\______/ /__/     \\__\\ | _| `._| |_______/ ";

    System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
    cursor(60, 1 + 12 - 1); cout << "           +            " << endl;
    cursor(60, 1 + 13 - 1); cout << "         +++            " << endl;
    cursor(60, 1 + 14 - 1); cout << "    ++  ++++       +    " << endl;
    cursor(60, 1 + 15 - 1); cout << "  +++   ++++++     +++  " << endl;
    cursor(60, 1 + 16 - 1); cout << "  ++    ++++++++    ++  " << endl;
    cursor(60, 1 + 17 - 1); cout << " ++++    +++++++   ++++ " << endl;
    cursor(60, 1 + 18 - 1); cout << " +++++     +++++  +++++ " << endl;
    cursor(60, 1 + 19 - 1); cout << "  +++++     +++  +++++  " << endl;
    cursor(60, 1 + 20 - 1); cout << "   +++++++++++++++++++  " << endl;
    cursor(60, 1 + 21 - 1); cout << "    ++++++++++++++++    " << endl;
    cursor(60, 1 + 22 - 1); cout << "      ++++++++++++      " << endl;
    cursor(60, 1 + 23 - 1); cout << "          ++++";

}
void marcoLogin(int largo, int ancho, int x, int y)
{
    cursor(x, y); cout << char(218);
    cursor(x, y + ancho); cout << char(192);

    for (int i = 0; i < largo; i++)
    {
        cursor(x + i + 1, y); cout << char(196);
        cursor(x + i + 1, y + ancho); cout << char(196);
        if (i >= largo - 1)
        {
            cursor(x + i + 2, y); cout << char(191);
            cursor(x + i + 2, y + ancho); cout << char(217);
        }
    }

    for (int j = 0; j < ancho - 1; j++)
    {
        cursor(x, y + j + 1); cout << char(179);
        cursor(x + largo + 1, y + j + 1); cout << char(179);
    }


}

bool Login() {
    while (true) {
        int x = 50;
        int y = 22;
        bool inicio = false;
        bool registro = false;
        System::Console::CursorVisible = false;
        System::Console::SetWindowSize(145, 40);

        nombreProgramaYlogo();


        System::Console::ForegroundColor = System::ConsoleColor::Yellow;
        marcoLogin(36, 2, 55, 27);
        cursor(65, 28); cout << "ESTUDIANTE|DOCENTE";


        System::Console::ForegroundColor = System::ConsoleColor::White;
        marcoLogin(36, 2, 55, 32);
        cursor(63, 33); cout << "REGISTRARSE COMO ALUMNO";


        while (true) {

            if (kbhit()) {

                char t = _getch();

                if (t == 'w') {
                    y = 22;

                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                    marcoLogin(36, 2, 55, 27);
                    cursor(65, 28); cout << "ESTUDIANTE|DOCENTE";

                    System::Console::ForegroundColor = System::ConsoleColor::White;
                    marcoLogin(36, 2, 55, 32);
                    cursor(63, 33); cout << "REGISTRARSE COMO ALUMNO";
                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                }
                else if (t == 's') {

                    y = 27;

                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                    cursor(63, 33); cout << "REGISTRARSE COMO ALUMNO";
                    marcoLogin(36, 2, 55, 32);


                    System::Console::ForegroundColor = System::ConsoleColor::White;
                    cursor(65, 28); cout << "ESTUDIANTE|DOCENTE";
                    marcoLogin(36, 2, 55, 27);

                }

                if (y == 22 && t == char(32)) {
                    system("cls");
                    inicio = true;
                    break;

                }
                else if (y == 27 && t == char(32)) {
                    system("cls");
                    registro = true;
                    break;
                }
            }
        }

        if (inicio && !registro) {
            System::Console::CursorVisible = true;
            string USER;
            string contraseña;

            nombreProgramaYlogo();


            System::Console::ForegroundColor = System::ConsoleColor::White;
            cursor(55, 28); cout << "Codigo de estudiante";
            marcoLogin(36, 2, 55, 29);

            cursor(55, 33); cout << "Contrasena";
            marcoLogin(36, 2, 55, 34);

            cursor(57, 30); cin >> USER;
            cursor(57, 35); cin >> contraseña;

            System::Console::CursorVisible = false;

            if (USER == "pc" && contraseña == "1")
            {
                system("cls");
                return false;
            }


            //inicioUSER(USER,contraseña);
            if (inicioUSER(USER, contraseña)) {
                // login correcto => salimos de Login para que main llame al menú principal
                // damos un pequeño tiempo para que el usuario vea el mensaje
                _getch();
                system("cls");
                return true;
            }
            else {
                // login fallido: esperamos que usuario presione una tecla y volvemos al menú
                _getch();
                system("cls");
                continue; // vuelve al inicio del while exterior (menú)
            }
        }
        else if (!inicio && registro) {
            System::Console::CursorVisible = true;
            string USER_r;
            string contraseña_r;

            nombreProgramaYlogo();


            System::Console::ForegroundColor = System::ConsoleColor::White;
            cursor(55, 28); cout << "Registre codigo de alumno (9 digitos)";
            marcoLogin(36, 2, 55, 29);


            cursor(55, 33); cout << "Registre Contrase" << char(164) << "a";
            marcoLogin(36, 2, 55, 34);

            do
            {
                cursor(57, 30); cout << "                    ";
                cursor(57, 30); cin >> USER_r;

            } while (stoll(USER_r) < 100000000 || stoll(USER_r) > 1000000000);

            cursor(57, 35); cin >> contraseña_r;

            oEstudiante->setIdUsuario(USER_r);
            oEstudiante->setContraseña(contraseña_r);

            registroUSER(oEstudiante);
            System::Console::ForegroundColor = System::ConsoleColor::Green;
            cursor(66, 37); cout << "Registro exitoso.";
            System::Console::ForegroundColor = System::ConsoleColor::White;
            cursor(55, 38); cout << "Presione una tecla para volver al login...";
            _getch();
            system("cls");
            continue;
            System::Console::CursorVisible = false;
        }
    }
}

Estudiante* getEstudiante() {
    return oEstudiante;
}