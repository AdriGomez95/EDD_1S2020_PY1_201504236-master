#include "ListaSimple.h"
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

ListaSimple::ListaSimple()
{
    this->inicial=NULL;
}

void ListaSimple::Insetar(int punteo)
{
    nodoLista*nuevo = new nodoLista(punteo);
    if(this->inicial==NULL)
    {
            this->inicial=nuevo;
    }
    else
    {
            nuevo->sig=this->inicial;
            this->inicial=nuevo;


    }
}


string ListaSimple::CodigoLista(){
    string cadena="";
    string cadena2="Punteo: ";
    int contador=0;
   string Dato="digraph G{\n";
   if (this->inicial == NULL) {//Revisa si la lista no esta vacia, de estar retorna NULL
       Dato += "Lista_Vacia";

   } else {

       nodoLista* temporal = inicial;
       while(temporal !=NULL)
       {
           cadena += "node"+to_string(contador)+"[shape = record,label = ""\""+cadena2+ to_string(temporal->punteo) +"\"""];\n";
           //cadena2 += "\"node""\" -> \"node"+ to_string(contador) +"\";\n";

           temporal=temporal->sig;
           contador++;
       }
       temporal =inicial;
       contador=0;
       if(temporal!=NULL)
       {
           while (temporal->sig !=NULL)
           {
               cadena+="node"+to_string(contador);
               if(temporal->sig != NULL)
               {
                   cadena+="->";
               }
               else
               {
                   cadena +=";";
               }
               temporal =temporal->sig;
               contador++;
               //cout<<"Punteo: "<<temporal->punteo<<"->";
           }
           cadena+="node"+to_string(contador);
       }

   }
   //contador++;
   Dato+=cadena;

Dato+="}";
       return Dato;
}

void ListaSimple::Graficar()
{
    ofstream files;
    files.open("ListaPunteo1.dot");
    files << CodigoLista();
    files.close();
    system("dot -Tpng ListaPunteo1.dot -o ListaPunteo1.png");

    const char* cmd2 = "cmd /c start ListaPunteo1.png ";

    system(cmd2);
}






//****PARA JUGADOR 2*****
void ListaSimple::Graficar2()
{
    ofstream files;
    files.open("ListaPunteo2.dot");
    files << CodigoLista();
    files.close();
    system("dot -Tpng ListaPunteo2.dot -o ListaPunteo2.png");

    const char* cmd3 = "cmd /c start ListaPunteo2.png ";

    system(cmd3);
}



