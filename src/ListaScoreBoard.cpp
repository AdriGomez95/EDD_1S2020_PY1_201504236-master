#include "ListaScoreBoard.h"



/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/

ListaScoreBoard::ListaScoreBoard()
{
    this->inicial=NULL;
}

void ListaScoreBoard::InsetarScoreBoard(string name, int punteo)
{
    NodoScoreBoard*nuevo = new NodoScoreBoard(name,punteo);
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


string ListaScoreBoard::CodigoLista(){
    string cadena="";
    string cadena2=": ";
    int contador=0;
   string Dato="digraph G{\n";
   if (this->inicial == NULL) {//Revisa si la lista no esta vacia, de estar retorna NULL
       Dato += "Lista_Vacia";

   } else {

       NodoScoreBoard* temporal = inicial;
       while(temporal !=NULL)
       {
           cadena += "node"+to_string(contador)+"[shape = record,label = ""\""+temporal->name+cadena2+ to_string(temporal->punteo) +"\"""];\n";
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

void ListaScoreBoard::GraficarScoreBoard()
{
    ofstream files;
    files.open("ListaScoreBoard.dot");
    files << CodigoLista();
    files.close();
    system("dot -Tpng ListaScoreBoard.dot -o ListaScoreBoard.png");

    const char* cmd2 = "cmd /c start ListaScoreBoard.png ";

    system(cmd2);
}


