#ifndef __TPoro__
#define __TPoro__

#include <iostream>
#include <cctype> //Para el towlower 
#include <cstring>

using namespace std;

class TPoro {
    friend ostream & operator<<(ostream &,const TPoro &); 

    public: 
        TPoro();
        TPoro(int, int, double);
        TPoro(int, int, double,const char *);
        TPoro(const TPoro &); 
        ~TPoro(); 
        TPoro & operator=(const TPoro &); 
        
        bool operator==(const TPoro &); 
        bool operator!=(const TPoro &); 
        void Posicion(int, int); 
        void Volumen(double);
        void Color(const char *); 
        int PosicionX();
        int PosicionY();
        double Volumen() const;
        char * Color();
        bool EsVacio() const;

    private: 
        int x; //Coordenada x de la posición
        int y; //Coordenada y de la posición
        double volumen; //Volumen
        char* color; //Color
};

#endif