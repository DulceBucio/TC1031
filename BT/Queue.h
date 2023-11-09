//
// Created by Dulce Nahomi Bucio Rivas | A01425284 on 09/11/2023.
//

#ifndef BT_QUEUE_H
#define BT_QUEUE_H
#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    List<T> *list;
public:
    Queue() { list = new List<T>(); };
    void enqueue(T *value) { list->add(value); };
    T *dequeue()
    {
        if (list->isEmpty())
        {
            return NULL;
        }
        T *value = list->getFirst()->getInfo();
        list->removeAt(0);
        return value;
    };
    bool isEmpty() { return list->isEmpty(); };
    ~Queue() { delete list; };
};

#endif //BT_QUEUE_H
