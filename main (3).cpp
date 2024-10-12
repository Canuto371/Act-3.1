#include "Arbol.h"
#include <iostream>
using namespace std;

int main() {
    Arbol arbolito;
    int lim;
    int data;
    int tipoOrden;
    int opcion;

    cout << "¿Cuántos datos deseas insertar?" << endl;
    cin >> lim;

    for (int i = 0; i < lim; i++) {
        cout << "Dato a insertar: " << endl;
        cin >> data;
        arbolito.insertarNodo(arbolito.raiz, data); 
    }

    do {
        cout << "Opciones del árbol:\n";
        cout << "1. Recorrido Preorder\n";
        cout << "2. Recorrido Inorder\n";
        cout << "3. Recorrido Postorder\n";
        cout << "4. Recorrido Nivel por Nivel\n";
        cout << "5. Mostrar ancestros de un nodo\n";
        cout << "6. Saber el nivel de un elemento\n";
        cout << "7. Terminar programa\n";
        cin >> opcion;

        switch (opcion) { 
            case 1:
                tipoOrden = 1; // Preorden
                arbolito.visit(tipoOrden);
                break;
            case 2:
                tipoOrden = 2; // Inorden
                arbolito.visit(tipoOrden);
                break;
            case 3:
                tipoOrden = 3; // Postorden
                arbolito.visit(tipoOrden);
                break;
            case 4:
                tipoOrden = 4; // Nivel por Nivel
                arbolito.visit(tipoOrden);
                break;
            case 5: 
            {
                int value;
                cout << "Ingresar el nodo: ";
                cin >> value;
                cout << "Ancestros de " << value << ": ";
                arbolito.ancestors(arbolito.raiz, value);
                cout << endl;
                break;
            }
            case 6:
            {
                int value;
                cout << "Ingresar el nodo: ";
                cin >> value;
                int nivel = arbolito.whatlevelamI(value);
                if (nivel == 0) {
                    cout << "El nodo " << value << " no se encuentra en el árbol." << endl;
                }
                break;
            }
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Favor de intentar de nuevo.\n";
                break;
        }
    } while (opcion != 7);

    return 0;
}