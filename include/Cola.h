#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"


/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/



class Cola
{
    public:
        Cola();
        void InsetarCola(string word);
        void EliminarCola(const string word);
        NodoCola*inicial;

        string word;
        void GraficarCola();
        void GraficarCola2();
        string CodigoLista();
};

#endif // COLA_H
