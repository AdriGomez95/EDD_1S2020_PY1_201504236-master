#ifndef NODOLISTA_H
#define NODOLISTA_H

/*
----------------------------
                            |
   @Author: Adriana G�mez   |
                            |
----------------------------
*/


class nodoLista
{
    public:
        int punteo;
        nodoLista* sig;
        nodoLista();
        nodoLista(int punteo);

        bool equals(nodoLista* Otro);
};

#endif // NODOLISTA_H
