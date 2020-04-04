#ifndef NODOCOLA_H
#define NODOCOLA_H
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

class NodoCola
{
    public:
        NodoCola();
        string word;
        NodoCola* sig;
        NodoCola(string word);

};

#endif // NODOCOLA_H
