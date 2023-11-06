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
  	arbolito->display();  
  
  	int val=0;
    do {
  		cout<<endl<<"Que valor quieres eliminar?";
      cin>>val;
      arbolito->removeValue(&val);
      cout<<"Nuevo arbol:";	
      arbolito->display();
      int nodeCount = arbolito->countNodes();
      cout << "Numero de nodos: " << nodeCount << endl;
    } while (val!=0);
}


