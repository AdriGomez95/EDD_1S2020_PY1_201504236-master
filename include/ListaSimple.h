#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodoLista.h"
#include<iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/



class ListaSimple
{
    public:
        ListaSimple();
        void Insetar(int punteo);
        nodoLista*inicial;

        int punteo;
        void Graficar();
        string CodigoLista();
        void Graficar2();
        string CodigoLista2();

};

#endif // LISTASIMPLE_H
