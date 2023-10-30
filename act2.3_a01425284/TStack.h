//
// Created by Dulce Nahomi Bucio Rivas A01425284
// 19/10/2023.
// Implementación de pila
//

#ifndef TSTACK_TSTACK_H
#define TSTACK_TSTACK_H


#include <iostream>
#include "List.h"
using namespace std;

// Declaración de la clase
template <class T>
class TStack {
private:
    List<T> *lista; // Lista que se va a usar para guardar los elementos de la pila
    int size;
public:
    TStack() { lista = new List<T>(); size = 0; }
    virtual bool empty();
    virtual T *pop();
    virtual void push(T *val);
    virtual T *stacktop();
};

// Método que devuelve un booleano para saber si la pila contiene elementos o no
template <class T>
bool TStack<T>::empty() {
    return lista->isEmpty(); // Usamos el método que hicimos para saber si la lista estaba vacía o no
}

// Método que devuelve un apuntador al elemento que está en el tope de la pila
template <class T>
T *TStack<T>::pop(){
    if (lista->isEmpty()) return NULL; // primero verifica que la lista esté limpia o no
    T *elem = lista->getLast()->getInfo(); // si no está vacía, entonces guarda el elemento que está en el tope de la pila
    // es necesario el uso de getInfo porque el método getLast devuelve un nodo, no un elemento
    lista->removeAt(--size); // elimina el elemento que está en el tope de la pila y disminuye el tamaño de la pila
    return elem; // devuelve el elemento que estaba en el tope de la pila
}

// Método para agregar un elemento a la pila
template <class T>
void TStack<T>::push(T *val) { // Método para agregar un elemento a la pila
    lista->add(val); // Agrega el elemento a la lista con el método de esta clase
    size++; // Aumenta el tamaño de la pila
}

// Método que devuelve un apuntador al elemento que está en el tope de la pila
template <class T>
T *TStack<T>::stacktop() {
    if (lista->isEmpty()) return NULL; // Primero verifica que la lista esté limpia o no
    return lista->getLast()->getInfo(); // En caso de no estarlo, devuelve el elemento que está en el tope de la pila
    // de nuevo, es necesario el uso de getInfo porque el método getLast devuelve un nodo, no un elemento
}

#endif //TSTACK_TSTACK_H
