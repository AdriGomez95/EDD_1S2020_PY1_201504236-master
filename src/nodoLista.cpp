#include "nodoLista.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/


nodoLista::nodoLista()
{
    this->punteo=0;
    this->sig = nullptr;
}

nodoLista::nodoLista(int punteo)
{
    this->punteo=punteo;
    this->sig = nullptr;
}


//Compara si un Nodo es igual a alguno de la lista
bool nodoLista::equals(nodoLista* Otro) {
    if (Otro == nullptr)
        return false;
    if (this->punteo == 0)
        return Otro->punteo == 0;
    if (Otro->punteo == 0)
        return false;
    return this->punteo == Otro->punteo;
}
