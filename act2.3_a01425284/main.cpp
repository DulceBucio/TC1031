//
// Dulce Nahomi Bucio Rivas A01425284
// 29/10/2023
// Implementación de pila para validación de expresiones matemáticas
//

#include <iostream>
#include "TStack.h"
using namespace std;

#define MAX 100 // Tamaño máximo de la expresión

// Función que determina si una expresión es válida o no usando una pila
void validExpresion(char expresion[]) {
    char *pos = expresion; // Se posiciona en el primer caracter de la expresión
    TStack<char> *expStack = new TStack<char>(); // Se crea una pila de caracteres
    bool valid = true; // Se inicializa la variable que determina si la expresión es válida o no,
    // empezamos asumiendo que sí lo es
    while (*pos) { // Mientras no hayamos leído toda la cadena
        if (*pos == '(' || *pos == '[' || *pos == '{') { // Si el caracter es un paréntesis de apertura, entonces
            expStack->push(pos); // lo agrega a la pila
        } else if (*pos == ')' || *pos == ']' || *pos == '}') { // Si el caracter es un paréntesis de cierre, entonces
            if (expStack->empty()) { // verificamos que la pila no esté vacía
                valid = false;
                break;
            } else {
                char topChar = *(expStack->pop()); // Si no está vacía, entonces sacamos el elemento que está en el tope
                // y comparamos ese elemento con el correspondiente del caracter que estamos leyendo
                if ((*pos == ')' && topChar != '(') || (*pos == ']' && topChar != '[') || (*pos == '}' && topChar != '{')) {
                    // Si no son correspondentes, entonces la expresión no es válida
                    valid = false;
                    break;
                }
            }
        }
        pos++;
    }
    if (!expStack->empty()){ // Al llegar al final de la expresión, la pila debe de estar vacía
        valid = false; // Si no está vacía, entonces la expresión no es válida
    }

    // Según el valor de la variable valid, se imprime un mensaje
    if(valid) {
        cout << "La expresion es valida \n";
    } else {
        cout << "La expresion no es valida \n";
    }
}

int main() {
    // Ciclo do while para que el usuario pueda ingresar varias expresiones hasta que decida terminar el programa
    do {
        cout << "Ingrese una expresion: ";
        char expresion[MAX];
        cin.getline(expresion, MAX); // Se lee la expresión
        // El programa termina cuando el usuario introduce una cadena vacía
        if (expresion[0] == '\0') break;
        validExpresion(expresion); // Se llama a la función que determina si la expresión es válida o no
    } while (true);
}



