#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct agenda{
    string titulo,hora;
    int minutos;
};
//variables globales//
struct agenda x;
queue<agenda> cola;
//declaro prototipos//
void agregar();
void borrar();
void mostrar();
void limpiarcola();

int main(void){
    bool flag=true;
    do
    {
        int opcion=0;
        cout<<"---------------------";
        cout<<"\tAGENDA DEL DIA";
        cout<<"---------------------\n";
        cout<<"1) Agregar una actividad a la agenda\n";
        cout<<"2) Borrar una actividad de la agenda\n";
        cout<<"3) Mostrar todas las actividades del dia\n";
        cout<<"4) Borrar todas las actividades del dia\n";
        cout<<"5) Salir\n";
        cout<<"Su opcion: "; cin>>opcion; cin.ignore();
        cout<<endl;

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2: borrar(); break;
        case 3: mostrar(); break;
        case 4: limpiarcola(); break;
        case 5: flag=false;
        }

    } while (flag);
    
    return 0;
}

void agregar(){
    cout<<"Titulo de la actividad: "; getline(cin, x.titulo);
    cout<<"Hora en que iniciara la actividad: "; getline(cin,x.hora);
    cout<<"Tiempo que tardara la actividad(min): "; cin>>x.minutos; cin.ignore();
    cola.push(x);
    cout<<endl;
    return;
}

void borrar(){
    if (cola.empty())
    {
        cout<<"La agenda esta vacia\n";
    }
     cola.pop();
    cout<<endl;
}

void mostrar(){
    while (!cola.empty())
    {
        struct agenda show;
        show=cola.front();
        cout<<"Titulo de la actividad: "<<show.titulo<<endl;
        cout<<"Hora a la que se realizara: "<<show.hora<<endl;
        cout<<"Tiempo que tardara la actividad: "<<show.minutos<<" min\n";
        cola.pop();
        cout<<endl;
    }
    cout<<"La agenda esta vacia\n";
}

void limpiarcola(){
    while (!cola.empty())
    {
        cola.pop();
    }
    cout<<"La agenda esta vacia\n";
}
