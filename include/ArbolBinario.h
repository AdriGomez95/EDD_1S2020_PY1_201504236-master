#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoArbol.h"
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


class ArbolBinario
{
    public:
        ArbolBinario();
        void InsertarJugador(const string jugador);
        void InsertarRecursivo(NodoArbol *raiz,NodoArbol* nuevo);
        NodoArbol* crearArbol(const string jugador);
        void graficar();
        string estructura();
        void imprimirInOrder();
        void ayudante(NodoArbol *raiz);
        string visitar(NodoArbol *raiz);
        NodoArbol *getRaiz();

        void graficarIn();
        void ayudanteIn(NodoArbol* raiz);
        void graficarPos();
        void ayudantePos(NodoArbol* raiz);
        void graficarPre();
        void ayudantePre(NodoArbol* raiz);

        void visitarOrden(NodoArbol*raiz);


        int hijos;

    //private:
        NodoArbol* root;
};

#endif // ARBOLBINARIO_H
