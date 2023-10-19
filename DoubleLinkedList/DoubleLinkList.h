//
// Created by Dulce Nahomi Bucio Rivas | A01425284 on 16/10/2023.
//

#ifndef DOUBLELINKEDLIST_DOUBLELINKLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKLIST_H
#include <iostream>
#include <sstream>
using namespace std;
#include "Node.h"

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

template <class T>
DoubleLinkList<T>::DoubleLinkList( ) { first = NULL; }

template <class T>
DoubleLinkList<T>::~DoubleLinkList( ) { }

template <class T>
void DoubleLinkList<T>::add(T *value)
{ // CAMBIÓ
    Node<T> *node = new Node<T>(value);
    if (first == NULL)
    {
        first = node;
    }
    else
    {
        Node<T> *ultimate = getLast();
        ultimate->setSig(node);
        node->setAnt(ultimate);
    }
}

template <class T>
Node<T> *DoubleLinkList<T>::getFirst(){
    return first;
}

template <class T>
bool DoubleLinkList<T>::isEmpty(){
    return first==NULL;
}


template <class T>
Node<T> *DoubleLinkList<T>::getLast()
{
    if (isEmpty())
        return NULL;

    Node<T> *p = first;
    while (p->getSig() != NULL)
    {
        p = p->getSig();
    }
    return p;
}

template <class T>
void DoubleLinkList<T>::remove(T *value) {
    Node<T> *node = getFirst();
    Node<T> *ant = NULL;
    while(node != NULL){
        if (node->getInfo() == value){
            if (ant == NULL){
                first = node->getSig();
                first->setAnt(NULL);
            } else {
                ant ->setSig(node->getSig());
                node->getSig()->setAnt(ant);
            }
            delete node;
            return;
}
        ant = node;
        node = node->getSig();
    }
}

template <class T>
bool DoubleLinkList<T>::removeAt(int index){
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

template <class T>
void DoubleLinkList<T>::display() {
    Node<T> *p = getFirst();
    string outputStr = "";
    while (p != NULL){
        stringstream ss;
        ss << *(p->getInfo());
        outputStr += ss.str() + " ";
        p = p->getSig();
    }
    cout << outputStr << endl;
}

template <class T>
void DoubleLinkList<T>::inverseDisplay() {
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

template <class T>
void DoubleLinkList<T>::update(int index, T *value) {
    Node<T> *node = getFirst();
    int contador = 0;
    while (node != NULL){
        if (contador == index){
            node->setInfo(value);
            return;
        }
        contador++;
        node = node->getSig();
    }
}






#endif //DOUBLELINKEDLIST_DOUBLELINKLIST_H
