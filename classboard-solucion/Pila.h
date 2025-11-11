#pragma once

#include "Nodo.h"

typedef unsigned int uint;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
	uint lon;
public:
	Pila(): tope(nullptr),lon(0){}

	void apilar(T v);
	T desapilar();
	bool esVacia();
	T obtenerPosicion(uint x){
		T elem;
		Nodo<T>* aux = tope;
		
		for (uint i = 0; i < x; i++) {
			aux = aux->get_Sgte();
		}

		elem = aux->valor;

		return elem;

	}

	uint longitud() const {
		return lon;
	}
};

template<class T>
void Pila<T>::apilar(T v) {
	if (esVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		tope = new Nodo<T>(v, tope);
	}
	lon++;
}

template<class T>
T Pila<T>::desapilar() {
	if (esVacia()) {
		return nullptr;
	}
	else {
		T elemento = (T)(tope->valor);
		tope = (Nodo<T>*)(tope->get_Sgte());
		lon--;
		return elemento;
	}
}


template<class T>
bool Pila<T>::esVacia() {
	return tope == nullptr;
}