#ifndef NODOSCOREBOARD_H
#define NODOSCOREBOARD_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

/*
----------------------------
                            |
   @Author: Adriana G�mez   |
                            |
----------------------------
*/
using namespace std;

class NodoScoreBoard
{
    public:
        int punteo;
        string name;
        NodoScoreBoard* sig;
        NodoScoreBoard();
        NodoScoreBoard(string name, int punteo);

};

#endif // NODOLISTA_H
