//
// Dulce Nahomi Bucio Rivas A01425284
// 08/10/2023
// Clase List
//

#ifndef LISTASTT_LIST_H
#define LISTASTT_LIST_H
#include <iostream>
#include <sstream>
using namespace std;
#include "Node.h"

// Clase lista que contiene los metodos para agregar, eliminar, buscar, reemplazar, etc. manipulando los nodos
// de la clase nodo para crear una lista ligada.

// Declaración de la lista
template <class T>
class List{
public:
    List(){first=NULL;}
    virtual void add(T *value);
    virtual Node<T> *getFirst() const;
    virtual Node<T> *getLast();
    virtual void remove(T *value);
    virtual bool elementExist(T *value);
    virtual bool removeAt(int index);
    virtual void replace(int index, T *value);
    virtual bool isEmpty();
    string toString() const;
    virtual int getSize();
private:
    Node<T> *first;
};

// Metodo para agregar un nodo a la lista que recibe un valor de tipo T, esto para poder usarlo con cualquier tipo de dato
template <class T>
void List<T>::add(T *value){
    Node<T> *node = new Node<T>(value);
    if (first == NULL)
    {
        first = node;
    }
    else
    {
        Node<T> *ultimateTeam=getLast();
        ultimateTeam -> setSig(node);
    }
}

// Metodo que devuelve el primer nodo de la lista
template <class T>
Node<T> *List<T>::getFirst() const{
    return first;
}

// Método que devuelve un booleano para saber si la lista contiene elementos o no
template <class T>
bool List<T>::isEmpty(){
    return first==NULL;
}

// Método que obtiene el último nodo de la lista, verificando que no esté vacía y posteriormente recorre la lista
// hasta encontrar el nodo cuyo siguiente sea NULL
template <class T>
Node<T> *List<T>::getLast() {
    if (isEmpty()) return NULL;

    Node<T> *p = first;
    while (p-> getSig()!=NULL){
        p = p -> getSig();
    }
    return p;
}

// Método que remueve un nodo de la lista según su valor, recibe un valor de tipo T y recorre la lista hasta
// encontrar el nodo al que corresponden los datos, posteriormente elimina el nodo
template <class T>
void List<T>::remove(T *value){
    Node<T> *node = getFirst();
    Node<T> *previous = NULL;
    while (node != NULL) {
        if (node->getInfo() == value){
            if (previous == NULL){
                first = node->getSig();
            } else {
                previous->setSig(node->getSig());
            }
            delete node;
            return;
        }
        previous = node;
        node = node->getSig();
    }
}
// Método que devuelve un booleano para saber si un elemento existe en la lista, recibe un valor de tipo T y
// recorre la lista
template <class T>
bool List<T>::elementExist(T *value){
    Node<T> *node = getFirst();
    while (node != NULL) {
        if (node->getInfo() == value){
            return true;
        }
        node = node->getSig();
    }
    return false;
}

// Mtodo para eliminar el objeto que se encuentra en la posición indicada, devuelve true si existe esa posición y
// puede eliminar el objeto y falso en caso contrario.
template <class T>
bool List<T>::removeAt(int index){
    Node<T> *node = getFirst();
    Node<T> *previous = NULL;
    int contador = 0;
    while (node != NULL) {
        if (contador == index) {
            if (previous == NULL) {
                first = node->getSig();
            } else {
                previous->setSig(node->getSig());
            }
            delete node; // <-- Delete the current node, not the previous one
            return true;
        }

        contador++;
        previous = node;
        node = node->getSig();
    }
    return false;
}

// Método que reemplaza el valor de un nodo en la lista según un índice dado y un valor de tipo T, recorre la lista
// hasta llegar al índice y posteriormente lo reemplaza por el valor tipo T
template <class T>
void List<T>::replace(int index, T *value){
    Node<T> *node = getFirst();
    int contador = 0;
    while (node != NULL) {
        if (contador == index){
            node->setInfo(value);
            return;
        }
        contador ++;
        node = node->getSig();
    }
}

// Método que devuelve un valor entero del tamaño de la lista
template <class T>
int List<T>::getSize(){
    Node<T> *node = getFirst();
    int contador = 0;
    while (node != NULL) {
        contador ++;
        node = node->getSig();
    }
    return contador;
}

// Sobrecarga del operador << para poder imprimir la lista
template <class T>
string List<T>::toString() const {
    Node<T> *p = getFirst();
    string outputStr="";
    while (p!=NULL)
    {
        stringstream ss;
        ss<<*(p->getInfo());
        outputStr+=ss.str()+" ";
        p=p->getSig();
    }
    return outputStr;
}
// Sobrecarga del operador << para poder imprimir la lista
template <class T>
ostream& operator<< ( ostream& outs, const List<T>* obj ) {
    return outs << obj->toString();
}

#endif //LISTASTT_LIST_H