#include <iostream>
using namespace std;

float mediana(int p[],int size);

int main(void){
    int arreglo[6]{1,2,3,4,5,6};
    cout<<mediana(arreglo,6);

    return 0;
}

float mediana(int p[],int size){
    int a=size/2;
    float mediana=0;
    if (a%2==0)
    {
        mediana=(p[a-1]+p[a])/2;
    }
    else
    {
        mediana=a;
    }
    
    
    return mediana;
}