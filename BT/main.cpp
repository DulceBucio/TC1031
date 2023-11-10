#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    int arr[] {20,1,4,7,23,5,10,8,11,21};
    int arr2[] {13,7,9,11,23,3,6,2,23,28,4,8,1,19};
    BST<int> *arbolito=new BST<int>();

    for (int i=0; i<14;i++) {
        arbolito->addValue(&arr2[i]);
    }

    // Función visit
  	cout<<"Valores del arbol en preorder: ";
    arbolito->visit(1);
    cout<<endl;
    cout<<"Valores del arbol en inorder: ";
    arbolito->visit(2);
    cout<<endl;
    cout<<"Valores del arbol en postorder: ";
    arbolito->visit(3);
    cout<<endl;
    cout<<"Valores del arbol en level by level: ";
    arbolito->visit(4);
    cout<<endl;

    // Función height
    cout<<"La altura del arbol es: "<<arbolito->height()<<endl;

    // Función ancestors
    cout<<"Los ancestros del nodo 23 son: ";
    arbolito->ancestors(23);

    // Función whatLevelAmI
    cout<<"El nivel del nodo 23 es: "<<arbolito->whatLevelAmI(23)<<endl;

}


