#include <iostream>
#include <stdlib.h> 
#include <time.h>    

using namespace std;

int buscar (int* arreg, int num,int cont)
{
	if (num != cont)
	{
		buscar(arreg, num, cont+1);
	}
	else 
	{
		return cont;
	}
}

int main(int argc, char** argv) {
	
	
	int cont=0, tam, num;
	
	cout<<"De que numero quiere que sea el arreglo?\n";
	cin>>tam;
	cout<<endl;
	tam--;
	
	srand (time(NULL));
	
	
	int arreg[tam];
	
	for (int i=0; i<=tam; i++)
	{
		arreg[i] = rand() % 100 + 1; 
	}
	
	for (int i=0; i<=tam; i++)
	{
		cout<<arreg[i]<<endl; 
	}
	
	cout<<endl;
	cout<<"Que numero del arreglo desea buscar\n";
	cin>>num;
	
	while (num>tam)
	{
		cout<<"Error favor digite un numero menor al tamanio\n";
		cin>>num;
	}
	
	while (num<1)
	{
		cout<<"Error favor digite un numero mayor a 0\n";
		cin>>num;
	}
	
	while (num>tam)
	{
		cout<<"Error favor digite un numero menor al tamanio\n";
		cin>>num;
	}
	
	while (num<1)
	{
		cout<<"Error favor digite un numero mayor a 0\n";
		cin>>num;
	}
	
	cout<<endl;
	num--;
	
	cout<<"El numero en la posicion "<<num+1<< " es:\n"; 
	cout<<arreg[buscar(arreg, num, cont)];
	
	
	
	
	return 0;
}