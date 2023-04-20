#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include "Avl.h"

using namespace std;

Avl::Avl(){
    raiz = NULL;
}

Avl::~Avl(){
    raiz = libera(raiz);
}

int Avl::getRaiz(){
    if(raiz != NULL)
        return raiz->getInfo();
    cout << "Arvore vazia" << endl;
    exit(1);
}

void Avl::imprime(){
    auxImprime(raiz);
}

void Avl::auxImprime(NoAvl *p){
    if(p != NULL){
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

NoAvl* Avl::libera(NoAvl *p){
    if (p != NULL){
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void Avl::rotSimEsq(NoAvl *p){
    auxRotSimEsq(p);
}

void Avl::rotSimDir(NoAvl *p){
    auxRotSimDir(p);
}

void Avl::rotDupEsq(NoAvl *p){
    auxRotDupEsq(p);
}

void Avl::rotDupDir(NoAvl *p){
    auxRotDupDir(p);
}

void Avl::auxRotSimEsq(NoAvl *p){
    NoAvl* q;
    q = p->getDir();
    p->setDir(q->getEsq());
    q->setEsq(p);
}

void Avl::auxRotSimDir(NoAvl *p){
    NoAvl* q;
    q = p->getEsq();
    p->setEsq(q->getDir());
    q->setDir(p);
}

void Avl::auxRotDupEsq(NoAvl *p){
    NoAvl *q;
    NoAvl *r;
    q = p->getDir();
    r = q->getEsq();
    p->setDir(r->getEsq());
    q->setEsq(r->getDir());
    r->setEsq(p);
    r->setDir(q);
}

void Avl::auxRotDupDir(NoAvl *p){
    NoAvl *q;
    NoAvl *r;
    q = p->getEsq();
    r = q->getDir();
    p->setEsq(r->getDir());
    q->setDir(r->getEsq());
    r->setDir(p);
    r->setEsq(q);
}

int Avl::altura(NoAvl *p){
    return auxAltura(p);
}

int Avl::auxAltura(NoAvl *p){
    if(p != NULL){
        int e =  1 + auxAltura(p->getEsq());
        int d =  1 + auxAltura(p->getDir());
        int h = d-e;
        return h;
    }
    else{
        return -1;
    }
}

void Avl::insere(int val){
    raiz = auxInsere(raiz, val);
}

NoAvl* Avl::auxInsere(NoAvl *p, int val){
    if(p == NULL){
        p = new NoAvl();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

/// verifica e conserta a árvore sempre que o valor da altura não bate
void Avl::verifica(){
    auxVerifica(raiz);
}

void Avl::auxVerifica(NoAvl *p){
    if(p != NULL){
        int h = altura(p);
        if(h == 1){
            rotSimEsq(p);
        }
        else if(h == -1){
            rotSimDir(p);
        }
        else if(h < -2){
            rotDupDir(p);
        }
        else if(h > 2){
            rotDupEsq(p);
        }
        else{
            cout << "Só possui raiz!" << endl;
            exit(1);
        }
        auxVerifica(p->getEsq());
        auxVerifica(p->getDir());
    }
}