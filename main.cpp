#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h> //Uso de random en las letras ------- variable=limite_inferior+rand()%(limite_superior+1-limite_inferior)
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <sstream>
#include "ListaSimple.h"
#include "ListaScoreBoard.h"
#include "ArbolBinario.h"
#include "matriz.h"
#include "ListaCircular.h"
#include "Cola.h"



#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock




/*
----------------------------
                            |
   @Author: Adriana G�mez   |
                            |
----------------------------
*/


using namespace std;
//***************Para la lectura del archio json
int dimension;
int doblesX, doblesY;
int triplesX, triplesY;
string palabraDiccionario;
string arrayDiccionario[500];
//***************fin de variables de la lectura del json

int respuesta,cont=1;
string jugador1="", jugador2=""; //Jugadores
string arrayJugadores[40];
int banderaJugador, banderaVerificaJuego=0;
int jugadorx=0;
int punteo1, punteo2, punteo1m=0, punteo2m=0; //Punteo de los jugadores
int coordenadaX, coordenadaY; //Coordenadas para la matriz

//***************Para concatenar las letras y validar las palabras en el tablero del juego
string letra;
char cad2[0];
char cad3[15];
string letra2;
char cad1[0];
char cad4[15];
int bandera;

//***************Para verificar las casillas dobles y triples
int banderaCasillaD, banderaCasillaT, banderaExisteCasilla;
int arrayDobleX[30];
int arrayDobleY[30];
int arrayTripleX[30];
int arrayTripleY[30];


ListaSimple* listaPunteo1 = new ListaSimple(); //Lista de punteo jugador 1
ListaSimple* listaPunteo2 = new ListaSimple(); //Lista de punteo jugador 2
ListaSimple* listaPunteo11 = new ListaSimple();
ListaSimple* listaPunteo22 = new ListaSimple();
ListaSimple* listaPunteo111 = new ListaSimple();
ListaSimple* listaPunteo222 = new ListaSimple();
ListaSimple* listaPunteo1111 = new ListaSimple();
ListaSimple* listaPunteo2222 = new ListaSimple();
ListaScoreBoard* listaScoreBoard = new ListaScoreBoard(); //Lista de punteos m�ximos del ScoreBoard
ArbolBinario* arbolito = new ArbolBinario(); //Usuarios
Matriz* matrix = new Matriz();
ListaCircular* listaCircularDiccionario = new ListaCircular(); //Diccionario de palabras
ListaCircular* listaDobleFichas1 = new ListaCircular(); //Fichas jugador 1
ListaCircular* listaDobleFichas2 = new ListaCircular(); //Fichas Jugador 2
ListaCircular* listaDobleFichas11 = new ListaCircular();
ListaCircular* listaDobleFichas22 = new ListaCircular();
ListaCircular* listaDobleFichas111 = new ListaCircular();
ListaCircular* listaDobleFichas222 = new ListaCircular();
ListaCircular* listaDobleFichas1111 = new ListaCircular();
ListaCircular* listaDobleFichas2222 = new ListaCircular();
Cola* colaFichas = new Cola(); //Ficas disponibles del juego
int contadorGeneralRondas=0;//Contador para verificar el #de rondas jugadas para los reportes
int contadorGeneralTurnos=0;

void menu();
void lecturaArchio();
void juego();
void menuMatriz1();
void menuMatriz2();
void comparaPunteos();
void randomFichas1();
void punteoFichas1();
void punteoFichas2();
int compararPalabra(); //Compara si la palabra existe para el jugador 1
int compararPalabra2();
int casillaDoble();  /* Compara si la coordenada es doble*/
int casillaTriple(); /* o si la coordenada es triple */
int existeCasilla(); //verifica si es casilla Doble o Triple y multiplica el punteo
int comparaJugador(); //Compara si el jugador ya existe o no
int comparaRonda();//Para comparar ronda por partida y crear nuevas fichas por jugador
void reportes();

void pruebas();
void prueas2();



using json = nlohmann::json;


int main()
{
    menu();

/*
        listaPunteo1->Insetar(2);
        listaPunteo1->Insetar(1);
        listaPunteo1->Insetar(9);
        listaPunteo1->Insetar(4);
        listaPunteo1->Graficar();

*/
/*
        arbolito->InsertarJugador(player);
        arbolito->InsertarJugador(player2);
        arbolito->InsertarJugador(player3);
        arbolito->InsertarJugador(player4);
        arbolito->graficar();
        arbolito->graficarIn();
        arbolito->graficarPos();
        arbolito->graficarPre();
*/
/*

        string palabrita1="Adriana";
        string palabrita2="Marie";
        string palabrita3="Gomez";
        string palabrita4="Davila";
        string palabrita5="Hola";
        listitaCircular->InsetarListaCircular(palabrita5);
        listitaCircular->InsetarListaCircular(palabrita1);
        listitaCircular->InsetarListaCircular(palabrita2);
        listitaCircular->InsetarListaCircular(palabrita3);
        listitaCircular->InsetarListaCircular(palabrita4);
        listitaCircular->GraficarListaCircular();
        listitaCircular->GraficarListaDoble();

        cout<<"\n\nLista Doble: \n\n"<<listitaCircular->CodigoLista3();
        cout<<"\n\nLista Circular: \n\n"<<listitaCircular->CodigoLista2();

        */

/*
        string letter1 = "D *3";
        string letter2 = "S *1";
        string letter3 = "H *1";
        string letter4 = "E *2";
        string letter5 = "J *1";
        colita->InsetarCola(letter1);
        colita->InsetarCola(letter2);
        colita->InsetarCola(letter3);
        colita->InsetarCola(letter4);
        colita->InsetarCola(letter5);
        colita->GraficarCola();
        colita->EliminarCola(letter1);
        colita->GraficarCola();
        */

}





void menu()
{
    system("color 1B");
    printf("\n    ---------MENU-------------\n");
    cout<<"   |                          |"<<endl;
    cout<<"   | 1.- Lectura de archivo.  |"<<endl;
    cout<<"   | 2.- Juego.               |"<<endl;
    cout<<"   | 3.- Reportes.            |"<<endl;
    cout<<"   | 4.- Salir.               |"<<endl;
    cout<<"   |                          |"<<endl;
    printf("    --------------------------\n");
    printf("\n    Selecciona una opcion: ");
    cin>>respuesta;


    if(respuesta==1)
    {
        system("cls");
        system("color 5F");
        lecturaArchio();
    }
    else if(respuesta==2)
    {
        jugadorx=jugadorx+1;
        //cout<<jugadorx;
        cout<<"\n    Jugador 1: ";
        cin>>jugador1;
        cout<<"\n    Jugador 2: ";
        cin>>jugador2;

        if(banderaVerificaJuego==0)
        {
            cout<<"\n Vamos al menu juego"<<endl;
            arrayJugadores[jugadorx]=jugador1;
            jugadorx=jugadorx+1;
            //cout<<jugadorx<<endl;
            arrayJugadores[jugadorx]=jugador2;
        }
        else
        {
            cout<<"\n Vamos a comparar en el array"<<endl;
            comparaJugador();
            if(banderaJugador==1)
            {
                cout<<"\n Jugador 1 ya existe, ingrese un nombre valido"<<endl;
                cout<<"\n    Jugador 1: ";
                cin>>jugador1;
                arrayJugadores[jugadorx]=jugador1;
                jugadorx=jugadorx+1;
                //cout<<jugadorx<<endl;
                arrayJugadores[jugadorx]=jugador2;
            }
            else if(banderaJugador==2)
            {
                cout<<"\n Jugador 2 ya existe, ingrese un nombre valido"<<endl;
                cout<<"\n    Jugador 2: ";
                cin>>jugador2;
                arrayJugadores[jugadorx]=jugador1;
                jugadorx=jugadorx+1;
                //cout<<jugadorx<<endl;
                arrayJugadores[jugadorx]=jugador2;
            }
            else
            {
                cout<<"\n Jugadores agregados con exito"<<endl;
                arrayJugadores[jugadorx]=jugador1;
                jugadorx=jugadorx+1;
                //cout<<jugadorx<<endl;
                arrayJugadores[jugadorx]=jugador2;
            }
        }
        banderaVerificaJuego++;

        arbolito->InsertarJugador(jugador1);
        arbolito->InsertarJugador(jugador2);
        arbolito->graficar();
        randomFichas1();
        juego();

    }
    else if(respuesta==3)
    {
        reportes();

    }
    else if(respuesta==4)
    {
        system(0);
    }
    else
    {
        system("cls");
        printf("\n **INGRESA UN NUMERO VALIDO EN EL RANGO DEL MENU**\n\n");
        menu();
    }

}

void lecturaArchio()
{
    std::ifstream i("scrabble.json");
    json j3;
    i >> j3;

    dimension = j3.at("dimension");
    cout << "dimension: " << dimension << endl;
    matrix->InsertarMatriz(dimension,dimension,"Maximum");

   for(int x = 0; x < j3.at("casillas").at("dobles").size(); x++)
    {
        string ddoblesX = j3.at("casillas").at("dobles")[x].at("x").dump();
        string ddoblesY = j3.at("casillas").at("dobles")[x].at("y").dump();
        //cout << "x: " << j3.at("casillas").at("dobles")[x].at("x").dump() << endl;
        //cout << "y: " << j3.at("casillas").at("dobles")[x].at("y").dump() << endl;

        doblesX = stoi(ddoblesX);
        doblesY = stoi(ddoblesY);
        //matrix->InsertarMatriz(doblesX,doblesY,"casilla x2");
        arrayDobleX[x]=doblesX;
        arrayDobleY[x]=doblesY;
    }
   for(int x = 0; x < j3.at("casillas").at("triples").size(); x++)
    {
        string ttriplesX = j3.at("casillas").at("triples")[x].at("x").dump();
        string ttriplesY = j3.at("casillas").at("triples")[x].at("y").dump();
        //cout << "x: " << j3.at("casillas").at("triples")[x].at("x").dump() << endl;
        //cout << "y: " << j3.at("casillas").at("triples")[x].at("y").dump() << endl;

        triplesX = stoi(ttriplesX);
        triplesY = stoi(ttriplesY);
       // matrix->InsertarMatriz(triplesY,triplesX,"casilla x3");
        arrayTripleX[x]=triplesX;
        arrayTripleY[x]=triplesY;
    }
    matrix->GraficarMatriz();
    for(int x = 0; x < j3.at("diccionario").size(); x++)
    {
        palabraDiccionario = j3.at("diccionario")[x].at("palabra");
        //cout << "palabra: " << j3.at("diccionario")[x].at("palabra") << endl;
        listaCircularDiccionario->InsetarListaCircular(palabraDiccionario);
        arrayDiccionario[x]=palabraDiccionario;
        //cout<<arrayDiccionario[x]<<endl;
    }
    listaCircularDiccionario->GraficarListaCircular();


    cout<<"\n\n   *** El archio ha sido leido exitosamente ***"<<endl;
    printf("\n    Pulse un numero para regresar: ");
    cin>>respuesta;
    system("cls");
    menu();


}

void juego()
{
    system("cls");
    system("color 5F");
    printf("\n    ---------TABLERO--------\n");
    cout<<"       Jugador 1: "<<jugador1<<endl;
    cout<<"       Punteo: "<<punteo1<<endl;
    printf("    ------------------------\n");
    cout<<"       Jugador 2: "<<jugador2<<endl;
    cout<<"       Punteo: "<<punteo2<<endl;
    printf("    ------------------------\n");

    menuMatriz1();

}

void menuMatriz1()
{
    if(contadorGeneralTurnos==0)
    {
        listaDobleFichas1->GraficarListaDoble();
        listaDobleFichas2->GraficarListaDoble2();
    }
    else if(contadorGeneralTurnos==1)
    {
        listaDobleFichas11->GraficarListaDoble();
        listaDobleFichas22->GraficarListaDoble2();
    }
    else if(contadorGeneralTurnos==2)
    {
        listaDobleFichas111->GraficarListaDoble();
        listaDobleFichas222->GraficarListaDoble2();
    }
    else if(contadorGeneralTurnos==3)
    {
        listaDobleFichas1111->GraficarListaDoble();
        listaDobleFichas2222->GraficarListaDoble2();
    }
    else
    {
        listaDobleFichas1->GraficarListaDoble();
        listaDobleFichas2->GraficarListaDoble2();
    }


    cout<<"\n\n *** TURNO JUGADOR 1: "<<jugador1<<" ***";
    cout<<"\n Ingresa coordenada en Y: ";
    cin>>coordenadaY;
    cout<<" Ingresa coordenada en X: ";
    cin>>coordenadaX;

    if((coordenadaX>dimension)||(coordenadaY>dimension))
    {
        cout<<"\n *** Por favor, no exceda la dimension ( "<<dimension<<", "<<dimension<<" ) limite del tablero ***"<<endl;
        cout<<"\n Ingresa coordenada en Y: ";
        cin>>coordenadaY;
        cout<<" Ingresa coordenada en X: ";
        cin>>coordenadaX;
        if((coordenadaX>dimension)||(coordenadaY>dimension))
        {
            cout<<"\n *** Por favor, no exceda la dimension ( "<<dimension<<", "<<dimension<<" ) limite del tablero ***"<<endl;
            cout<<"\n Ingresa coordenada en Y: ";
            cin>>coordenadaY;
            cout<<" Ingresa coordenada en X: ";
            cin>>coordenadaX;
        }
    }
    cout<<" Ingresa una letra: ";
    cin>>cad2;

    casillaDoble();
    casillaTriple();
    strcat(cad3, cad2);

    stringstream ss;
    ss<<cad2;
    ss>>letra;


    if((letra=="a")||(letra=="A")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="b")||(letra=="B")){
            punteo1=punteo1+3;
            punteo1m=punteo1m+3;
    }else if((letra=="c")||(letra=="C")){
            punteo1=punteo1+3;
            punteo1m=punteo1m+3;
    }else if((letra=="d")||(letra=="D")){
            punteo1=punteo1+2;
            punteo1m=punteo1m+2;
    }else if((letra=="e")||(letra=="E")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="f")||(letra=="F")){
            punteo1=punteo1+4;
            punteo1m=punteo1m+4;
    }else if((letra=="g")||(letra=="G")){
            punteo1=punteo1+2;
            punteo1m=punteo1m+2;
    }else if((letra=="h")||(letra=="H")){
            punteo1=punteo1+4;
            punteo1m=punteo1m+4;
    }else if((letra=="i")||(letra=="I")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="j")||(letra=="J")){
            punteo1=punteo1+8;
            punteo1m=punteo1m+8;
    }else if((letra=="k")||(letra=="K")){//LETRA � PERO NO SE PUEDE POR EL TECLADO
            punteo2=punteo2+8;
            punteo1m=punteo1m+8;
    }else if((letra=="l")||(letra=="L")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="m")||(letra=="M")){
            punteo1=punteo1+3;
            punteo1m=punteo1m+3;
    }else if((letra=="n")||(letra=="N")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="o")||(letra=="O")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="p")||(letra=="P")){
            punteo1=punteo1+3;
            punteo1m=punteo1m+3;
    }else if((letra=="q")||(letra=="Q")){
            punteo1=punteo1+5;
            punteo1m=punteo1m+5;
    }else if((letra=="r")||(letra=="R")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="s")||(letra=="S")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="t")||(letra=="T")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="u")||(letra=="U")){
            punteo1=punteo1+1;
            punteo1m=punteo1m+1;
    }else if((letra=="v")||(letra=="V")){
            punteo1=punteo1+4;
            punteo1m=punteo1m+4;
    }else if((letra=="w")||(letra=="W")){
    }else if((letra=="x")||(letra=="X")){
            punteo1=punteo1+8;
            punteo1m=punteo1m+8;
    }else if((letra=="y")||(letra=="Y")){
            punteo1=punteo1+4;
            punteo1m=punteo1m+4;
    }else if((letra=="z")||(letra=="Z")){
            punteo1=punteo1+10;
            punteo1m=punteo1m+10;
    }


    matrix->InsertarMatriz(coordenadaY,coordenadaX,letra);
    matrix->GraficarMatriz();

    int resp;
    printf("\n �Desea ingresar otra letra?");
    printf("\n [1]-Si");
    printf("\n [0]-No");
    cin>>resp;

    if(resp==1)
    {
        menuMatriz1();
    }
    else
    {
       compararPalabra();
       if(bandera==1)
       {
           cout<<"\n La palabra se encontro"<<endl;
           if(banderaCasillaD==1)
           {
               punteo1=punteo1*2;
           }
           else if(banderaCasillaT==1)
           {
               punteo1=punteo1*3;
           }
           else
           {
               punteo1=punteo1;
           }
       }
       else
       {
           cout<<"\n La palabra no se encuentra"<<endl;
           punteo1=punteo1-punteo1m;
       }
        //system("cls");
        punteo1m=0;
        cad3[0] = '\0';
        cout<<"\n punteo 1: "<<punteo1;
        menuMatriz2();

    }


}

void menuMatriz2()
{
    cout<<"\n *** TURNO JUGADOR 2: "<<jugador2<<" ***";
    cout<<"\n Ingresa coordenada en Y: ";
    cin>>coordenadaY;
    cout<<" Ingresa coordenada en X: ";
    cin>>coordenadaX;

    if((coordenadaX>dimension)||(coordenadaY>dimension))
    {
        cout<<"\n *** Por favor, no exceda la dimension ( "<<dimension<<", "<<dimension<<" ) limite del tablero ***"<<endl;
        cout<<"\n Ingresa coordenada en Y: ";
        cin>>coordenadaY;
        cout<<" Ingresa coordenada en X: ";
        cin>>coordenadaX;
        if((coordenadaX>dimension)||(coordenadaY>dimension))
        {
            cout<<"\n *** Por favor, no exceda la dimension ( "<<dimension<<", "<<dimension<<" ) limite del tablero ***"<<endl;
            cout<<"\n Ingresa coordenada en Y: ";
            cin>>coordenadaY;
            cout<<" Ingresa coordenada en X: ";
            cin>>coordenadaX;
        }
    }
    cout<<" Ingresa una letra: ";
    cin>>cad1;

    casillaDoble();
    casillaTriple();
    strcat(cad4, cad1);

    stringstream sss;
    sss<<cad1;
    sss>>letra2;


    if((letra2=="a")||(letra2=="A")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="b")||(letra2=="B")){
            punteo2=punteo2+3;
            punteo2m=punteo2m+3;
    }else if((letra2=="c")||(letra2=="C")){
            punteo2=punteo2+3;
            punteo2m=punteo2m+3;
    }else if((letra2=="d")||(letra2=="D")){
            punteo2=punteo2+2;
            punteo2m=punteo2m+2;
    }else if((letra2=="e")||(letra2=="E")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="f")||(letra2=="F")){
            punteo2=punteo2+4;
            punteo2m=punteo2m+4;
    }else if((letra2=="g")||(letra2=="G")){
            punteo2=punteo2+2;
            punteo2m=punteo2m+2;
    }else if((letra2=="h")||(letra2=="H")){
            punteo2=punteo2+4;
            punteo2m=punteo2m+4;
    }else if((letra2=="i")||(letra2=="I")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="j")||(letra2=="J")){
            punteo2=punteo2+8;
            punteo2m=punteo2m+8;
    }else if((letra2=="k")||(letra2=="K")){//LETRA � PERO NO SE PUEDE POR EL TECLADO
            punteo2=punteo2+8;
            punteo2m=punteo2m+8;
    }else if((letra2=="l")||(letra2=="L")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="m")||(letra2=="M")){
            punteo2=punteo2+3;
            punteo2m=punteo2m+3;
    }else if((letra2=="n")||(letra2=="N")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="o")||(letra2=="O")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="p")||(letra2=="P")){
            punteo2=punteo2+3;
            punteo2m=punteo2m+3;
    }else if((letra2=="q")||(letra2=="Q")){
            punteo2=punteo2+5;
            punteo2m=punteo2m+5;
    }else if((letra2=="r")||(letra2=="R")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="s")||(letra2=="S")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="t")||(letra2=="T")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="u")||(letra2=="U")){
            punteo2=punteo2+1;
            punteo2m=punteo2m+1;
    }else if((letra2=="v")||(letra2=="V")){
            punteo2=punteo2+4;
            punteo2m=punteo2m+4;
    }else if((letra2=="w")||(letra2=="W")){
    }else if((letra2=="x")||(letra2=="X")){
            punteo2=punteo2+8;
            punteo2m=punteo2m+8;
    }else if((letra2=="y")||(letra2=="Y")){
            punteo2=punteo2+4;
            punteo2m=punteo2m+4;
    }else if((letra2=="z")||(letra2=="Z")){
            punteo2=punteo2+10;
            punteo2m=punteo2m+10;
    }


    matrix->InsertarMatriz(coordenadaY,coordenadaX,letra2);
    matrix->GraficarMatriz();


    int resp;
    printf("\n �Desea ingresar otra letra?");
    printf("\n [1]-Si");
    printf("\n [0]-No");
    cin>>resp;

    if(resp==1)
    {
        menuMatriz2();
    }
    else
    {
        compararPalabra2();
       if(bandera==1)
       {
           cout<<"\n La palabra se encontro"<<endl;
           if(banderaCasillaD==1)
           {
               punteo2=punteo2*2;
           }
           else if(banderaCasillaT==1)
           {
               punteo2=punteo2*3;
           }
           else
           {
               punteo2=punteo2;
           }
       }
       else
       {
           cout<<"\n La palabra no se encuentra"<<endl;
           punteo2=punteo2-punteo2m;
       }
        //system("cls");
        punteo2m=0;
        cad4[0] = '\0';
        cout<<"\n punteo 2: "<<punteo2;

        int resp2;
        printf("\n �Desea jugar otra ronda?");
        printf("\n [1]-Si");
        printf("\n [0]-No");
        cin>>resp2;

        if(resp2==1)
        {
            contadorGeneralTurnos=contadorGeneralTurnos+1;
            if(contadorGeneralRondas==0)
            {
                listaPunteo1->Insetar(punteo1);
                listaPunteo2->Insetar(punteo2);
                listaPunteo1->Graficar();
                listaPunteo2->Graficar2();
            }
            else if(contadorGeneralRondas==1)
            {
                listaPunteo11->Insetar(punteo1);
                listaPunteo22->Insetar(punteo2);
                listaPunteo11->Graficar();
                listaPunteo22->Graficar2();
            }
            else if(contadorGeneralRondas==2)
            {
                listaPunteo111->Insetar(punteo1);
                listaPunteo222->Insetar(punteo2);
                listaPunteo111->Graficar();
                listaPunteo222->Graficar2();
            }
            else if(contadorGeneralRondas==3)
            {
                listaPunteo1111->Insetar(punteo1);
                listaPunteo2222->Insetar(punteo2);
                listaPunteo1111->Graficar();
                listaPunteo2222->Graficar2();
            }
            else
            {
                listaPunteo1->Insetar(punteo1);
                listaPunteo2->Insetar(punteo2);
                listaPunteo1->Graficar();
                listaPunteo2->Graficar2();
            }
            juego();
        }
        else
        {
            cout<<"\n\t Punteo "<<jugador1<<": "<<punteo1;
            cout<<"\n\t Punteo "<<jugador2<<": "<<punteo2;
            if(contadorGeneralRondas==0)
            {
                listaPunteo1->Insetar(punteo1);
                listaPunteo2->Insetar(punteo2);
                listaPunteo1->Graficar();
                listaPunteo2->Graficar2();
            }
            else if(contadorGeneralRondas==1)
            {
                listaPunteo11->Insetar(punteo1);
                listaPunteo22->Insetar(punteo2);
                listaPunteo11->Graficar();
                listaPunteo22->Graficar2();
            }
            else if(contadorGeneralRondas==2)
            {
                listaPunteo111->Insetar(punteo1);
                listaPunteo222->Insetar(punteo2);
                listaPunteo111->Graficar();
                listaPunteo222->Graficar2();
            }
            else if(contadorGeneralRondas==3)
            {
                listaPunteo1111->Insetar(punteo1);
                listaPunteo2222->Insetar(punteo2);
                listaPunteo1111->Graficar();
                listaPunteo2222->Graficar2();
            }
            else
            {
                listaPunteo1->Insetar(punteo1);
                listaPunteo2->Insetar(punteo2);
                listaPunteo1->Graficar();
                listaPunteo2->Graficar2();
            }
            listaScoreBoard->InsetarScoreBoard(jugador1,punteo1);
            listaScoreBoard->InsetarScoreBoard(jugador2,punteo2);
            listaScoreBoard->GraficarScoreBoard();
            contadorGeneralRondas=contadorGeneralRondas+1;
            contadorGeneralTurnos=0;
            punteo1=0;
            punteo2=0;
            system("cls");
            menu();
        }
    }

}




void randomFichas1()
{
    int num, c;
    string letraFicha="";
    string letraFicha2="";
    srand(time(NULL));
    //char vectorFichas1[48];
    //char vectorFichas2[47];

    //Total de fichas = 95
    for(c = 1; c <= 95; c++)
    {
        num = 1 + rand() % (26 - 1);

        switch(num)
        {
        case 1:
            letraFicha="a";
            letraFicha2="a x 1pts";
            break;
        case 2:
            letraFicha="b";
            letraFicha2="b x 3pts";
            break;
        case 3:
            letraFicha="c";
            letraFicha2="c x 3pts";
            break;
        case 4:
            letraFicha="d";
            letraFicha2="d x 2pts";
            break;
        case 5:
            letraFicha="e";
            letraFicha2="e x 1pts";
            break;
        case 6:
            letraFicha="f";
            letraFicha2="f x 4pts";
            break;
        case 7:
            letraFicha="g";
            letraFicha2="g x 2pts";
            break;
        case 8:
            letraFicha="h";
            letraFicha2="h x 4pts";
            break;
        case 9:
            letraFicha="i";
            letraFicha2="i x 1pts";
            break;
        case 10:
            letraFicha="j";
            letraFicha2="j x 8pts";
            break;
        case 11:
            letraFicha="l";
            letraFicha2="l x 1pts";
            break;
        case 12:
            letraFicha="m";
            letraFicha2="m x 3pts";
            break;
        case 13:
            letraFicha="n";
            letraFicha2="n x 1pts";
            break;
        case 14:
            letraFicha="k";//LETRA � PERO NO SE PUEDE POR EL TECLADO
            letraFicha2="k x 8pts";
            break;
        case 15:
            letraFicha="o";
            letraFicha2="o x 1pts";
            break;
        case 16:
            letraFicha="p";
            letraFicha2="p x 3pts";
            break;
        case 17:
            letraFicha="q";
            letraFicha2="q x 5pts";
            break;
        case 18:
            letraFicha="r";
            letraFicha2="r x 1pts";
            break;
        case 19:
            letraFicha="s";
            letraFicha2="s x 1pts";
            break;
        case 20:
            letraFicha="t";
            letraFicha2="t x 1pts";
            break;
        case 21:
            letraFicha="u";
            letraFicha2="u x 1pts";
            break;
        case 22:
            letraFicha="v";
            letraFicha2="v x 4pts";
            break;
        case 23:
            letraFicha="x";
            letraFicha2="X x 8pts";
            break;
        case 24:
            letraFicha="y";
            letraFicha2="y x 4pts";
            break;
        case 25:
            letraFicha="z";
            letraFicha2="z x 10pts";
            break;
        default:
            cout<<"\n\n Error en la generacion de fichas aleatorias";
        }

        //PARA INGRESAR A LA LISTA DOBLE, QUE ES LA DE LAS FICHAS DE LOS JUGADORES POR PARTIDA
        if(c<=7)
        {
            listaDobleFichas1->InsetarListaCircular(letraFicha);
        }
        else if((c>=8)&&(c<=14))
        {
            listaDobleFichas2->InsetarListaCircular(letraFicha);
        }
        else if((c>=15)&&(c<=21))
        {
            listaDobleFichas11->InsetarListaCircular(letraFicha);
        }
        else if((c>=22)&&(c<=28))
        {
            listaDobleFichas22->InsetarListaCircular(letraFicha);
        }
        else if((c>=29)&&(c<=35))
        {
            listaDobleFichas111->InsetarListaCircular(letraFicha);
        }
        else if((c>=36)&&(c<=42))
        {
            listaDobleFichas222->InsetarListaCircular(letraFicha);
        }
        else if((c>=43)&&(c<=49))
        {
            listaDobleFichas1111->InsetarListaCircular(letraFicha);
        }
        else if((c>=50)&&(c<=57))
        {
            listaDobleFichas2222->InsetarListaCircular(letraFicha);
        }


        //cout << letraFicha<< " ";
        //INGRESANDO A LA COLA, QUE ES LA QUE MUESTRA LAS FICHAS TOTALES DISPONIBLES DEL JUEGO
        colaFichas->InsetarCola(letraFicha2);
    }
        //GRAFICANDO LA COLA Y LISTA DOBLE
        colaFichas->GraficarCola();
        /*listaDobleFichas1->GraficarListaDoble();
        listaDobleFichas2->GraficarListaDoble2();*/

}




int compararPalabra()
{
    bandera=0;
    int s;
    for(s=0; s<500; s++)
    {
        if(arrayDiccionario[s]==cad3)
        {
            bandera=1;
            return bandera;
        }
    }
    return bandera;
}

int compararPalabra2()
{
    bandera=0;
    int s;
    for(s=0; s<500; s++)
    {
        if(arrayDiccionario[s]==cad4)
        {
            bandera=1;
            return bandera;
        }
    }
    return bandera;
}



int casillaDoble()
{
    banderaCasillaD=0;
    int ii;
    for(ii=0; ii<30; ii++)
    {
        if((arrayDobleX[ii]==coordenadaX)&&(arrayDobleY[ii]==coordenadaY))
        {
            banderaCasillaD=1;
            cout<<"\t*** CASILLA x2 ***"<<endl;
            return banderaCasillaD;
        }
    }
    return banderaCasillaD;
}

int casillaTriple()
{
    banderaCasillaT=0;
    int ii;
    for(ii=0; ii<30; ii++)
    {
        if((arrayTripleX[ii]==coordenadaX)&&(arrayTripleY[ii]==coordenadaY))
        {
            banderaCasillaT=1;
            cout<<"\t*** CASILLA x3 ***"<<endl;
            return banderaCasillaT;
        }
    }
    return banderaCasillaT;

}




int comparaJugador()
{
    banderaJugador=0;
    int s;
    for(s=0; s<40; s++)
    {
        if(arrayJugadores[s]==jugador1)
        {
            banderaJugador=1;
            return banderaJugador;
        }
        else if(arrayJugadores[s]==jugador2)
        {
            banderaJugador=2;
            return banderaJugador;
        }
    }
    return banderaJugador;
}




void reportes()
{
    cout<<"\n\t Generando reportes...";
    arbolito->graficar();
    arbolito->graficarIn();
    arbolito->graficarPos();
    arbolito->graficarPre();
}


