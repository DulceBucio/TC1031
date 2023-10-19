//
// Dulce Nahomi Bucio Rivas | A01425284
// 16/10/2023.
// Implementación de una lista doblemente ligada
//

#ifndef DOUBLELINKEDLIST_DOUBLELINKLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKLIST_H
#include <iostream>
#include <sstream>
using namespace std;
#include "Node.h"

// Declaración de la clase DoubleLinkList con sus métodos
template <class T>
class DoubleLinkList
{
public:
    DoubleLinkList();
    ~ DoubleLinkList();
    virtual void add(T *value);
    virtual void remove(T *value);
    virtual bool removeAt(int index);
    virtual bool isEmpty();
    virtual Node<T> *getFirst();
    virtual Node<T> *getLast();
    void display();
    void inverseDisplay();
    virtual void update(int index, T *value);
    string toString() const;
private:
    Node<T> *first;
};

// Constructor sin parámetros
template <class T>
DoubleLinkList<T>::DoubleLinkList( ) { first = NULL; }

// Destructor
template <class T>
DoubleLinkList<T>::~DoubleLinkList( ) { }

// Método para agregar un nodo al final de la lista
template <class T>
void DoubleLinkList<T>::add(T *value)
{
    Node<T> *node = new Node<T>(value); // Creación del nodo
    if (first == NULL)
    {
        first = node; // Verifica que la lista esté vacía, en caso de estarlo, agrega el nuevo nodo al inicio
    }
    else
    {
        // Si la lista no está vacía, agrega el nuevo nodo al final de la lista
        Node<T> *ultimate = getLast(); // Para esto, primero obtiene el último nodo de la lista
        ultimate->setSig(node); // Agrega el nuevo nodo al final de la lista asignandolo como siguiente al último nodo
        node->setAnt(ultimate); // Asigna el último nodo como anterior al nuevo nodo para mantener la lista doblemente ligada
    }
}

// Método para obtener el primer nodo de la lista
template <class T>
Node<T> *DoubleLinkList<T>::getFirst(){
    return first;
}

// Método para verificar si la lista está vacía
template <class T>
bool DoubleLinkList<T>::isEmpty(){
    return first==NULL;
}

// Método para obtener el último nodo de la lista
template <class T>
Node<T> *DoubleLinkList<T>::getLast()
{
    if (isEmpty())
        return NULL; // Si la lista está vacía, regresa NULL

    Node<T> *p = first;
    while (p->getSig() != NULL)
    {
        p = p->getSig(); // Si la lista no está vacía, recorre toda la lista hasta que llegue al último nodo
    }
    return p;
}

// Método para remover el valor de un nodo en la lista con el uso de plantillas
template <class T>
void DoubleLinkList<T>::remove(T *value) {
    Node<T> *node = getFirst(); // Obtiene el primer nodo de la lista
    Node<T> *ant = NULL; // Crea un nodo anterior que se inicializa en NULL
    while(node != NULL){ // Recorre toda la lista
        if (node->getInfo() == value){ // Verifica que el nodo actual sea igual al valor que se quiere eliminar
            if (ant == NULL){
                first = node->getSig(); // Si el nodo anterior es NULL, significa que el nodo a eliminar es el primero
                first->setAnt(NULL); // Por lo que el nuevo primer nodo será el siguiente del nodo a eliminar,
                // y el anterior del nuevo primer nodo será NULL
            } else {
                ant ->setSig(node->getSig()); // Asignamos el siguiente del nodo anterior al siguiente del nodo a eliminar
                node->getSig()->setAnt(ant); // y el anterior del siguiente del nodo a eliminar será el nodo anterior
            }
            delete node; // Eliminamos el nodo
            return;
}
        ant = node; // Si el nodo actual no es el que se quiere eliminar, el nodo anterior será el nodo actual
        node = node->getSig(); // y el nodo actual será el siguiente del nodo actual
    }
}

// Método para remover el valor de un nodo en la lista con el uso de plantillas por un índice
template <class T>
bool DoubleLinkList<T>::removeAt(int index){
    // Usa la misma lógica para eliminar un nodo por valor, pero en este caso, se recorre la lista hasta llegar al índice
    Node<T> *node = getFirst();
    Node<T> *ant = NULL;
    int contador = 0;
    while (node != NULL){
        if (contador == index){
            if (ant == NULL){
                first = node->getSig();
                first->setAnt(NULL);
            } else {
                ant->setSig(node->getSig());
                if (node->getSig()!= NULL){
                    node->getSig()->setAnt(ant);
                }
            }
            delete node;
            return true;
        }
        contador++;
        ant = node;
        node = node->getSig();
    }
    return false;
}

// Método para mostrar la lista
template <class T>
void DoubleLinkList<T>::display() {
    Node<T> *p = getFirst(); // Obtiene el primer nodo de la lista
    string outputStr = "";
    while (p != NULL){ // Recorre toda la lista
        stringstream ss;
        ss << *(p->getInfo()); // Convierte el valor del nodo a string
        outputStr += ss.str() + " "; // Concatena el valor del nodo a la cadena de salida
        p = p->getSig();
    }
    cout << outputStr << endl;
}

// Método para mostrar la lista en orden inverso
template <class T>
void DoubleLinkList<T>::inverseDisplay() {
    // Usa la misma lógica que el método display, pero en este caso, recorre la lista de atrás hacia adelante con
    // el uso del método getAnt
    Node<T> *p = getLast();
    string outputStr = "";
    while (p != NULL){
        stringstream ss;
        ss << *(p->getInfo());
        outputStr += ss.str() + " ";
        p = p->getAnt();
    }
    cout << outputStr << endl;
}

// Método para actualizar el valor de un nodo en la lista con el uso de plantillas por un índice
template <class T>
void DoubleLinkList<T>::update(int index, T *value) {
    Node<T> *node = getFirst(); // Obtiene el primer nodo de la lista
    int contador = 0; // Crea un contador que se inicializa en 0
    while (node != NULL){
        if (contador == index){
            node->setInfo(value); // Si el contador es igual al índice, asigna el nuevo valor al nodo
            return;
        }
        contador++;
        node = node->getSig();
    }
}

#endif //DOUBLELINKEDLIST_DOUBLELINKLIST_H
