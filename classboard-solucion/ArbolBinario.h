#ifndef __ARBOLBB_HPP__
#define __ARBOLBB_HPP__

#include <functional>
#include <string>
using namespace std;

template <class T>
class NodoBB {
public:
	T elemento;
	NodoBB* izq;
	NodoBB* der;
};

template <class T>
class ArbolBB {
	typedef function<int(T, T)> Comp; //Lambda

	NodoBB<T>* raiz;

	void(*procesarXY)(T, int, int);

	Comp comparar; // lambda de criterio de comparación
	int valor = 0;
	vector<int>numeros;

private:

	bool _buscar(NodoBB<T>* nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return true;
			else if (r < 0) {
				return _buscar(nodo->der, e);
			}
			else {
				return _buscar(nodo->izq, e);
			}
		}
	}
	NodoBB<T>* _obtener(NodoBB<T>* nodo, T e) {
		if (nodo == nullptr) return nullptr;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return nodo;
			else if (r < 0) {
				return _obtener(nodo->der, e);
			}
			else {
				return _obtener(nodo->izq, e);
			}

		}
	}
	bool _insertar(NodoBB<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new NodoBB<T>();
			nodo->elemento = e;
			nodo->izq = nodo->der = nullptr;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return false;
			else if (r < 0) {
				return _insertar(nodo->der, e);
			}
			else {
				return _insertar(nodo->izq, e);
			}
		}
	}

	void _imprimirenOrdenXY(NodoBB<T>* nodo, int& x, int& y) {

		if (!nodo) return;

		_imprimirenOrdenXY(nodo->izq, x, y);

		if (procesarXY != nullptr)
			procesarXY(nodo->elemento, x, y);

		x += 38;
		if (x > 110)
		{
			y = 30;
			x = 32;
		}

		_imprimirenOrdenXY(nodo->der, x, y);
	}

	void _imprimirPreOrdenXY(NodoBB<T>* nodo, int& x, int& y)
	{
		if (nodo == nullptr)return;
		if (procesarXY != nullptr)
			procesarXY(nodo->elemento, x, y);


		x += 38;
		if (x > 110)
		{
			y = 30;
			x = 32;
		}
		_imprimirPreOrdenXY(nodo->izq, x, y);
		_imprimirPreOrdenXY(nodo->der, x, y);
	}

	//Funcion para contan en un rango especifico
	int _contarEnRango(NodoBB<T>* nodo, T min, T max)
	{
		if (nodo == nullptr) return 0;

		int contador = 0;
		contador += _contarEnRango(nodo->izq, min, max);
		if (nodo->elemento >= min && nodo->elemento <= max)
		{
			//Un contador el cual irá aumentando según la condicion se cumpla
			contador++;
			//Un vector el cual almacena los elementos que están dentro del rango para posteriormente poder imprimirlos en el cpp
			numeros.push_back(nodo->elemento);
		}
		contador += _contarEnRango(nodo->der, min, max);

		return contador;
	}


	void _postOrdenXY(NodoBB<T>* nodo, int& x, int& y)
	{
		bool activ = true;
		if (nodo == nullptr)return;

		_postOrdenXY(nodo->izq, x, y);
		_postOrdenXY(nodo->der, x, y);

		if (procesarXY != nullptr)
		{
			procesarXY(nodo->elemento, x, y);
		}
		x += 38;
		if (x > 110)
		{
			y = 30;
			x = 32;
		}
	}



	int _cantidad(NodoBB<T>* nodo) {
		//La cantidad de nodos del árbol es:
		//	0 si es vacío
		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha

		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}

	}

	bool _eliminar(NodoBB<T>*& nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r < 0) {
				return _eliminar(nodo->der, e);
			}
			else if (r > 0) {
				return _eliminar(nodo->izq, e);
			}
			else { // r==0 es porque se encontró el elemento e en el arbol
				if (nodo->der == nullptr && nodo->izq == nullptr) {//caso 1
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->izq == nullptr) { //caso 2
					nodo = nodo->der;
					return true;
				}
				else if (nodo->der == nullptr) { //caso 3
					nodo = nodo->izq;
					return true;
				}
				else { //caso 4
					NodoBB<T>* aux = nodo->der; //Se establece buscar el menor elemento por la derecha
					while (aux->izq != nullptr)
					{
						aux = aux->izq; //Se obtiene la hoja menor
					}
					nodo->elemento = aux->elemento; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, aux->elemento); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}
	}

public:

	ArbolBB(void(*procesarXYptr)(T, int, int), bool opcion) {

		this->procesarXY = procesarXYptr;

		//true = 1
		if (opcion) {
			this->comparar = [](T a, T b)->int {

				auto extraerHora = [](const string& h) -> int {
					// formato esperado: HH:MM - HH:MM
					// obtenemos solo los dígitos iniciales
					int i = 0;
					while (i < h.size() && isdigit(h[i])) i++;

					if (i == 0) return -1;        // NO había dígitos -> error
					return stoi(h.substr(0, i));  // HH
					};

				int iniA = extraerHora(a.horario);
				int iniB = extraerHora(b.horario);

				if (iniA != iniB)
					return iniA - iniB;

				return a.nrc - b.nrc;
				};
		}
		// false = 0 -> ordenar exclusivamente por NRC
		else {
			this->comparar = [](T a, T b)->int {
				return a.nrc - b.nrc;  // Comparación 100% por NRC
				};
		}



		raiz = nullptr;
	}

	bool insertar(T e) {
		return _insertar(raiz, e);
	}
	void enOrden() {
		_enOrden(raiz);
	}
	void preOrden() {
		_preOrden(raiz);
	}
	void postOrden() {
		_postOrden(raiz);
	}
	void postOrdenXY(int x, int y)
	{
		_postOrdenXY(raiz, x, y);
	}
	void imprimirNodoXY(T e, int x, int y) {
		NodoBB<T>* nodo = Obtener(e);
		if (nodo && procesarXY) {
			procesarXY(nodo->elemento, x, y);
		}
	}
	void imprimirenOrdenXY(int x, int y) {
		_imprimirenOrdenXY(raiz, x, y);
	}
	void imprimirPreOrdenXY(int x, int y)
	{
		_imprimirPreOrdenXY(raiz, x, y);
	}
	vector<int> getNumeros() { return numeros; }
	int contarEnRango(int min, int max)
	{
		return _contarEnRango(raiz, min, max);
	}
	int cantidad() {
		return _cantidad(raiz);
	}

	bool BuscarPorNRC(int nrc) {
		T temp{};
		temp.nrc = nrc;
		temp.horario = "00:00";
		return Buscar(temp);
	}

	T ObtenerPorNRC(int nrc) {
		T temp{};
		temp.nrc = nrc;
		NodoBB<T>* nodo = Obtener(temp);
		if (nodo != nullptr) {
			return nodo->elemento;
		}
		return temp; // vacío si no existe
	}

	bool Buscar(T e) {
		return _buscar(raiz, e);
	}

	bool Eliminar(T e) {
		return _eliminar(raiz, e);
	}
	NodoBB<T>* Obtener(T e) {
		return _obtener(raiz, e);
	}

};

#endif
