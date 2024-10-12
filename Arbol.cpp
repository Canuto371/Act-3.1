#include "Arbol.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Definición del constructor por defecto de la clase Nodo
Nodo::Nodo(){
    right = left = nullptr;
}

// Definición del constructor que recibe un dato
Nodo::Nodo(int d){
    dato = d;
    right = left = nullptr;
}

// Obtener datos
int Nodo::getDato(){
    return dato;
}
        
Nodo* Nodo::getLeft(){
    return left;
}
        
Nodo* Nodo::getRight(){
    return right;
}
  
void Nodo::setLeft(Nodo *_left){
    left = _left;
}
  
void Nodo::setRight(Nodo *_right){
    right = _right;
}
  
void Nodo::setDato(int _dato){
    dato = _dato;
}

// Destructor de la clase Nodo
Nodo::~Nodo(){}

// Constructor de la clase Arbol
Arbol::Arbol(){
    raiz = nullptr;
}

// Complejidad del peor caso: O(n) 
// Donde n es la altura del árbol.
Nodo* Arbol::insertarNodo(Nodo *r, int d){
    if (r == nullptr) {
        return new Nodo(d);
    } 
    if (d < r->getDato()) {
        r->setLeft(insertarNodo(r->getLeft(),d));
    } else if (d > r->getDato()) {
        r->setRight(insertarNodo(r->getRight(),d));
    } else {
        cout << "ERROR. Solo puede existir una vez el valor." << endl;
    }
    return r;
}

// Destructor de la clase Arbol
Arbol::~Arbol(){}

// Método para realizar el recorrido en preorden
// Complejidad del peor caso: O(n) 
// Donde n es el número de nodos.
void Arbol::preOrden(Nodo *r){
    if (r != nullptr){
        cout << r->getDato() << ", ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}

// Método para realizar el recorrido en inorden	
// Complejidad del peor caso: O(n) 	
void Arbol::inOrden(Nodo *r){
    if (r != nullptr){
        inOrden(r->getLeft());
        cout << r->getDato() << ", ";
        inOrden(r->getRight());
    }
}

// Método para realizar el recorrido en postorden  
// Complejidad del peor caso: O(n) 
void Arbol::postOrden(Nodo *r){
    if (r != nullptr){
        postOrden(r->getLeft());
        postOrden(r->getRight());
        cout << r->getDato() << ", ";
    }
}

// Método para imprimir los nodos de un nivel específico
// Complejidad del peor caso: O(n)
void Arbol::imprimirNivel(Nodo *r, int nivel){
    if (r == nullptr){
        return;
    }
    if (nivel == 0) {
        cout << r->getDato() << " ";
    } else if (nivel > 0){
        imprimirNivel(r->getLeft(),nivel-1);
        imprimirNivel(r->getRight(),nivel-1);
    }
}

// Método para recorrer el árbol por niveles
// Complejidad del peor caso: O(n)
void Arbol::nivelporNivel(Nodo *r){
    int altura = height(r);
    if (r != nullptr) {
        for (int i = 0; i < altura; i++) {
            imprimirNivel(r, i);
            cout << endl;
        }
    }
}

// Método para realizar el recorrido basado en la opción seleccionada
// Complejidad del peor caso: O(n)
void Arbol::visit(int tipoOrden) {
    Nodo *raiz = this->raiz;
    switch(tipoOrden) {
        case 1:
            cout << "Recorrido PreOrder: \n";
            preOrden(raiz);
            cout << endl;
            break;
        case 2:
            cout << "Recorrido InOrder: \n";
            inOrden(raiz);
            cout << endl;
            break;
        case 3:
            cout << "Recorrido PostOrder: \n";
            postOrden(raiz);
            cout << endl;
            break;
        case 4:
            cout << "Recorrido Nivel por Nivel: \n";
            nivelporNivel(raiz);
            cout << endl;
            break;
        default:
            cout << "Elemento no válido. Ingrese un número entre 1 y 4.\n";
            break;
    }
}

// Método para calcular la altura del árbol
// Complejidad del peor caso: O(n)
int Arbol::height(Nodo* r) {
    if (r == nullptr) return 0;
    int leftHeight = height(r->getLeft());
    int rightHeight = height(r->getRight());
    return 1 + max(leftHeight, rightHeight);
}

// Método para mostrar los ancestros de un nodo
// Complejidad del peor caso: O(n)
void Arbol::ancestors(Nodo *r, int value) {
    if (r == nullptr) return;

    if (r->getDato() == value) {
        return;
    }

    if (value < r->getDato()) {
        cout << r->getDato() << " ";
        ancestors(r->getLeft(), value);
    } else {
        cout << r->getDato() << " ";
        ancestors(r->getRight(), value);
    }
}

// Método recursivo para encontrar el nivel de un nodo
// Complejidad del peor caso: O(n)
int Arbol::whatlevelamIrecursivo(Nodo* nodo, int dato){
    if (nodo == nullptr){
        return -1;
    }
    if (nodo->getDato() == dato){
        return 0;
    } 

    int nivelIzquierdo = whatlevelamIrecursivo(nodo->getLeft(), dato);
    if (nivelIzquierdo != -1) {
        return nivelIzquierdo + 1;
    }

    int nivelDerecho = whatlevelamIrecursivo(nodo->getRight(), dato);
    if (nivelDerecho != -1) {
        return nivelDerecho + 1;
    }

    return -1;
}

// Método para determinar el nivel de un nodo
// Complejidad del peor caso: O(n)
int Arbol::whatlevelamI(int dato){
    return whatlevelamIrecursivo(raiz, dato);
}
