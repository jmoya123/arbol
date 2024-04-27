#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo {
    int value;

    nodo *izq;
    nodo *der;
};

nodo *raiz, *aux, *aux2;

// Function to insert a node in the BST
int posicionar() {
    if (aux->value < aux2->value) {
        if (aux2->izq == NULL) {
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if (aux2->der == NULL) {
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
    return 0;
}

// Function to register (insert) a new node
int registrar() {
    aux = (nodo*)malloc(sizeof(struct nodo));
    cout << "Cual es el valor: " << endl;
    cin >> aux->value;
    aux->izq = NULL;
    aux->der = NULL;

    if (!raiz) {
        raiz = aux;
    } else {
        aux2 = raiz;
        posicionar();
    }
    return 0;
}

/* Función para mostrar los elementos del BST en orden transversal
void mostrar(nodo *temp) {
    if (temp != NULL) {
        mostrar(temp->izq); // Recorrer recursivamente el subárbol izquierdo
        cout << temp->value << " "; // Imprimir el valor del nodo actual
        mostrar(temp->der); // Recorrer recursivamente el subárbol derecho
    }
}
*/
/*void mostrar(nodo *temp) {
    if (temp != NULL) {
        // Visita previa: Imprime primero el valor del nodo actual
        cout << temp->value << " ";
        mostrar(temp->izq); // Recorrer recursivamente el subárbol izquierdo
        mostrar(temp->der); // Recorre recursivamente el subárbol derecho/
    }
}
*/
void mostrar(nodo *temp) {
    if (temp != NULL) {
        mostrar(temp->izq); // Recorrer recursivamente el subárbol izquierdo.
        mostrar(temp->der); // Recorrer recursivamente el subárbol derecho.
        // Visita post-orden: Imprime el valor del nodo actual después de visitar los hijos.
        cout << temp->value << " ";
    }
}
int main() {
    int opc = 0;
    do {
        cout << "1. Registrar" << endl;
        cout << "2. Mostrar" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                if (raiz != NULL) {
                    cout << "Elementos del arbol: ";
                    mostrar(raiz);
                    cout << endl;
                } else {
                    cout << "El arbol esta vacio." << endl;
                }
                break;
        }
    } while (opc != 5);
    return 0;
}