#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/
using namespace std;

//------------------NODOS--------------------------

class NodoMatriz
{
    public:
        int Fila;
        int Columna;
        string letra;
        NodoMatriz();
        NodoMatriz(int Fila,int Columna,string letra);
        NodoMatriz* Izquierda;
        NodoMatriz* Derecha;
        NodoMatriz* Arriba;
        NodoMatriz* Abajo;
};

class NodoEncabezado
{
    public:
        int ID;
        NodoEncabezado();
        NodoEncabezado(int ID);
        NodoEncabezado* Siguiente;
        NodoEncabezado* Anterior;
        NodoMatriz* Acceso;

};


class ListaEncabezado
{
    public:
        ListaEncabezado();
        void InsertarEncabezado(int ID);
        void InsertarEncabezado(int ID,NodoMatriz* Matriz);
        void EliminarEncabezado(int ID);
        int MayoMenorE(int Val1,int Val2);

        NodoEncabezado* BuscarEncabezado(int ID);
        NodoEncabezado* Primero;
        NodoEncabezado* Ultimo;
        NodoEncabezado* Actual;

};

class Matriz
{
    public:
        Matriz();
        void InsertarMatriz(int Fila,int Columna,string letra);
        void GraficarMatriz();

        int MayoMenorM(int Val1,int Val2);

        string GraficarEncabezado(NodoEncabezado* Temp);
        string GraficarNodoM(NodoMatriz* Temp);
        string GCabezas();
        string GNodos();

        string getNodos(NodoMatriz* Temp);
        string GetFila(NodoEncabezado* Temp);
        string GetColumna(NodoEncabezado* Temp);

        //...................Graficar Capa---------------------------
        NodoEncabezado* RecuperarUltimo(ListaEncabezado* Encabezado);
    void GraficarCapas();
        NodoMatriz* BuscarPosicion(int Fila,int Columna);
        //----------------------------------------

        ListaEncabezado* EncabezadoFila;
        ListaEncabezado* EncabezadoColumna;
        NodoMatriz* Actual;
        NodoMatriz* Modificar(int Fila,int Columna,string letra);


        Matriz* BusquedaInsercion(Matriz* Global);

        //...................Graficar Capa---------------------------



};


#endif // MATRIZ_H
