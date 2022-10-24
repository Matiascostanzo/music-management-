#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctime>


using namespace std;
#include "funcionesGlobales.h"
#include "clases.h"
#include "reportes.h"
#include "funciones.h"
#include "menues.h"



int main(){

    int opc;
    while (true){

        system("cls");
        cout<<"MENU PRINCIPAL "<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1.Menu Canciones"<<endl;
        cout<<"2.Menu Interpretes"<<endl;
        cout<<"3.Menu Generos"<<endl;
        cout<<"4.Reportes"<<endl;
        cout<<"5.Configuracion"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0.FIN DEL PROGRAMA"<<endl;
        cout<<"Seleccionar opcion: "<<endl;
        cin>>opc;
        switch(opc){
            case 0: exit(1);
                    break;
            case 1: mostrarMenuCanciones();
                    break;
            case 2: mostrarMenuInterpretes();
                    break;
            case 3: mostrarMenuGeneros();
                    break;

            case 4: mostrarMenuReportes();
                    break;

            case 5: mostrarMenuConfig();
                    break;

           }

    }



    return 0;

}











