#ifndef __TVectorPoro__
#define __TVectorPoro__

#include <iostream>
#include "tporo.h"

using namespace std;

class TVectorPoro {
    friend ostream & operator<<(ostream &,const TVectorPoro &); 

    public: 
        TVectorPoro();
        TVectorPoro(int);
        TVectorPoro(TVectorPoro &); 
        ~TVectorPoro(); 
        TVectorPoro & operator=(const TVectorPoro &); 
        
        bool operator==(const TVectorPoro &); 
        bool operator!=(const TVectorPoro &); 

        TPoro & operator[] (int x); 
        TPoro operator[] (int x) const;
        int Longitud();
        int Cantidad();
        bool Redimensionar(int x); 

    private: 
        int dimension; //Dimensión del vector
        TPoro *datos; //Datos del vector
        TPoro error; //Para cuando haya error en el operator[]
};

#endif