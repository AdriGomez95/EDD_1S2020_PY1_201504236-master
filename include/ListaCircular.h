#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NodoCircular.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/


class ListaCircular
{
    public:
        ListaCircular();
        void InsetarListaCircular(string palabra);
        NodoCircular *inicial;
        NodoCircular *ultimo;

        string palabra;
        void GraficarListaCircular();
        string CodigoLista2();
        void GraficarListaDoble();
        void GraficarListaDoble2();
        string CodigoLista3();


};

#endif // LISTACIRCULAR_H
