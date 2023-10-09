//
// Dulce Nahomi Bucio Rivas A01425284
// 08/10/2023
// Main
//

#include <iostream>
#include "Node.h"
#include "List.h"
#include "Contacto.h"
#include <sstream>
using namespace std;

int main(){
    // Creación de la lista de contactos previa al menú
    List<Contacto> *listaContactos=new List<Contacto>();
    // Menú de opciones para el usuario que siempre se muestra tras finalizar una operación
    while (true) {
        cout << "Bienvenido a la agenda de contactos \n";
        cout << "1. Agregar contacto \n";
        cout << "2. Ver contactos \n";
        cout << "3. Modificar contacto \n";
        cout << "4. Eliminar contacto \n";
        cout << "5. Salir \n";
        cout << "Ingrese la opcion que desea realizar: ";
        int opcion;
        cin >> opcion;
        // Validación de tipo de dato int
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Opcion no valida. Intente de nuevo:";
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                // Creación de un nuevo contacto según los datos ingresados por el usuario
                string nombre, calle, municipio, estado;
                int numero;
                cout << "Ingrese el nombre del contacto: ";
                cin >> nombre;
                cout << "Ingrese la calle: ";
                cin >> calle;
                cout << "Ingrese el numero: ";
                cin >> numero;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Ese no parece ser un numero valido. Intente de nuevo: ";
                    cin >> numero;
                }
                cout << "Ingrese el municipio: ";
                cin >> municipio;
                cout << "Ingrese el estado: ";
                cin >> estado;
                Direccion direccion = Direccion(calle, numero, municipio, estado);
                Contacto *contacto = new Contacto(nombre, direccion);
                listaContactos->add(contacto); // Se agrega el contacto a la lista
                cout << "Contacto agregado con exito \n";
                cout << listaContactos << endl; // Se despliega la lista de contactos
                break;
            }
            case 2:{
                cout << listaContactos << endl; // Se despliega la lista de contactos
                break;
            }
            case 3: {
                cout << "Ingrese el numero de contacto que desea modificar: ";
                int index;
                cin >> index;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Ese no parece ser un numero valido. Intente de nuevo: ";
                    cin >> index;
                }
                // Tras recibir el índice del contacto a modificar, se solicitan los nuevos datos
                if (index < 0 || index > listaContactos->getSize()) { // Validación de índice
                    cout << "El contacto no existe \n";
                } else {
                    string nombre, calle, municipio, estado;
                    int numero;
                    cout << "Ingrese el nombre del contacto: ";
                    cin >> nombre;
                    cout << "Ingrese la calle: ";
                    cin >> calle;
                    cout << "Ingrese el numero: ";
                    cin >> numero;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Ese no parece ser un numero valido. Intente de nuevo: ";
                        cin >> numero;
                    }
                    cout << "Ingrese el municipio: ";
                    cin >> municipio;
                    cout << "Ingrese el estado: ";
                    cin >> estado;
                    Direccion direccion = Direccion(calle, numero, municipio, estado); // Creación de la nueva dirección
                    Contacto *contacto = new Contacto(nombre, direccion); // Creación del nuevo contacto
                    listaContactos->replace(index, contacto); // Se reemplaza el contacto en la lista
                    cout << "Contacto modificado con exito \n";
                    cout << listaContactos << endl;
                }
            }
            case 4: {
                // Se solicita de un índice para eliminar el contacto
                cout << "Ingrese el numero de contacto que desea eliminar: ";
                int index;
                cin >> index;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Ese no parece ser un numero valido. Intente de nuevo: ";
                    cin >> index;
                }
                if (index < 0 || index > listaContactos->getSize()) { // Validacion de índice
                    cout << "El contacto no existe \n";
                } else {
                    listaContactos->removeAt(index); // Si el índice es válido, se elimina el contacto
                    cout << "Contacto eliminado con exito \n";
                    cout << listaContactos << endl;
                }
            }
            case 5: {
                cout << "Gracias por usar la agenda de contactos \n";
                return 0;
            }
        }
    }
}
