#include <iostream>
#include <string>
using namespace std;

struct info{
    string color;
    string material;
    string tipo;
};

struct nodo{
    info I;
    nodo *siguiente;
};

typedef struct nodo *pila;

void initialize(pila *s);
bool empty(pila *s);
void push(pila *s,info unplato);

int main(void){
    pila unapila;
    initialize(&unapila);
    char opcion='s';
    info unPlato;
    do{
        cout<<"Inserte un plato:\n";
        cout << "Color: ";   getline(cin, unPlato.color);
        cout << "Material: ";   getline(cin, unPlato.material);
        cout << "Tipo: ";       getline(cin, unPlato.tipo);
        push(&unapila,unPlato);

        cout << "\nDesea apilar otro plato? (s/n): ";
        cin >> opcion; cin.ignore();    
    }while(opcion=='s');

    
    return 0;
}

void initialize(pila *s){
    *s=NULL;
}
bool empty(pila *s){
    return *s==NULL;
}

void push(pila *s,info unplato){
    nodo *unnodo=new nodo;
    unnodo->I=unplato;
    unnodo->siguiente=*s;

    *s= unnodo;
}