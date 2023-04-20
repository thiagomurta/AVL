#ifndef NOAVL_H_INCLUDED
#define NOAVL_H_INCLUDED

class NoAvl{
    public:
        NoAvl()               {};
        ~NoAvl()              {};
        void setEsq(NoAvl *p) { esq = p; };
        void setInfo(int val) { info = val; };
        void setDir(NoAVL *p) { dir = p; };
        NoAvl* getEsq()       { return esq; };
        int getInfo()         { return info; };
        NoAvl* getDir()       { return dir; };

    private:
        NoAvl *esq;  // ponteiro para o filho a esquerda
        int info; // informação do No (int)
        NoAvl *dir;  // ponteiro para o filho a direita
};

#endif // NOAVL_H_INCLUDED