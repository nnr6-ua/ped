#include "tporo.h"

//Constructor por defecto
TPoro::TPoro(){
    x = 0;
    y = 0; 
    volumen = 0.0;
    color = NULL;
}

//Constructor sobrecargado sin color
TPoro::TPoro(int xx, int yy, double vv){
    x = xx;
    y = yy; 
    volumen = vv;
    color = NULL;
}

//Constructor sobrecargado con color
// El color tiene que estar en minusculas
TPoro::TPoro(int xx, int yy, double vv,const char * cc){
    x = xx;
    y = yy; 
    volumen = vv;

    if(cc != nullptr){
        color = new char[strlen(cc) + 1]; //más uno porque hay que tener en cuenta /0
        strcpy(color,cc);
        for(int i = 0; i < strlen(cc); i++){
            color[i] = tolower(cc[i]);
        }
    } else {
        color = NULL; 
    }
}

//Contructor copia 
TPoro::TPoro(const TPoro & poro){
    x = poro.x; 
    y = poro.y; 
    volumen = poro.volumen;

    if(poro.color != nullptr){
        color = new char[strlen(poro.color) + 1];
        strcpy(color,poro.color);
        for(int i = 0; i < strlen(poro.color); i++){
            color[i] = tolower(color[i]);
        }
    } else {
        color = NULL; 
    }
}

//Destructor
TPoro::~TPoro(){
    x = 0;
    y = 0; 
    volumen = 0; 
    if(color != nullptr){ //liberar memoria
        delete color;
        color = NULL;
    }
}

//Sobrecarga del operador = 
//Copias en A (this) la información de B, pero no se machaca,
//si no que tu tienes que liberar los recursos primeros 
TPoro & TPoro::operator=(const  TPoro & poro){
    (*this).~TPoro();

    x = poro.x;
    y = poro.y;
    volumen = poro.volumen;

    if(poro.color != nullptr){
        color = new char[strlen(poro.color) + 1];
        strcpy(color,poro.color);
        for(int i = 0; i < strlen(poro.color); i++){
            color[i] = tolower(color[i]);
        }
    } else {
        color = NULL; 
    } 
    return *this;
}


//Dos poros son iguales si están en la misma coordenada,
//Si tienen el mismo volumen y el mismo color
bool TPoro::operator==(const TPoro & poro){
    if(x == poro.x && y == poro.y && volumen == poro.volumen){
        if (color == NULL && poro.color == NULL) {
            return true;
        } else if (color != NULL && poro.color != NULL) {
            return strcmp(color, poro.color) == 0;
        }
    }
    return false;
}

bool TPoro::operator!=(const TPoro & poro){
    return(!(*this==poro));
}

//Setter posición
void TPoro::Posicion(int xx, int yy){
    x = xx; 
    y = yy;
}

//Setter volumen
void TPoro::Volumen(double vv){
    volumen = vv; 
}

//Setter color
void TPoro::Color(const char * cc){
    if(cc != nullptr){
        color = new char[strlen(cc) + 1];
        strcpy(color,cc);
        for(int i = 0; i < strlen(cc); i++){
            color[i] = tolower(color[i]);
        }
    } else {
        color = NULL; 
    }
}

//Getter x
int TPoro::PosicionX(){
    return x; 
}

//Getter y
int TPoro::PosicionY(){
    return y; 
}

//Getter volumen 
double TPoro::Volumen() const{
    return volumen; 
}

//Getter volumen
char * TPoro::Color(){
    if(color == nullptr){
        return NULL;
    }
    else{
        char * copia = new char[strlen(color) + 1];
        strcpy(copia,color);
        return copia; 
    }
}

bool TPoro::EsVacio() const{
    return(x == 0
    && y == 0
    && volumen ==0
    && color == NULL);
}

ostream & operator<<(ostream &os,const TPoro &poro){
    if(!poro.EsVacio()){
        os.setf(ios::fixed); 
        os.precision( 2 ); 
        os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" "; 
        if(poro.color!=NULL) 
            os<<poro.color; 
        else os<<"-"; 
    } else 
        os << "()"; 
        
    return os; 
}  


