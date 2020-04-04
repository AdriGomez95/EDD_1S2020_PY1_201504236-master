#include "matriz.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>


/*
----------------------------
                            |
   @Author: Adriana Gómez   |
                            |
----------------------------
*/


using namespace std;




//-----------------------Matriz Insertar-----------------------------------------

void Matriz::InsertarMatriz(int Fila, int Columna,string letra){
//printf("Entre\n");


    if(Modificar(Fila,Columna,letra)!=NULL){
   //Temp->Color=Color;
        printf("Columna Modificada");
        return;
    }else{
        NodoMatriz* Nuevo= new NodoMatriz(Fila,Columna,letra);
        NodoEncabezado* eFila=EncabezadoFila->BuscarEncabezado(Fila);
        if(eFila==NULL){
            EncabezadoFila->InsertarEncabezado(Fila,Nuevo);
        }else {
            if(MayoMenorM(Nuevo->Columna,eFila->Acceso->Columna)<0){//------editado Nuevo->Fila a Nuevo->Columna
                Nuevo->Izquierda=eFila->Acceso;
                eFila->Acceso->Derecha=Nuevo;
                eFila->Acceso=Nuevo;

            }else{
                NodoMatriz* Temp=eFila->Acceso;
                while(Temp->Izquierda!=NULL){
                    if(MayoMenorM(Nuevo->Columna,Temp->Izquierda->Columna)<0){
                        Nuevo->Izquierda=Temp->Izquierda;
                        Temp->Izquierda->Derecha=Nuevo;
                        Nuevo->Derecha=Temp;
                        Temp->Izquierda=Nuevo;
                    break;
                    }
                    Temp=Temp->Izquierda;
                }
                if(Temp->Izquierda==NULL){
                    Temp->Izquierda=Nuevo;
                    Nuevo->Derecha=Temp;
                }
            }
        }


        NodoEncabezado* eColumna=EncabezadoColumna->BuscarEncabezado(Columna);
        if(eColumna==NULL){
            EncabezadoColumna->InsertarEncabezado(Columna,Nuevo);
        }else{
            if(MayoMenorM(Nuevo->Fila,eColumna->Acceso->Fila)<0){
                Nuevo->Abajo=eColumna->Acceso;
                eColumna->Acceso->Arriba=Nuevo;
                eColumna->Acceso=Nuevo;
            }else{

                NodoMatriz* Temp=eColumna->Acceso;
                while (Temp->Abajo!=NULL){
                    if(MayoMenorM(Nuevo->Fila,Temp->Abajo->Fila)<0){
                        Nuevo->Abajo=Temp->Abajo;
                        Temp->Abajo->Arriba=Nuevo;
                        Nuevo->Arriba=Temp;
                        Temp->Abajo=Nuevo;
                    break;
                    }
                Temp=Temp->Abajo;
                }
                if(Temp->Abajo==NULL){
                    Temp->Abajo=Nuevo;
                    Nuevo->Arriba=Temp;
                }
           }
        }
    }
}


//-----------------------MayorMenorMatriz------------------------------
int Matriz::MayoMenorM(int Val1, int Val2){
    string val1 = to_string(Val1);
    string val2=to_string(Val2);
    int cont1=val1.length()-val2.length();
    if(cont1==0){
       return strcmp(val1.c_str(),val2.c_str());
    }else{
        if(cont1>0){
            std::string temp="";
            for(int x=0;x<cont1;x++){
                temp+="0";
            }
            temp+=val2;
            return strcmp(val1.c_str(),temp.c_str());
        }else{
            std::string temp="";
            cont1=cont1*(-1);
            for(int x=0;x<cont1;x++){
                temp+="0";
            }
            temp+=val1;
            return strcmp(temp.c_str(),val2.c_str());
        }
    }
}




//-----------------------Insertar Encabezado------------------------------------

void ListaEncabezado::InsertarEncabezado(int ID, NodoMatriz *Matriz){
    NodoEncabezado* Nuevo=new NodoEncabezado(ID);
    Nuevo->Acceso=Matriz;
    if(Primero==NULL){
        Primero=Nuevo;
       // Ultimo=Nuevo;
    }else{
        if(MayoMenorE(ID,Primero->ID)<0){
            Nuevo->Siguiente=Primero;
            Primero->Anterior=Nuevo;
            Primero=Nuevo;
        }else{
            NodoEncabezado* Temp=Primero;
            while(Temp->Siguiente!=NULL){
                if(MayoMenorE(ID,Temp->Siguiente->ID)<0){
                    Nuevo->Siguiente=Temp->Siguiente;
                    Temp->Siguiente->Anterior=Nuevo;
                    Nuevo->Anterior=Temp;
                    Temp->Siguiente=Nuevo;
                    break;
                }

                Temp=Temp->Siguiente;
            }
            if(Temp->Siguiente==NULL){
                Temp->Siguiente=Nuevo;
                Nuevo->Anterior=Temp;
            }
        }
    }
}

//---------------------Buscar Encabezado-----------------------------------------
NodoEncabezado* ListaEncabezado::BuscarEncabezado(int ID){
    NodoEncabezado* Temp=Primero;
    while(Temp!=NULL){
        if(Temp->ID==ID){
            Actual=Temp;
            return Temp;
        }
        Temp=Temp->Siguiente;
    }
    return  NULL;
}



//------------------------Metodo Mayor Menor Encabezado-----------------
int ListaEncabezado::MayoMenorE(int Val1, int Val2){
    string val1=to_string(Val1);
    string val2=to_string(Val2);

    int cont1=val1.length()-val2.length();
        if(cont1==0){
           return strcmp(val1.c_str(),val2.c_str());
        }else{
            if(cont1>0){
                std::string temp="";
                for(int x=0;x<cont1;x++){
                    temp+="0";
                }
                temp+=val2;
                return strcmp(val1.c_str(),temp.c_str());
            }else{
                std::string temp="";
                cont1=cont1*(-1);
                for(int x=0;x<cont1;x++){
                    temp+="0";
                }
                temp+=val1;
                return strcmp(temp.c_str(),val2.c_str());
            }
        }
}



//-------------------------Modificar Matriz---------------------

NodoMatriz* Matriz::Modificar(int Fila, int Columna,string letra){
    NodoEncabezado* TempColumna=this->EncabezadoColumna->Primero;
    NodoMatriz* TempRecorrer;
    while(TempColumna!=NULL){
        if(TempColumna->ID==Columna){
            TempRecorrer=TempColumna->Acceso;
            while(TempRecorrer!=NULL){
                if(TempRecorrer->Fila==Fila){
                    //cout<<"\n Cloro:" + TempRecorrer->letra<<endl;
                    TempRecorrer->letra=letra;
                    printf(" Cambio: ");
                    //cout<<" "+ TempRecorrer->Color<<endl;
                    return TempRecorrer;
                }
                TempRecorrer=TempRecorrer->Abajo;
            }
        }
        TempColumna=TempColumna->Siguiente;
    }
    return  NULL;
}


//-----------Inicio Graficar------------------
void Matriz::GraficarMatriz(){
    //printf("Entre a Graficar");

    string grafica="digraph Matriz {\n node[shape=box];\n";


    grafica+="\"Mat\"";
    grafica+=GCabezas();
    grafica+=GNodos();
    NodoEncabezado* eFila=EncabezadoFila->Primero;
    NodoEncabezado* eColumna=EncabezadoColumna->Primero;

    if(eFila!=NULL && eColumna!=NULL){
        grafica+="{rank=min;\"Mat\";";
        while(eColumna!=NULL){
        grafica+=GetColumna(eColumna)+";";
        eColumna=eColumna->Siguiente;
    }
    grafica+="};\n";
    while(eFila!=NULL){
        grafica+="{rank=same;";
        grafica+=GetFila(eFila)+";";
        NodoMatriz* temp=eFila->Acceso;
        while(temp!=NULL){
            grafica+=getNodos(temp)+";";
            temp=temp->Izquierda;
        }
        grafica+="};\n";
        eFila=eFila->Siguiente;
    }
    eFila=EncabezadoFila->Primero;
    while(eFila!=NULL){
        grafica+=GetFila(eFila)+"->"+getNodos(eFila->Acceso)+"[constraint=false];\n";
        grafica+=getNodos(eFila->Acceso)+"->"+GetFila(eFila)+"[constraint=false];\n";
        NodoMatriz* temp=eFila->Acceso;
        while(temp->Izquierda!=NULL){
            grafica+=getNodos(temp)+"->"+getNodos(temp->Izquierda)+"[constraint=false];\n";
            temp=temp->Izquierda;
        }
        while(temp->Derecha!=NULL){
            grafica+=getNodos(temp)+"->"+getNodos(temp->Derecha)+"[constraint=false];\n";
            temp=temp->Derecha;
        }
    eFila=eFila->Siguiente;
    }

    eColumna=EncabezadoColumna->Primero;
    if(eColumna!=NULL){
        grafica+="\"Mat\"->"+GetColumna(eColumna)+";\n";
        grafica+=GetColumna(eColumna)+"->\"Mat\";\n";
    }
    while(eColumna->Siguiente!=NULL){
        grafica+=GetColumna(eColumna)+"->"+GetColumna(eColumna->Siguiente)+";\n";
        eColumna=eColumna->Siguiente;
    }
    while(eColumna->Anterior!=NULL){
            grafica+=GetColumna(eColumna)+"->"+GetColumna(eColumna->Anterior)+"[constraint=false];\n";
            eColumna=eColumna->Anterior;
    }
    eFila=EncabezadoFila->Primero;
    if(eFila!=NULL){
        grafica+="\"Mat\"->"+GetFila(eFila)+"[rankdir=UD];\n";
        grafica+=GetFila(eFila)+"->\"Mat\";\n";//-------------------------editado
    }
    while(eFila->Siguiente!=NULL){
        grafica+=GetFila(eFila)+"->"+GetFila(eFila->Siguiente)+"[rankdir=UD];\n";
        eFila=eFila->Siguiente;
    }//-------------------------agregado
    while(eFila->Anterior!=NULL){
        grafica+=GetFila(eFila)+"->"+GetFila(eFila->Anterior)+"[constraint=false];\n";
        eFila=eFila->Anterior;
    }

    //-------------------Agregado

    eColumna=EncabezadoColumna->Primero;
    while(eColumna!=NULL){
        NodoMatriz* temp=eColumna->Acceso;
        grafica+=GetColumna(eColumna)+"->"+getNodos(eColumna->Acceso)+"[rankdir=UD];\n";
        //---------------------edit
          grafica+=getNodos(eColumna->Acceso)+"->"+GetColumna(eColumna)+"[rankdir=UD];\n";

          //------------------edit
        while(temp->Abajo!=NULL){
            grafica+=getNodos(temp)+"->"+getNodos(temp->Abajo)+"[rankdir=UD];\n";
            temp=temp->Abajo;
        }
        while(temp->Arriba!=NULL){
                grafica+=getNodos(temp)+"->"+getNodos(temp->Arriba)+"[rankdir=UD];\n";
                temp=temp->Arriba;
        }
        eColumna=eColumna->Siguiente;
    }

    }
    grafica+="\n}";

    //Crear el Archivo para Graficar
    ofstream file;
    file.open("Matriz.dot");
    file << grafica;
    file.close();

    system("dot -Tpng Matriz.dot -o Matriz.png");
    const char* cmd2 = "cmd /c start Matriz.png ";
       // system(cmd1);
      //const char* cmd1 = "dot  -Tpng Archivo.dot -o Estructura.png ";
    system(cmd2);

        //------------------------------------Claro------------------------
}

string Matriz::GNodos(){
    string salida="";
    NodoEncabezado* eFila=EncabezadoFila->Primero;
    while(eFila!=NULL){
        NodoMatriz* temp=eFila->Acceso;
        while(temp!=NULL){
            salida+="\"nodo"+to_string(temp->Fila)+to_string(temp->Columna)+"\"[label="+GraficarNodoM(temp)+"];\n";
            temp=temp->Izquierda;
        }

        eFila=eFila->Siguiente;
    }
    return salida;
}

string  Matriz::GCabezas(){
    string salida="";
    NodoEncabezado* eFila=EncabezadoFila->Primero;
    NodoEncabezado* eColuma=EncabezadoColumna->Primero;
    while(eColuma!=NULL){
        salida+="\"columna"+to_string(eColuma->ID)+"\"[label="+GraficarEncabezado(eColuma)+"];\n";
        eColuma=eColuma->Siguiente;
    }
    while(eFila!=NULL){
        salida+="\"fila"+to_string(eFila->ID)+"\"[label="+GraficarEncabezado(eFila)+"]\n";
        eFila=eFila->Siguiente;
    }
    return salida;
}

string Matriz::GraficarNodoM(NodoMatriz* temp){
    string salida="";
    salida+="\" "+temp->letra;
    salida+="\"";
    return salida;
}
string Matriz::GraficarEncabezado(NodoEncabezado* temp){
    string salida="";
    salida+="\""+to_string(temp->ID)+"\"";
    return salida;
}


//-----------Fin Graficas-----------------------------------


void Matriz::GraficarCapas(){
    NodoEncabezado* ColumnaMax=RecuperarUltimo(EncabezadoColumna);
    NodoEncabezado* FilaMax=RecuperarUltimo(EncabezadoFila);

    cout<<"La ColumnaMAX:"<<to_string(ColumnaMax->ID)<<endl;
    cout<<"La FilaMAX:"<<to_string(FilaMax->ID)<<endl;

    string Dot="";
    string letra="#f4f4f4";
    string Spacio="     ";
    Dot+="digraph { tbl [shape=plaintext label=<<table border='0' cellborder='0' color='black' cellspacing='0'>";

    for(int i=0;i<FilaMax->ID;i++){
        Dot+="\n <tr>";
        for(int j=0;j<ColumnaMax->ID;j++){
            NodoMatriz* NodoBuscado=BuscarPosicion(i,j);
            if(NodoBuscado==NULL){
                    cout<<"No se Encontro Nodo \n";
                 Dot+="<td bgcolor=\""+ letra+"\">"+Spacio+"</td>"+"\n";
            }else{
           // cout<<"Color de Este Nodo:"<<NodoBuscado->Color<<endl;
                Dot+="<td bgcolor=\""+ NodoBuscado->letra+"\">"+Spacio+"</td>"+"\n";
            }
        }
        Dot+="</tr>";
        }

    Dot+="</table> >];}";

    ofstream files;
    files.open("CapaImagen.dot");
    files << Dot;
    files.close();
    system("dot -Tpng CapaImagen.dot -o CapaImagen.png");

    const char* cmd2 = "cmd /c start CapaImagen.png ";

    system(cmd2);





}

NodoMatriz* Matriz::BuscarPosicion(int Fila, int Columna){
    NodoEncabezado* TempColumna=this->EncabezadoColumna->Primero;
    NodoMatriz* TempRecorrer;
    while(TempColumna!=NULL){
        if(TempColumna->ID==Columna){
            TempRecorrer=TempColumna->Acceso;
            while(TempRecorrer!=NULL){
                if(TempRecorrer->Fila==Fila){
                    //cout<<"\n Cloro:" + TempRecorrer->Color<<endl;
                    //TempRecorrer->Color=Color;
                   // printf(" Cambio: ");
                    //cout<<" "+ TempRecorrer->Color<<endl;
                    return TempRecorrer;
                }
                TempRecorrer=TempRecorrer->Abajo;
            }
        }
        TempColumna=TempColumna->Siguiente;
    }
    return  NULL;
}

NodoEncabezado* Matriz::RecuperarUltimo(ListaEncabezado* Encabezado){
    NodoEncabezado* Temp=Encabezado->Primero;
    while(Temp->Siguiente!=NULL){

     cout<<"El MAX:"+to_string(Temp->ID)<<endl;
      Temp=Temp->Siguiente;
    }
    return Temp;
};




//---------Metodos Get----------------

string Matriz::getNodos(NodoMatriz* Temp){
    string salida="\"nodo"+to_string(Temp->Fila)+to_string(Temp->Columna)+"\"" ;

    return salida;
}
string Matriz::GetColumna(NodoEncabezado* Temp){
    string salida="\"columna"+to_string(Temp->ID)+"\"";
    return salida;
}
string Matriz::GetFila(NodoEncabezado* Temp){
    string salida="\"fila"+to_string(Temp->ID)+"\"";
    return salida;
}



Matriz* Matriz::BusquedaInsercion(Matriz* Global){
    NodoEncabezado* TempColumna=this->EncabezadoColumna->Primero;
    NodoMatriz* TempRecorrer;
    while(TempColumna!=NULL){
            TempRecorrer=TempColumna->Acceso;
            while(TempRecorrer!=NULL){
                Global->InsertarMatriz(TempRecorrer->Fila,TempRecorrer->Columna,TempRecorrer->letra);
                TempRecorrer=TempRecorrer->Abajo;
            }
        TempColumna=TempColumna->Siguiente;
    }
    return  Global;
}






//--------------Inicializar Nodos -------------------------------

NodoMatriz::NodoMatriz(){
    this->Izquierda=NULL;
    this->Derecha=NULL;
    this->Arriba=NULL;
    this->Abajo=NULL;
    this->Fila=0;
    this->Columna=0;
    this->letra="";
}

NodoMatriz::NodoMatriz(int Fila,int Columna,string letra){
    this->Izquierda=NULL;
    this->Derecha=NULL;
    this->Arriba=NULL;
    this->Abajo=NULL;
    this->Fila=Fila;
    this->Columna=Columna;
    this->letra=letra;
}

NodoEncabezado::NodoEncabezado(){
    this->ID=0;
    this->Acceso=NULL;
    this->Siguiente=NULL;
    this->Anterior=NULL;
}

NodoEncabezado::NodoEncabezado(int ID){
    this->ID=ID;
    this->Acceso=NULL;
    this->Siguiente=NULL;
    this->Anterior=NULL;
}

Matriz::Matriz(){
    this->EncabezadoFila=new ListaEncabezado();
    this->EncabezadoColumna=new ListaEncabezado();
    this->Actual=NULL;
}

ListaEncabezado::ListaEncabezado(){
    this->Primero=NULL;
    this->Actual=NULL;
}
