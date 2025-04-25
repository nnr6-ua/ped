#include "tvectorporo.h"

TVectorPoro::TVectorPoro(){
    dimension = 0;
    datos = NULL;
    error = TPoro();
}

TVectorPoro::TVectorPoro(int d){
    if (d <= 0){
        dimension = 0;
        datos = NULL;
    } 
    else{
        dimension = d; 
        datos = new TPoro[d];
    }
}

TVectorPoro::TVectorPoro(TVectorPoro & vector){
    dimension = vector.dimension; 
    datos = new TPoro[vector.dimension]; 
    if(datos != nullptr){
        for(int i = 0; i < vector.dimension;i++){
            datos[i] = TPoro(vector.datos[i]);
        }
    }
    else{
        datos = NULL;
        dimension = 0; 
    }
}

TVectorPoro::~TVectorPoro(){
    dimension = 0; 
    if(datos != nullptr){
        delete[] datos; 
        datos = NULL;
    }
}

TVectorPoro & TVectorPoro::operator=(const TVectorPoro & vector){
    (*this).~TVectorPoro();

    dimension = vector.dimension; 

    if(vector.datos != nullptr){
        datos = new TPoro[dimension];
        for(int i = 0; i < dimension; i++){
            datos[i] = TPoro(vector.datos[i]);
        }
    } else {
        datos = NULL; 
    } 
    return *this;
}
    
bool TVectorPoro::operator==(const TVectorPoro &vector){
    bool iguales = false; 
    if(dimension == vector.dimension){
        iguales = true;
        for(int i = 0; i < dimension; i++){
            if(datos[i] != vector.datos[i])
                iguales = false;
        } 
    }
    return iguales;
}

bool TVectorPoro::operator!=(const TVectorPoro &vector){
    return(!(*this==vector));
}

TPoro & TVectorPoro::operator[] (int indice){
    if(indice > 0 && indice <= dimension){
        return datos[indice-1];
    } 
    return error; 
}

TPoro TVectorPoro::operator[] (int indice) const{
    if(indice > 0 && indice <= dimension){
        return datos[indice-1];
    } 
    return error; 
}

int TVectorPoro::Longitud(){
    return dimension;
}

int TVectorPoro::Cantidad(){
    int cant = 0;
    for(int i = 0; i < dimension; i++){
        if(!datos[i].EsVacio()){
            cant++;
        }
    }
    return cant;
}

bool TVectorPoro::Redimensionar(int entero){
    if(entero <= 0 || entero == dimension){
        return false;
    }
    if(entero > dimension){
        TPoro *aux = new TPoro[entero];
        for(int i = 0; i < entero; i++){
            if(i < dimension){
                aux[i] = TPoro(datos[i]);
            }
            else{
                aux[i] = TPoro();
            }
        }
        datos = aux;
        dimension = entero;
        return true;
    }
    TPoro *aux = new TPoro[entero];
    for(int i = 0; i < entero; i++){
        aux[i] = TPoro(datos[i]);
    }
    datos = aux;
    dimension = entero; 
    return true;
}

ostream & operator<<(ostream &os,const TVectorPoro &vector){
    if(vector.dimension == 0){
        os << "[]";
    }
    else{
        os << "[";
        for(int i = 0; i < vector.dimension; i++){
            if(i == vector.dimension -1){
                os << i+1 << " " << vector.datos[i] << "]";
            }
            else{
                os << i+1 << " " << vector.datos[i] << " ";
            }
        }
    }
    return os;
}