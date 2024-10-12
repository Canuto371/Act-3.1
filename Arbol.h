#ifndef ARBOL_H
#define ARBOL_H

using namespace std;

class Nodo{
private:
    Nodo *right, *left;
    int dato;

public:
    Nodo();
    Nodo(int d);
    int getDato();
    Nodo* getLeft();
    Nodo* getRight();
  	void setLeft(Nodo *_left);
  	void setRight(Nodo *_right);
    void setDato(int _dato);
    ~Nodo();
};

class Arbol {
private:

public:
    Nodo *raiz;
    Arbol();
    Nodo* insertarNodo(Nodo *r, int d);
    void preOrden(Nodo* r);
    void inOrden(Nodo* r);
    void postOrden(Nodo* r);
    void imprimirNivel(Nodo *r, int nivel);
    void nivelporNivel(Nodo *r);
    void visit(int tipoOrden);
    int height(Nodo *r);
    void ancestors(Nodo *r, int value);
    int whatlevelamIrecursivo(Nodo* nodo, int dato);
    int whatlevelamI(int value);
    ~Arbol();
};

#endif