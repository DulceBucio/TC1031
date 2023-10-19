//
// Dulce Nahomi Bucio Rivas | A01425284
// 16/10/2023.
// Clase Node para la implementación de una lista doblemente ligada.
//


#ifndef DOUBLELINKEDLIST_Node_H
#define DOUBLELINKEDLIST_Node_H
#include <iostream>
using namespace std;


// Declaración de la clase Node con sus métodos
template <class T>
class Node {
public:
    Node(T *info, Node<T> *sig, Node<T> *ant);
    Node(T *info);
    virtual void setSig(Node<T> *sig);
    virtual Node<T> *getSig();
    virtual void setAnt(Node<T> *ant);
    virtual Node<T> *getAnt();
    virtual void setInfo(T *info);
    virtual T *getInfo();
private:
    Node<T> *Sig; // Apuntador al siguiente nodo
    Node<T> *Ant; // Apuntador al anterior nodo
    T *Info; // Apuntador al objeto que contiene el nodo
};

// Constructor con parámetros, recibe un apuntador a un objeto de tipo T, un apuntador al siguiente Node y un apuntador al anterior Node.
template <class T>
Node<T>::Node(T *info, Node<T> *sig, Node<T> *ant):Info(info), Sig(sig), Ant(ant) {}

// Contructor con parámetros, recibe un apuntador a un objeto de tipo T. El apuntador al siguiente nodo se inicializa.
template <class T>
Node<T>::Node(T *info) { Sig=NULL; Info=info; }

// Métodos set y get para el apuntador al siguiente nodo
template <class T>
void Node<T>::setSig(Node<T> *sig) {Sig = sig;};

template <class T>
Node<T> *Node<T>::getSig(){return Sig;};

// Métodos set y get para el apuntador al anterior nodo
template <class T>
void Node<T>::setAnt(Node<T> *ant) {Ant = ant;};

template <class T>
Node<T> *Node<T>::getAnt(){return Ant;};

// Métodos set y get para el apuntador al objeto que contiene el nodo
template <class T>
void Node<T>::setInfo(T *info) {Info=info; };

template <class T>
T *Node<T>::getInfo(){return Info;};

#endif //DOUBLELINKEDLIST_Node_H
