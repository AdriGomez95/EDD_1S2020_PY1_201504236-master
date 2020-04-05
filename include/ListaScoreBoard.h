#ifndef LISTASCOREBOARD_H
#define LISTASCOREBOARD_H
#include "NodoScoreBoard.h"
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



class ListaScoreBoard
{
    public:
        ListaScoreBoard();
        void InsetarScoreBoard(string name, int punteo);
        NodoScoreBoard*inicial;

        int punteo;
        string name;
        void GraficarScoreBoard();
        string CodigoLista();

};

#endif // LISTASIMPLE_H
