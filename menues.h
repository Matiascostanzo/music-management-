#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

mostrarMenuCanciones(){

int opc;
    while (true){
        system("cls");
        cout<<"MENU CANCIONES:"<<endl;
        cout<<"---------------"<<endl;
        cout<<endl;
        cout<<"1.Agregar Cancion"<<endl;
        cout<<"2.Listar Cancion por ID"<<endl;
        cout<<"3.Listar todas las canciones"<<endl;
        cout<<"4.Modificar fecha de estreno"<<endl;
        cout<<"5.Eliminar cancion"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"0.Volver al menu principal"<<endl<<endl;
        cout<<"Seleccionar opcion"<<endl;
        cin>>opc;

        switch(opc){
            case 0: return 0;
                    break;

            case 1: if(agregarCancion()==false)
            {
                cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<endl;
                system("pause");
                return -1;
            }
            else
            {
                cout<<"CANCION AGREGADA"<<endl;
            }
            break;

            case 2: system("cls");
                cout<<"INGRESAR ID DE LA CANCION A BUSCAR: "<<endl;
                int id;
                cin>>id;
                if(buscarIDCancion(id)==-1){
                cout<<"NO EXISTE ESE ID."<<endl;
                system("pause");
                return -1;
            } else {
            leerRegistroCanciones(buscarIDCancion(id)).Mostrar();
            system("pause");
            }
            break;


            case 3: if(mostrarCanciones()==false){

                     cout<<"No hay Canciones en el registro."<<endl;
                     system("pause");
                       }

                    break;

            case 4: if(modificarFechaDeEstreno()==false){
                            cout<<"ERROR EN LA MODIFICACION DEL REGISTRO"<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"REGISTRO MODIFICADO"<<endl;
                            system("pause");
                        }
                        break;

           case 5:  if(eliminarCancion()==false){
                            cout<<"ERROR EN EL BORRADO DEL REGISTRO"<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"REGISTRO BORRADO"<<endl;
                            system("pause");
                        }
                        break;



      }

    }


    return 0;

}

int mostrarMenuInterpretes(){

int opc;
    while (true){
        system("cls");
        cout<<"MENU INTERPRETE:"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1.Agregar Interprete."<<endl;
        cout<<"2.Listar Interprete por ID."<<endl;
        cout<<"3.Listar todos los Interpretes."<<endl;
        cout<<"4.Modificar genero musical principal."<<endl;
        cout<<"5.Eliminar Interprete"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"0.Volver al menu principal"<<endl<<endl;
        cout<<"Seleccionar opcion: "<<endl;
        cin>>opc;
        switch(opc){
            case 0: return 0;
                    break;
            case 1: if(agregarInterprete()==false){
                cout<<"ERROR EN LA APERTURA DEL ARCHIVO."<<endl;
                system("pause");
                return -1;
            }
            else
            {
                cout<<"INTERPRETE AGREGADO."<<endl;
            }
            break;

            case 2:
                system("cls");
                cout<<"INGRESAR ID DEL INTERPRETE A BUSCAR: "<<endl;
                int id;
                cin>>id;
                if(buscarIDInterprete(id)==-1){
                cout<<"NO EXISTE ESE ID."<<endl;
                system("pause");
                return -1;
            } else {
            leerRegistroInterprete(buscarIDInterprete(id)).Mostrar();
            system("pause");
            }
            break;

            case 3: if(listarInterpretes()==-1){
                        cout<<"ERROR DE APERTURA. "<<endl;
                        system("pause");
                        return -1;
                }
            break;

            case 4:
                system("cls");
                cout<<"INGRESAR ID PARA CAMBIAR GENERO: "<<endl;
                int ID;
                cin>>ID;
                if(buscarIDInterprete(ID)==-1){
                    cout<<"NO EXISTE ESE ID."<<endl;
                    system("pause");
                    return -1;
                } else {
                    if (cambiarGenero(buscarIDInterprete(ID)) == 0){
                        cout<<"GENERO CAMBIADO EXITOSAMENTE."<<endl;
                        system("pause");
                    } else {
                        cout<<"ERROR. POR FAVOR VOLVER A INTENTAR."<<endl;
                        system("pause");
                    }

                }
                break;

            case 5:
                system("cls");
                cout<<"INGRESAR ID DEL INTERPRETE A ELIMINAR: "<<endl;
                int ide;
                cin>>ide;
                if(buscarIDInterprete(ide)==-1){
                    cout<<"NO EXISTE ESE ID. "<<endl;
                    system("pause");
                    return -1;
                } else {
                    if (eliminarInterpreteLogico(ide)){
                        cout<<"ELIMINADO EXITOSAMENTE."<<endl;
                        system("pause");
                    } else {
                        cout<<"ERROR EN EL BORRADO."<<endl;
                    }
                }
            }
        }

    }

int mostrarMenuGeneros(){
    int opc;
    while (true){
        system("cls");
        cout<<"MENU GENEROS:"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1.Agregar Genero."<<endl;
        cout<<"2.Listar Genero por ID."<<endl;
        cout<<"3.Listar Todos los Generos."<<endl;
        cout<<"4.Modificar Tipo de Instrumentacion."<<endl;
        cout<<"-------------------"<<endl;
        cout<<"0.Volver al menu principal"<<endl<<endl;
        cout<<"Seleccionar opcion: "<<endl;
        cin>>opc;
        switch(opc){
        case 0: return 0;
            exit(1);
            break;

        case 1: if(agregarGenero() == false){
            cout<<"Error al cargar genero. Intentar nuevamente."<<endl;
            system("pause");
            return -1;
            } else {
            cout<<"Genero agregado exitosamente. "<<endl;
            system("pause");
            }
            break;

        case 2: system("cls");
                cout<<"INGRESAR ID DEL INTERPRETE A BUSCAR: "<<endl;
                int id;
                cin>>id;
                if(buscarIDGenero(id)==-1){
                cout<<"NO EXISTE ESE ID."<<endl;
                system("pause");
                return -1;
            } else {
            leerRegistroGenero(buscarIDGenero(id)).Mostrar();
            system("pause");
            }
            break;
        case 3: system("cls");
                if(listarGeneros()==-1){
                    cout<<"ERROR DE APERTURA. "<<endl;
                    return -1;
                }
                break;
        case 4: system("cls");
                cout<<"Ingresar ID para cambiar Instrumentacion: ";
                cin>>id;
                if(buscarIDGenero(id)==-1){
                    cout<<"NO EXISTE ESE ID."<<endl;
                    system("pause");
                    return -1;
                } else {
                    if (cambiarInstrumentacion(buscarIDGenero(id)) == 0){
                        cout<<"INSTRUMENTACION CAMBIADA EXITOSAMENTE."<<endl;
                        system("pause");
                    } else {
                        cout<<"ERROR. POR FAVOR VOLVER A INTENTAR."<<endl;
                        system("pause");
                    }

                }
                break;
        }

        }
}

int mostrarMenuReportes(){

int opc;
    while (true){
        system("cls");
        cout<<"MENU REPORTES:"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1. Cantidad de interpretes argentinos"<<endl;
        cout<<"2 Cantidad de generos por tipo de instrumentacion"<<endl;
        cout<<"3 Cantidad de canciones de cada interprete"<<endl;
        cout<<"4 Cantidad de canciones por cada genero"<<endl;
        cout<<"5 Punto 1 Parcial: Listar las canciones estrenadas despues del 2010 de un autor ingresado por teclado"<<endl;
        cout<<"6 Punto 3 Parcial: "<<endl;

        cout<<"-------------------"<<endl;
        cout<<"0.Volver al menu principal"<<endl<<endl;
        cout<<"Seleccionar opcion: "<<endl;
        cin>>opc;

        switch(opc){


    case 0: return 0;
            break;

    case 1: if(interpretesArgentinos() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            break;
    }
    case 2: if(cantGenerosPorInstrumentacion() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            }
            break;



    case 3: contarCancionesTodosLosInterprete();
        break;

    case 4:int id;
           contarCancionesPorGenero(id);

   case 5:punto1Parcial();

   case 6:punto3Parcial();


}
}
}

int mostrarMenuConfig(){
    int opc;
    while (true){
        system("cls");
        cout<<"MENU CONFIGURACION:"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1. COPIA DE SEGURIDAD DEL ARCHIVO CANCIONES"<<endl;
        cout<<"2. COPIA DE SEGURIDAD DEL ARCHIVO INTERPRETES"<<endl;
        cout<<"3. COPIA DE SEGURIDAD DEL ARCHIVO GENEROS"<<endl;
        cout<<"4. RESTAURAR EL ARCHIVO CANCIONES"<<endl;
        cout<<"5. RESTAURAR EL ARCHIVO INTERPRETES"<<endl;
        cout<<"6. RESTAURAR EL ARCHIVO GENEROS"<<endl;
        cout<<"7. ESTABLECEER DATOS DE INICIO"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"0.Volver al menu principal"<<endl<<endl;
        cout<<"Seleccionar opcion: "<<endl;
        cin>>opc;

        switch(opc){


    case 0: return 0;
            break;

    case 1: if(copiaCanciones() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Copia generada exitosamente."<<endl;
            system("pause");
            }

            break;
    case 2: if(copiaInterprete() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Copia generada exitosamente."<<endl;
            system("pause");
            }
            break;

    case 3: if(copiaGeneros() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Copia generada exitosamente."<<endl;
            system("pause");
            }
            break;

    case 4: if(restaurarCanciones() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Restauracion generada exitosamente."<<endl;
            system("pause");
            }
            break;
    case 5: if(restaurarInterprete() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Restauracion generada exitosamente."<<endl;
            system("pause");
            }
            break;
    case 6: if(restaurarGeneros() == false){
            cout<<"Error al abrir archivo. Intentar nuevamente."<<endl;
            system("pause");
            return false;
            } else {
            cout<<"Restauracion generada exitosamente."<<endl;
            system("pause");
            }
            break;




}
}
}

#endif // MENUES_H_INCLUDED
