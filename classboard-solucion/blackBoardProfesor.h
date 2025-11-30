#pragma once
#include <iostream> 
#include <string> 
#include <vector>  
#include"ArbolBinario.h"
#include "Profesor.h"
#include "HashTabla.h"
#include "ArbolAVL.h"

using namespace std;
using namespace System;

int HashString(string s);

void imprimir(int e) {
	cout << e << " ";
}

//SECCION 1
Profesor* oProfesor1 = new Profesor();
vector<string> nombresAlumnos1 = oProfesor1->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes1;

//SECCION 2
Profesor* oProfesor2 = new Profesor();
vector<string> nombresAlumnos2 = oProfesor2->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes2;

//SECCION 3
Profesor* oProfesor3 = new Profesor();
vector<string> nombresAlumnos3 = oProfesor3->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes3;

//SECCION 4
Profesor* oProfesor4 = new Profesor();
vector<string> nombresAlumnos4 = oProfesor4->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes4;


//SECCION 5
Profesor* oProfesor5 = new Profesor();
vector<string> nombresAlumnos5 = oProfesor5->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes5;

//SECCION 6
Profesor* oProfesor6 = new Profesor();
vector<string> nombresAlumnos6 = oProfesor6->getNombreAlumnos();

HashTabla<vector<int>>* tablaEstudiantes6;

//VECTOR TODO LOS ALUMNOS

vector<string> todosAlumnos;


struct AtributosCurso {
	int nrc;
	string horario;
};

void imprimirCursoXY(AtributosCurso c, int x, int y) {

	Console::SetCursorPosition(x, y); cout << "NRC: " << c.nrc << "  ";


	Console::SetCursorPosition(x, y + 3); cout << "Horario: " << c.horario << "  ";
}


ArbolBB<AtributosCurso>* arbolNRC = new ArbolBB<AtributosCurso>(imprimirCursoXY, false);
ArbolBB<AtributosCurso>* arbolHorario = new ArbolBB<AtributosCurso>(imprimirCursoXY, true);


void perfilProfesor() {

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
	cursor(67, 26), cout << "	      Ingeniero";
	cursor(73, 28), cout << "Pedro Paulet Mostajo";
}

void dibujarRectanguloProfesor(int x, int y, int ancho, int alto, int color = 7) {

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

}

int indexprofesor = 0;
void paginaPrincipalPrfesor() {

	int x = 30, y = 7, ancho = 110, alto = 7;

	vector<string> mensajes = {
		"SEMANA UNIVERSITARIA",
		"VERANO UPC 2026",
		"ANUNCIOS UPC"
	};

	dibujarRectanguloProfesor(x, y, ancho, alto);
	// Texto centrado
	string msg = mensajes[indexprofesor];
	cursor(x + (ancho / 2) - (msg.size() / 2), y + (alto / 2));
	cout << msg;

	// Flechas de adorno
	cursor(x + 2, y + (alto / 2));
	cout << "<<";
	cursor(x + ancho - 4, y + (alto / 2));
	cout << ">>";

	// --- Cuadros pequeños que cambian según index ---
	if (indexprofesor == 0) {
		// ---- SEMANA UNIVERSITARIA ----
		dibujarRectanguloProfesor(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Dia del deporte";

		dibujarRectanguloProfesor(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Concurso";

		dibujarRectanguloProfesor(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Concierto";

		dibujarRectanguloProfesor(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Feria";

		dibujarRectanguloProfesor(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Taller danza";

		dibujarRectanguloProfesor(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Teatro";


		int gx = x + 77;
		int gy = y + alto + 5;
		int dx = 1;
		int dy = 1;
		int rectX = x + 75;
		int rectY = y + alto + 3;
		int rectW = 35;
		int rectH = 12;
		dibujarRectanguloProfesor(rectX, rectY, rectW, rectH);
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
	else if (indexprofesor == 1) {
		// ---- VERANO UPC ----
		dibujarRectanguloProfesor(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Cursos verano";

		dibujarRectanguloProfesor(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Deportes playa";

		dibujarRectanguloProfesor(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Viajes UPC";



		dibujarRectanguloProfesor(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Conferencias";

		dibujarRectanguloProfesor(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Taller verano";

		dibujarRectanguloProfesor(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Becas verano";


		static int rectX = x + 75;
		static int rectY = y + alto + 3;
		static int rectW = 35;
		static int rectH = 12;
		static int gx = rectX + 2;
		static int gy = rectY + 2;
		static int dx = 1;
		static int dy = 1;

		dibujarRectanguloProfesor(rectX, rectY, rectW, rectH);

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

	}
	else if (indexprofesor == 2) {
		// ---- ANUNCIOS UPC ----
		dibujarRectanguloProfesor(x, y + alto + 3, 20, 5, 4);
		cursor(x + 3, y + alto + 5); cout << " Pago cuotas";

		dibujarRectanguloProfesor(x + 25, y + alto + 3, 20, 5, 4);
		cursor(x + 28, y + alto + 5); cout << " Nuevo curso";

		dibujarRectanguloProfesor(x + 50, y + alto + 3, 20, 5, 4);
		cursor(x + 53, y + alto + 5); cout << " Invitacion";



		dibujarRectanguloProfesor(x, y + alto + 10, 20, 5, 4);
		cursor(x + 3, y + alto + 12); cout << " Charla UPC";

		dibujarRectanguloProfesor(x + 25, y + alto + 10, 20, 5, 4);
		cursor(x + 28, y + alto + 12); cout << " Seguridad";

		dibujarRectanguloProfesor(x + 50, y + alto + 10, 20, 5, 4);
		cursor(x + 53, y + alto + 12); cout << " Biblioteca";


	}
}

void marcoProfesor()
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
void marcoCursoProfesor(int largo, int ancho, int x, int y)
{
	cursor(x, y); cout << char(201);
	cursor(x, y + ancho); cout << char(200);

	for (int i = 0; i < largo; i++)
	{
		cursor(x + i + 1, y); cout << char(205);
		cursor(x + i + 1, y + ancho); cout << char(205);
		if (i >= largo - 1)
		{
			cursor(x + i + 2, y); cout << char(187);
			cursor(x + i + 2, y + ancho); cout << char(188);
		}
	}

	for (int j = 0; j < ancho - 1; j++)
	{
		cursor(x, y + j + 1); cout << char(186);
		cursor(x + largo + 1, y + j + 1); cout << char(186);
	}


}
void marcoOpcionesCursoProfesor(int x, int y, int z, int k)
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
void marcoOpcionesProfesor(int x, int y, int z, int k)
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
void marcoBaclkBoardProfesor() {

	Console::SetWindowSize(145, 40);
	Console::CursorVisible = false;

	//Primera fila
	cout << char(201);
	for (int i = 0; i < 27; i++)
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


	marcoOpcionesProfesor(1, 14, 1, 15);
	cursor(2, 16); cout << "Pagina principal";

	marcoOpcionesProfesor(1, 19, 1, 20);
	cursor(2, 21); cout << "Perfil";

	marcoOpcionesProfesor(1, 24, 1, 25);
	cursor(2, 26); cout << "Cursos";

	marcoOpcionesProfesor(1, 29, 1, 30);
	cursor(2, 31); cout << "Ver Alumnos";

	marcoOpcionesProfesor(1, 34, 1, 35);
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



	marcoProfesor();
	cursor(144, 6); cout << char(185);


}

void mostrarSeccion()
{
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			//Posicion que irá aumentando hasta llegar al 3er curso 0, 1, 2
			cursor(32 * (i + 1) + (i * 6), 24); cout << "SECCION: 1ACC0182";
		}
		else
		{
			//Luego que sea mayor a los 3 cursos impresos, pasará a la parte inferior a imprimir los siguientes cursos 3, 4, 5
			cursor(32 * (i - 2) + ((i - 3) * 6), 36); cout << "SECCION: 1ACC0182";
		}

	}
}


void imprimirNRC()
{

	Random r;
	bool activ = true;
	Console::ForegroundColor = ConsoleColor::Gray;
	for (int i = 0; i < 6; i++)
	{

		AtributosCurso c1;
		c1.nrc = r.Next(100, 15001);
		int ini = r.Next(7, 20);
		int fin = r.Next(1, 5);
		//Crear horario en un inicio y sumandole al inicio el fin y cosa que el horario no pasa de las 4 horas, hay clases de 1, 2, 3 y 4 horas
		c1.horario = to_string(ini) + ":00 - " + to_string(ini + fin) + ":00";

		arbolNRC->insertar(c1);
		arbolHorario->insertar(c1);
		if (i < 3)
		{
			//Posicion que irá aumentando hasta llegar al 3er curso 0, 1, 2
			cursor(32 * (i + 1) + (i * 6), 24); cout << "SECCION: 1ACC0182";
		}
		else
		{
			//Luego que sea mayor a los 3 cursos impresos, pasará a la parte inferior a imprimir los siguientes cursos 3, 4, 5
			cursor(32 * (i - 2) + ((i - 3) * 6), 36); cout << "SECCION: 1ACC0182";
		}

	}
	arbolNRC->imprimirPreOrdenXY(32, 18);
	Console::ForegroundColor = ConsoleColor::White;

}

void cursosProfesor()
{
	int posX = 31;
	int posY = 15;

	//cursos del profesor
	marcoCursoProfesor(35, 11, 29, 15);
	marcoCursoProfesor(35, 11, 67, 15);
	marcoCursoProfesor(35, 11, 105, 15);
	marcoCursoProfesor(35, 11, 29, 27);
	marcoCursoProfesor(35, 11, 67, 27);
	marcoCursoProfesor(35, 11, 105, 27);

	for (int i = 0; i < 3; i++)
	{
		cursor(posX, posY); cout << " Estructura de datos ";
		posX += 38;
	}

	posX = 31;
	for (int i = 0; i < 3; i++)
	{
		cursor(posX, posY + 12); cout << " Estructura de datos ";
		posX += 38;
	}
}

void limpiarcursos()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 113; j++)
		{
			cursor(j + 29, i + 15); cout << " ";
		}
	}
}








void BlackBoardProfesor()
{
	system("cls");
	marcoBaclkBoardProfesor();

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

	int n = 0;
	Console::ForegroundColor = ConsoleColor::DarkRed;
	marcoOpciones(1, 14, 1, 15);
	cursor(2, 16); cout << "Pagina principal";

	bool prueba = true;
	bool evitarEspacios = true;
	bool numActivo = true;

	


	while (true) {
		int nrc;
		if (_kbhit()) {
			char t = _getch();
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

				// ======= Dibujar menú lateral =======
				Console::ForegroundColor = ConsoleColor::White;

				marcoOpciones(1, 14, 1, 15); cursor(2, 16); cout << "Pagina principal";
				marcoOpciones(1, 19, 1, 20); cursor(2, 21); cout << "Perfil";
				marcoOpciones(1, 24, 1, 25); cursor(2, 26); cout << "Cursos";
				marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Ver Alumnos";
				marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion";


				switch (opcion) {
				case 0: marcoOpciones(1, 14, 1, 15); cursor(2, 16); cout << "Pagina principal"; break;
				case 1: marcoOpciones(1, 19, 1, 20); cursor(2, 21); cout << "Perfil"; break;
				case 2: marcoOpciones(1, 24, 1, 25); cursor(2, 26); cout << "Cursos"; break;
				case 3: marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Ver Alumnos"; break;
				case 4: marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion"; break;
				}

				if (opcion == 0)
				{

					evitarEspacios = true;
					if (t == char(32)) {
						index = (index - 1 + 3) % 3;
						system("cls");
						marcoBaclkBoardProfesor();
						paginaPrincipal();

					}
					else if (t == char(32)) {
						index = (index + 1) % 3;
						system("cls");
						marcoBaclkBoardProfesor();
						paginaPrincipal();
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

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Pagina principal";

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";

					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Ver Alumnos";

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";


					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";
					evitarEspacios = true;
				}

				else if (opcion == 2)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Pagina principal";

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";

					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Ver Alumnos";

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";

					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";




				}
				else if (opcion == 3)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Pagina principal";
					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";
					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Ver Alumnos";
					evitarEspacios = true;

				}
				else if (opcion == 4)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Pagina principal";

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";

					marcoOpciones(1, 24, 1, 25);
					cursor(2, 26); cout << "Cursos";

					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Ver Alumnos";

					Console::ForegroundColor = ConsoleColor::DarkRed;

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";
					evitarEspacios = true;
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
					cursor(31, 9); cout << " BUSQUEDA POR NRC        V";

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
					cursor(69, 9); cout << " ORDENAR POR HORARIO         V";

					marcoOpcionesCurso(106, 7, 106, 8);
					cursor(107, 9); cout << " ORDENAR POR NRC              V";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR NRC        V";

				}
				else if (opcionSuperior == 2)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR NRC        V";

					marcoOpcionesCurso(106, 7, 106, 8);
					cursor(107, 9); cout << " ORDENAR POR NRC              V";

					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoOpcionesCurso(68, 7, 68, 8);
					cursor(69, 9); cout << " ORDENAR POR HORARIO         V";
				}
				else if (opcionSuperior == 3)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpcionesCurso(68, 7, 68, 8);
					cursor(69, 9); cout << " ORDENAR POR HORARIO         V";

					marcoOpcionesCurso(30, 7, 30, 8);
					cursor(31, 9); cout << " BUSQUEDA POR NRC        V";

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



			if (t == char(32) && (opcion >= 0 && opcion <= 3) && evitarEspacios)
			{
				
				//PARA IMPRIMIR LOS CURSOS
				int auxX = 40;
				int auxY = 20;
				switch (opcion) {

				case 1:

					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoardProfesor();
					perfilProfesor();
					cursos = false;

					break;
				case 2:


					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoardProfesor();
					cursos = true;

					cursor(30, 3); cout << "CURSO";

					//opciones superiores 

					marcoOpcionesCurso(30, 7, 30, 8);
					marcoOpcionesCurso(68, 7, 68, 8);
					marcoOpcionesCurso(106, 7, 106, 8);


					Console::ForegroundColor = ConsoleColor::DarkGray;
					cursor(31, 9); cout << " BUSQUEDA POR NRC        V";
					cursor(69, 9); cout << " ORDENAR POR HORARIO         V";
					cursor(107, 9); cout << " ORDENAR POR NRC              V";
					Console::ForegroundColor = ConsoleColor::White;

					cursor(30, 13); cout << "202520-AC";

					cursosProfesor();
					if (prueba)
					{
						imprimirNRC();

					}
					else
					{
						arbolNRC->imprimirPreOrdenXY(32, 18);
						mostrarSeccion();
					}
					evitarEspacios = false;
					prueba = false;
					break;
				}
			}


			//Funciones para las opciones de los cursos 
			if (opcionSuperior == 1 && t == char(32))
			{
				numActivo = false;
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoOpcionesCurso(30, 7, 30, 8);
				cursor(31, 9); cout << " BUSQUEDA POR NRC        V";
				cursor(45, 12); cout << "^";
				limpiarcursos();
				cursor(50, 22); cout << "Ingresa el NRC: "; cin >> nrc;


				if (arbolNRC->BuscarPorNRC(nrc))
				{
					auto curso = arbolNRC->ObtenerPorNRC(nrc);

					limpiarcursos();

					marcoCursoProfesor(35, 11, 29, 15);
					cursor(31, 15); cout << " Estructura de datos ";

					cursor(31, 18); cout << "NRC: " << curso.nrc << endl;
					cursor(31, 21); cout << "HORARIO: " << curso.horario;
					cursor(31, 24); cout << "SECCION: 1ACC0182";
				}
				else
				{
					cursor(50, 24); cout << "NO SE ENCONTRO";
				}

				Console::ForegroundColor = ConsoleColor::Gray;
			}
			if (opcionSuperior == 2 && t == char(32))
			{
				numActivo = true;
				Console::ForegroundColor = ConsoleColor::Gray;
				limpiarcursos();
				cursosProfesor();
				Console::ForegroundColor = ConsoleColor::DarkRed;
				marcoOpcionesCurso(68, 7, 68, 8);
				cursor(69, 9); cout << " ORDENAR POR HORARIO         V";
				cursor(85, 12); cout << "^";
				Console::ForegroundColor = ConsoleColor::Gray;
				arbolHorario->imprimirenOrdenXY(32, 18);

			}
			if (opcionSuperior == 3 && t == char(32))
			{
				numActivo = true;
				Console::ForegroundColor = ConsoleColor::Gray;
				limpiarcursos();
				cursosProfesor();
				Console::ForegroundColor = ConsoleColor::DarkRed;
				marcoOpcionesCurso(106, 7, 106, 8);
				cursor(107, 9); cout << " ORDENAR POR NRC              V";
				cursor(125, 12); cout << "^";
				Console::ForegroundColor = ConsoleColor::Gray;

				arbolNRC->imprimirenOrdenXY(32, 18);
			}

			

			//Para acceder a los cursos
			if (numActivo)
			{

				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(49))
				{ 
					cout << "Seccion 1";
					
					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes1 = oProfesor1->getTablaAlumnos();


					oProfesor1->setNombre("Matias");
					oProfesor1->setApellido("Carrillo");
					
					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();
					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 29, 15);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(31, 15); cout << " Estructura de datos ";

					_sleep(1000);

					limpiarcursos();

					oProfesor1->verAlumnos(30,17);
					

					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos1.size(); i++) {
						
						for (int j = 0; j < tablaEstudiantes1->getValue(HashString(nombresAlumnos1[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes1->getValue(HashString(nombresAlumnos1[i]))[j];
							
							xCursorAux += 3;
							
						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}
					

					
				}
				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(50))
				{

					cout << "Seccion 2";
					
					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes2 = oProfesor2->getTablaAlumnos();

					oProfesor2->setNombre("Matias");
					oProfesor2->setApellido("Carrillo");

					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();
					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 67, 15);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(69, 15); cout << " Estructura de datos ";

					_sleep(1000);

					limpiarcursos();

					oProfesor2->verAlumnos(30, 17);

					
					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos2.size(); i++) {

						for (int j = 0; j < tablaEstudiantes2->getValue(HashString(nombresAlumnos2[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes2->getValue(HashString(nombresAlumnos2[i]))[j];

							xCursorAux += 3;

						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}

				}
				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(51))
				{

					cout << "Seccion 3";

					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes3 = oProfesor3->getTablaAlumnos();

					oProfesor3->setNombre("Matias");
					oProfesor3->setApellido("Carrillo");

					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();


					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 105, 15);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(107, 15); cout << " Estructura de datos ";


					_sleep(1000);

					limpiarcursos();

					oProfesor3->verAlumnos(30, 17);


					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos3.size(); i++) {

						for (int j = 0; j < tablaEstudiantes3->getValue(HashString(nombresAlumnos3[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes3->getValue(HashString(nombresAlumnos3[i]))[j];

							xCursorAux += 3;

						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}
				}

				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(52))
				{

					cout << "Seccion 4";

					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes4 = oProfesor4->getTablaAlumnos();

					oProfesor4->setNombre("Matias");
					oProfesor4->setApellido("Carrillo");


					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();


					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 29, 27);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(31, 27); cout << " Estructura de datos ";


					_sleep(1000);

					limpiarcursos();

					oProfesor4->verAlumnos(30, 17);


					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos4.size(); i++) {

						for (int j = 0; j < tablaEstudiantes4->getValue(HashString(nombresAlumnos4[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes4->getValue(HashString(nombresAlumnos4[i]))[j];

							xCursorAux += 3;

						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}

				}
				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(53))
				{

					cout << "Seccion 5";

					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes5 = oProfesor5->getTablaAlumnos();

					oProfesor5->setNombre("Matias");
					oProfesor5->setApellido("Carrillo");

					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();


					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 67, 27);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(69, 27); cout << " Estructura de datos ";

					_sleep(1000);

					limpiarcursos();

					oProfesor5->verAlumnos(30, 17);


					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos5.size(); i++) {

						for (int j = 0; j < tablaEstudiantes5->getValue(HashString(nombresAlumnos5[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes5->getValue(HashString(nombresAlumnos5[i]))[j];

							xCursorAux += 3;

						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}

				}
				if ((opcionSuperior == 1 || opcionSuperior == 2 || opcionSuperior == 3) && t == char(54))
				{


					cout << "Seccion 6";

					//Recibirá la tabla de alumnos: Clave = nombreAlumno ; Valor = vector de notas
					tablaEstudiantes6 = oProfesor6->getTablaAlumnos();

					oProfesor6->setNombre("Matias");
					oProfesor6->setApellido("Carrillo");


					Console::ForegroundColor = ConsoleColor::White;
					cursosProfesor();


					Console::ForegroundColor = ConsoleColor::DarkRed;
					marcoCursoProfesor(35, 11, 105, 27);
					Console::ForegroundColor = ConsoleColor::White;
					cursor(107, 27); cout << " Estructura de datos ";

					_sleep(1000);

					limpiarcursos();

					oProfesor6->verAlumnos(30, 17);


					int xCursorAux = 30;
					int yCursorAux = 19;
					int yAuxNum = yCursorAux;
					for (int i = 0; i < nombresAlumnos6.size(); i++) {

						for (int j = 0; j < tablaEstudiantes6->getValue(HashString(nombresAlumnos6[i])).size(); j++) {
							cursor(xCursorAux, yCursorAux); cout << "|";

							cursor(xCursorAux + 1, yCursorAux); cout << tablaEstudiantes6->getValue(HashString(nombresAlumnos6[i]))[j];

							xCursorAux += 3;

						}
						_sleep(100);

						xCursorAux -= 15;
						yCursorAux += 7;

						if (yCursorAux > 35) {
							yCursorAux = yAuxNum;
							xCursorAux += 22;
						}

					}
				}
			}
			if (opcion == 3 && t == char(32))
			{
				int xAUXLOCAL = 30;
				int yAUXLOCAL = 9;
				
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos1.begin(), nombresAlumnos1.end());
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos2.begin(), nombresAlumnos2.end());
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos3.begin(), nombresAlumnos3.end());
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos4.begin(), nombresAlumnos4.end());
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos5.begin(), nombresAlumnos5.end());
				todosAlumnos.insert(todosAlumnos.end(), nombresAlumnos6.begin(), nombresAlumnos6.end());

				int nrcLocal;
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoardProfesor();

				Console::ForegroundColor = ConsoleColor::Blue;
				cursor(28, 7); cout << "|Seccion 1|";
				cursor(48, 7); cout << "|Seccion 2|";
				cursor(68, 7); cout << "|Seccion 3|";
				cursor(88, 7); cout << "|Seccion 4|";
				cursor(108, 7); cout << "|Seccion 5|";
				cursor(128, 7); cout << "|Seccion 6|";
				Console::ForegroundColor = ConsoleColor::Gray;

				vector<Alumno*> auxSeccion1 = oProfesor1->getAlumnos();
				vector<Alumno*> auxSeccion2 = oProfesor2->getAlumnos();
				vector<Alumno*> auxSeccion3 = oProfesor3->getAlumnos();
				vector<Alumno*> auxSeccion4 = oProfesor4->getAlumnos();
				vector<Alumno*> auxSeccion5 = oProfesor5->getAlumnos();
				vector<Alumno*> auxSeccion6 = oProfesor6->getAlumnos();

				ArbolAVL<int>* arbolSeccion1 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion1.size(); i++) {
					arbolSeccion1->Insertar(auxSeccion1[i]->getPromedioSimple());
				}

				ArbolAVL<int>* arbolSeccion2 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion2.size(); i++) {
					arbolSeccion2->Insertar(auxSeccion2[i]->getPromedioSimple());
				}

				ArbolAVL<int>* arbolSeccion3 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion3.size(); i++) {
					arbolSeccion3->Insertar(auxSeccion3[i]->getPromedioSimple());
				}

				ArbolAVL<int>* arbolSeccion4 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion4.size(); i++) {
					arbolSeccion4->Insertar(auxSeccion4[i]->getPromedioSimple());
				}

				ArbolAVL<int>* arbolSeccion5 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion5.size(); i++) {
					arbolSeccion5->Insertar(auxSeccion5[i]->getPromedioSimple());
				}

				ArbolAVL<int>* arbolSeccion6 = new ArbolAVL<int>(imprimir);
				for (int i = 0; i < auxSeccion6.size(); i++) {
					arbolSeccion6->Insertar(auxSeccion6[i]->getPromedioSimple());
				}

				
				for (int i = 0; i < todosAlumnos.size(); i++) {
					cursor(xAUXLOCAL, yAUXLOCAL); cout << todosAlumnos[i];
					yAUXLOCAL+=2;

					if (yAUXLOCAL > 37) {
						xAUXLOCAL += 20;
						yAUXLOCAL = 9;
					}
				}

				int numSeccion;
				string nombreEstudianteSeccion;

				cursor(70, 2); cout << "Ingrese num de seccion: "; cin >> numSeccion;

				if (numSeccion != 1 && numSeccion != 2 && numSeccion != 3 && numSeccion != 4 && numSeccion != 5 && numSeccion != 6) {
					cursor(70, 4); cout << "Seccion no encontrada";
				}
				else {
					switch (numSeccion) {
					case 1:
						cursor(70, 4); arbolSeccion1->inOrden();
						break;
					case 2:
						cursor(70, 4); arbolSeccion2->inOrden();
						break;
					case 3:
						cursor(70, 4); arbolSeccion3->inOrden();
						break;
					case 4:
						cursor(70, 4); arbolSeccion4->inOrden();
						break;
					case 5:
						cursor(70, 4); arbolSeccion5->inOrden();
						break;
					case 6:
						cursor(70, 4); arbolSeccion6->inOrden();
						break;
					}
				}

			}
			if (opcion == 4 && t == char(32))
			{
				exit(0);
			}
		}

	}
}