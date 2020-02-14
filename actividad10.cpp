#include <iostream>
#include <string>
using namespace std;

struct Pedido{
    string apellido;
    int mesa;
    int sushicamaron;
    int sushicangrejo;
    int sushicalamar;
    int tiempo;
};


typedef Pedido T;
const T noValido = {{" "},-1,-1,-1,-1,-1};


struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};


void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct sushi{
    Cola colaPedidos;
    int ordenlistas;
};
sushi king;

void agregar();
void consultar();
void servir();
void vertodos();

int main(){
    initialize(&king.colaPedidos);
    king.ordenlistas = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}


void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}


void agregar(){
    
    Pedido unPedido;
    cout << "Digite su apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Cantidad de rollos de camaron: "; cin >> unPedido.sushicamaron; cin.ignore();
    cout << "Cantidad de rollos de cangrejo: "; cin >> unPedido.sushicangrejo; cin.ignore();
    cout << "Cantidad de rollos de calamar: "; cin >> unPedido.sushicalamar; cin.ignore();
    unPedido.tiempo = (unPedido.sushicamaron+unPedido.sushicangrejo+unPedido.sushicalamar) * 90;
    
    
    enqueue(&king.colaPedidos, unPedido);
    
    king.ordenlistas += (unPedido.sushicamaron+unPedido.sushicangrejo+unPedido.sushicalamar);
}

void consultar(){
    cout << "Pedidos en espera: " << size(&king.colaPedidos) << endl;
    cout << "Total de rollos hechos: " << king.ordenlistas << endl;
}

void servir(){
    Pedido pedidoDespachado = dequeue(&king.colaPedidos);
    cout << "Familia " << pedidoDespachado.apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.mesa << endl;
}

void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    
    while(!empty(&king.colaPedidos)){
        Pedido unPedido = dequeue(&king.colaPedidos);
        enqueue(&colaTemporal, unPedido);
        
        cout << "Info del pedido: " << unPedido.apellido << ", ";
        cout << "Rollos de camaron: " << unPedido.sushicamaron << ", ";
        cout << "Rollos de cangrejo: " << unPedido.sushicangrejo << ", ";
        cout << "Rollos de calamar: " << unPedido.sushicalamar << "\n\n";
    }
   
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&king.colaPedidos, elemento);
    }
}

