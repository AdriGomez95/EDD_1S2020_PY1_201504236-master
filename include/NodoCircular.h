#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H
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


class NodoCircular
{
    public:
        string palabra;
        NodoCircular();
        NodoCircular(string palabra);

        NodoCircular *sig;
        NodoCircular *ant;

};

#endif // NODOCIRCULAR_H
