#include "NodoScoreBoard.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/


NodoScoreBoard::NodoScoreBoard()
{
    this->punteo=0;
    this->name="";
    this->sig = nullptr;
}

NodoScoreBoard::NodoScoreBoard(string name, int punteo)
{
    this->punteo=punteo;
    this->name=name;
    this->sig = nullptr;
}

