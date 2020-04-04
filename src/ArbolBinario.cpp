#include "ArbolBinario.h"

/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/

string cadena="";
string cadena2="";
int contador=0;


ArbolBinario::ArbolBinario()
{
    this->root=NULL;
    this->hijos=0;
}

NodoArbol* ArbolBinario::crearArbol(const string jugador)
{
    NodoArbol* nuevo = new NodoArbol(jugador);
    return nuevo;
}

void ArbolBinario::InsertarJugador(const string jugador)
{
    NodoArbol* nuevo = this->crearArbol(jugador);
    nuevo->numero=this->hijos;
    if(this->root != NULL)
    {
        this->InsertarRecursivo(this->getRaiz(),nuevo);
    }
    else
    {
        this->root=nuevo;
    }
    this->hijos=this->hijos+1;
}

void ArbolBinario::InsertarRecursivo(NodoArbol* raiz,NodoArbol*nuevo)
{
    if(raiz->jugador[0]==nuevo->jugador[0])
    {
        /**** para el tercer caracter*****/
        if(raiz->jugador[1]==nuevo->jugador[1])
        {
            /**** para el tercer caracter*****/
            if(raiz->jugador[2]==nuevo->jugador[2])
            {
                /**** para el tercer caracter*****/
                if(raiz->jugador[3] < nuevo->jugador[3])
                {
                    if(raiz->getDerecho()!=NULL)
                    {
                        this->InsertarRecursivo(raiz->getDerecho(),nuevo);
                    }
                    else
                    {
                        raiz->setDerecho(nuevo);
                    }

                }
                else if(raiz->jugador[3] > nuevo->jugador[3])
                {
                    if(raiz->getIzquierdo() != NULL)
                    {
                        this->InsertarRecursivo(raiz->getIzquierdo(),nuevo);
                    }
                    else
                    {
                        raiz->setIzquierdo(nuevo);
                    }
                }
            }
            else if(raiz->jugador[2] < nuevo->jugador[2])
            {
                if(raiz->getDerecho()!=NULL)
                {

                    this->InsertarRecursivo(raiz->getDerecho(),nuevo);
                }
                else
                {
                    raiz->setDerecho(nuevo);
                }
            }
            else if(raiz->jugador[2] > nuevo->jugador[2])
            {
                if(raiz->getIzquierdo() != NULL)
                {
                    this->InsertarRecursivo(raiz->getIzquierdo(),nuevo);
                }
                else
                {
                    raiz->setIzquierdo(nuevo);
                }
            }
        }
        else if(raiz->jugador[1] < nuevo->jugador[1])
        {
            if(raiz->getDerecho()!=NULL)
            {
                this->InsertarRecursivo(raiz->getDerecho(),nuevo);
            }
            else
            {
                raiz->setDerecho(nuevo);
            }
        }
        else if(raiz->jugador[1] > nuevo->jugador[1])
        {
            if(raiz->getIzquierdo() != NULL)
            {
                this->InsertarRecursivo(raiz->getIzquierdo(),nuevo);
            }
            else
            {
                raiz->setIzquierdo(nuevo);
            }
        }
    }
    else if(raiz->jugador[0] < nuevo->jugador[0])
    {
        if(raiz->getDerecho()!=NULL)
        {
            this->InsertarRecursivo(raiz->getDerecho(),nuevo);
        }
        else
        {
            raiz->setDerecho(nuevo);
        }
    }
    else if(raiz->jugador[0] > nuevo->jugador[0])
    {
        if(raiz->getIzquierdo() != NULL)
        {
            this->InsertarRecursivo(raiz->getIzquierdo(),nuevo);
        }
        else
        {
            raiz->setIzquierdo(nuevo);
        }
    }

}

NodoArbol* ArbolBinario::getRaiz()
{
    return this->root;
}

void ArbolBinario::imprimirInOrder()
{
    this->ayudante(this->getRaiz());
}

void ArbolBinario::ayudante(NodoArbol*raiz)
{
    if(raiz==NULL)
    {
        return;
    }
    this->ayudante(raiz->getIzquierdo());
    //cout<<raiz->getImagen()->nombre<<endl;
    cout<<raiz->jugador<<endl;
    this->ayudante(raiz->getDerecho());
}

void ArbolBinario::graficar()
{

    ofstream files;
    files.open("ArbolBinario.dot");
    files << estructura();
    files.close();
    system("dot -Tpng ArbolBinario.dot -o ArbolBinario.png");

    const char* cmd2 = "cmd /c start ArbolBinario.png ";

    system(cmd2);

}


string ArbolBinario::estructura()
{
    string Codigo= "digraph ArbolAVL{\n rankdir=TB;\n node [shape = record, style=filled, fillcolor=seashell2];\n"+visitar(this->getRaiz())+"}\n";
    return Codigo;
}

string ArbolBinario::visitar(NodoArbol*raiz)
{
    string etiqueta;
    if(raiz==NULL)
    {
        etiqueta="nodoVacio [label =\"ABB Vacio\"  ];\n";
        return etiqueta;
    }
          if(raiz->hijoIzq==NULL && raiz->hijoDer==NULL){
              etiqueta="nodo"+to_string(raiz->numero)+" [ label =\""+raiz->jugador+"\"];\n";
          }else{
              etiqueta="nodo"+to_string(raiz->numero)+" [ label =\"<C0>|"+raiz->jugador+"|<C1>\"];\n";
          }
          if(raiz->hijoIzq!=NULL){
              etiqueta=etiqueta + visitar(raiz->hijoIzq) +
                 "nodo"+to_string(raiz->numero)+":C0->nodo"+to_string(raiz->hijoIzq->numero)+"\n";
          }
          if(raiz->hijoDer!=NULL){
              etiqueta=etiqueta + visitar(raiz->hijoDer) +
                 "nodo"+to_string(raiz->numero)+":C1->nodo"+to_string(raiz->hijoDer->numero)+"\n";
          }
          return etiqueta;
}













void ArbolBinario::graficarIn()
{

    cadena="";
    contador=0;

    if(this->root != NULL)
    {
        this->ayudanteIn(this->root);
        ofstream archivo; //declarando
        archivo.open("InOrden.dot",ios::out); //abriendo o creando el archivo
        if(archivo.fail())
        {
            cout<<"no se pudo abrir archivo"<<endl;
            exit(1);
        }
        archivo<<"digraph G{\n";
        archivo<<"rankdir=LR;\n";
        archivo<<"node [shape = record,height=.1];\n";
        archivo<<cadena;
        archivo<<";";
               archivo<<"}";
        archivo.close();//cerrando archivo
        system("dot -Tjpg InOrden.dot -o InOrden.jpg");

        const char* cmd4 = "cmd /c start InOrden.jpg ";
        system(cmd4);

    }
    else
    {
        cout<<"No hay nada que graficar en el arbol"<<endl;
    }

}

void ArbolBinario::ayudanteIn(NodoArbol*raiz)
{
    if(raiz == NULL)
        {
            return;
        }
    this->ayudanteIn(raiz->getIzquierdo());
    this->visitarOrden(raiz);
    this->ayudanteIn(raiz->getDerecho());
}


void ArbolBinario::graficarPos()
{
    cadena="";
    contador=0;

    if(this->root != NULL)
    {
        this->ayudantePos(this->root);
        ofstream archivo; //declarando
        archivo.open("PosOrden.dot",ios::out); //abriendo o creando el archivo
        if(archivo.fail())
        {
            cout<<"no se pudo abrir archivo"<<endl;
            exit(1);
        }
        archivo<<"digraph G{\n";
        archivo<<"rankdir=LR;\n";
        archivo<<"node [shape = record,height=.1];\n";
        archivo<<cadena;
        archivo<<";";
               archivo<<"}";
        archivo.close();//cerrando archivo
        system("dot -Tjpg PosOrden.dot -o PosOrden.jpg");

        const char* cmd5 = "cmd /c start PosOrden.jpg ";
        system(cmd5);

    }
    else
    {
        cout<<"No hay nada que graficar en el arbol"<<endl;
    }


}

void ArbolBinario::ayudantePos(NodoArbol*raiz)
{
    if(raiz == NULL)
        {
            return;
        }
    this->ayudantePos(raiz->getIzquierdo());
    this->ayudantePos(raiz->getDerecho());
    this->visitarOrden(raiz);
}


void ArbolBinario::graficarPre()
{
    cadena="";
    contador=0;

    if(this->root != NULL)
    {
        this->ayudantePre(this->root);
        ofstream archivo; //declarando
        archivo.open("PreOrden.dot",ios::out); //abriendo o creando el archivo
        if(archivo.fail())
        {
            cout<<"no se pudo abrir archivo"<<endl;
            exit(1);
        }
        archivo<<"digraph G{\n";
        archivo<<"rankdir=LR;\n";
        archivo<<"node [shape = record,height=.1];\n";
        archivo<<cadena;
        archivo<<";";
               archivo<<"}";
        archivo.close();//cerrando archivo
        system("dot -Tjpg PreOrden.dot -o PreOrden.jpg");

        const char* cmd6 = "cmd /c start PreOrden.jpg ";
        system(cmd6);

    }
    else
    {
        cout<<"No hay nada que graficar en el arbol"<<endl;
    }

}

void ArbolBinario::ayudantePre(NodoArbol*raiz)
{
    if(raiz == NULL)
        {
            return;
        }
    this->visitarOrden(raiz);
    this->ayudantePre(raiz->getIzquierdo());
    this->ayudantePre(raiz->getDerecho());
}



void ArbolBinario::visitarOrden(NodoArbol*raiz)
{
    cadena+="\""+raiz->jugador+"\"";
    if(contador<this->hijos-1)
    {
        cadena+="->";
    }
    contador++;
}





