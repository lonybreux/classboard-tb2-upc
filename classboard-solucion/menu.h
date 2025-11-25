#pragma once
#include<iostream>
#include<string>
#include"Login.h"

using namespace std;
enum MenuOpcion { NINGUNO, MATRICULA, BLACKBOARD };
enum activo { MATRI, BLACK };

activo activ = MATRI;

void verificar(activo act)
{
	activ = act;
}
void marcoMenu(int x, int y, int z, int k)
{

	//Horizontal
	cursor(x - 1, y); cout << char(201);
	cursor(x - 1, y + 6); cout << char(200);
	for (int j = 0; j < 35; j++)
	{
		cursor(x, y); cout << char(205);
		cursor(x, y + 6); cout << char(205);
		x++;
	}
	cursor(x, y); cout << char(187);
	cursor(x, y + 6); cout << char(188);

	//vertical
	for (int i = 0; i < 5; i++)
	{
		cursor(z - 1, k); cout << char(186);
		cursor(z + 35, k); cout << char(186);
		k++;
	}

}


void menu(int cod)
{
	cursor(70, 20); cout << "BIENVENIDO " << to_string(cod);


	cursor(33, 9); cout << " __  __  _____  _   _   _ _      ____  _____      ___  ____   ____ ___ ___  _   _ _____ ____    ";
	cursor(33, 10); cout << "|  \\/  ||_____|| \\ | | | | |    |  _ \\| ____|    / _ \\|  _ \\ / ___|_ _/ _ \\| \\ | | ____/ ___|   " << endl;
	cursor(33, 11); cout << "| |\\/| |||_|   |  \\| | | | |    | | | |  _|     | | | | |_) | |    | | | | |  \\| |  _| \\___ \\   " << endl;
	cursor(33, 12); cout << "| |  | |||____ | |\\  | | | |    | |_| | |___    | |_| |  __/| |___ | | |_| | |\\  | |___ ___) |  " << endl;
	cursor(33, 13); cout << "|_|  |_||_____||_| \\_| \\___/    |____/|_____|    \\___/|_|    \\____|___\\___/|_| \\_|_____|____/   " << endl;



}
void colorMatri(bool x)
{
	if (x) {
		Console::ForegroundColor = ConsoleColor::Red;
		marcoMenu(40, 27, 40, 28);
		cursor(48, 30); cout << "M A T R I C U L A";
		Console::ForegroundColor = ConsoleColor::DarkGray;
		marcoMenu(82, 27, 82, 28);
		cursor(90, 30); cout << "B L A C K B O A R D";
	}
	else {
		Console::ForegroundColor = ConsoleColor::Yellow;
		marcoMenu(40, 27, 40, 28);
		cursor(48, 30); cout << "M A T R I C U L A";
		Console::ForegroundColor = ConsoleColor::DarkGray;
		marcoMenu(82, 27, 82, 28);
		cursor(90, 30); cout << "B L A C K B O A R D";
	}

}
void colorBlackBoard()
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	marcoMenu(82, 27, 82, 28);
	cursor(90, 30); cout << "B L A C K B O A R D";
	Console::ForegroundColor = ConsoleColor::DarkGray;
	marcoMenu(40, 27, 40, 28);
	cursor(48, 30); cout << "M A T R I C U L A";
}
void marcoPrincipal()
{

	for (int i = 2; i < 144; i++)
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

	cursor(2, 0);
	cout << char(201);
	cursor(2, 39);
	cout << char(200);

	for (int j = 1; j < 39; j++)
	{
		cursor(144, j);
		cout << char(186);
		cursor(2, j);
		cout << char(186);
	}
}
MenuOpcion mostrarOpciones(bool colaFULL)
{

	Console::ForegroundColor = ConsoleColor::White;
	menu(codigoUsuarioActual);
	Console::ForegroundColor = ConsoleColor::Gray;
	marcoPrincipal();
	int x = 57;

	if (activ == MATRI)
	{

		colorMatri(colaFULL);
		cursor(x, 34);
		cout << "^";
	}
	if (activ == BLACK)
	{

		colorBlackBoard();
		cursor(x + 42, 34);
		cout << "^";
	}

	while (true)
	{
		if (_kbhit())
		{
			char t = _getch();

			cursor(x, 34);
			cout << " ";


			// Dibujar cursor en nueva posición
			if (activ == MATRI)
			{

				cursor(x, 34);
				cout << "^";
			}
			if (activ == BLACK)
			{
				cursor(x + 42, 34);
				cout << "^";
			}

			// Selección con la tecla 'ESPACIO'
			if (t == char(32))
			{
				if (activ == MATRI)
				{
					return MATRICULA;
				}
				if (activ == BLACK)
				{
					Console::ForegroundColor = ConsoleColor::White;
					return BLACKBOARD;
				}
			}
		}
	}
}
