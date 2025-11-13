#pragma once

#include <iostream>
#include "HashEntidad.h"

template<class T>
class HashTabla {

	HashEntidad<T>** tabla;
	int numElementos;
	int TABLE_SIZE;

public:
	HashTabla(int TABLE_SIZE = 128) {
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new HashEntidad<T> * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++) {
			tabla[i] = nullptr;
		}
		numElementos = 0;
	}

	~HashTabla() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (tabla[i] != nullptr)
				delete tabla[i];
		}

		delete[] tabla;
	}

	void insertar(int key, T value) {
		int base, step, hash;

		if (numElementos == TABLE_SIZE) return;

		//Función Hash
		base = key % TABLE_SIZE;
		hash = base;

		step = 0;

		while (tabla[hash] != nullptr) {
			hash = (base + step) % TABLE_SIZE;
			step++;
		}

		tabla[hash] = new HashEntidad<T>(key, value);
		numElementos++;
	}

	int size() {
		return TABLE_SIZE;
	}

	int sizeactual() {
		return numElementos;
	}

	int buscar(int key) {
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE; //hash1 es = a hash2 cuando step=0;
		while (true)
		{
			if (tabla[i] == nullptr)return -1;
			else if (tabla[i]->getKey() == key) {
				return i;
			}
			else step++;

			i = (base + step) % TABLE_SIZE;
		}
	}

	T getValue(int key) {
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE;
		while (true) {
			if (tabla[i] == nullptr) return T();
			else if (tabla[i]->getKey() == key) {
				return tabla[i]->getValue();
			}
			else step++;

			i = (base + step) % TABLE_SIZE;
		}
	}


};