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
            cursor(62, 35); cout << "Inicio de sesion exitosa...";
            encontrado = true;

            break;
        }
    }

    oEstudiante->setIdUsuario(u);
    oEstudiante->setContraseña(c);



    if (!encontrado) {
        cursor(58, 35); cout << "Usuario o contrasena incorrectas";
    }
    return encontrado;
}

bool Login() {
    while (true) {
        int x = 50;
        int y = 22;
        bool inicio = false;
        bool registro = false;
        System::Console::CursorVisible = false;
        System::Console::SetWindowSize(145, 40);
        System::Console::ForegroundColor = System::ConsoleColor::White;


        cursor(27, 4);    cout << "           /$$                              /$$$$$$$                                      /$$";
        cursor(27, 5); cout << "          | $$                             | $$__  $$                                    | $$";
        cursor(27, 6); cout << "  /$$$$$$$| $$  /$$$$$$   /$$$$$$$ /$$$$$$$| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$";
        cursor(27, 7); cout << " /$$_____/| $$ |____  $$ /$$_____//$$_____/| $$$$$$$  /$$__  $$ |____  $$ /$$__  $$ /$$__  $$";
        cursor(27, 8); cout << "| $$      | $$  /$$$$$$$|  $$$$$$|  $$$$$$ | $$__  $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$  | $$";
        cursor(27, 9); cout << "| $$      | $$ /$$__  $$ \\____  $$\\____  $$| $$  \\ $$| $$  | $$ /$$__  $$| $$      | $$  | $$";
        cursor(27, 10); cout << "|  $$$$$$$| $$|  $$$$$$$ /$$$$$$$//$$$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$$| $$      |  $$$$$$$";
        cursor(27, 11); cout << " \\_______/|__/ \\_______/|_______/|_______/ |_______/  \\______/  \\_______/|__/       \\_______/";

        System::Console::ForegroundColor = System::ConsoleColor::Yellow;
        cursor(67, 22); cout << "INICIAR SESION";
        cursor(55, 21); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(191);
        cursor(55, 22); cout << char(179);
        cursor(92, 22); cout << char(179);
        cursor(55, 23); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(217);

        System::Console::ForegroundColor = System::ConsoleColor::White;
        cursor(63, 27); cout << "REGISTRARSE COMO ALUMNO";
        cursor(55, 26); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(191);
        cursor(55, 27); cout << char(179);
        cursor(92, 27); cout << char(179);
        cursor(55, 28); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
            << char(196) << char(196) << char(196) << char(196) << char(217);


        while (true) {

            if (kbhit()) {

                char t = _getch();

                if (t == 'w') {
                    y = 22;

                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                    cursor(67, 22); cout << "INICIAR SESION";
                    cursor(55, 21); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(191);
                    cursor(55, 22); cout << char(179);
                    cursor(92, 22); cout << char(179);
                    cursor(55, 23); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(217);

                    System::Console::ForegroundColor = System::ConsoleColor::White;
                    cursor(63, 27); cout << "REGISTRARSE COMO ALUMNO";
                    cursor(55, 26); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(191);
                    cursor(55, 27); cout << char(179);
                    cursor(92, 27); cout << char(179);
                    cursor(55, 28); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(217);
                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                }
                else if (t == 's') {

                    y = 27;

                    System::Console::ForegroundColor = System::ConsoleColor::Yellow;
                    cursor(63, 27); cout << "REGISTRARSE COMO ALUMNO";
                    cursor(55, 26); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(191);
                    cursor(55, 27); cout << char(179);
                    cursor(92, 27); cout << char(179);
                    cursor(55, 28); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(217);


                    System::Console::ForegroundColor = System::ConsoleColor::White;
                    cursor(67, 22); cout << "INICIAR SESION";
                    cursor(55, 21); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(191);
                    cursor(55, 22); cout << char(179);
                    cursor(92, 22); cout << char(179);
                    cursor(55, 23); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                        << char(196) << char(196) << char(196) << char(196) << char(217);

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
            System::Console::ForegroundColor = System::ConsoleColor::White;
            System::Console::CursorVisible = true;
            string USER;
            string contraseña;

            cursor(27, 4);    cout << "           /$$                              /$$$$$$$                                      /$$";
            cursor(27, 5); cout << "          | $$                             | $$__  $$                                    | $$";
            cursor(27, 6); cout << "  /$$$$$$$| $$  /$$$$$$   /$$$$$$$ /$$$$$$$| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$";
            cursor(27, 7); cout << " /$$_____/| $$ |____  $$ /$$_____//$$_____/| $$$$$$$  /$$__  $$ |____  $$ /$$__  $$ /$$__  $$";
            cursor(27, 8); cout << "| $$      | $$  /$$$$$$$|  $$$$$$|  $$$$$$ | $$__  $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$  | $$";
            cursor(27, 9); cout << "| $$      | $$ /$$__  $$ \\____  $$\\____  $$| $$  \\ $$| $$  | $$ /$$__  $$| $$      | $$  | $$";
            cursor(27, 10); cout << "|  $$$$$$$| $$|  $$$$$$$ /$$$$$$$//$$$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$$| $$      |  $$$$$$$";
            cursor(27, 11); cout << " \\_______/|__/ \\_______/|_______/|_______/ |_______/  \\______/  \\_______/|__/       \\_______/";

            cursor(55, 22); cout << "Nombre de usuario";
            cursor(55, 23); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(191);
            cursor(55, 24); cout << char(179);
            cursor(92, 24); cout << char(179);
            cursor(55, 25); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(217);


            cursor(55, 27); cout << "Contrasena";
            cursor(55, 28); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(191);
            cursor(55, 29); cout << char(179);
            cursor(92, 29); cout << char(179);
            cursor(55, 30); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(217);

            cursor(57, 24); cin >> USER;
            cursor(57, 29); cin >> contraseña;


            System::Console::CursorVisible = false;

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


            cursor(27, 4);    cout << "           /$$                              /$$$$$$$                                      /$$";
            cursor(27, 5); cout << "          | $$                             | $$__  $$                                    | $$";
            cursor(27, 6); cout << "  /$$$$$$$| $$  /$$$$$$   /$$$$$$$ /$$$$$$$| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$";
            cursor(27, 7); cout << " /$$_____/| $$ |____  $$ /$$_____//$$_____/| $$$$$$$  /$$__  $$ |____  $$ /$$__  $$ /$$__  $$";
            cursor(27, 8); cout << "| $$      | $$  /$$$$$$$|  $$$$$$|  $$$$$$ | $$__  $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$  | $$";
            cursor(27, 9); cout << "| $$      | $$ /$$__  $$ \\____  $$\\____  $$| $$  \\ $$| $$  | $$ /$$__  $$| $$      | $$  | $$";
            cursor(27, 10); cout << "|  $$$$$$$| $$|  $$$$$$$ /$$$$$$$//$$$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$$| $$      |  $$$$$$$";
            cursor(27, 11); cout << " \\_______/|__/ \\_______/|_______/|_______/ |_______/  \\______/  \\_______/|__/       \\_______/";

            cursor(55, 22); cout << "Registre codigo de alumno (9 digitos)";
            cursor(55, 23); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(191);
            cursor(55, 24); cout << char(179);
            cursor(92, 24); cout << char(179);
            cursor(55, 25); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(217);


            cursor(55, 27); cout << "Registre Contrasena";
            cursor(55, 28); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(191);
            cursor(55, 29); cout << char(179);
            cursor(92, 29); cout << char(179);
            cursor(55, 30); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
                << char(196) << char(196) << char(196) << char(196) << char(217);

            do
            {
                cursor(57, 24); cout << "                    ";
                cursor(57, 24); cin >> USER_r;

            } while (stoll(USER_r) < 100000000 || stoll(USER_r) > 1000000000);

            cursor(57, 29); cin >> contraseña_r;

            oEstudiante->setIdUsuario(USER_r);
            oEstudiante->setContraseña(contraseña_r);

            registroUSER(oEstudiante);
            cursor(66, 31); cout << "Registro exitoso.";
            cursor(55, 32); cout << "Presione una tecla para volver al login...";
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