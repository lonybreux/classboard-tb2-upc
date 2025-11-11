#pragma once

template<class T>
class Nodo {
public:
    T valor;
    Nodo<T>* siguiente;

public:
    Nodo(T v, Nodo<T>* sig = nullptr) {
        valor = v;
        siguiente = sig;
    }

    void set_Sgte(Nodo<T>* sig) {
        siguiente = sig;
    }

    Nodo<T>* get_Sgte() const {
        return siguiente;
    }
};
