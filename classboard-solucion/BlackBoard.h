#pragma once
#include <iostream>
#include "Codigo.h"
#include "Curso.h"
#include "Ciclo.h"
#include "Global.h"
#include <string>
#include "Login.h"
#include "Pila.h"  
#include "Grafo.h"


using namespace std;
using namespace System;

CGrafo<string>* malla = new CGrafo<string>();

//RECURSIVA
int sumatoria(vector<int>& v, int n) {
	if (n == 0)
		return 0;

	return v[n - 1] + sumatoria(v, n - 1);
}

void const perfil(int cod) {
	Codigo* aux = new Codigo(cod);
	Console::ForegroundColor = ConsoleColor::White;

	cursor(30, 3); cout << "PERFIL";

	cursor(70, 10); cout << "	     .::::::::::.		";
	cursor(70, 11); cout << "	   .::::::::::::::.		";
	cursor(70, 12); cout << "	 .::::::::::::::::::.	";
	cursor(70, 13); cout << "	.:::::::======:::::::.	";
	cursor(70, 14); cout << "	::::::-========-::::::	";
	cursor(70, 15); cout << "	::::::-========-::::::	";
	cursor(70, 16); cout << "	:::::::-======-:::::::	";
	cursor(70, 17); cout << "	:::::::::----:::::::::	";
	cursor(70, 18); cout << "	 :::::-========-:::::	";
	cursor(70, 19); cout << "	  ::-============-::	";
	cursor(70, 20); cout << "	   :==============:		";
	cursor(70, 21); cout << "       .--======--.		";

	Console::ForegroundColor = ConsoleColor::Blue;

	cursor(80, 13); cout << "======";
	cursor(78, 14); cout << "-========-";
	cursor(78, 15); cout << "-========-";
	cursor(79, 16); cout << "-======-";
	cursor(81, 17); cout << "----";
	cursor(78, 18); cout << "-========-";
	cursor(76, 19); cout << "-============-";
	cursor(76, 20); cout << "==============";
	cursor(77, 21); cout << ".--======--.";

	Console::ForegroundColor = ConsoleColor::White;
	cursor(78, 25); cout << to_string(cod);
	cursor(67, 28), cout << "Carrera: Ingenieria de Software";
	cursor(73, 31); cout << "Nivel de estudio: "; cout << aux->getNivelEstudio();
}


void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void dibujarRectangulo(int x, int y, int ancho, int alto, int color = 7) {
	setColor(color);

	// Esquinas
	cursor(x, y); cout << "+";
	cursor(x + ancho - 1, y); cout << "*";
	cursor(x, y + alto - 1); cout << "*";
	cursor(x + ancho - 1, y + alto - 1); cout << "*";

	// Bordes horizontales
	for (int i = 1; i < ancho - 1; i++) {
		cursor(x + i, y); cout << "-";
		cursor(x + i, y + alto - 1); cout << "-";
	}

	for (int i = 1; i < alto - 1; i++) {
		cursor(x, y + i); cout << "|";
		for (int j = 1; j < ancho - 1; j++) {
			cursor(x + j, y + i);
			cout << " ";
		}
		cursor(x + ancho - 1, y + i); cout << "|";
	}

	setColor(7);
}

int index = 0;
void paginaPrincipal() {

	int x = 30, y = 7, ancho = 110, alto = 7;

	vector<string> mensajes = {
		"SEMANA UNIVERSITARIA",
		"VERANO UPC 2026",
		"ANUNCIOS UPC"
	};

	dibujarRectangulo(x, y, ancho, alto);
	// Texto centrado
	string msg = mensajes[index];
	cursor(x + (ancho / 2) - (msg.size() / 2), y + (alto / 2));
	cout << msg;

	// Flechas de adorno
	cursor(x + 2, y + (alto / 2));
	cout << "<<";
	cursor(x + ancho - 4, y + (alto / 2));
	cout << ">>";

	// --- Cuadros pequeños que cambian según index ---
	if (index == 0) {
		// ---- SEMANA UNIVERSITARIA ----
		dibujarRectangulo(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Dia del deporte";

		dibujarRectangulo(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Concurso";

		dibujarRectangulo(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Concierto";

		dibujarRectangulo(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Feria";

		dibujarRectangulo(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Taller danza";

		dibujarRectangulo(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Teatro";


		int gx = x + 77;
		int gy = y + alto + 5;
		int dx = 1;
		int dy = 1;
		int rectX = x + 75;
		int rectY = y + alto + 3;
		int rectW = 35;
		int rectH = 12;
		dibujarRectangulo(rectX, rectY, rectW, rectH);
		static vector<string> gato = {
			"   ***   ",
"  *   *  ",
" *  o  * ",
"  *   *  ",
"   ***   "
		};


		// Dibujar gato
		for (int k = 0; k < gato.size(); k++) {
			cursor(gx, gy + k);
			cout << gato[k];
		}

		// Actualizar posición (una vez por llamada)
		gx += dx;
		gy += dy;

		// Rebote en bordes
		if (gx <= rectX + 1 || gx + (int)gato[0].size() >= rectX + rectW - 1)
			dx = -dx;
		if (gy <= rectY + 1 || gy + (int)gato.size() >= rectY + rectH - 1)
			dy = -dy;


	}
	else if (index == 1) {
		// ---- VERANO UPC ----
		dibujarRectangulo(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Cursos verano";

		dibujarRectangulo(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Deportes playa";

		dibujarRectangulo(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Viajes UPC";



		dibujarRectangulo(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Conferencias";

		dibujarRectangulo(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Taller verano";

		dibujarRectangulo(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Becas verano";


		static int rectX = x + 75;
		static int rectY = y + alto + 3;
		static int rectW = 35;
		static int rectH = 12;
		static int gx = rectX + 2;
		static int gy = rectY + 2;
		static int dx = 1;
		static int dy = 1;

		dibujarRectangulo(rectX, rectY, rectW, rectH);

		vector<string> sol = {
			"  \\ | /  ",
			" -- O -- ",
			"  / | \\  "
		};

		// Limpiar solo el área del sol
		//for (int i = 1; i < rectH - 1; i++) {
		//	cursor(rectX + 1, rectY + i);
		//	cout << string(rectW - 2, ' ');
		//}
		//
		//// Dibujar el sol
		for (int k = 0; k < sol.size(); k++) {
			cursor(gx, gy + k);
			cout << sol[k];
		}
		//
		//// Actualizar posición
		//gx += dx;
		//gy += dy;
		//
		//// Rebote horizontal
		//if (gx <= rectX + 1 || gx + (int)sol[0].size() >= rectX + rectW - 1)
		//	dx = -dx;
		//
		//// Rebote vertical
		//if (gy <= rectY + 1 || gy + (int)sol.size() >= rectY + rectH - 1)
		//	dy = -dy;

	}
	else if (index == 2) {
		// ---- ANUNCIOS UPC ----
		dibujarRectangulo(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Pago cuotas";

		dibujarRectangulo(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Nuevo curso";

		dibujarRectangulo(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Invitacion";



		dibujarRectangulo(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Charla UPC";

		dibujarRectangulo(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Seguridad";

		dibujarRectangulo(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Biblioteca";
		//Sleep(5000);

		/*int rectX = x + 75; int rectY = y + alto + 3; int rectW = 35; int rectH = 12;
		dibujarRectangulo(rectX, rectY, rectW, rectH); vector<string> gato = { " ______ ", " / \\ ", "| UPC |", " \\/ " };
		int gx = rectX + 2; int gy = rectY + 2; int dx = 1, dy = 1;
		for (int step = 0; step < 50; step++) {
			for (int i = 1; i < rectH - 1; i++) {
				cursor(rectX + 1, rectY + i); cout << string(rectW - 2, ' '); }
			for (int k = 0; k < gato.size(); k++) {
				cursor(gx, gy + k); cout << gato[k]; }
			gx += dx; gy += dy;
			if (gx <= rectX + 1 || gx + (int)gato[0].size() >= rectX + rectW - 1) {
				dx = -dx; }
			if (gy <= rectY + 1 || gy + (int)gato.size() >= rectY + rectH - 1) {
				dy = -dy; }

			Sleep(100);
		}*/

	}
}

void marco()
{
	cursor(25, 0);
	cout << char(203);
	cursor(25, 39);
	cout << char(202);
	for (int i = 26; i < 144; i++)
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
	}
}
void marcosCurso(int x, int y, int z, int k)
{

	//Horizontal
	cursor(x - 1, y); cout << char(201);
	cursor(x - 1, y + 11); cout << char(200);
	for (int j = 0; j < 35; j++)
	{
		cursor(x, y); cout << char(205);
		cursor(x, y + 11); cout << char(205);
		x++;
	}
	cursor(x, y); cout << char(187);
	cursor(x, y + 11); cout << char(188);

	//vertical
	for (int i = 0; i < 10; i++)
	{
		cursor(z - 1, k); cout << char(186);
		cursor(z + 35, k); cout << char(186);
		k++;
	}

}
void marcoOpcionesCurso(int x, int y, int z, int k)
{
	//Horizontal
	cursor(x - 1, y); cout << char(201);
	cursor(x - 1, y + 4); cout << char(200);
	for (int j = 0; j < 35; j++)
	{
		cursor(x, y); cout << char(205);
		cursor(x, y + 4); cout << char(205);
		x++;
	}

	cursor(x, y); cout << char(187);
	cursor(x, y + 4); cout << char(188);

	//vertical
	for (int i = 0; i < 3; i++)
	{
		cursor(z - 1, k); cout << char(186);
		cursor(z + 35, k); cout << char(186);
		k++;
	}

}
void marcoOpciones(int x, int y, int z, int k)
{
	//Horizontal
	cursor(x - 1, y); cout << char(204);
	cursor(x - 1, y + 5); cout << char(204);
	for (int j = 0; j < 24; j++)
	{
		cursor(x, y); cout << char(205);
		cursor(x, y + 5); cout << char(205);
		x++;
	}
	cursor(x, y); cout << char(185);
	cursor(x, y + 5); cout << char(185);

	//vertical
	for (int i = 0; i < 4; i++)
	{
		cursor(z - 1, k); cout << char(186);
		cursor(z + 24, k); cout << char(186);
		k++;
	}
}
void marcoBaclkBoard() {

	Console::SetWindowSize(145, 40);
	Console::CursorVisible = false;

	//Primera fila
	cout << char(201);
	for (int i = 0; i < 24; i++)
	{
		cout << char(205);
	}
	cursor(25, 0);
	cout << char(187);

	//columnas
	for (int j = 1; j < 39; j++)
	{
		cursor(0, j);
		cout << char(186);
		cursor(25, j);
		cout << char(186);
	}

	//Ultima fila 
	cursor(0, 39);
	cout << char(200);
	cursor(25, 39);
	cout << char(188);
	for (int i = 1; i < 25; i++)
	{
		cursor(i, 39);
		cout << char(205);
	}


	marcoOpciones(1, 14, 1, 15);
	cursor(2, 16); cout << "Malla Curricular";

	marcoOpciones(1, 19, 1, 20);
	cursor(2, 21); cout << "Perfil";

	marcoOpciones(1, 24, 1, 25);
	cursor(2, 26); cout << "Cursos";

	marcoOpciones(1, 29, 1, 30);
	cursor(2, 31); cout << "Calificaciones";

	marcoOpciones(1, 34, 1, 35);
	cursor(2, 36); cout << "Cerrar Sesion";


	//Marco Horizontal del nombre principal de la opcion
	cursor(25, 6); cout << char(204);
	for (int i = 26; i < 144; i++)
	{
		cursor(i, 6); cout << char(205);
	}

	Console::ForegroundColor = ConsoleColor::DarkRed;
	cursor(1, 2 - 1); cout << "           +            " << endl;
	cursor(1, 3 - 1); cout << "         +++            " << endl;
	cursor(1, 4 - 1); cout << "    ++  ++++       +    " << endl;
	cursor(1, 5 - 1); cout << "  +++   ++++++     +++  " << endl;
	cursor(1, 6 - 1); cout << "  ++    ++++++++    ++  " << endl;
	cursor(1, 7 - 1); cout << " ++++    +++++++   ++++ " << endl;
	cursor(1, 8 - 1); cout << " +++++     +++++  +++++ " << endl;
	cursor(1, 9 - 1); cout << "  +++++     +++  +++++  " << endl;
	cursor(1, 10 - 1); cout << "   +++++++++++++++++++  " << endl;
	cursor(1, 11 - 1); cout << "    ++++++++++++++++    " << endl;
	cursor(1, 12 - 1); cout << "      ++++++++++++      " << endl;
	cursor(1, 13 - 1); cout << "          ++++";
	Console::ForegroundColor = ConsoleColor::DarkGray;


	Console::ForegroundColor = ConsoleColor::White;



	marco();
	cursor(144, 6); cout << char(185);
}

void MallaCurricular()
{


	//CICLO 1 
	malla->adicionarVertice("Creatividad y Liderazgo"); //0
	malla->adicionarVertice("Etica y Ciudadania"); //1
	malla->adicionarVertice("Matematica Basica"); //2
	malla->adicionarVertice("Introduccion a los Algoritmos"); //3
	malla->adicionarVertice("CPL I"); //4

	//CICLO 2
	malla->adicionarVertice("Algoritmos"); //5
	malla->adicionarArco(3, 5);
	malla->adicionarVertice("CPL II"); //6
	malla->adicionarArco(4, 6);
	malla->adicionarVertice("Calculo I"); //7
	malla->adicionarArco(2, 7);
	malla->adicionarVertice("Organizacion y Direccion de Empresas"); //8
	malla->adicionarVertice("Seminario de Investigacion Academica I"); //9
	malla->adicionarArco(4, 9);

	//CICLO 3
	malla->adicionarVertice("Disenio y Patrones de Software"); //10
	malla->adicionarArco(5, 10);
	malla->adicionarVertice("Algoritmos y Estructura de Datos"); //11
	malla->adicionarArco(5, 11);
	malla->adicionarVertice("Fisica I"); //12
	malla->adicionarArco(7, 12);
	malla->adicionarVertice("Especificacion Y Analisis de Requerimientos"); //13
	malla->adicionarArco(8, 13);
	malla->adicionarVertice("Matematica Discreta"); //14 
	malla->adicionarArco(3, 14);
	malla->adicionarArco(2, 14);


	//CICLO 4
	malla->adicionarVertice("Arquitectura de Computadoras"); //15
	malla->adicionarArco(14, 15);
	malla->adicionarVertice("Disenio de Base de Datos"); //16
	malla->adicionarArco(10, 16);
	malla->adicionarArco(11, 16);
	malla->adicionarVertice("Fisica II"); //17
	malla->adicionarArco(12, 17);
	malla->adicionarVertice("IHC y Tecnologias Moviles"); //18
	malla->adicionarArco(13, 18);
	malla->adicionarVertice("Matematica Computacional"); //19 
	malla->adicionarArco(14, 19);


	//CICLO 5
	malla->adicionarVertice("Aplicaciones Web"); //20
	malla->adicionarArco(16, 20);
	malla->adicionarVertice("Desarrollo de Aplicaciones Open Source"); //21
	malla->adicionarArco(16, 21);
	malla->adicionarVertice("Calculo II"); //22
	malla->adicionarArco(7, 22);
	malla->adicionarVertice("Sistemas Operativos"); //23 
	malla->adicionarArco(15, 23);
	malla->adicionarArco(18, 23);


	//CICLO 6
	malla->adicionarVertice("Aplicaciones para Dispositivos Moviles"); //24
	malla->adicionarArco(20, 24);
	malla->adicionarVertice("Complejidad Algoritmica"); //25
	malla->adicionarArco(11, 25);
	malla->adicionarVertice("Estadistica Aplicada I"); //26
	malla->adicionarArco(19, 26);
	malla->adicionarVertice("Redes y Comunicaciones de Datos"); //27 
	malla->adicionarArco(23, 27);


	//CICLO 7
	malla->adicionarVertice("Fundamentos de Arquitectura de Software"); //28
	malla->adicionarArco(21, 28);
	malla->adicionarVertice("Desarrollo de Soluciones IoT"); //29
	malla->adicionarArco(24, 29);
	malla->adicionarVertice("Disenio de Experimentos de Ingenieria de Software"); //30
	malla->adicionarArco(26, 30);
	malla->adicionarVertice("Finanzas e Ingenieria Economica"); //31  


	//CICLO 8
	malla->adicionarVertice("Arquitecturas de Software Emergentes"); //32
	malla->adicionarArco(28, 32);
	malla->adicionarVertice("Gerencia de Proyectos en Computacion"); //33
	malla->adicionarVertice("Seminario de Investigacion Academica II"); //34
	malla->adicionarArco(9, 34);
	malla->adicionarVertice("Taller de Desempenio Profesional"); //35
	malla->adicionarArco(30, 35);


	//CICLO 9 
	malla->adicionarVertice("Calidad Y Mejora De Procesos Software"); //36
	malla->adicionarArco(28, 36);
	malla->adicionarVertice("Desarrollo Agil de Productos de Software"); //37
	malla->adicionarArco(32, 37);
	malla->adicionarArco(33, 37);
	malla->adicionarVertice("Taller De Proyecto I"); //38
	malla->adicionarArco(33, 38);
	malla->adicionarArco(35, 38);
	malla->adicionarArco(34, 38);


	//CICLO 10 
	malla->adicionarVertice("Taller De Proyecto II"); //39 
	malla->adicionarArco(38, 39);

	//ADICIONAL
	malla->adicionarVertice("100 Creditos aprobados");//40
	malla->adicionarArco(40, 30);
	malla->adicionarArco(40, 31);
	malla->adicionarVertice("140 Creditos aprobados");//41
	malla->adicionarArco(41, 33);
	malla->adicionarVertice("145 Creditos aprobados");//42
	malla->adicionarArco(42, 34);
	malla->adicionarVertice("Ingles 5");//43
	malla->adicionarArco(43, 35);
	malla->adicionarVertice("Aprobacion por el Director de carrera");//44
	malla->adicionarArco(44, 38);



}
void mostrarMalla()
{
	cursor(45, 7); cout << " __  __       _ _          ____                _            _            ";
	cursor(45, 8); cout << "|  \\/  | __ _| | | __ _   / ___|   _ _ __ _ __(_) ___ _   _| | __ _ _ __  ";
	cursor(45, 9); cout << "| |\\/| |/ _` | | |/ _` | | |  | | | | '__| '__| |/ __| | | | |/ _` | '__| ";
	cursor(45, 10); cout << "| |  | | (_| | | | (_| | | |__| |_| | |  | |  | | (__| |_| | | (_| | |    ";
	cursor(45, 11); cout << "|_|  |_|\\__,_|_|_|\\__,_|  \\____\\__,_|_|  |_|  |_|\\___|\\__,_|_|\\__,_|_|";

	// Número de cursos por ciclo
	int cursosPorCiclo[10] = { 5,5,5,5,4,4,4,4,3,1 };

	int index = 0; // índice global de vértices del grafo
	int valorX = 40;
	int valorY = 14;

	for (int i = 0; i < 10; i++)
	{
		Console::ForegroundColor = ConsoleColor::DarkRed;
		cursor(valorX, valorY); cout << "CICLO " << i + 1;
		Console::ForegroundColor = ConsoleColor::White;
		for (int j = 0; j < cursosPorCiclo[i]; j++)
		{
			cursor(valorX, valorY + j + 2); cout << malla->obtenerVertice(index++);
		}

		valorY += 8;
		if (i == 2)
		{
			valorY = 14;
			valorX = 90;
		}
		if (i == 5)
		{

			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 113; j++)
				{
					cursor(j + 29, i + 14); cout << " ";
				}
			}
			valorY = 14;
			valorX = 40;
		}
		if (i == 8)
		{
			valorX = 100;
			valorY = 14;
		}
		_sleep(650);
	}

	Console::ForegroundColor = ConsoleColor::Red;
	cursor(87, 38); cout << "Presione una tecla para buscar prerrequisito de un curso";
	system("pause>0");
	Console::ForegroundColor = ConsoleColor::White;

}
void BlackBoard()
{
	system("cls");

	marcoBaclkBoard();

	int i = 27;
	int j = 16;
	int estadoMenu = 0;  //0-> menu vertical | 1 -> opciones horizontales
	int opcion = 0;
	int numOpciones = 4;
	int salto = 5;

	Console::ForegroundColor = ConsoleColor::Gray;
	cursor(i, j + opcion * salto);
	cout << "<";

	int opcionSuperior = 0;
	int saltoSuperior = 40;
	int a = 5;
	int b = 12;
	bool cursos = false;

	string nombre;
	int n = 0;
	Console::ForegroundColor = ConsoleColor::DarkRed;
	marcoOpciones(1, 14, 1, 15);
	cursor(2, 16); cout << "Malla Curricular";

	string curso;
	bool orden[2] = { true, true };
	bool activ[2] = { false, false };
	MallaCurricular();
	while (true) {

		if (_kbhit()) {
			char t = _getch();
			Estudiante* oE = getEstudiante();
			Lista<Curso*>* aux = oE->getCursos();
			vector<Curso*>auxV;
			vector<Curso*> resultados;
			Curso* temp;

			bool estaEnPaginaPrincipal = false;
			if (estadoMenu == 0)
			{
				estaEnPaginaPrincipal = true;

				cursor(i, j + opcion * salto);
				cout << " ";

				// Movimiento del cursor en el menú lateral
				if (t == 'w') {
					if (opcion > 0) opcion--;
				}
				else if (t == 's') {
					if (opcion < numOpciones) opcion++;
				}

				cursor(i, j + opcion * salto);
				cout << "<";


				Console::ForegroundColor = ConsoleColor::White;

				marcoOpciones(1, 14, 1, 15); cursor(2, 16); cout << "Malla Curricular";
				marcoOpciones(1, 19, 1, 20); cursor(2, 21); cout << "Perfil";
				marcoOpciones(1, 24, 1, 25); cursor(2, 26); cout << "Cursos";
				marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Calificaciones";
				marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion";


				switch (opcion) {
				case 0: marcoOpciones(1, 14, 1, 15); cursor(2, 16); cout << "Malla Curricular"; break;
				case 1: marcoOpciones(1, 19, 1, 20); cursor(2, 21); cout << "Perfil"; break;
				case 2: marcoOpciones(1, 24, 1, 25); cursor(2, 26); cout << "Cursos"; break;
				case 3: marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Calificaciones"; break;
				case 4: marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion"; break;
				}

				if (opcion == 0)
				{
					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Malla Curricular";
					Console::ForegroundColor = ConsoleColor::White;

					if (t == char(32)) {
						system("cls");

						index = (index - 1 + 3) % 3;
						marcoBaclkBoard();
						cursor(30, 3); cout << "MALLA CURRICULAR";


						mostrarMalla();
						for (int i = 0; i < 25; i++)
						{
							for (int j = 0; j < 114; j++)
							{
								cursor(j + 29, i + 14); cout << " ";
							}
						}

						while (cin.rdbuf()->in_avail() > 0)
						{
							cin.get();
						}

						cursor(30, 18); cout << "Ingrese curso: ";
						Console::ForegroundColor = ConsoleColor::DarkGray;
						getline(cin, curso);

						vector<CVertice<string>*> aux;

						aux = malla->getPrerrequisitos(curso);

						int j = 22;
						if (aux.size() == 0) {
							Console::ForegroundColor = ConsoleColor::DarkRed;
							cursor(30, 20); cout << "No tiene prerrequisitos";
						}
						else {
							for (const CVertice<string>* i : aux) {
								Console::ForegroundColor = ConsoleColor::DarkRed;
								cursor(40, 21); cout << "Prerrequisitos: ";
								Console::ForegroundColor = ConsoleColor::Gray;
								cursor(40, j); cout << " - " << i->info << "\n";
								j++;
							}
						}



					}

				}

				if (t == 'd' && opcion == 2 && cursos == true)
				{
					cursor(27, 26); cout << " ";
					estadoMenu = 1;
					opcionSuperior = 0;
					cursor(a + opcionSuperior * saltoSuperior, b);
					cout << "^";

				}

				else if (opcion == 1)
				{
					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";
					Console::ForegroundColor = ConsoleColor::White;
				}

				else if (opcion == 2)
				{

					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";
					Console::ForegroundColor = ConsoleColor::White;
				}
				else if (opcion == 3)
				{

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Calificaciones";
					Console::ForegroundColor = ConsoleColor::White;
				}
				else if (opcion == 4)
				{
					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";
					Console::ForegroundColor = ConsoleColor::White;
				}


				if (t == 'd' && opcion == 2 && cursos == true)
				{
					cursor(27, 26); cout << " ";
					estadoMenu = 1;
					opcionSuperior = 0;
					cursor(a + opcionSuperior * saltoSuperior, b);
					cout << "^";

				}

			}

			if (estadoMenu == 1)
			{

				cursor(a + opcionSuperior * saltoSuperior, b);
				cout << " ";

				if (t == 'a') {
					if (opcionSuperior > 0) opcionSuperior--;
				}
				else if (t == 'd') {
					if (opcionSuperior < 3) opcionSuperior++;
				}


				if (opcionSuperior == 0)
				{
					Console::ForegroundColor = ConsoleColor::White;

					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";

					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";

				}
				else if (opcionSuperior == 1)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";

					marcoOpcionesCurso(68, 7, 68, 8);
					cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";

					marcoOpcionesCurso(106, 7, 106, 8);
					cursor(107, 9); cout << " ORDENAR POR NRC              V";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";

				}
				else if (opcionSuperior == 2)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";

					marcoOpcionesCurso(106, 7, 106, 8);
					cursor(107, 9); cout << " ORDENAR POR NRC              V";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpcionesCurso(68, 7, 68, 8);
					cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
				}
				else if (opcionSuperior == 3)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpcionesCurso(68, 7, 68, 8);
					cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";

					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpcionesCurso(106, 7, 106, 8);
					cursor(107, 9); cout << " ORDENAR POR NRC              V";

				}

				cursor(a + opcionSuperior * saltoSuperior, b); cout << "^";

				if (t == 'a' && opcionSuperior == 0) {

					cursor(a + opcionSuperior * saltoSuperior, b);
					cout << " ";
					estadoMenu = 0;

					cursor(i, j + opcion * salto);
					cout << "<";
				}

			}

			if (t == char(32) && (opcion >= 0 && opcion <= 3))
			{


				bool yaBusco = false;

				for (int i = 0; i < aux->longitud(); i++) {
					auxV.push_back(aux->obtenerPos(i));
				}

				//PARA IMPRIMIR LOS CURSOS
				int auxX = 40;
				int auxY = 20;
				switch (opcion) {

				case 1:

					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoard();
					perfil(codigoUsuarioActual);
					cursos = false;

					break;
				case 2:


					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoard();
					cursos = true;

					cursor(30, 3); cout << "CURSO";

					//opciones superiores 

					marcoOpcionesCurso(30, 7, 30, 8);
					marcoOpcionesCurso(68, 7, 68, 8);
					marcoOpcionesCurso(106, 7, 106, 8);


					Console::ForegroundColor = ConsoleColor::DarkGray;
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";
					cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
					cursor(107, 9); cout << " ORDENAR POR NRC              V";
					Console::ForegroundColor = ConsoleColor::White;

					cursor(30, 13); cout << "202520-AC";



					//IMPRIMIR CURSOS

					switch (auxV.size()) {
					case 1:
						marcosCurso(30, 15, 30, 16);
						cursor(33, 15); cout << auxV[0]->getNombre();
						auxV[0]->mostrarCurso(31, 17);
						break;
					case 2:
						marcosCurso(30, 15, 30, 16);
						marcosCurso(68, 15, 68, 16);
						cursor(33, 15); cout << auxV[0]->getNombre();
						auxV[0]->mostrarCurso(31, 17);
						cursor(71, 15); cout << auxV[1]->getNombre();
						auxV[1]->mostrarCurso(69, 17);
						break;
					case 3:
						marcosCurso(30, 15, 30, 16);
						marcosCurso(68, 15, 68, 16);
						marcosCurso(106, 15, 106, 16);
						cursor(33, 15); cout << auxV[0]->getNombre();
						auxV[0]->mostrarCurso(31, 17);
						cursor(71, 15); cout << auxV[1]->getNombre();
						auxV[1]->mostrarCurso(69, 17);
						cursor(109, 15); cout << auxV[2]->getNombre();
						auxV[2]->mostrarCurso(107, 17);
						break;
					case 4:
						marcosCurso(30, 15, 30, 16);
						marcosCurso(68, 15, 68, 16);
						marcosCurso(106, 15, 106, 16);
						marcosCurso(30, 27, 30, 28);
						cursor(33, 15); cout << auxV[0]->getNombre();
						auxV[0]->mostrarCurso(31, 17);
						cursor(71, 15); cout << auxV[1]->getNombre();
						auxV[1]->mostrarCurso(69, 17);
						cursor(109, 15); cout << auxV[2]->getNombre();
						auxV[2]->mostrarCurso(107, 17);
						cursor(33, 27); cout << auxV[3]->getNombre();
						auxV[3]->mostrarCurso(31, 29);
						break;
					case 5:
						marcosCurso(30, 15, 30, 16);
						marcosCurso(68, 15, 68, 16);
						marcosCurso(106, 15, 106, 16);
						marcosCurso(30, 27, 30, 28);
						marcosCurso(68, 27, 68, 28);

						Console::ForegroundColor = ConsoleColor::White;
						cursor(33, 15); cout << auxV[0]->getNombre();
						auxV[0]->mostrarCurso(31, 17);
						cursor(71, 15); cout << auxV[1]->getNombre();
						auxV[1]->mostrarCurso(69, 17);
						cursor(109, 15); cout << auxV[2]->getNombre();
						auxV[2]->mostrarCurso(107, 17);
						cursor(33, 27); cout << auxV[3]->getNombre();
						auxV[3]->mostrarCurso(31, 29);
						cursor(71, 27); cout << auxV[4]->getNombre();
						auxV[4]->mostrarCurso(69, 29);

						Console::ForegroundColor = ConsoleColor::DarkGray;

						break;
					}


					break;
				case 3:
					cursos = false;
					string nrcCalificaciones;
					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoard();
					string nombreCurso;

					Lista<Curso*>* auxC = oE->getCursos();
					vector<Curso*> auxVC;
					vector<int> notas;
					vector<Examen*> auxExamenes;
					vector<Proyecto*> auxProyectos;
					map<string, int> cursoYNota;
					bool calificaciones_OP = true;
					int k;

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

					//INSERTION SORT
					auto insertionSort = [](vector<int>& v) {

						int n = v.size();

						int aux, k;

						for (int i = 1; i < n; i++) {
							aux = v[i];
							k = i - 1;

							while (k >= 0 && aux > v[k]) {
								v[k + 1] = v[k];
								k--;
							}
							v[k + 1] = aux;
						}

						};


					for (int i = 0; i < auxC->longitud(); i++) {
						auxVC.push_back(auxC->obtenerPos(i));
					}

					cursor(30, 3); cout << "Calificaciones";
					cursor(66, 21); cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
						<< char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
						<< char(196) << char(196) << char(196) << char(196) << char(191);
					cursor(66, 22); cout << char(179);
					cursor(103, 22); cout << char(179);
					cursor(66, 23); cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
						<< char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)
						<< char(196) << char(196) << char(196) << char(196) << char(217);
					cursor(73, 19); cout << "Ingrese NRC de curso";
					System::Console::CursorVisible = true;

					System::Console::CursorVisible = false;

					bool seEncontroCurso = false;
					cursor(83, 22); cin >> nrcCalificaciones;



					for (const Curso* i : auxVC) {
						if (nrcCalificaciones == i->getNRC()) {
							seEncontroCurso = true;
							break;
						}
						else {
							cursor(68, 30); cout << "No se encontro curso con nrc: " << nrcCalificaciones;
						}
					}
					if (seEncontroCurso) {
						system("cls");
						marcoBaclkBoard();

						cursor(30, 3); cout << "Calificaciones";


						for (const Curso* i : auxVC) {
							if (nrcCalificaciones == i->getNRC()) {
								cursor(27, 7); cout << "Curso: " << i->getNombre();
								nombreCurso = i->getNombre();
							}
						}

						for (int i = 0; i < auxVC.size(); i++) {
							if (nrcCalificaciones == auxVC[i]->getNRC()) {
								auxExamenes = auxVC[i]->getVectorExamenes();
								auxProyectos = auxVC[i]->getVectorProyectos();
							}
						}

						for (const Curso* i : auxVC) {
							if (nrcCalificaciones == i->getNRC()) {
								notas = i->getNotasCursos();
							}
						}

						marcoOpcionesCurso(41, 10, 41, 11);
						cursor(58, 9); cout << "1";
						cursor(50, 12); cout << "Ver evaluaciones";

						marcoOpcionesCurso(89, 10, 89, 11);
						cursor(106, 19); cout << "4";
						cursor(94, 12); cout << "Por cantidad de Preguntas";

						marcoOpcionesCurso(41, 20, 41, 21);
						cursor(58, 19); cout << "2";
						cursor(54, 22); cout << "Por notas";

						marcoOpcionesCurso(89, 20, 89, 21);
						cursor(106, 9); cout << "3";
						cursor(102, 22); cout << "Por fecha";

						marcoOpcionesCurso(65, 30, 65, 31);
						cursor(82, 29); cout << "5";
						cursor(73, 32); cout << "Promedio de notas";

						while (calificaciones_OP) {
							switch (_getch()) {
							case '1':
								system("cls");
								marcoBaclkBoard();

								for (int i = 0; i < 2; i++)
								{

									cursor(80, 21); cout << "Cargando.";
									_sleep(250);
									cursor(80, 21); cout << "Cargando..";
									_sleep(250);
									cursor(80, 21); cout << "Cargando...";
									_sleep(250);
									cursor(80, 21); cout << "           ";
								}


								marcosCurso(30, 15, 30, 16);
								marcosCurso(68, 15, 68, 16);
								marcosCurso(106, 15, 106, 16);
								marcosCurso(30, 27, 30, 28);
								marcosCurso(68, 27, 68, 28);

								cursor(30, 3); cout << "Calificaciones";


								cursor(27, 7); cout << "evaluaciones de " << nombreCurso;
								for (const Curso* i : auxVC) {
									if (nrcCalificaciones == i->getNRC()) {
										i->getExamenesToString(34, 17);
										i->getProyectosToString(34, 29);
									}
								}


								calificaciones_OP = false;
								break;
							case '2':
								system("cls");


								marcoBaclkBoard();
								cursor(30, 3); cout << "Calificaciones";

								for (int i = 0; i < 2; i++) {
									cursor(80, 21); cout << "Cargando.";
									_sleep(250);
									cursor(80, 21); cout << "Cargando..";
									_sleep(250);
									cursor(80, 21); cout << "Cargando...";
									_sleep(250);
									cursor(80, 21); cout << "           ";
								}

								cursor(27, 7); cout << "Ordenar por notas de: " << nombreCurso;


								bubbleSort(notas);
								auxX = 56;
								auxY = 17;
								k = 1;
								cursor(51, 14); cout << "De menor a mayor";
								for (const int& i : notas) {
									cursor(auxX, auxY); cout << k << ".- " << i;
									auxY += 2;
									k++;
								}

								marcosCurso(42, 15, 42, 16);

								insertionSort(notas);

								auxX = 106;
								auxY = 17;
								k = 1;
								cursor(101, 14); cout << "De mayor a menor";
								for (const int& i : notas) {
									cursor(auxX, auxY); cout << k << ".- " << i;
									auxY += 2;
									k++;
								}

								marcosCurso(92, 15, 92, 16);

								calificaciones_OP = false;
								break;

							case '3':
								system("cls");
								marcoBaclkBoard();
								for (int i = 0; i < 2; i++) {
									cursor(80, 21); cout << "Cargando.";
									_sleep(250);
									cursor(80, 21); cout << "Cargando..";
									_sleep(250);
									cursor(80, 21); cout << "Cargando...";
									_sleep(250);
									cursor(80, 21); cout << "           ";
								}

								cursor(27, 7); cout << "Ordenar por cantidad de preguntas de examenes de: " << nombreCurso;

								for (const Curso* i : auxVC) {
									if (nrcCalificaciones == i->getNRC()) {
										i->getCantidadPreguntasToString(34, 17);
									}
								}

								marcosCurso(30, 15, 30, 16);
								marcosCurso(68, 15, 68, 16);
								marcosCurso(106, 15, 106, 16);

								calificaciones_OP = false;
								break;
							case '4':
								system("cls");
								marcoBaclkBoard();
								for (int i = 0; i < 2; i++) {
									cursor(80, 21); cout << "Cargando.";
									_sleep(250);
									cursor(80, 21); cout << "Cargando..";
									_sleep(250);
									cursor(80, 21); cout << "Cargando...";
									_sleep(250);
									cursor(80, 21); cout << "           ";
								}
								cursor(27, 7); cout << "Ordenar por fecha de inicio de: " << nombreCurso;

								for (const Curso* i : auxVC) {
									if (nrcCalificaciones == i->getNRC()) {
										i->getFechaString(32, 13);
									}
								}


								marcosCurso(30, 12, 30, 13);
								marcosCurso(68, 12, 68, 13);
								marcosCurso(106, 12, 106, 13);
								marcosCurso(30, 27, 30, 28);
								marcosCurso(68, 27, 68, 28);



								calificaciones_OP = false;
								break;
							case '5':
								system("cls");
								marcoBaclkBoard();
								for (int i = 0; i < 2; i++) {
									cursor(80, 21); cout << "Cargando.";
									_sleep(250);
									cursor(80, 21); cout << "Cargando..";
									_sleep(250);
									cursor(80, 21); cout << "Cargando...";
									_sleep(250);
									cursor(80, 21); cout << "           ";
								}
								cursor(27, 7); cout << "Promedio ponderado de: " << nombreCurso;

								auto promedioPonderado = [](vector<Examen*> v, vector<Proyecto*> v2) {

									double sumatoriaNotas = 0.0;


									for (int i = 0; i < v.size(); i++) {
										sumatoriaNotas += (v[i]->getNota() * v[i]->getPeso());

									}

									for (int i = 0; i < v2.size(); i++) {
										sumatoriaNotas += (v2[i]->getNota() * v2[i]->getPeso());
									}


									return sumatoriaNotas;

									};

								auto promedioSimple = [&](int sum, int n) {

									return double(sum / n);

									};


								cursor(81, 14); cout << "Promedios";
								marcosCurso(68, 15, 68, 16);
								cursor(72, 19); cout << "Promedio ponderado: " << promedioPonderado(auxExamenes, auxProyectos);
								cursor(72, 22); cout << "Promedio simple: " << promedioSimple(sumatoria(notas, notas.size()), notas.size());

								calificaciones_OP = false;
								break;
							}

						}

						break;
					}
				}


			}

			//Funciones para las opciones de los cursos 
			if (opcionSuperior == 1 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoard();
				cursor(30, 3); cout << "CURSO";

				marcoOpcionesCurso(30, 7, 30, 8);
				marcoOpcionesCurso(68, 7, 68, 8);
				marcoOpcionesCurso(106, 7, 106, 8);


				Console::ForegroundColor = ConsoleColor::DarkGray;
				cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";
				cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
				cursor(107, 9); cout << " ORDENAR POR NRC              V";
				Console::ForegroundColor = ConsoleColor::White;

				cursor(30, 13); cout << "202520-AC";


				Console::CursorVisible = true;
				for (int i = 0; i < 20; i++)
				{
					cursor(i + 67, 21); cout << char(196);
					cursor(i + 67, 23); cout << char(196);
				}
				//esquinas
				cursor(67, 21); cout << char(218);
				cursor(87, 21); cout << char(191);
				cursor(67, 23); cout << char(192);
				cursor(87, 23); cout << char(217);

				cursor(67, 22); cout << char(179);
				cursor(87, 22); cout << char(179);

				cursor(67, 20); cout << "Profesor: (primer nombre)";
				cursor(69, 22); cin >> nombre;
				Console::CursorVisible = false;

				cursor(67, 20); cout << "                         ";;
				cursor(67, 21); cout << "                         ";;
				cursor(67, 22); cout << "                         ";;
				cursor(67, 23); cout << "                         ";;


				//Busqueda por profesor
				//LAMBDA 1
				auto lambBusqueda = [&]()
					{
						for (int i = 0; i < aux->longitud(); i++) {
							if (nombre == auxV[i]->getProfesor()->getNombre()) {
								resultados.push_back(auxV[i]);
							}
						}
					};

				lambBusqueda();


				for (int i = 0; i < 2; i++)
				{

					cursor(80, 25); cout << "Cargando.";
					_sleep(250);
					cursor(80, 25); cout << "Cargando..";
					_sleep(250);
					cursor(80, 25); cout << "Cargando...";
					_sleep(250);
					cursor(80, 25); cout << "           ";
				}



				switch (resultados.size()) {
				case 1:
					marcosCurso(30, 15, 30, 16);
					cursor(33, 15); cout << resultados[0]->getNombre();
					resultados[0]->mostrarCurso(31, 17);
					break;
				case 2:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					cursor(33, 15); cout << resultados[0]->getNombre();
					resultados[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << resultados[1]->getNombre();
					resultados[1]->mostrarCurso(69, 17);
					break;
				case 3:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					cursor(33, 15); cout << resultados[0]->getNombre();
					resultados[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << resultados[1]->getNombre();
					resultados[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << resultados[2]->getNombre();
					resultados[2]->mostrarCurso(107, 17);
					break;
				case 4:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					cursor(33, 15); cout << resultados[0]->getNombre();
					resultados[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << resultados[1]->getNombre();
					resultados[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << resultados[2]->getNombre();
					resultados[2]->mostrarCurso(107, 17);
					cursor(33, 27); cout << resultados[3]->getNombre();
					resultados[3]->mostrarCurso(31, 29);
					break;
				case 5:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					marcosCurso(68, 27, 68, 28);

					Console::ForegroundColor = ConsoleColor::White;
					cursor(33, 15); cout << resultados[0]->getNombre();
					resultados[0]->mostrarCurso(31, 17);

					cursor(71, 15); cout << resultados[1]->getNombre();
					resultados[1]->mostrarCurso(69, 17);

					cursor(109, 15); cout << resultados[2]->getNombre();
					resultados[2]->mostrarCurso(107, 17);

					cursor(33, 27); cout << resultados[3]->getNombre();
					resultados[3]->mostrarCurso(31, 29);

					cursor(71, 27); cout << resultados[4]->getNombre();
					resultados[4]->mostrarCurso(69, 29);

					Console::ForegroundColor = ConsoleColor::DarkGray;



					break;
				}

				if (resultados.size() == NULL)
				{
					cursor(55, 23); cout << "No se encontro ningun profesor llamado '" << nombre << "'.";

				}
			}
			if (opcionSuperior == 2 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoard();
				cursor(30, 3); cout << "CURSO";

				marcoOpcionesCurso(30, 7, 30, 8);
				marcoOpcionesCurso(68, 7, 68, 8);
				marcoOpcionesCurso(106, 7, 106, 8);


				Console::ForegroundColor = ConsoleColor::DarkGray;
				cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";
				cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
				cursor(107, 9); cout << " ORDENAR POR NRC              V";
				Console::ForegroundColor = ConsoleColor::White;

				cursor(30, 13); cout << "202520-AC";

				//Algoritmo de ordenamiento

				//Orden de menor a mayor
				//LAMBDA 2
				auto ordenCREDm = [&]()
					{

						if (orden[0] == true)
						{
							cursor(70, 13); cout << "menor A MAYOR";
							for (int i = 0; i < aux->longitud(); i++)
							{
								for (int j = i + 1; j < aux->longitud(); j++)
								{
									if (auxV[i]->getCreditos() > auxV[j]->getCreditos())
									{
										temp = auxV[i];
										auxV[i] = auxV[j];
										auxV[j] = temp;

									}
								}
								activ[0] = true;
							}
						}

					};

				ordenCREDm();

				//Orden de mayor a menor
				//LAMBDA 3
				auto ordenCREDM = [&]()
					{
						if (orden[0] == false)
						{
							cursor(70, 13); cout << "MAYOR A menor";

							for (int i = 0; i < aux->longitud(); i++)
							{
								for (int j = i + 1; j < aux->longitud(); j++)
								{
									if (auxV[i]->getCreditos() < auxV[j]->getCreditos())
									{
										temp = auxV[i];
										auxV[i] = auxV[j];
										auxV[j] = temp;

									}
								}
							}
							activ[0] = false;
						}
					};

				ordenCREDM();

				if (activ[0] == true)
				{
					orden[0] = false;
				}
				else
				{
					orden[0] = true;
				}

				for (int i = 0; i < 1; i++)
				{

					cursor(80, 21); cout << "Cargando.";
					_sleep(250);
					cursor(80, 21); cout << "Cargando..";
					_sleep(250);
					cursor(80, 21); cout << "Cargando...";
					_sleep(250);
					cursor(80, 21); cout << "           ";
				}


				switch (auxV.size()) {
				case 1:
					marcosCurso(30, 15, 30, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					break;
				case 2:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					break;
				case 3:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					break;
				case 4:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					cursor(33, 27); cout << auxV[3]->getNombre();
					auxV[3]->mostrarCurso(31, 29);
					break;
				case 5:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					marcosCurso(68, 27, 68, 28);

					Console::ForegroundColor = ConsoleColor::White;
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					cursor(33, 27); cout << auxV[3]->getNombre();
					auxV[3]->mostrarCurso(31, 29);
					cursor(71, 27); cout << auxV[4]->getNombre();
					auxV[4]->mostrarCurso(69, 29);
					Console::ForegroundColor = ConsoleColor::DarkGray;

					break;
				}
			}
			if (opcionSuperior == 3 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoard();
				cursor(30, 3); cout << "CURSO";

				marcoOpcionesCurso(30, 7, 30, 8);
				marcoOpcionesCurso(68, 7, 68, 8);
				marcoOpcionesCurso(106, 7, 106, 8);


				Console::ForegroundColor = ConsoleColor::DarkGray;
				cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";
				cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
				cursor(107, 9); cout << " ORDENAR POR NRC              V";
				Console::ForegroundColor = ConsoleColor::White;

				cursor(30, 13); cout << "202520-AC";

				//Algoritmo de ordenamiento

				//orden de menor a mayor
				//LAMBDA 4
				auto ordenNRCm = [&]()
					{

						if (orden[1] == true)
						{
							cursor(70, 13); cout << "menor A MAYOR";

							for (int i = 0; i < aux->longitud(); i++)
							{
								for (int j = i + 1; j < aux->longitud(); j++)
								{
									if (stoi(auxV[i]->getNRC()) > stoi(auxV[j]->getNRC()))
									{

										temp = auxV[i];
										auxV[i] = auxV[j];
										auxV[j] = temp;
									}
								}
							}
							activ[1] = true;

						}

					};

				ordenNRCm();

				//orden de mayor a menor
				//LAMBDA 5
				auto ordenNRCM = [&]()
					{
						if (orden[1] == false)
						{
							cursor(70, 13); cout << "MAYOR A menor";

							for (int i = 0; i < aux->longitud(); i++)
							{
								for (int j = i + 1; j < aux->longitud(); j++)
								{
									if (stoi(auxV[i]->getNRC()) < stoi(auxV[j]->getNRC()))
									{
										temp = auxV[i];
										auxV[i] = auxV[j];
										auxV[j] = temp;
									}

								}

							}
							activ[1] = false;
						}
					};

				ordenNRCM();


				if (activ[1] == true)
				{
					orden[1] = false;
				}
				else
				{
					orden[1] = true;
				}



				for (int i = 0; i < 1; i++)
				{


					cursor(80, 21); cout << "Cargando.";
					_sleep(250);
					cursor(80, 21); cout << "Cargando..";
					_sleep(250);
					cursor(80, 21); cout << "Cargando...";
					_sleep(250);
					cursor(80, 21); cout << "           ";
				}


				switch (auxV.size()) {
				case 1:
					marcosCurso(30, 15, 30, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					break;
				case 2:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					break;
				case 3:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					break;
				case 4:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					cursor(33, 27); cout << auxV[3]->getNombre();
					auxV[3]->mostrarCurso(31, 29);
					break;
				case 5:
					marcosCurso(30, 15, 30, 16);
					marcosCurso(68, 15, 68, 16);
					marcosCurso(106, 15, 106, 16);
					marcosCurso(30, 27, 30, 28);
					marcosCurso(68, 27, 68, 28);

					Console::ForegroundColor = ConsoleColor::White;
					cursor(33, 15); cout << auxV[0]->getNombre();
					auxV[0]->mostrarCurso(31, 17);
					cursor(71, 15); cout << auxV[1]->getNombre();
					auxV[1]->mostrarCurso(69, 17);
					cursor(109, 15); cout << auxV[2]->getNombre();
					auxV[2]->mostrarCurso(107, 17);
					cursor(33, 27); cout << auxV[3]->getNombre();
					auxV[3]->mostrarCurso(31, 29);
					cursor(71, 27); cout << auxV[4]->getNombre();
					auxV[4]->mostrarCurso(69, 29);
					Console::ForegroundColor = ConsoleColor::DarkGray;

					break;
				}

			}

			if (opcion == 4 && t == char(32))
			{
				exit(0);
			}
		}

	}

}
