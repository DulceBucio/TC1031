//
// Dulce Nahomi Bucio Rivas | A01425284
// 16/10/2023.
// Implementación de una lista doblemente ligada
//

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "DoubleLinkList.h"

using namespace std;

int main(){

    DoubleLinkList<int> dblist; // Creación de la lista doblemente ligada
    srand(static_cast<unsigned int>(time(NULL)));
    int randoms[20]; // Creación de un arreglo de 20 números aleatorios
    for (int i = 0; i < 20; i++) {
        randoms[i] = (1 + rand() % 101);
        dblist.add(&randoms[i]); // Agrega los números aleatorios a la lista

    }

    // Despliega los valores de la lista y su inversa
    cout << "Lista original: \n";
    dblist.display();
    cout << "Lista inversa: \n";
    dblist.inverseDisplay();

    cout << "Ingrese un indice: \n";
    int index;
    cin >> index;
    cout << "Ingrese un valor para reemplazar el valor en el indice: \n";
    int value;
    cin >> value;
    dblist.update(index, &value);
    dblist.display();
    dblist.inverseDisplay();

    int index2;
    cout << "Ingrese un indice para eliminar el valor \n";
    cin >> index2;
    dblist.removeAt(index2);
    dblist.display();
    dblist.inverseDisplay();

    return 0;
}

