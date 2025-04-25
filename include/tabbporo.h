#ifndef __TDBBBro__
#define __TDBBBro__

#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include <queue>
using namespace std; 

class TNodoABB;

class TABBPoro {
    friend class TNodoABB;
    friend ostream & operator<<(ostream &,const TABBPoro &); 
    private:
        TNodoABB *nodo;
        void InordenAux(TVectorPoro & vector, int & i) const;
        void PreordenAux(TVectorPoro & vector, int &i) const; 
        void PostordenAux(TVectorPoro & vector, int &i) const; 
        TPoro Max() const;
    public:
       TABBPoro();
       TABBPoro(const TABBPoro &); 
       ~TABBPoro(); 
       TABBPoro & operator=(const TABBPoro &); 
       bool operator==(const TABBPoro &) const; 
       bool EsVacio() const; 
       bool Insertar(const TPoro &); 
       bool Borrar(const TPoro &); 
       bool Buscar(const TPoro &) const; 
       TPoro Raiz() const;  
       int Altura() const; 
       int Nodos() const;
       int NodosHoja() const; 
       TVectorPoro Inorden() const;
       TVectorPoro Preorden() const;
       TVectorPoro Postorden() const; 
       TVectorPoro Niveles(); 
       TABBPoro operator+( TABBPoro &); 
       TABBPoro operator-( TABBPoro &);
    
};

class TNodoABB {
    friend class TABBPoro;
    private:
        TPoro item;
        TABBPoro iz, de;

    public:
        TNodoABB(): item(), iz(),de() {}
        TNodoABB(const TNodoABB & nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {}
        ~TNodoABB(){} 
        TNodoABB & operator =(const TNodoABB & nodo){ item = nodo.item; iz = nodo.iz; de = nodo.de; return *this;}
};

#endif