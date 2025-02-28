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
        TPoro(int, int, double, char *);
        TPoro(TPoro &); 
        ~TPoro(); 
        TPoro & operator=(const TPoro &); 
        
        bool operator==(const TPoro &); 
        bool operator!=(const TPoro &); 
        void Posicion(int, int); 
        void Volumen(double);
        void Color(char *); 
        int PosicionX();
        int PosicionY();
        double Volumen();
        char * Color();
        bool EsVacio() const;

    private: 
        int x;
        int y; 
        double volumen; 
        char* color;
};

#endif