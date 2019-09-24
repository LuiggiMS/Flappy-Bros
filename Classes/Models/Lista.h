#ifndef __LISTA_H__
#define __LISTA_H__

#include "nodo.h"
#include "Nivel.h"
#include<iostream>
using namespace std;

template<class T>
class Lista {
private:
    Nodo<T> *inicio;
    
public:
    Lista() { inicio = NULL; }
    ~Lista();
    void insertarInicio(T v);
    void insertarFinal(T v);
    void mostrar();
};

//------------------------------------------------------------------------------
template<class T>
Lista<T>::~Lista() {
    Nodo<T> *temp;
    while(inicio != NULL) {
        temp = inicio;
        inicio=inicio->siguiente;
        delete temp;
        temp=NULL;
    }
    delete inicio;
    inicio=NULL;
}

//------------------------------------------------------------------------------
template<class T>
void Lista<T>::insertarInicio(T v){
    Nodo<T> *nodo = new Nodo<T>(v);
    
    if(inicio == NULL)
        inicio = nodo;
    else
        nodo->siguiente = inicio;
    inicio = nodo;
    //delete nodo;
    nodo = NULL;
}

//------------------------------------------------------------------------------
template<class T>
void Lista<T>::insertarFinal(T v) {
}

//------------------------------------------------------------------------------
template<class T>
void Lista<T>::mostrar() {
    Nodo<T> *nodo = inicio;
    cout<< "L -> ";
    do {
        Nivel* pto = (Nivel*)(nodo->valor);
        cout << pto->toString();
        
        if(nodo != NULL)
            cout<< "-> ";
        nodo = nodo->siguiente;
    } while(nodo != NULL);
    cout << endl;
}

//------------------------------------------------------------------------------

#endif
