#ifndef JUGADOR_H
#define JUGADOR_H
#include "ListaSimple.h"


class Jugador
{
    public:
        Jugador();
        Jugador(const string nombre);
        void insertarListaPunteo(ListaSimple*l);
        ListaSimple *getPunteo(int punteo);
        void visitar();

        string nombre;

    private:
        ListaSimple* listaPunteo;
};

#endif // JUGADOR_H
