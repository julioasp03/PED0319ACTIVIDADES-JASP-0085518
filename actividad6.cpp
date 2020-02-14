#include<iostream>
#include<stack>
using namespace std;

struct correo{
    string destinatario,remitente;
    int letras;
};

int main(void){
    stack<correo> cartas;
    char flag='s';
    correo datos;
    do{
        cout<<"\tCartas El salvador\nCartas recibidas hoy:\n";
        cout<<"Nombre del remitente: "; getline(cin,datos.remitente);
        cout<<"Nombre del destinatario: "; getline(cin,datos.destinatario);
        cout<<"Numero de letras en la carta: "; cin>>datos.letras; cin.ignore();
        cout<<endl;
        cout<<"Hay aun mas cartas (s/n): "; cin>>flag; cin.ignore();
        cout<<endl;
        cartas.push(datos);
    }while(flag=='s');
    
    return 0;
}