#include "Jugador.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::Jugador(const string nombre)
{
    this->nombre= nombre;
    this->listaPunteo=NULL;
}

void Jugador::insertarListaPunteo(ListaSimple*l)
{
    if(this->listaPunteo==NULL)
    {
        this->listaPunteo=l;
    }
    else if(this->listaPunteo->getNoCapa() > m->getNoCapa())
    {
        m->setSig(this->capaUno);
        this->capaUno = m;
    }
    else
    {
        matriz* aux = this->capaUno;
        while(aux->getSig() != NULL)
        {
            if(aux->getSig()->getNoCapa() > m->getNoCapa())
                {
                    m->setSig(aux->getSig());
                    aux->setSig(m);
                    break;
                }
                aux=aux->getSig();
        }
        if(aux->getSig()==NULL)
            {
                aux->setSig(m);
            }
    }
}

ListaSimple* Jugador::getPunteo(int punteo)
{
    ListaSimple* aux = this->listaPunteo;
    while(aux != NULL)
        {
            if(aux->getNoCapa()==capa)
                {
                    break;
                }
                aux=aux->getSig();
        }

    return aux;
}

void cubo::visitar()
{
    if(this->capaUno ==NULL)
        {
            cout<<"cubo vacio xD";
        }
    else
        {
            matriz*aux=this->capaUno;
            while(aux!=NULL)
                {
                    cout<<aux->getNombre()<<endl;
                    aux=aux->getSig();
                }
        }
}

