#include "Arbol.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Nodo::Nodo(){
    right = left = nullptr;
}

Nodo::Nodo(int d){
    dato = d;
    right = left = nullptr;
}

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

Nodo::~Nodo(){}

Arbol::Arbol(){
    raiz = nullptr;
}

Nodo* Arbol::insertarNodo(Nodo *r, int d){
    if (r == nullptr) {
        r = new Nodo(d);
    } else if(d < r->getDato()) {
        r->setLeft(insertarNodo(r->getLeft(),d));
    } else if(d > r->getDato()) {
        r->setRight(insertarNodo(r->getRight(),d));
    } else {
        cout << "ERROR. Solo puede existir una vez el valor." << endl;
    }
    return r;
}

void Arbol::preOrden(Nodo *r){
    if (r != nullptr){
        cout << r->getDato() << ", ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}
  		
void Arbol::inOrden(Nodo *r){
    if (r != nullptr){
        inOrden(r->getLeft());
        cout << r->getDato() << ", ";
        inOrden(r->getRight());
    }
}
  		
void Arbol::postOrden(Nodo *r){
    if (r != nullptr){
        postOrden(r->getLeft());
        postOrden(r->getRight());
        cout << r->getDato() << ", ";
    }
}

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

void Arbol::nivelporNivel(Nodo *r){
    int altura = height(r);
    if (r != nullptr) {
        for (int i = 0; i < altura; i++) {
            imprimirNivel(r, i);
            cout << endl;
        }
    }
}

void Arbol::visit(int tipoOrden) {
    Nodo *raiz = this->raiz;
    switch(tipoOrden) {
        case 1:
            cout << "Recorrido PreOrden: \n";
            preOrden(raiz);
            break;
        case 2:
            cout << "Recorrido InOrden: \n";
            inOrden(raiz);
            break;
        case 3:
            cout << "Recorrido PostOrden: \n";
            postOrden(raiz);
            break;
        case 4:
            cout << "Recorrido Nivel por Nivel: \n";
            nivelporNivel(raiz);
            break;
        default:
            cout << "Elemento no válido. Ingrese un número entre 1 y 4.\n";
            break;
    }
}

int Arbol::height(Nodo* r) {
    if (r == nullptr) return 0;
    int leftHeight = height(r->getLeft());
    int rightHeight = height(r->getRight());
    return 1 + max(leftHeight, rightHeight);
}

void Arbol::ancestors(Nodo *r, int value) {
    if (r == nullptr) return;

    if (r->getDato() == value) {
        cout << value << " ";
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

int Arbol::whatlevelamIrecursivo(Nodo* nodo, int dato){
    if (nodo == nullptr){
        return 0;
    }
    if (nodo->getDato()==dato){
        return 1;
    } 

    int numeroIzquierdo = whatlevelamIrecursivo (nodo -> getLeft(), dato); 
    int numeroDerecho = whatlevelamIrecursivo (nodo -> getRight(), dato);

    if (numeroIzquierdo > 0) {
        return numeroIzquierdo + 1; 
    }
    if (numeroDerecho > 0){
        return numeroDerecho +1;  
    }
    return 0; 
}


int Arbol::whatlevelamI(int dato){
    int resultado = whatlevelamIrecursivo (nodo, dato); 
    cout << "Nivel de" << dato << ": " << resultado << endl;    
}


