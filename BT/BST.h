//
// Created by PC BULLOCK on 06/11/2023.
//

#ifndef BT_BST_H
#define BT_BST_H
#include <iostream>
using namespace std;
#include "TreeNode.h"
#include "List.h"
#include "Queue.h"

template <class T>
class BST
{
private:
    TreeNode<T> *rootNode;
    void privBFS(TreeNode<T> *node);
    List<T> *markedNodes;
    Queue<TreeNode<T>> *queue;
    int privHeight(TreeNode<T> *node);
    bool privAncestors(TreeNode<T> *node, T value);
    int privWhatLevelAmI(TreeNode<T>* node, T value, int level);
public:
    BST<T>() { rootNode = NULL;}
    bool addValue(T *value);
    bool findValue(T *value);
    bool removeValue(T *value);
    int compareNodeValues(T *v1, T *v2);
    void display();
    void InOrder(TreeNode<T> *node);
    int countNodes();
    int countNodes(TreeNode<T>* node);
    void BFS();
    void visit(int order);
    void PreOrder(TreeNode<T> *node);
    void PostOrder(TreeNode<T> *node);
    int height();
    void ancestors(T value);
    int whatLevelAmI(T value);
};

template <class T>
int BST<T>::compareNodeValues(T *v1, T *v2)
{
    if (*v1 == *v2)
    {
        return 0;
    }
    if (*v1 > *v2)
    {
        return 1;
    }
    else
        return -1;
}

template <class T>
bool BST<T>::addValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return false;
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    // si llego aqui se inserta
    newNode = new TreeNode<T>(value);
    if (prevNode == NULL)
        rootNode = newNode;
    else
    {
        if (compareNodeValues(value, prevNode->getValue()) == 1)
            prevNode->setRightNode(newNode);
        else
            prevNode->setLeftNode(newNode);
    }
    return true;
}

template <class T>
bool BST<T>::findValue(T *value)
{
    TreeNode<T> *newNode, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return true;
        currentNode = (compareNodeValues(value, currentNode) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
void BST<T>::display()
{
    InOrder(rootNode);
}

template <class T>
void BST<T>::InOrder(TreeNode<T> *node)
{
    if (node == NULL)
        return;
    InOrder(node->getLeftNode());
    cout << *(node->getValue()) << " ";
    InOrder(node->getRightNode());
}

template <class T>
bool BST<T>::removeValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
        {   // ya lo encontramos
            // es un nodo hoja
            if (currentNode->getLeftNode() == NULL && currentNode->getRightNode() == NULL)
            {
                if (prevNode != NULL)
                { // No es el nodo raiz
                    if (currentNode == prevNode->getLeftNode())
                        prevNode->setLeftNode(NULL);
                    if (currentNode == prevNode->getRightNode())
                        prevNode->setRightNode(NULL);
                }
                else // es el nodo raiz
                    rootNode = NULL;
                delete currentNode;
                return true;
            }
            // es un nodo con dos hijos
            if (currentNode->getLeftNode() != NULL && currentNode->getRightNode() != NULL)
            {
                // en busca del predecesor
                TreeNode<T> *p = currentNode->getLeftNode();
                TreeNode<T> *prevP = NULL;
                if (currentNode->getLeftNode() != NULL) { // verifica que tenga hijo izq
                    prevP = currentNode; // prevP es el padre del predecesor
                    p = currentNode->getLeftNode(); // p es el posible predecesor
                    while (p->getRightNode() != NULL) { // mientras tenga hijo derecho
                        prevP = p; // prevP es el padre del predecesor
                        p = p->getRightNode(); // p es el predecesor
                    }
                }
                // desconectar el predecesor
                if (p->getLeftNode() != NULL)
                { // tiene un hijo a la izq
                    if (prevP != NULL)
                    {
                        if (p == prevP->getLeftNode())
                            prevP->setLeftNode(currentNode->getLeftNode());
                        else
                            prevP->setRightNode(currentNode->getLeftNode());
                    }
                }
                else
                { // se trata de un nodo hoja
                    if (p == prevP->getLeftNode())
                        prevP->setLeftNode(NULL);
                    else
                        prevP->setRightNode(NULL);
                }
                delete p;
                return true;
            }
            else
            { // tiene un solo hijo
                if (prevNode != NULL)
                {
                    if (prevNode->getLeftNode() == currentNode)
                    {
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setLeftNode(currentNode->getLeftNode());
                        else
                            prevNode->setLeftNode(currentNode->getRightNode());
                    }
                    else
                    { // se encuentra a la derecha
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setRightNode(currentNode->getLeftNode());
                        else
                            prevNode->setRightNode(currentNode->getRightNode());
                    }
                }
                else
                { // se trata del nodo raiz
                    if (currentNode->getLeftNode() != NULL)
                        rootNode = currentNode->getLeftNode();
                    else
                        rootNode = currentNode->getRightNode();
                }
                delete currentNode;
                return true;
            }
        }
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
int BST<T>::countNodes() {
    return countNodes(rootNode); // llamada recursiva
}

template <class T>
int BST<T>::countNodes(TreeNode<T>* node) {
    if (node == NULL) return 0; // en caso de que el arbol este vacio
    return 1 + countNodes(node->getLeftNode()) + countNodes(node->getRightNode()); // llamada recursiva
    // cuenta los nodos de la izquierda + cuenta los nodos de la derecha + 1 (por el nodo actual)
}


template <class T>
void BST<T>::BFS() {
    markedNodes=new List<T>();
    queue = new Queue<TreeNode<T>> ();
    privBFS(rootNode);
}

template <class T>
void BST<T>::privBFS(TreeNode<T> *node) {
    markedNodes->add(node->getValue());
    cout<<*(node->getValue())<<endl;
    queue->enqueue(node);
    while (!queue->isEmpty()) {
        TreeNode<T> *u=queue->dequeue();
        if ( u->getLeftNode()!=NULL && !markedNodes->find(u->getLeftNode()->getValue()) ) {
            markedNodes->add(u->getLeftNode()->getValue());
            cout<<*(u->getLeftNode()->getValue())<<endl;
            queue->enqueue(u->getLeftNode());
        }
        if ( u->getRightNode()!=NULL && !markedNodes->find(u->getRightNode()->getValue()) ) {
            markedNodes->add(u->getRightNode()->getValue());
            cout<<*(u->getRightNode()->getValue())<<endl;
            queue->enqueue(u->getRightNode());
        }
        //cin.get();
    }
}

template <class T>
void BST<T>::PreOrder(TreeNode<T> *node) {
    if (node == NULL) return;
    cout << *(node->getValue()) << " "; // Empieza por la raiz.
    PreOrder(node->getLeftNode());      // Recorre el subarbol izquierdo recursivamente.
    PreOrder(node->getRightNode());     // Recorre el subarbol dereecho recursivamente.
}

template <class T>
void BST<T>::PostOrder(TreeNode<T> *node) {
    if (node == NULL) return;
    PostOrder(node->getLeftNode());     // Recorre el subarbol izquierdo recursivamente.
    PostOrder(node->getRightNode());    // Recorre el subarbol dereecho recursivamente.
    cout << *(node->getValue()) << " "; // Visita el nodo.
}

template <class T>
void BST<T>::visit(int order) {
    switch (order) {
        case 1: PreOrder(rootNode); break;
        case 2: InOrder(rootNode); break;
        case 3: PostOrder(rootNode); break;
        case 4: BFS(); break;
        default: cout << "Parámetro invalido" << endl;
    }
    cout << endl;
}

template <class T>
int BST<T>::height() {
    return privHeight(rootNode);
}

template <class T>
int BST<T>::privHeight(TreeNode<T> *node) {
    if (node == NULL) {
        return -1;
    } else {
        // Contabiliza la altura de cada subarbol
        int leftHeight = privHeight(node->getLeftNode());
        int rightHeight = privHeight(node->getRightNode());
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // Compara y devuelve el de mayor profundidad
    }
}

template <class T>
bool BST<T>::privAncestors(TreeNode<T>* node, T value) {
    // Caso base
    if (node == NULL) {
        return false;
    }

    if (*(node->getValue()) == value) {
        return true;
    }
    // Si el valor es menor que el nodo actual, busca en el subarbol izquierdo
    if (value < *(node->getValue())) {
        if (privAncestors(node->getLeftNode(), value)) {
            cout << *(node->getValue()) << " ";
            return true;
        }
    } else { // de lo contrario, busca en el subarbol derecho
        if (privAncestors(node->getRightNode(), value)) {
            cout << *(node->getValue()) << " ";
            return true;
        }
    }

    return false;
}
template <class T>
void BST<T>::ancestors(T value) {
    if (rootNode == NULL) {
        cout << "El árbol está vacío" << endl;
        return;
    }
    if (!privAncestors(rootNode, value)) {
        cout << "No se encontraron ancestros para el valor" << value;
    }
}

// Función recursiva que devuelve el nivel de un nodo
template <class T>
int BST<T>::privWhatLevelAmI(TreeNode<T>* node, T value, int level) {
    if (node == NULL) {
        return -1;
    }
    if (*(node->getValue()) == value) {
        return level;
    } else if (value < *(node->getValue())) {
        return privWhatLevelAmI(node->getLeftNode(), value, level + 1);
    } else {
        return privWhatLevelAmI(node->getRightNode(), value, level + 1);
    }
}

template <class T>
int BST<T>::whatLevelAmI(T value) {
    return privWhatLevelAmI(rootNode, value, 0);
}


#endif //BT_BST_H
