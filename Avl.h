#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "NoAvl.h"

class Avl{
    public:
        Avl();
        ~Avl();
        int getRaiz();
        NoAvl* libera(NoAvl *p);
        void imprime();
        void rotSimEsq(NoAvl *p);
        void rotSimDir(NoAvl *p);
        void rotDupEsq(NoAvl *p);
        void rotDupDir(NoAvl *p);
        int altura(NoAvl *p);
        void insere(int val);
        void verifica();
    private:
        NoAvl *raiz;

        void auxImprime(NoAvl *p);
        void auxRotSimEsq(NoAvl *p);
        void auxRotSimDir(NoAvl *p);
        void auxRotDupEsq(NoAvl *p);
        void auxRotDupDir(NoAvl *p);
        int auxAltura(NoAvl *p);
        NoAvl* auxInsere(NoAvl *p, int val);
        void auxVerifica(NoAvl *p);
};
#endif // AVL_H_INCLUDED