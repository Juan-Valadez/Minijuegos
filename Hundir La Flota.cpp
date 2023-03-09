#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(){

char tablero[7][7];
srand(time(nullptr));

//-----------------------------------------------PRESENTACION----------------------------------------------
cout<<endl<<endl;
cout<<"     //    / / //   / / /|    / / //    ) )   / /    //   ) )       / /        // | |       //   / / / /        //   ) ) /__  ___/ // | |"<<endl;
cout<<"    //___ / / //   / / //|   / / //    / /   / /    //___/ /       / /        //__| |      //___    / /        //   / /    / /    //__| |"<<endl;
cout<<"   / ___   / //   / / // |  / / //    / /   / /    / ___ (        / /        / ___  |     / ___    / /        //   / /    / /    / ___  |"<<endl;
cout<<"  //    / / //   / / //  | / / //    / /   / /    //   | |       / /        //    | |    //       / /        //   / /    / /    //    | |"<<endl;
cout<<" //    / / ((___/ / //   |/ / //____/ / __/ /___ //    | |      / /____/ / //     | |   //       / /____/ / ((___/ /    / /    //     | |"<<endl;
cout<<endl<<endl;
cout << "//////////BIEN VENIDO A//////////"<<endl;
cout << "//////////HUNDIR LA FLOTA//////////"<<endl<<endl;

//Quieres Jugar?
char s;
cout<<"         Quieres Jugar? s/n ";
cin >> s;
if(s == 'n'){
    return 0;
}
cout<<endl;

//----------------------------------------------Tablero Final----------------------------------------------

//--------Valores Vacios ---------

for(int i=0;i<7;i++){
    for(int a=0;a<7;a++){
    
    tablero[i][a] = '~';
    //Filas A
    tablero[i][0] = 'A';

    //Columnas B
    tablero[0][i] = 'B';
    }
}
//Espacio en blanco
tablero[0][0] = ' ';

//--------------------------------------------BARCOS-----------------------------------------------------
int barcos;
barcos = rand() % 3 + 1;

//---------------------Opcion 1
if(barcos == 1){
//---Barco 1
tablero[5][5] = '+'; 
tablero[4][5] = '+'; 
//---Barco 2
tablero[4][1] = '+'; 
tablero[4][2] = '+';
tablero[4][3] = '+';
//---Barco 3
tablero[3][5] = '+'; 
tablero[2][4] = '+';
tablero[1][3] = '+'; 
tablero[4][6] = '+'; 
}
//---------------------Opcion 2
if(barcos == 2){
//---Barco 1
tablero[6][5] = '+'; 
tablero[6][6] = '+'; 
//---Barco 2
tablero[4][1] = '+'; 
tablero[3][2] = '+';
tablero[2][3] = '+';
//---Barco 3
tablero[6][2] = '+'; 
tablero[5][3] = '+';
tablero[4][4] = '+'; 
tablero[3][5] = '+'; 
}
//---------------------Opcion 3
if(barcos == 3){
//---Barco 1
tablero[6][2] = '+'; 
tablero[5][3] = '+'; 
//---Barco 2
tablero[1][1] = '+'; 
tablero[2][1] = '+';
tablero[3][1] = '+';
//---Barco 3
tablero[1][6] = '+'; 
tablero[2][6] = '+';
tablero[3][6] = '+'; 
tablero[4][6] = '+'; 
}


//----------------------------------------------Inicio Juego----------------------------------------------
int fila=0;
int columna=0;
char tableroc[7][7];
int ganar=0;

//----------------------------------------------Tablero de Jugador----------------------------------------
for(int i=0;i<7;i++){
    for(int a=0;a<7;a++){
    
    tableroc[i][a] = '~';
    //Filas A
    tableroc[i][0] = 'A';

    //Columnas B
    tableroc[0][i] = 'B';
    }
}
//Espacio en blanco
tableroc[0][0] = ' ';

//----------------------------------------------Inicio Juego----------------------------------------------
for(int b=0;b<18;b++){cout<<endl<<endl;

    //Filas
    cout << "Diga una fila del 1 al 6: ";cin >> fila;

    while(fila<1 || fila>6){
    cout << "Esta coordenada esta fuera de rango"<<endl;
    cout << "Diga una fila del 1 al 6: ";cin >> fila;
    }

    //Columnas
    cout << "Diga una columna del 1 al 6: ";cin >> columna;
    while(columna<1 || columna>6){
    cout << "Esta coordenada esta fuera de rango"<<endl;
    cout << "Diga una columna del 1 al 6: ";cin >> fila;
    }cout<<endl;

    //Repetirdo
    if(tablero[fila][columna]=='X' || tablero[fila][columna]=='O'){
    cout << "Ya has dicho esta coordenada"<<endl;
    b = b - 1;
    }

    //Tocado
    if(tablero[fila][columna]=='+'){
        cout <<"\t Tocado!!!"<<endl;
        tableroc[fila][columna]='X';
        tablero[fila][columna]='X';
        ganar = ganar + 1;



    //Agua
    }
    if(tablero[fila][columna]=='~'){
        cout <<"\t Agua :("<<endl;
        tableroc[fila][columna]='O';
        tablero[fila][columna]='O';
    }

    //Has ganado?
    if(ganar > 8){
    cout << "HAS GANADO :)";
    return 0;
    }

//--------Salida Tablero de Jugador---------

for(int i=0;i<7;i++){cout<<endl;
    for(int a=0;a<7;a++){
    cout << tableroc[i][a] <<"   ";
    }
}
}


//------------------------------------------Salida de Valores para tablero--------------------------

cout <<"\n Has Perdido :("<<endl<<endl;

cout << "Si hay una X has acertado esa coordenada"<<endl;
cout << "Si hay una O no has acertado esa coordenada"<<endl;
cout << "Estas son las ubicaciones de los barcso"<<endl<<endl;
//------------------------------
for(int i=0;i<7;i++){cout<<endl;
    for(int a=0;a<7;a++){
    cout << tablero[i][a] <<"   ";
    }
}
//------------------------------------------Fin-Tablero----------------------------------------------

    return 0;
}