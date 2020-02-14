#include <iostream>
#include <string>
using namespace std;

struct continente{
    string nombre;
    string capital;
    int habitantes;
};
typedef struct continente arreglo[5];

int main(void){
   
   for(int i=0; i<5;i++){
        cout<< "digite nombre del pais";
        getline(cin,arreglo[i].nombre);
        cout<<"digite capital del pais";
        getline(cin,*(arreglo + i).capital);
        cout<<"digite la cantidad de habitantes";
        cin>>*(arreglo + i).habitantes;
   }
    p(5);

    return 0;
}

void p(int lim){
    int acum=0;
    string capi;
    for (int i = 0; i < lim; i++)
    {
        acum=acum+*(arreglo + i).habitantes;
    }    
    cout<<"la cantidad de poblacion total es: "<<acum;
    for (int i = 0; i < lim; i++)
    {
        if( *(arreglo + i).habitantes >*(arreglo + (i+1)).habitantes){
            capi= getline(cin,*(arreglo + i).capital);}
        else{
            capi= getline(cin,*(arreglo + i).capital);
        }
    }
    cout<<"la capital con mayor poblacion es:  "<<capi;
    
}