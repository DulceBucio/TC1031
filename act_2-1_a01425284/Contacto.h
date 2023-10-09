//
// Dulce Nahomi Bucio Rivas A01425284
// 08/10/2023
// Clase Contacto
//


#ifndef LISTASTT_CONTACTO_H
#define LISTASTT_CONTACTO_H
#include <iostream>
#include <sstream>

#include "Direccion.h"
using namespace std;

// Clase que representa un contacto, contiene un nombre y un objeto de tipo Direccion

// Declaración de la clase Contacto
class Contacto {
private:
    string nombre;
    Direccion direccion;
public:
    Contacto() {};

    Contacto(string nombre, Direccion direccion) {
        this->nombre = nombre;
        this->direccion = direccion;
    }
    Contacto(string nombre){
        this->nombre=nombre;
    }
    void setNombre(string valor) { nombre = valor; }

    void setDireccion(Direccion valor) { direccion = valor; }

    string getNombre() { return nombre; }

    Direccion getDireccion() { return direccion; }

    string toString() const {
        stringstream ss;
        ss << "Nombre: " << nombre << endl << "Direccion: " << direccion << endl;
        return ss.str();
    }
};

// Sobrecarga del operador << para imprimir un objeto de tipo Contacto
ostream& operator<< ( ostream& outs, const Contacto obj ) {
    return outs << obj.toString();
}


#endif //LISTASTT_CONTACTO_H
