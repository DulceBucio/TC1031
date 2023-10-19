//
// Created by Dulce Nahomi Bucio Rivas | A01425284 on 16/10/2023.
//

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "DoubleLinkList.h"

using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(NULL)));

    DoubleLinkList<int> dblist;
    int randoms[20];
    for (int i = 0; i < 20; i++) {
        randoms[i] = (1 + rand() % 101);
        dblist.add(&randoms[i]);
    }
    dblist.display();
    dblist.inverseDisplay();

    return 0;
}

