#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

int contarRegistrosCanciones();
int contarRegistrosInterprete();
int contarRegistrosGeneros();

class Fecha{
private:
    int dia, mes, anio;
public:
    void setDia(int d){dia=d;}
    void setMes(int d){mes=d;}
    void setAnio(int d){anio=d;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void Cargar(){
        cout<<"DIA: ";
        cin>>dia;
        while(dia<1 || dia>31){
            cout<<"INGRESAR DIA VALIDO: "<<endl;
            cin>>dia;
        }
        cout<<"MES: ";
        cin>>mes;
        while(mes<1 || mes>12){
            cout<<"INGRESAR MES VALIDO: "<<endl;
            cin>>mes;
        }
        switch(mes)
        {
            case 4: case 6: case 9: case 11:
                while(dia>30){
                    cout<<"INGRESAR DIA VALIDO: "<<endl;
                    cin>>dia;
                }
                break;
            case 2:
                while(dia>28){
                    cout<<"INGRESAR DIA VALIDO: "<<endl;
                    cin>>dia;
                }
                break;
        }
        cout<<"ANIO: ";
        cin>>anio;


        while(anio>2022) {
        cout<<"INGRESAR ANIO VALIDO: "<<endl;
        cin>>anio;
        }
    }
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

};

class Interprete{

private:
        int IDdelInterprete;
        char nombreInterprete[40];
        int nacionalidad;
        int tipoDeInterprete;
        int generoMusicalPrincipal;
        Fecha fechaInicioActividad;
        bool estado;


public:
       void setIDdelInterprete(int in){IDdelInterprete=in;}
       void setNombreInterprete(const char *ni){strcpy(nombreInterprete, ni);}
       void setNacionalidad(int nac){nacionalidad=nac;}
       void setTipoDeInterprete(int tip){tipoDeInterprete=tip;}
       void setFechaInicioActividad(Fecha fe){fechaInicioActividad=fe;}
       void setGeneroMusicalPrincipal(int gen){generoMusicalPrincipal=gen;}
       void setEstado(bool es){estado=es;}

       int getIDdelInterprete(){return IDdelInterprete;}
       const char *getNombreInterprete(){return nombreInterprete;}
       int getNacionalidad(){return nacionalidad;}
       int getTipoDeInterprete(){return tipoDeInterprete;}
       Fecha getFechaInicioActividad(){return fechaInicioActividad;}
       int getGeneroMusicalPrincipal(){return generoMusicalPrincipal;}
       bool getEstado(){return estado;}


       void Cargar(){

       cout<<"ID del interprete: ";
       IDdelInterprete = contarRegistrosInterprete() + 1;
       cout<<IDdelInterprete;
       cout<<endl;
       cout<<"Ingresar nombre del interprete: ";
       cargarCadena(nombreInterprete, 39);
       cout<<endl;
       cout<<"Ingresar nacionalidad del interprete: ";
       cin>>nacionalidad;
       cout<<endl;
       cout<<"Ingresar tipo de interprete: "<<endl;
       cin>>tipoDeInterprete;
       cout<<endl;
       cout<<"Ingresar fecha de inicio de actividad del interprete: "<<endl;
       fechaInicioActividad.Cargar();
       cout<<endl;
       cout<<"Ingresar genero principal del interprete:"<<endl;
       cin>>generoMusicalPrincipal;
       cout<<endl;

       estado = true;


    }

      void Mostrar(){
    if (estado==true){
    cout<<"ID de interprete: "<<getIDdelInterprete()<<endl;
    cout<<"Nombre del interprete: "<<getNombreInterprete()<<endl;
    cout<<"Nacionalidad del interprete: "<<getNacionalidad()<<endl;
    cout<<"Tipo de interprete: "<<getTipoDeInterprete()<<endl;
    cout<<"Fecha de inicio de actividad del interprete: ";
    fechaInicioActividad.Mostrar();
    cout<<"Genero musical principal del interprete: "<<getGeneroMusicalPrincipal()<<endl;
    }
}

    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("Interprete.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Interprete),0);
    bool leyo=fread(this, sizeof (Interprete), 1,p);
    fclose(p);
    return leyo;
}

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("Interprete.dat","ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(this, sizeof (Interprete), 1,p);
    fclose(p);
    return escribio;
}

bool buscarIDInterprete(int ID){
    Interprete obj;
    FILE *pInterprete;
    int pos=0;
    pInterprete=fopen("Interprete.dat","rb");
    if(pInterprete==NULL){
        return false;
    }
    while(fread(&obj,sizeof obj, 1, pInterprete)==1){
        if(obj.getIDdelInterprete()==ID){
            fclose(pInterprete);
            return true;
        }
        pos++;
    }
    fclose(pInterprete);
    return false;
}




};

class Canciones{

private:
        int ID;
        char nombre[30];
        char nombreAutor[30];
        int IDinterprete;
        Fecha fechaDeEstreno;
        float duracion;
        int genero;
        bool estado;


public:
       void setID(int i){ID=i;}
       void setNombre(const char *n){strcpy(nombre, n);}
       void setNombreAutor(const char *na){strcpy(nombreAutor,na);}
       void setIDinterprete(int in){IDinterprete=in;}
       void setFechaDeEstreno(Fecha f){fechaDeEstreno=f;}
       void setDuracion(float d){duracion=d;}
       void setGenero(int g){genero=g;}
       void setEstado(bool e){estado=e;}

       int getID(){return ID;}
       const char *getNombre(){return nombre;}
       const char *getNombreAutor(){return nombreAutor;}
       int getIDinterprete(){return IDinterprete;}
       Fecha getFechaDeEstreno(){return fechaDeEstreno;}
       float getDuracion(){return duracion;}
       int getGenero(){return genero;}
       bool getEstado(){return estado;}

       void Cargar(){

       system("cls");
       cout<<"ID de la cancion: ";
       ID = contarRegistrosCanciones() + 1;
       cout<<ID;
       cout<<endl;
       cout<<"Ingresar nombre de la cancion: ";
       cargarCadena(nombre, 29);
       cout<<endl;
       cout<<"Ingresar nombre del autor: ";
       cargarCadena(nombreAutor, 29);
       cout<<endl;
       cout<<"Ingresar ID del interprete: "<<endl;
       cin>>IDinterprete;
       Interprete obj;
       while(!obj.buscarIDInterprete(IDinterprete)){
        cout<<"Ingresar ID del interprete EXISTENTE: "<<endl;
        cin>>IDinterprete;
       }
       cout<<endl;
       cout<<"Ingresar fecha de estreno de la cancion: "<<endl;
       fechaDeEstreno.Cargar();
       cout<<endl;
       cout<<"Ingresar duracion de la cancion: "<<endl;
       cin>>duracion;
       while(duracion<0){
        cout<<"Ingresar duracion VALIDA: "<<endl;
        cin>>duracion;
       }
       cout<<endl;
       cout<<"Ingresar numero del genero de la cancion:"<<endl;
       cin>>genero;
       while(genero<0 || genero>10){
        cout<<"Ingresar numero del genero de la cancion:"<<endl;
       cin>>genero;
       }
       cout<<endl;
       estado=true;
       //cout<<"Ingresar el estado de la cancion: "<<endl;
      // cin>>estado;


       }

       void Mostrar(){
    if(estado==true){

    cout<<"ID cancion: "<<getID()<<endl;
    cout<<"Nombre de la cancion: "<<getNombre()<<endl;
    cout<<"Nombre del autor: "<<getNombreAutor()<<endl;
    cout<<"ID del interprete: "<<getIDinterprete()<<endl;
    cout<<"Fecha de estreno de la cancion: ";
    fechaDeEstreno.Mostrar();
    cout<<"Duracion de la cancion: "<<getDuracion()<<" minutos"<<endl;
    cout<<"Genero de la cancion: "<<" "<<getGenero()<<endl;

    }

}

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("Canciones.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Canciones),0);
    bool leyo=fread(this, sizeof (Canciones), 1,p);
    fclose(p);
    return leyo;
}

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("Canciones.dat","ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(this, sizeof (Canciones), 1,p);
    fclose(p);
    return escribio;
}






};

class Generos{
private:
    int id;
    char nombre[40];
    int origen;
    int inst;
    bool estado;

public:
    void setID(int d){id=d;}
    void setNombre(const char *p){strcpy(nombre, p);}
    void setOrigen(int d){origen=d;}
    void setInst(int d){inst=d;}
    void setEstado(bool d){estado=d;}

    int getID(){return id;}
    const char *getNombre(){return nombre;}
    int getOrigen(){return origen;}
    int getInst(){return inst;}
    bool getEstado(){return estado;}

    void Cargar(){
        int val=1;
        cout<<"ID del genero: ";
        id = contarRegistrosGeneros() + 1;
        cout<<id<<endl;
        cout<<"Nombre: ";
        cargarCadena(nombre, 40);
        while(val!=0){
        cout<<"Pais de origen: ";
        cin>>origen;
        if (origen>100 || origen<=0){
            cout<<"El pais de origen no puede ser menor a 1 ni mayor a 100."<<endl;

        }
        else{
            val=0;
        }
        }

        cout<<"Tipo de instrumentacion: ";
        cin>>inst;
        if (inst>5 || inst<=0){
            cout<<"El tipo de instrumentacion no puede ser menor a 1 ni mayor a 5."<<endl;
            exit(1);
        }
        estado = true;
    }
    void Mostrar(){
        if(estado==true){
            cout<<"ID del genero: "<<id<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Pais de origen: "<<origen<<endl;
            cout<<"Tipo de instrumentacion: "<<inst<<endl;
        }
    }

    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("Generos.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Generos),0);
    bool leyo=fread(this, sizeof (Generos), 1,p);
    fclose(p);
    return leyo;
}

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("Generos.dat","ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(this, sizeof (Generos), 1,p);
    fclose(p);
    return escribio;
}





};

int contarRegistrosCanciones(){
    int total=0, cant_registros=0;
    FILE *p;
    p=fopen("Canciones.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, SEEK_END);
    total = ftell(p); // cant de bytes desde el inicio hasta donde está el seek
    fclose(p);
    cant_registros=total/sizeof(Canciones);
    return cant_registros;
}

int contarRegistrosInterprete(){
    int total=0, cant_registros=0;
    FILE *p;
    p=fopen("Interprete.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, SEEK_END);
    total = ftell(p); // cant de bytes desde el inicio hasta donde está el seek
    fclose(p);
    cant_registros=total/sizeof(Interprete);
    return cant_registros;
}

int contarRegistrosGeneros(){
    int total=0, cant_registros=0;
    FILE *p;
    p=fopen("Generos.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, SEEK_END);
    total = ftell(p); // cant de bytes desde el inicio hasta donde está el seek
    fclose(p);
    cant_registros=total/sizeof(Generos);
    return cant_registros;
}

#endif // CLASES_H_INCLUDED
