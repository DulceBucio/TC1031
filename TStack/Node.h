//
// Dulce Nahomi Bucio Rivas A01425284
// 08/10/2023
// Clase Nodo
//


#ifndef LISTASTT_NODE_H
#define LISTASTT_NODE_H
#include <iostream>
#include <sstream>
using namespace std;

// Esta es la clase que se encarga de crear los nodos de la lista. Hace uso de templates para poder sobreescribir
// el tipo de dato que se va a guardar en el nodo.

// Declaración de la clase
template <class T>
class Node {
public:
    Node(T *info, Node<T> *sig);
    Node(T *info);
    virtual void setSig(Node<T> *sig);
    virtual void setInfo(T *info);
    virtual Node<T> *getSig();
    virtual T *getInfo();
private:
    Node<T> *Sig;
    T *Info;
};

// Constructor con parámetros, recibe un apuntador a un objeto de tipo T y un apuntador a un nodo de tipo T que
// corresponde al siguiente nodo en la lista.
template <class T>
Node<T>::Node(T *info, Node<T> *sig):Info(info), Sig(sig) {}

// Contructor con parámetros, recibe un apuntador a un objeto de tipo T. El apuntador al siguiente nodo se inicializa.
template <class T>
Node<T>::Node(T *info) { Sig=NULL; Info=info; }

// Setter para el apuntador al siguiente nodo.
template <class T>
void Node<T>::setSig(Node<T> *sig){Sig=sig;};

// Setter para el apuntador al objeto de tipo T.
template <class T>
void Node<T>::setInfo(T *info) {Info=info; };

// Getter para el apuntador al siguiente nodo.
template <class T>
Node<T> *Node<T>::getSig(){return Sig;};

// Getter para el apuntador al objeto de tipo T.
template <class T>
T *Node<T>::getInfo(){return Info;};


#endif //LISTASTT_NODE_H
