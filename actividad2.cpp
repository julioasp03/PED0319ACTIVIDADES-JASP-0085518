#include <iostream>
#include <stdlib.h>
using namespace std;

int **puntero_matriz1,**puntero_matriz2,filas,column;
void datos();
void suma(int**matriz1,int**matriz2,int filas,int colum);
void mostrar(int**matriz1,int filas,int column);

int main(void){
    datos();
    suma(puntero_matriz1,puntero_matriz2,filas,column);
    mostrar(puntero_matriz1,filas,column);

    return 0;
}

void datos(){
    cout<<"digite el numero de filas: "; cin>>filas;
    cout<<"Digite el numero de columnas; "; cin>> column;
    puntero_matriz1=new int*[filas];
    for (int i = 0; i < filas; i++)
    {
        puntero_matriz1[i]=new int[column];
    }
    cout<<"\nDigite los elementos de la primera matriz:\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout<<"Digite un numero para:["<<i<<"]"<<"["<<j<<"]";
            cin>>*(*(puntero_matriz1+i)+j);
        }
        
    }

    puntero_matriz2=new int*[filas];
    for (int i = 0; i < filas; i++)
    {
        puntero_matriz2[i]=new int[column];
    }
    cout<<"\nDigite los elementos de la segunda matriz:\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout<<"Digite un numero para:["<<i<<"]"<<"["<<j<<"]";
            cin>>*(*(puntero_matriz2+i)+j);
        }
        
    }
    
}

void suma(int**matriz1,int**matriz2,int filas,int colum){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            *(*(matriz1+i)+j)+=*(*(matriz2+i)+j);
        }
        
    }
    
}

void mostrar(int**matriz1,int filas,int column){
    cout<<"La suma de las matrices es: \n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < column; i++)
        {
            cout<<*(*(matriz1+i)+j)<<" ";
        }
        cout<<endl;
    }
    
}