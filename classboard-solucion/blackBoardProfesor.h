#pragma once
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
using namespace System;

void const perfilProfesor() {

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
	cursor(67, 28), cout << "Carrera: Ingenieria de Software";
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
void marcosCursoProfesor(int x, int y, int z, int k)
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
	cursor(2, 31); cout << "Calificaciones";

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
	Console::ForegroundColor = ConsoleColor::Yellow;
	marcoOpciones(1, 14, 1, 15);
	cursor(2, 16); cout << "Pagina principal";
	while (true) {

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
				marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Calificaciones";
				marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion";


				switch (opcion) {
				case 0: marcoOpciones(1, 14, 1, 15); cursor(2, 16); cout << "Pagina principal"; break;
				case 1: marcoOpciones(1, 19, 1, 20); cursor(2, 21); cout << "Perfil"; break;
				case 2: marcoOpciones(1, 24, 1, 25); cursor(2, 26); cout << "Cursos"; break;
				case 3: marcoOpciones(1, 29, 1, 30); cursor(2, 31); cout << "Calificaciones"; break;
				case 4: marcoOpciones(1, 34, 1, 35); cursor(2, 36); cout << "Cerrar Sesion"; break;
				}

				if (opcion == 0)
				{

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
					cursor(2, 31); cout << "Calificaciones";

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";


					Console::ForegroundColor = ConsoleColor::Yellow;

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";

				}

				else if (opcion == 2)
				{

					Console::ForegroundColor = ConsoleColor::White;

					marcoOpciones(1, 14, 1, 15);
					cursor(2, 16); cout << "Pagina principal";

					marcoOpciones(1, 19, 1, 20);
					cursor(2, 21); cout << "Perfil";

					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Calificaciones";

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";

					Console::ForegroundColor = ConsoleColor::Yellow;

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

					Console::ForegroundColor = ConsoleColor::Yellow;
					marcoOpciones(1, 29, 1, 30);
					cursor(2, 31); cout << "Calificaciones";

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
					cursor(2, 31); cout << "Calificaciones";

					Console::ForegroundColor = ConsoleColor::Yellow;

					marcoOpciones(1, 34, 1, 35);
					cursor(2, 36); cout << "Cerrar Sesion";

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

					Console::ForegroundColor = ConsoleColor::Yellow;

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

					Console::ForegroundColor = ConsoleColor::Yellow;
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

					Console::ForegroundColor = ConsoleColor::Yellow;
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

					Console::ForegroundColor = ConsoleColor::Yellow;
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


				//PARA IMPRIMIR LOS CURSOS
				int auxX = 40;
				int auxY = 20;
				switch (opcion) {

				case 1:

					system("cls");
					Console::ForegroundColor = ConsoleColor::Gray;
					marcoBaclkBoardProfesor();
					perfil(codigoUsuarioActual);
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
					cursor(31, 9); cout << " BUSQUEDA POR PROFESOR        V";
					cursor(69, 9); cout << " ORDENAR POR CREDITOS         V";
					cursor(107, 9); cout << " ORDENAR POR NRC              V";
					Console::ForegroundColor = ConsoleColor::White;

					cursor(30, 13); cout << "202520-AC";

					break;
				}


			}

			//Funciones para las opciones de los cursos 
			if (opcionSuperior == 1 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoardProfesor();
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



			}
			if (opcionSuperior == 2 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoardProfesor();
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


			}
			if (opcionSuperior == 3 && t == char(32))
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Gray;
				marcoBaclkBoardProfesor();
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



			}

			if (opcion == 4 && t == char(32))
			{
				exit(0);
			}
		}

	}
}