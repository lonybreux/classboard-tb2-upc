#include "Matricula.h"
#include"menu.h"
#include <iostream>
using namespace std;

int main() {

    vector<string> colaAUX = leerCola();
    bool colaFull;
    if (colaAUX.size() < 5) {
        colaFull = false;
    }
    else {
        colaFull = true;
    }

    if (Login())
    {
        while (true) {
            
            MenuOpcion opcion = mostrarOpciones(colaFull);

            if (opcion == MATRICULA && !colaFull) menuMatricula();
            else if (opcion == BLACKBOARD) BlackBoard();
            
        }
    }

    



    system("pause>0");
    return 0;
}

