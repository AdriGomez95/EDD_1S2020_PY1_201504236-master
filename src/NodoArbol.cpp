#include "NodoArbol.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/

NodoArbol::NodoArbol()
{
    //ctor
}

NodoArbol::NodoArbol(const string jugador)
{
    this->jugador=jugador;
    this->hijoDer=NULL;
    this->hijoIzq=NULL;
    this->nuevaLista=NULL;


}

NodoArbol* NodoArbol::getDerecho()
{
    return this->hijoDer;
}

NodoArbol* NodoArbol::getIzquierdo()
{
    return this->hijoIzq;
}

void NodoArbol::setDerecho(NodoArbol* j)
{
    this->hijoDer = j;
}

void NodoArbol::setIzquierdo(NodoArbol*j)
{
    this->hijoIzq= j;
}
