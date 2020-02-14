#include <iostream>
using namespace std;

int addNumbers(int limit, int aux);

int main(void){
    int num;
    cout<<"Digite el numero hasta donde llegara la suma: "; cin>>num; cin.ignore();
    cout << addNumbers(num, 1) << endl;
}

int addNumbers(int limit, int aux){
    if(aux == limit){
        return aux;
    }
    else{
        return aux + addNumbers(limit, aux + 1);
    }
}