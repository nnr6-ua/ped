#include "tabbporo.h"

//inorden(iz)
//escribe
//inorden(de)
void TABBPoro::InordenAux(TVectorPoro & vector, int & i) const{
    if (nodo != NULL) {
        (*nodo).iz.InordenAux(vector, i);
        vector[i++] = (*nodo).item;
        (*nodo).de.InordenAux(vector, i);
    }
}

//escribe
//preorden(iz)
//preorden(de)
void TABBPoro::PreordenAux(TVectorPoro & vector, int &i) const{
    if (nodo != NULL) {
        vector[i++] = (*nodo).item;
        (*nodo).iz.PreordenAux(vector, i);
        (*nodo).de.PreordenAux(vector, i);
    }
}

//postorden(iz)
//postorden(de)
//escribe
void TABBPoro::PostordenAux(TVectorPoro & vector, int &i) const{
    if (nodo != NULL) {
        (*nodo).iz.PostordenAux(vector, i);
        (*nodo).de.PostordenAux(vector, i);
        vector[i++] = (*nodo).item;
    }
}

TABBPoro::TABBPoro(){
    nodo = NULL;
}

TABBPoro::TABBPoro(const TABBPoro &arbol) {
    if (arbol.nodo != nullptr)
        nodo = new TNodoABB(*arbol.nodo);
    else
        nodo = nullptr;
}


TABBPoro::~TABBPoro(){
    if(nodo != nullptr){
        delete nodo;
        nodo = NULL;
    }
}

TABBPoro & TABBPoro::operator=(const TABBPoro &arbol){
    if (this != &arbol) {
        (*this).~TABBPoro();
        if (arbol.nodo != nullptr)
            nodo = new TNodoABB(*arbol.nodo);
        else
            nodo = nullptr;
    }
    return *this;
}

//Dos árboles son iguales si poseen los mismos elementos 
//independientemente de la estructura itnerna del árbol
bool TABBPoro::operator==(const TABBPoro &arbol) const{
    return Inorden() == arbol.Inorden();
}

bool TABBPoro::EsVacio()const {
    return nodo == nullptr;
}

bool TABBPoro::Insertar(const TPoro & poro){
    bool insertado = false;

    if((*this).Buscar(poro)) return insertado;

    if((*this).EsVacio()){
        TNodoABB nuevo = TNodoABB();
        nuevo.item = poro;
        nuevo.iz = TABBPoro();
        nuevo.de = TABBPoro();
        nodo = &nuevo;
        insertado = true;
    }

    else if(poro.Volumen() < (*nodo).item.Volumen()){
        insertado = (*nodo).iz.Insertar(poro); //enraizar( insertar( i, y ), x, d )
    }

    else if(poro.Volumen() > (*nodo).item.Volumen()){
        insertado = (*nodo).de.Insertar(poro); //enraizar( i, x, insertar( d, y ) ) 
    }
    
    //PREGUNTAR QUE PASA SI EL VOLUMEN ES IGUAL 

    return insertado;
}

TPoro TABBPoro::Max() const {
    if (EsVacio()) return TPoro(); //error_item()

    if ((*nodo).iz.EsVacio())
        return (*nodo).item;
    else
        return (*nodo).de.Max();
}


bool TABBPoro::Borrar(const TPoro &poro){
    bool borrado = false; 

    if(!(*this).Buscar(poro)){
        return borrado;
    }

    if(poro.Volumen() < (*nodo).item.Volumen()){
        borrado = (*nodo).iz.Borrar(poro);
    }
    else if(poro.Volumen() > (*nodo).item.Volumen()){
        borrado = (*nodo).de.Borrar(poro);
    }
    if(poro.Volumen() == (*nodo).item.Volumen()){
        if ((*nodo).iz.EsVacio() && (*nodo).de.EsVacio()) {
            delete nodo;
            nodo = nullptr;
            borrado = true;
        }
        else if((*nodo).iz.EsVacio()){
            (*nodo).item = (*nodo).de.nodo->item;
            borrado = true;
        }
        else if((*nodo).de.EsVacio()){
            (*nodo).item = (*nodo).iz.nodo->item;
            borrado = true;
        }    
        else{
            TPoro maximo = (*nodo).iz.Max();
            (*nodo).item = maximo;
            (*nodo).iz.Borrar(maximo);
        }
    }
    return borrado;
}

bool TABBPoro::Buscar(const TPoro & poro) const{
    bool encontrado = false; 

    if((*this).EsVacio()){
        return false;
    }

    if(poro.Volumen() < (*nodo).item.Volumen()){
        encontrado = (*nodo).iz.Buscar(poro);
    }

    else if(poro.Volumen() > (*nodo).item.Volumen()){
        encontrado = (*nodo).de.Buscar(poro);
    }

    else if(poro.Volumen() == (*nodo).item.Volumen()){
        encontrado = true;
    }

    return encontrado; 
}

TPoro TABBPoro::Raiz() const{
    return (*nodo).item;
}

int TABBPoro::Altura() const{
    if((*this).EsVacio()){
        return 0;
    }

    return 1+max((*nodo).iz.Altura(),(*nodo).de.Altura());
}

int TABBPoro::Nodos() const{
    if((*this).EsVacio()){
        return 0;
    }

    return 1+(*nodo).iz.Nodos() + (*nodo).de.Nodos();
}

/* nodosHoja(crea_arbin()) = 0
nodosHoja(enraizar(i,x,d)) =
    si esvacio(i) & esvacio(d) entonces 1
    sino nodosHoja(i) + nodosHoja(d)
*/
int TABBPoro::NodosHoja() const{
    if((*this).EsVacio()){
        return 0;
    }

    if((*nodo).iz.EsVacio() && (*nodo).de.EsVacio()){
        return 1;
    }

    return (*nodo).iz.NodosHoja() + (*nodo).de.NodosHoja();
}

//IRD
TVectorPoro TABBPoro::Inorden() const{
    int i = 1;
    TVectorPoro vector(Nodos());
    InordenAux(vector, i);
    return vector;
}

//RID
TVectorPoro TABBPoro::Preorden() const{
    int i = 1;
    TVectorPoro vector(Nodos());
    InordenAux(vector, i);
    return vector;
}

//IDR
TVectorPoro TABBPoro::Postorden() const{
    int i = 1;
    TVectorPoro vector(Nodos());
    InordenAux(vector, i);
    return vector;
}

/*cola.push(valor);	Inserta un valor al FINAL de la cola
cola.front();	DEVUELVE el primer elemento (sin eliminarlo)
cola.pop();	ELIMINA el primer elemento de la cola
cola.empty();
cola.size();
*/
TVectorPoro TABBPoro::Niveles(){
    TVectorPoro vector(Nodos());
    int i = 1;

    if (nodo == nullptr){
        return TVectorPoro();
    }

    queue<TABBPoro*> cola;
    cola.push(this);

    while (!cola.empty()) {
        TABBPoro* actual = cola.front();
        cola.pop();

        if ((*actual).nodo != nullptr) {
            vector[i] = (*actual).nodo->item;
            i++;
            
            if ((*actual).nodo->iz.nodo != nullptr)
                cola.push(&((*actual).nodo->iz));

            if ((*actual).nodo->de.nodo != nullptr)
                cola.push(&((*actual).nodo->de));
        }
    }

    return vector;
}

TABBPoro TABBPoro::operator+(TABBPoro & arbol){
    TVectorPoro vector(Nodos()) = (*this).Inorden();
    TVectorPoro vector2(arbol.Nodos()) = arbol.Inorden();
    return vector + vector2;
}

TABBPoro TABBPoro::operator-(TABBPoro &){

}

ostream & operator<<(ostream &os,const TABBPoro &arbol){

}