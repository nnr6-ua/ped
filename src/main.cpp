#include "tporo.h"
#include "tvectorporo.h"
#include "tlistaporo.h"
#include <iostream> 
using namespace std;

int main(){
    cout << endl;
    cout << "=================================" << endl;
    cout << "    PRUEBAS DE LA CLASE TPORO    " << endl;
    cout << "=================================" << endl;

    TPoro p1, p2;
    TPoro p3(0, 0, 7);
    TPoro p4(1, 2, 3, "ROJO");
    TPoro p5(4, 2, 4.5, "Azul");
    TPoro p6(-2, -3, -6.7, "vErDe");
    TPoro p7(p1);
    TPoro p8(p4);
    TPoro p9 = p6;

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;
    cout << "p6: " << p6 << endl;
    cout << "p7: " << p7 << endl;
    cout << "p8: " << p8 << endl;
    cout << "p9: " << p9 << endl;
    cout << "p1 == p2: " << ((p1 == p2) ? "True" : "False") << endl;
    cout << "p3 == p4: " << ((p3 == p4) ? "True" : "False") << endl;
    cout << "p4 == p8: " << ((p4 == p8) ? "True" : "False") << endl;
    cout << "p6 == p9: " << ((p6 == p9) ? "True" : "False") << endl;
    cout << "p1 != p2: " << ((p1 != p2) ? "True" : "False") << endl;
    cout << "p3 != p4: " << ((p3 != p4) ? "True" : "False") << endl;
    cout << "p4 != p8: " << ((p4 != p8) ? "True" : "False") << endl;
    cout << "p6 != p9: " << ((p6 != p9) ? "True" : "False") << endl;
    p1.Posicion(1, 2);
    cout << "p1.Posicion(1, 2): " << p1 << endl;
    cout << "p1.EsVacio(): " << (p1.EsVacio() ? "True" : "False") << endl;
    cout << "p2.EsVacio(): " << (p2.EsVacio() ? "True" : "False") << endl;
    p3.Color("Rojo");
    cout << "p3.Color(\"Rojo\"): " << p3.Color() << endl;
    p4.Color("Azul");
    cout << "p4.Color(\"Azul\"): " << p4.Color() << endl;
    p4.~TPoro();
    cout << "p4.~TPoro(): " << p4 << endl;
    cout << "p4.EsVacio(): " << (p4.EsVacio() ? "True" : "False") << endl;
    p4.Posicion(1, 2);
    cout << "p4.Posicion(1, 2) [x]: " << p4.PosicionX() << endl;;

    cout << endl;
    cout << "=================================" << endl;
    cout << " PRUEBAS DE LA CLASE TVECTORPORO " << endl;
    cout << "=================================" << endl;

    TVectorPoro v1, v2(5), v3(3), v4(5);
    
    v1[1] = p1; v1[2] = p2; v1[3] = p3; v1[4] = p4; v1[5] = p5;
    v2[1] = p3; v2[2] = p4; v2[3] = p6; v2[4] = p7; v2[5] = p8;

    cout << "v1: " << v1 << endl;
    cout << "v1.Redimensionar(3): " << (v1.Redimensionar(3) ? "True" : "False") << endl;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v2.Redimensionar(5): " << (v2.Redimensionar(5) ? "True" : "False") << endl;
    cout << "v2.Redimensionar(0): " << (v2.Redimensionar(0) ? "True" : "False") << endl;
    cout << "v2.Redimensionar(7): " << (v2.Redimensionar(7) ? "True" : "False") << endl;
    cout << "v2: " << v2 << endl;
    cout << "v2.Cantidad(): " << v2.Cantidad() << endl;
    cout << "v2.Redimensionar(3): " << (v2.Redimensionar(3) ? "True" : "False") << endl;
    cout << "v2: " << v2 << endl;
    cout << "v2.Cantidad(): " << v2.Cantidad() << endl;
    cout << "v3: " << v3 << endl;
    cout << "v3.Cantidad(): " << v3.Cantidad() << endl;
    cout << "v1 == v3: " << (v1 == v3 ? "True" : "False") << endl;
    cout << "v4: " << v4 << endl;
    cout << "v2 == v4: " << (v2 == v4 ? "True" : "False") << endl;

    TVectorPoro v5(v2);
    TVectorPoro v6 = v3;

    cout << "v5: " << v5 << endl;
    cout << "v2 == v5: " << (v2 == v5 ? "True" : "False") << endl;
    cout << "v6: " << v6 << endl;
    cout << "v3 == v6: " << (v3 == v6 ? "True" : "False") << endl;
    cout << "v3 != v6: " << (v3 != v6 ? "True" : "False") << endl;
    cout << "v2[1]: " << v2[1] << endl;
    cout << "v2[2]: " << v2[2] << endl;
    cout << "v2[4]: " << v2[4] << endl;
    cout << "v2[8]: " << v2[8] << endl;
    cout << "v2[0]: " << v2[0] << endl;
    cout << "v3[1]: " << v3[1] << endl;
    cout << "v3[4]: " << v3[4] << endl;
    
    cout << endl;
    cout << "=================================" << endl;
    cout << " PRUEBAS DE LA CLASE TLISTAPORO " << endl;
    cout << "=================================" << endl;

    TListaPoro l1, l2, l3, l4;
    l1.Insertar(p1);
    l1.Insertar(p2);
    l1.Insertar(p3);
    l1.Insertar(p4);
    l1.Insertar(p5);
    l1.Insertar(p6);
    cout << "l1: " << l1 << endl;
    l2.Insertar(p3);
    l2.Insertar(p4);
    cout << "l2: " << l2 << endl;
    l3.Insertar(p1);
    l3.Insertar(p6);
    cout << "l3: " << l3 << endl;
    l4 = l1 - l2;
    cout << "l4 = l1 - l2: " << l4 << endl;
    l4 = l1 + l2;
    cout << "l4 = l2 + l3: " << l4 << endl;
    cout << "l1.Buscar(p3): " << (l1.Buscar(p3) ? "True" : "False") << endl;
    cout << "l2.Buscar(p3): " << (l2.Buscar(p3) ? "True" : "False") << endl;
    cout << "l3.Buscar(p3): " << (l3.Buscar(p3) ? "True" : "False") << endl;
    cout << "l4.Buscar(p3): " << (l4.Buscar(p3) ? "True" : "False") << endl;
    cout << "l1.Longitud(): " << l1.Longitud() << endl;
    cout << "l2.Longitud(): " << l2.Longitud() << endl;
    cout << "l3.Longitud(): " << l3.Longitud() << endl;
    cout << "l4.Longitud(): " << l4.Longitud() << endl;
    TListaPoro l5 = l4.ExtraerRango(2, 4);
    cout << "l4.ExtraerRango(2, 4): " << l4 << endl;
    cout << "   Extraido: " << l5 << endl;

    cout << endl;
    return 0;
}