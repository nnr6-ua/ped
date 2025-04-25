#ifndef __TVectorPoro__
#define __TVectorPoro__

#include <iostream>
#include "tporo.h"

using namespace std;

class TVectorPoro {
    friend ostream & operator<<(ostream &,const TVectorPoro &vector); 

    public: 
        TVectorPoro();
        TVectorPoro(int d);
        TVectorPoro(TVectorPoro & vector); 
        ~TVectorPoro(); 
        TVectorPoro & operator=(const TVectorPoro &vector); 
        
        bool operator==(const TVectorPoro &vector); 
        bool operator!=(const TVectorPoro &vector); 

        TPoro & operator[] (int indice); 
        TPoro operator[] (int indice) const;
        int Longitud();
        int Cantidad();
        bool Redimensionar(int entero); 

    private: 
        int dimension; //Dimensión del vector
        TPoro *datos; //Datos del vector
        TPoro error; //Para cuando haya error en el operator[]
};

#endif