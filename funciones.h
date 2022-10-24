#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

bool agregarCancion(){
    system("cls");
     Canciones reg;

     FILE *pCancion;
     pCancion=fopen("Canciones.dat","ab");
    if(pCancion==NULL){
        return false;
    }

        cout<<"INGRESAR DATOS DE LA CANCION"<<endl;
        cout<<endl;
        reg.Cargar();
        fwrite(&reg,sizeof reg, 1, pCancion);
        fclose(pCancion);
        return true;
}

bool agregarInterprete(){
    system("cls");
     Interprete reg;

     FILE *pInterprete;
     pInterprete=fopen("Interprete.dat","ab");
    if(pInterprete==NULL){
        return false;
    }

        cout<<"INGRESAR DATOS DEL INTERPRETE"<<endl;
        cout<<endl;
        reg.Cargar();
        fwrite(&reg,sizeof reg, 1, pInterprete);
        fclose(pInterprete);
        return true;
}

bool agregarGenero(){
    system("cls");
     Generos reg;

     FILE *pGeneros;
     pGeneros=fopen("Generos.dat","ab");
    if(pGeneros==NULL){
        return false;
    }

        cout<<"INGRESAR DATOS DEL GENERO."<<endl;
        cout<<endl;
        reg.Cargar();
        fwrite(&reg,sizeof reg, 1, pGeneros);
        fclose(pGeneros);
        return true;
}

int buscarIDCancion(int ID){
    Canciones obj;
    FILE *pCancion;
    int pos=0;
    pCancion=fopen("Canciones.dat","rb");
    if(pCancion==NULL){
        return -1;
    }
    while(fread(&obj,sizeof obj, 1, pCancion)==1){
        if(obj.getID()==ID){
            fclose(pCancion);
            return pos;
        }
        pos++;
    }
    fclose(pCancion);
    return -1;
}

int buscarIDInterprete(int ID){
    Interprete obj;
    FILE *pInterprete;
    int pos=0;
    pInterprete=fopen("Interprete.dat","rb");
    if(pInterprete==NULL){
        return -1;
    }
    while(fread(&obj,sizeof obj, 1, pInterprete)==1){
        if(obj.getIDdelInterprete()==ID){
            fclose(pInterprete);
            return pos;
        }
        pos++;
    }
    fclose(pInterprete);
    return -1;
}

int buscarIDGenero(int ID){
    Generos obj;
    FILE *pGeneros;
    int pos=0;
    pGeneros=fopen("Generos.dat","rb");
    if(pGeneros==NULL){
        return -1;
    }
    while(fread(&obj,sizeof obj, 1, pGeneros)==1){
        if(obj.getID()==ID){
            fclose(pGeneros);
            return pos;
        }
        pos++;
    }
    fclose(pGeneros);
    return -1;
}

int listarCanciones(int ID){
    Canciones obj;
    FILE *pCancion;
    int pos=0;
    pCancion=fopen("Canciones.dat","rb");
    if(pCancion==NULL){
        return -1;
    }
    while(fread(&obj,sizeof obj, 1, pCancion)==1){
        if(obj.getID()==ID){
            fclose(pCancion);
            return pos;
        }
        pos++;
    }
    fclose(pCancion);
    return -1;
}

int listarInterpretes(){
    Interprete obj;
    FILE *pInterprete;
    int pos=0;
    pInterprete=fopen("Interprete.dat","rb");
    if(pInterprete==NULL){
        return -1;
    }
    while(fread(&obj, sizeof obj, 1, pInterprete) == 1){
    // este while va a leer todo lo que haya en el archivo.
    obj.Mostrar();
    cout<<endl;
}
    system("pause");
    fclose(pInterprete);
    return 0;
}

int listarGeneros(){
    Generos obj;
    FILE *pGeneros;
    int pos=0;
    pGeneros=fopen("Generos.dat","rb");
    if(pGeneros==NULL){
        return -1;
    }
    while(fread(&obj, sizeof obj, 1, pGeneros) == 1){
    // este while va a leer todo lo que haya en el archivo.
    obj.Mostrar();
    cout<<endl;
}
    system("pause");
    fclose(pGeneros);
    return 0;
}

Canciones leerRegistroCanciones(int pos){
    Canciones reg;
    reg.setID(-1);
    FILE *pCancion;
    pCancion=fopen("Canciones.dat","rb");
    if(pCancion==NULL){
        return reg;
    }
    int desplazamiento=pos*sizeof reg;///cantidad de bytes que necesito desplazarme
    int desde_donde=0;
    ///0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    ///1 SEEK_CUR DESDE LA POSICION ACTUACL
    ///2 SEEK_END DESDE LA POSICION FINAL

    fseek(pCancion,desplazamiento,0);
    fread(&reg, sizeof reg, 1,pCancion);
    fclose(pCancion);
    return reg;
}

Interprete leerRegistroInterprete(int pos){
    Interprete reg;
    reg.setIDdelInterprete(-1);
    FILE *pInterprete;
    pInterprete=fopen("Interprete.dat","rb");
    if(pInterprete==NULL){
        return reg;
    }
    int desplazamiento=pos*sizeof reg;///cantidad de bytes que necesito desplazarme
    int desde_donde=0;
    ///0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    ///1 SEEK_CUR DESDE LA POSICION ACTUACL
    ///2 SEEK_END DESDE LA POSICION FINAL

    fseek(pInterprete,desplazamiento,0);
    fread(&reg, sizeof reg, 1,pInterprete);
    fclose(pInterprete);
    return reg;
}

Generos leerRegistroGenero(int pos){
    Generos reg;
    reg.setID(-1);
    FILE *pGeneros;
    pGeneros=fopen("Generos.dat","rb");
    if(pGeneros==NULL){
        return reg;
    }
    int desplazamiento=pos*sizeof reg;///cantidad de bytes que necesito desplazarme
    int desde_donde=0;
    ///0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    ///1 SEEK_CUR DESDE LA POSICION ACTUACL
    ///2 SEEK_END DESDE LA POSICION FINAL

    fseek(pGeneros, desplazamiento,0);
    fread(&reg, sizeof reg, 1,pGeneros);
    fclose(pGeneros);
    return reg;
}

bool sobreEscribirRegistroCanciones(Canciones obj, int pos){
    FILE *pCancion;
    pCancion=fopen("Canciones.dat", "rb+"); ///+ le agrega al modo lo que le falta
    if(pCancion==NULL)return false;
    fseek(pCancion, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, pCancion);
    fclose(pCancion);
    return escribio;
}

bool sobreEscribirRegistroInterprete(Interprete obj, int pos){
    FILE *pInterprete;
    pInterprete=fopen("Interprete.dat", "rb+"); ///+ le agrega al modo lo que le falta
    if(pInterprete==NULL)return false;
    fseek(pInterprete, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, pInterprete);
    fclose(pInterprete);
    return escribio;
}

bool sobreEscribirRegistroGenero(Generos obj, int pos){
    FILE *pGeneros;
    pGeneros=fopen("Generos.dat", "rb+"); ///+ le agrega al modo lo que le falta
    if(pGeneros==NULL)return false;
    fseek(pGeneros, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, pGeneros);
    fclose(pGeneros);
    return escribio;
}

int cambiarGenero(int pos){
    cout<<"INGRESAR GENERO: "<<endl;
    int genero;
    cin>>genero;
    Interprete obj;
    FILE *pInterprete;
    obj = leerRegistroInterprete(pos);
    obj.setGeneroMusicalPrincipal(genero);
    if (sobreEscribirRegistroInterprete(obj, pos)){
        return 0;
    }
    return -1;
}

int cambiarInstrumentacion(int pos){
    cout<<"INGRESAR INSTRUMENTACION: "<<endl;
    int inst;
    cin>>inst;
    if (inst>0 && inst<5){
        Generos obj;
        FILE *pGeneros;
        obj = leerRegistroGenero(pos);
        obj.setInst(inst);
        if (sobreEscribirRegistroGenero(obj, pos)){
            return 0;
    }

    } else {
    cout<<"El tipo de instrumentacion no puede ser menor que 1 ni mayor a 5. "<<endl;
    return -1;
    }
}


bool modificarFechaDeEstreno(){

Canciones obj;
    int ID, pos;
    ///buscar el registro a modificar
    cout<<"INGRESE EL ID DEL REGISTRO A MODIFICAR: ";
    cin>>ID;
    ///leer si existe el registro
    pos=buscarIDCancion(ID);
    if(pos==-1){
        cout<<"NO EXISTE EL DNI EN EL ARCHIVO"<<endl;
        return false;
    }
    obj=leerRegistroCanciones(pos);
    ///cambiar la nueva fecha de estreno
    Fecha nuevaFecha;
    cout<<"INGRESE la nueva fecha de estreno: ";
    nuevaFecha.Cargar();
    obj.setFechaDeEstreno(nuevaFecha);
    ///sobreescribir el registro
    return sobreEscribirRegistroCanciones(obj, pos);
}

bool eliminarCancion(){
    Canciones obj;
    int ID, pos;
    ///buscar el registro a eliminar
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>ID;
    ///leer si existe el registro
    pos=buscarIDCancion(ID);
    if(pos==-1){
        cout<<"NO EXISTE LA CANCION EN EL ARCHIVO"<<endl;
        return false;
    }
    obj=leerRegistroCanciones(pos);
    ///cambiar el estado del campo
    obj.setEstado(false);
    ///sobreescribir el registro
    if(sobreEscribirRegistroCanciones(obj, pos))
    return true;
    return false;
}


bool mostrarCanciones(){

system("cls");

    Canciones reg;
    FILE *pCanc;
    pCanc=fopen("Canciones.dat","rb");
    if(pCanc==NULL)
    {
        return false;
    }

    while(fread(&reg,sizeof reg, 1, pCanc)==1)
    {
        reg.Mostrar();

        cout<<endl;
    }
    fclose(pCanc);
    system("pause");

    return true;

}

bool eliminarInterpreteLogico(int id){
    Interprete obj;
    int pos;
    FILE *pAlu;
    pos = buscarIDInterprete(id);
    obj=leerRegistroInterprete(pos);
    /// Cambiar el estado del campo:
    obj.setEstado(false); // para esto, la clase objeto debe tener un valor booleando dentro de si que se llame estado
    /// sobreescribir el registro:
    if (sobreEscribirRegistroInterprete(obj, pos))
    return true;

}

bool copiaCanciones(){
Canciones obj;
int pos=0;
FILE *p;
p=fopen("Canciones.bkp", "wb");
if(p==NULL){
    return false;
}
while(obj.leerDeDisco(pos++)){

fwrite(&obj, sizeof obj, 1, p);
}
fclose(p);
return true;
}

bool copiaInterprete(){
Interprete obj;
int pos=0;
FILE *p;
p=fopen("Interprete.bkp", "wb");
if(p==NULL){
    return false;
}
while(obj.leerDeDisco(pos++)){

fwrite(&obj, sizeof obj, 1, p);
}
fclose(p);
return true;
}

bool copiaGeneros(){
Generos obj;
int pos=0;
FILE *p;
p=fopen("Generos.bkp", "wb");
if(p==NULL){
    return false;
}
while(obj.leerDeDisco(pos++)){

fwrite(&obj, sizeof obj, 1, p);
}
fclose(p);
return true;
}

bool restaurarCanciones(){
Canciones obj;
int pos=0;
FILE *p;
p=fopen("Canciones.bkp", "rb");
if(p==NULL){
    return false;
}
FILE *p2;
p2=fopen("Canciones.dat", "wb");

if(p2==NULL){
    return false;
}

while(fread(&obj, sizeof obj, 1, p)==1){

fwrite(&obj, sizeof obj, 1, p2);

}
fclose(p);
fclose(p2);
return true;
}

bool restaurarInterprete(){
Interprete obj;
int pos=0;
FILE *p;
p=fopen("Interprete.bkp", "rb");
if(p==NULL){
    return false;
}
FILE *p2;
p2=fopen("Interprete.dat", "wb");

if(p2==NULL){
    return false;
}

while(fread(&obj, sizeof obj, 1, p)==1){

fwrite(&obj, sizeof obj, 1, p2);

}
fclose(p);
fclose(p2);
return true;
}

bool restaurarGeneros(){
Generos obj;
int pos=0;
FILE *p;
p=fopen("Generos.bkp", "rb");
if(p==NULL){
    return false;
}
FILE *p2;
p2=fopen("Generos.dat", "wb");

if(p2==NULL){
    return false;
}

while(fread(&obj, sizeof obj, 1, p)==1){

fwrite(&obj, sizeof obj, 1, p2);

}
fclose(p);
fclose(p2);
return true;
}
#endif // FUNCIONES_H_INCLUDED
