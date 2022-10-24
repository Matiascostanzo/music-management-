#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

bool interpretesArgentinos(){


Interprete obj;
int pos=0;

while(obj.leerDeDisco(pos)){

        if(obj.getNacionalidad()==5){

            obj.Mostrar();
            cout<<endl;
        }
        pos++;
     }

}

void mostrarVector(int *v, int tam){

for(int i=0;i<tam;i++){
    cout<<"PARA EL TIPO DE INSTRUMENTACION "<<i+1<<" HAY "<<v[i]<<" GENEROS"<<endl;
}


}

bool cantGenerosPorInstrumentacion(){

Generos obj;
int vGenero[5]{};
int pos=0;

while(obj.leerDeDisco(pos++)){

    vGenero[obj.getInst()-1]++;
}
mostrarVector(vGenero,5);

}

class Interprete2021{

private:
        int ID;
        char nombre[40];
        int cantCanciones;

public:
       void setId(int i){ID=i;}
       void setNombre(const char *n){strcpy(nombre,n);}
       void setCantCanciones(int c){cantCanciones=c;}

       void Mostrar(){
        cout<<"ID de interprete: "<<ID<<endl;
        cout<<"Nombre del interprete: "<<nombre<<endl;
        cout<<"Cantidad de canciones: "<<cantCanciones<<endl;
        }

       bool grabarEnDisco(){

       FILE *p;
       p=fopen("interpretes2021.dat","ab");
       if(p==NULL)return false;
       bool escribio=fwrite(this,sizeof(Interprete2021),1,p);
       fclose(p);
       return escribio;

       }


};


int contarCancionesInterprete(int id){

Canciones obj;
int pos=0,cant=0;

while(obj.leerDeDisco(pos++)){

    //POR CADA REG, CHEQUEAR SI ES DEL INTERPRETE QUE RECIBI

    if(obj.getIDinterprete()==id && obj.getEstado()){

        cant++;
    }
}

return cant;

}










int contarCancionesTodosLosInterprete(){

Canciones obj;
int i,id=1;


for(i=0;i<8;i++){
int pos=0;
int cant=0;
while(obj.leerDeDisco(pos++)){



    if(obj.getIDinterprete()==id && obj.getEstado()){

        cant++;
    }
}
cout<<"El interprete"<<" "<<id<<" "<<"tiene"<< " "<<cant<<" canciones."<<endl;
id++;
}
system("pause");



}

int contarCancionesPorGenero(int id){

Canciones obj;
int pos=0,cant=0;
cout<<"Ingresar genero a analizar"<<endl;
cin>>id;
while(obj.leerDeDisco(pos++)){

    //POR CADA REG, CHEQUEAR SI ES DEL INTERPRETE QUE RECIBI

    if(obj.getGenero()==id && obj.getEstado()){

        cant++;
    }
}

 cout<<" El genero"<<" "<<id<<" tiene "<<" "<<cant<<" "<<" cancion/canciones"<<endl;
system("pause");
}


void punto1Parcial(){

Canciones obj;
int pos=0;
int contador=0;

char nombreAutor[30];
cout<<"Ingresar autor para visualizar sus canciones:"<<endl;
cargarCadena(nombreAutor,29);

while(obj.leerDeDisco(pos)==1){

    if(obj.getFechaDeEstreno().getAnio()<2010 && strcmp(obj.getNombreAutor(),nombreAutor)==0){

    obj.Mostrar();
    system("pause");


    contador++;

    }
    pos++;
}

if(contador==0){
    cout<<"No tiene canciones previas al anio 2010"<<endl;
    system("pause");
}

}

/*void punto2Parcial(){

Interprete aux;
Generos obj;
int pos=0;
int contador=0;
int total=0;
int vectorNacionalidades[10];


while(aux.leerDeDisco(pos)==1){

    if(aux.getNacionalidad()==10){

    while(obj.leerDeDisco(pos1)==1){
    if(obj.getID){
       contador++;

    }

    }

    }


}
pos++;
}
*/

class InterpreteSolistas{

private:
        int id;
        char nombre[40];
        int cantCanciones;


public:

       void setId(int i){id=i;}
       void setNombre(const char *n){strcpy(nombre, n);}
       void setCantidadCanciones(int cant){cantCanciones=cant;}

       int getID(){return id;}
       const char *getNombre(){return nombre;}
       int getCantidadCanciones(){return cantCanciones;}


       bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("interpreteSolista.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (InterpreteSolistas),0);
    bool leyo=fread(this, sizeof (InterpreteSolistas), 1,p);
    fclose(p);
    return leyo;
}

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("interpreteSolista.dat","ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(this, sizeof (InterpreteSolistas), 1,p);
    fclose(p);
    return escribio;
}

   void Mostrar(){

    cout<<"ID de interprete: "<<getID()<<endl;
    cout<<"Nombre del interprete: "<<getNombre()<<endl;
    cout<<"Cantidad de canciones: "<<getCantidadCanciones()<<endl;


}


};


bool punto3Parcial(){



Interprete obj;
InterpreteSolistas aux;
int pos=0,cant;

while(obj.leerDeDisco(pos++)){



  if(obj.getTipoDeInterprete()==1){


    cant=contarCancionesInterprete(obj.getIDdelInterprete());



    aux.setId(obj.getIDdelInterprete());
    aux.setNombre(obj.getNombreInterprete());
    aux.setCantidadCanciones(cant);
    aux.grabarEnDisco();

}

}
aux.Mostrar();

system("pause");
return true;
}


























#endif // REPORTES_H_INCLUDED
