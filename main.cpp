#include <iostream>
#include <string>
#include <fstream>
#include "Avl.cpp"

using namespace std;

int main(){
    int tam = 10;
    int* vet = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        vet[i] = 2*i;
    }
    Avl* arv = new Avl();
    for (int i = 0; i < tam; i++)
    {
        arv->insere(vet[i]);
    }
    arv->imprime();
    cout << endl << "Raiz: " << arv->getRaiz() << endl;
    arv->verifica();
    arv->imprime();
    cout << endl << "Raiz: " << arv->getRaiz() << endl;
}