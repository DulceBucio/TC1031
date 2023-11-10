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

  	cout<<"Valores del arbol:";
    arbolito -> visit(1);
    arbolito->ancestors(1);
    cout << arbolito->whatLevelAmI(13);
    cout << arbolito -> height();
    arbolito->BFS();

}


