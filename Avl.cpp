#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include "Avl.h"

using namespace std;

AVL::AVL(){
    raiz = NULL;
}

AVL::~AVL(){
    raiz = libera(raiz);
}

int AVL::getRaiz(){
    if(raiz != NULL)
        return raiz->getInfo();
    cout << "Arvore vazia" << endl;
    exit(1);
}

void AVL::imprime(){
    auxImprime(raiz);
}

void AVL::auxImprime(NoAvl *p){
    if(p != NULL){
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

NoAvl* AVL::libera(NoAvl *p){
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void AVL::rotSimEsq(NoAvl *p){
    auxRotSimEsq(p);
}

void AVL::rotSimDir(NoAvl *p){
    auxRotSimDir(p);
}

void AVL::rotDupEsq(NoAvl *p){
    auxRotDupEsq(p);
}

void AVL::rotDupDir(NoAvl *p){
    auxRotDupDir(p);
}

void AVL::auxRotSimEsq(NoAvl *p){
    NoAvl* q;
    q = p->getDir();
    p->setDir(q->getEsq());
    q->setEsq(p);
}

void AVL::auxRotSimDir(NoAvl *p){
    NoAvl* q;
    q = p->getEsq();
    p->setEsq(q->getDir());
    q->setDir(p);
}

void AVL::auxRotDupEsq(NoAvl *p){
    NoAvl *q;
    NoAvl *r;
    q = p->getDir();
    r = q->getEsq();
    p->setDir(r->getEsq());
    q->setEsq(r->getDir());
    r->setEsq(p);
    r->setDir(q);
}

void AVL::auxRotDupDir(NoAvl *p){
    NoAvl *q;
    NoAvl *r;
    q = p->getEsq();
    r = q->getDir();
    p->setEsq(r->getDir());
    q->setDir(r->getEsq());
    r->setDir(p);
    r->setEsq(q);
}

int AVL::altura(NoAvl *p){
    return auxAltura(p);
}

int AVL::auxAltura(NoAvl *p){
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

void AVL::insere(int val){
    raiz = auxInsere(raiz, val);
}

NoAvl* AVL::auxInsere(NoAvl *p, int val){
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
void AVL::verifica(){
    auxVerifica(raiz);
}

void AVL::auxVerifica(NoAvl *p){
    if(p != NULL){
        int h = altura(p);
        if(h == 1){
            rotSimEsq(p);
        }
        else if(h == -1){
            rotSimDir(p);
        }
        else if(h <= -2){
            rotDupDir(p);
        }
        else if(h >= 2){
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