#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "ListaSimple.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/



class NodoArbol
{
    public:
        NodoArbol();
        NodoArbol(const string jugador);
        NodoArbol* getDerecho();
        NodoArbol* getIzquierdo();

        void setDerecho(NodoArbol* j);
        void setIzquierdo(NodoArbol* j);
        int numero;

    //private:
        NodoArbol* hijoDer;
        string jugador;
        NodoArbol* hijoIzq;
        ListaSimple* nuevaLista;
};

#endif // NODOARBOL_H
