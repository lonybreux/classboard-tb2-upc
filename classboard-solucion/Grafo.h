#pragma once
#include <vector>
using namespace std;

template<class T>
class CArco {
public:
	T info;
	int v; //indice del vertice de llegada
	CArco(int vLlegada) {
		info = T();
		v = vLlegada;
	}
};

template<class T>
class CVertice {
public:
	T info;
	vector<CVertice<T>*> antecesores;
	vector<CArco<T>*>* ady; //Lista de adyacencia
	CVertice(T info) {
		this->info = info;
		ady = new vector<CArco<T>*>();
	}


};


template<class T>
class CGrafo {
private:

	//Lista de vértices
	vector<CVertice<T>*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice<T>*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice<T>* vert = new CVertice<T>(info);
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) {
		CVertice<T>* ver = vertices->at(v);
		CVertice<T>* llegada = vertices->at(vLlegada);
		//Crear el objeto ARCO
		CArco<T>* arc = new CArco<T>(vLlegada);
		ver->ady->push_back(arc);

		llegada->antecesores.push_back(ver);

		return ver->ady->size() - 1;
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	T obtenerArco(int v, int apos) {
		CVertice<T>* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {
		CVertice<T>* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int v, int apos) {
		CVertice<T>* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}

	vector<CVertice<T>*> getPrerrequisitos(T v) {
		CVertice<T>* ver = nullptr;

		for (int i = 0; i < vertices->size(); i++) {
			if ((*vertices)[i]->info == v) {
				ver = (*vertices)[i];
				break;
			}
		}

		return ver->antecesores;

	}

};


