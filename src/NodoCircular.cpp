#include "NodoCircular.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/

NodoCircular::NodoCircular()
{
    this->palabra="";
    this->sig = nullptr;
    this->ant = nullptr;
}


NodoCircular::NodoCircular(string palabra)
{
    this->palabra=palabra;
    this->sig = nullptr;
    this->ant = nullptr;
}

