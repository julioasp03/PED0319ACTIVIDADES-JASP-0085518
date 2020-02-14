#include <iostream>

void buscar(int arreglo[8],int low,int high,int mid,int dato);

int main(void){
    int arreglo[8]={1, 3, 4, 5, 17, 18, 31, 33};
    int dato,low,high,mid;
    cout<<"Que numero desea encontrar: "; cin>>dato; cin.ignore();
    low=0;
    high=8;
    mid=(low+high)/2;
    buscar(arreglo,low,high,mid,dato);
    return 0;
}

void buscar(int arreglo[8],int low,int high,int mid,int dato){
    if (arreglo[mid]==dato)
    {
        cout<<"El numero a sido encontrado "<<dato;
    }
    else if (arreglo[mid]>dato)
    {
        buscar(arreglo,low,high,mid-1,dato);
    }
    else if (arreglo[mid]<dato)
    {
        buscar(arreglo,low,high,mid+1,dato);
    }
    
}