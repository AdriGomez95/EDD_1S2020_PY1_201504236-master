#include "Cola.h"


/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/


Cola::Cola()
{
    this->inicial=nullptr;
}


void Cola::InsetarCola(string word)
{
    NodoCola*nuevo = new NodoCola(word);
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


void Cola::EliminarCola(const string word)
{
    NodoCola* temporal = new NodoCola(word);
    if(this->inicial->word==temporal->word)
    {
        delete(this->inicial);
    }

}


string Cola::CodigoLista(){
    string cadena="";
    int contador=0;
   string Dato="digraph G{\n";
   if (this->inicial == NULL) {//Revisa si la lista no esta vacia, de estar retorna NULL
       Dato += "Lista_Vacia";

   } else {

       NodoCola* temporal = inicial;
       while(temporal !=NULL)
       {
           cadena += "node"+to_string(contador)+"[shape = record,label = ""\""+temporal->word+"\"""];\n";
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

void Cola::GraficarCola()
{
    ofstream files;
    files.open("FichasDisponiblesDelJuego.dot");
    files << CodigoLista();
    files.close();
    system("dot -Tpng FichasDisponiblesDelJuego.dot -o FichasDisponiblesDelJuego.png");

    const char* cmd2 = "cmd /c start FichasDisponiblesDelJuego.png ";

    system(cmd2);
}




