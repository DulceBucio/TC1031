//
// Created by Dulce Nahomi Bucio Rivas | A01425284 on 16/10/2023.
//

#ifndef DOUBLELINKEDLIST_Node_H
#define DOUBLELINKEDLIST_Node_H
#include <iostream>
using namespace std;


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
    Node<T> *Sig;
    Node<T> *Ant;
    T *Info;
};

template <class T>
Node<T>::Node(T *info, Node<T> *sig, Node<T> *ant):Info(info), Sig(sig), Ant(ant) {}

// Contructor con parámetros, recibe un apuntador a un objeto de tipo T. El apuntador al siguiente Node se inicializa.
template <class T>
Node<T>::Node(T *info) { Sig=NULL; Info=info; }

template <class T>
void Node<T>::setSig(Node<T> *sig) {Sig = sig;};

template <class T>
Node<T> *Node<T>::getSig(){return Sig;};

template <class T>
void Node<T>::setAnt(Node<T> *ant) {Ant = ant;};

template <class T>
Node<T> *Node<T>::getAnt(){return Ant;};

template <class T>
void Node<T>::setInfo(T *info) {Info=info; };

template <class T>
T *Node<T>::getInfo(){return Info;};

#endif //DOUBLELINKEDLIST_Node_H
