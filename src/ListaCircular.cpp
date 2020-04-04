#include "ListaCircular.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/

ListaCircular::ListaCircular()
{
    this->inicial=NULL;
    this->ultimo=NULL;
}

void ListaCircular::InsetarListaCircular(string palabra)
{
    NodoCircular*nuevo = new NodoCircular(palabra);
    if(this->inicial==NULL)
    {
            nuevo->ant=this->ultimo;
            nuevo->sig=this->inicial;
            this->inicial=nuevo;
            this->ultimo=nuevo;
    }
    else
    {
            this->inicial->ant=nuevo;
            nuevo->sig=this->inicial;
            this->inicial=nuevo;
            this->ultimo->sig=nuevo;
            this->inicial->ant=this->ultimo;
    }
}

string ListaCircular::CodigoLista2()
{
    string cadena="";
    string cadena2="";
    int contador=0, contador3;
   string Dato="digraph G{\n";
   if (this->inicial == NULL) {//Revisa si la lista no esta vacia, de estar retorna NULL
       Dato += "Lista_Vacia";

   } else {

        NodoCircular* temporal = inicial;
        cadena += "node"+to_string(contador)+"[shape = record,label = ""\""+ultimo->palabra+"\"""];\n";
        contador++;
        while(temporal !=ultimo)
           {

               cadena += "node"+to_string(contador)+"[shape = record,label = ""\""+temporal->palabra+"\"""];\n";
               //cadena2 += "\"node""\" -> \"node"+ to_string(contador) +"\";\n";
                cout<<cadena2;
               temporal=temporal->sig;
               contador++;
           }


       temporal =inicial;
       contador=0;
       if(temporal!=ultimo)
       {
           while (temporal->sig !=ultimo)
           {
               cadena+="node"+to_string(contador);
               if(temporal->sig != ultimo)
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
           cadena+="node"+to_string(contador)+"->";
           contador++;
       }
       temporal=ultimo;
       if(temporal==ultimo)
       {
           cadena+="node"+to_string(contador)+"->";
           int contador2=0;
           cadena+="node"+to_string(contador2)+";";
       }





        contador3=contador;

        temporal =ultimo;
       //contador=0;
       if(temporal!=inicial)
       {
           while (temporal->ant !=inicial)
           {
               cadena+="node"+to_string(contador);
               if(temporal->ant != inicial)
               {
                   cadena+="->";
               }
               else
               {
                   cadena +=";";
               }
               temporal =temporal->ant;
               contador--;
               //cout<<"Punteo: "<<temporal->punteo<<"->";
           }
           cadena+="node"+to_string(contador)+"->";
           contador--;
       }
       temporal=ultimo;
       if(temporal==ultimo)
       {
           cadena+="node"+to_string(contador)+"->";
           cadena+="node"+to_string(contador3)+";";

       }







   }
   //contador++;
   Dato+=cadena;
   Dato+=cadena2;

Dato+="}";
       return Dato;
}


void ListaCircular::GraficarListaCircular()
{

    ofstream files;
    files.open("ListaDiccionario.dot");
    files << CodigoLista2();
    files.close();
    system("dot -Tpng ListaDiccionario.dot -o ListaDiccionario.png");

    const char* cmd2 = "cmd /c start ListaDiccionario.png ";

    system(cmd2);

}













string ListaCircular::CodigoLista3()
{
    string cadenax="";
    int contador=0;
   string Cadenita="digraph G{\n";
   if (this->inicial == NULL) {//Revisa si la lista no esta vacia, de estar retorna NULL
       Cadenita += "Lista_Vacia";

   } else {

        NodoCircular* temporal = inicial;
        cadenax += "node"+to_string(contador)+"[shape = record,label = ""\""+ultimo->palabra+"\"""];\n";
        contador++;
        while(temporal !=ultimo)
           {

               cadenax += "node"+to_string(contador)+"[shape = record,label = ""\""+temporal->palabra+"\"""];\n";
               //cadena2 += "\"node""\" -> \"node"+ to_string(contador) +"\";\n";
                //cout<<cadena2;
               temporal=temporal->sig;
               contador++;
           }


       temporal =inicial;
       contador=0;
       if(temporal!=ultimo)
       {
           while (temporal->sig !=ultimo)
           {
               cadenax+="node"+to_string(contador);
               if(temporal->sig != ultimo)
               {
                   cadenax+="->";
               }
               else
               {
                   cadenax +=";";
               }
               temporal =temporal->sig;
               contador++;
               //cout<<"Punteo: "<<temporal->punteo<<"->";
           }
           cadenax+="node"+to_string(contador)+"->";
           contador++;
       }
       temporal=ultimo;
       if(temporal==ultimo)
       {
           cadenax+="node"+to_string(contador)+";";
       }





        temporal =ultimo;
       //contador=0;
       if(temporal!=inicial)
       {
           while (temporal->ant !=inicial)
           {
               cadenax+="node"+to_string(contador);
               if(temporal->ant != inicial)
               {
                   cadenax+="->";
               }
               else
               {
                   cadenax +=";";
               }
               temporal =temporal->ant;
               contador--;
               //cout<<"Punteo: "<<temporal->punteo<<"->";
           }
           cadenax+="node"+to_string(contador)+"->";
           contador--;
       }
       temporal=ultimo;
       if(temporal==ultimo)
       {
           cadenax+="node"+to_string(contador)+";";

       }







   }
   //contador++;
   Cadenita+=cadenax;

Cadenita+="}";
       return Cadenita;
}


void ListaCircular::GraficarListaDoble()
{

    ofstream files;
    files.open("FichasDeJugador1.dot");
    files << CodigoLista3();
    files.close();
    system("dot -Tpng FichasDeJugador1.dot -o FichasDeJugador1.png");

    const char* cmd2 = "cmd /c start FichasDeJugador1.png ";

    system(cmd2);

}


void ListaCircular::GraficarListaDoble2()
{

    ofstream files;
    files.open("FichasDeJugador2.dot");
    files << CodigoLista3();
    files.close();
    system("dot -Tpng FichasDeJugador2.dot -o FichasDeJugador2.png");

    const char* cmd2 = "cmd /c start FichasDeJugador2.png ";

    system(cmd2);

}








