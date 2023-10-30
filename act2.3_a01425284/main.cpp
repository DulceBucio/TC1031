#include <iostream>
#include "TStack.h"
#include <cstring>
using namespace std;

#define MAX 100



int main() {
    char expresion[MAX] = "{A+B + (a+b}";
    // cin.getline(expresion, MAX);

    char *pos = expresion;
    TStack<char> *expStack = new TStack<char>();
    bool valid = true;
    while (*pos) {
        if (*pos == '(' || *pos == '[' || *pos == '{') {
            expStack->push(pos);
            cout << *pos << "\n";
        } else if (*pos == ')' || *pos == ']' || *pos == '}') {
            if (expStack->empty()) {
                valid = false;
                break;
            } else {
                char topChar = *(expStack->pop());
                if ((*pos == ')' && topChar != '(') || (*pos == ']' && topChar != '[') || (*pos == '}' && topChar != '{')) {
                    valid = false;
                    break;
                }
            }
        }
        pos++;
    }
    if (!expStack->empty()){
        valid = false;
    }

    if(valid) {
        cout << "La expresion es valida \n";
    } else {
        cout << "La expresion no es valida \n";
    }
}



