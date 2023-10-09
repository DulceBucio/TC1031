//
// Dulce Nahomi Bucio Rivas A01425284
// 08/10/2023
// Clase Direccion
//


#ifndef LISTASTT_DIRECCION_H
#define LISTASTT_DIRECCION_H
#include <iostream>
#include <sstream>
using namespace std;

// Clase que contiene los atributos de la direccion

// Declaración de la clase Direccion
class Direccion{
public:
    Direccion(){};
    Direccion(string calle, int numero, string municipio, string estado){
        this->calle=calle;
        this->numero=numero;
        this->municipio=municipio;
        this->estado=estado;
    }
    void setCalle(string valor) {calle=valor;}
    void setNumero(int valor) {numero=valor;}
    void setMunicipio(string valor) {municipio=valor;}
    void setEstado(string valor) {estado=valor;}
    string getCalle() {return calle;}
    int getNumero() {return numero;}
    string getMunicipio() {return municipio;}
    string getEstado() {return estado;}
    string toString() const {
        stringstream ss;
        ss<< "Calle: " << calle << endl << "Numero: " << numero << endl << "Municipio: " << municipio << endl << "Estado: " << estado << endl;
        return ss.str();
    };
private:
    string calle;
    int numero;
    string municipio;
    string estado;
};

// Sobrecarga del operador <<
ostream& operator<< ( ostream& outs, const Direccion obj ) {
    return outs << obj.toString();
}


#endif //LISTASTT_DIRECCION_H
