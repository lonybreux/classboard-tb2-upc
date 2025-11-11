#pragma once
#include "Nodo.h"
typedef unsigned int uint;

template<class T>
class Lista {
    uint lon;
    Nodo<T>* ini;

public:
    Lista() : ini(nullptr), lon(0) {}

    Nodo<T>* getInicio() {
        return ini;   // puntero al primer nodo de la lista
    }

    bool esVacia() const {
        return lon == 0;
    }

    uint longitud() const {
        return lon;
    }

    // Agregar al inicio
    void agregarInicial(T v) {
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (nuevo != nullptr) {
            nuevo->set_Sgte(ini); // ✅ enlazas con el nodo que antes era la cabeza
            ini = nuevo;          // ahora nuevo pasa a ser la nueva cabeza
            lon++;
        }
    }

    // Agregar en posición
    void agregarPos(T v, uint pos) {
        if (pos > lon) return;
        if (pos == 0) {
            agregarInicial(v);
        }
        else {
            Nodo<T>* aux = ini;
            for (uint i = 1; i < pos; i++) {
                aux = aux->get_Sgte();
            }
            Nodo<T>* nuevo = new Nodo<T>(v);  // 🔹 corregido aquí
            if (nuevo != nullptr) {
                nuevo->set_Sgte(aux->get_Sgte());
                aux->set_Sgte(nuevo);
                lon++;
            }
        }
    }

    // Agregar al final
    void agregarFinal(T v) {
        agregarPos(v, lon);
    }

    T obtenerPos(uint pos) {

        if (pos >= 0 && pos < lon) {
            Nodo<T>* aux = ini;
            for (int i = 0; i < pos; i++) {
                aux = aux->siguiente;
            }
            return aux->valor;
        }
        else {
            return 0;
        }
    }

    T obtenerInicial() {
        return obtenerPos(0);
    }

    void eliminaInicial() {
        if (lon > 0) {
            Nodo<T>* aux = ini;
            ini = ini->get_Sgte();
            delete aux;
            lon--;
        }
    }
};
