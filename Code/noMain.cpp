#include "MetodosTAD.h"
#include "MetodosOperacion.h"

#include <iostream>
#include <string>

using namespace std;

Titular<string> miTitular
listaDEnlazada<string> lista = miTitular.listar();

// Función para mostrar todas las noticias ordenadas por relevancia
void mostrarNoticiasOrdenadas() {
    
    cout << "Mostrar todas las noticias ordenadas por relevancia: " << endl;
    for (int i = 0 ; i < 5 ; i++){
        string dato = lista.getInfo(i);
        cout<< i+1 <<". " << dato <<endl;
}
    
}

// Función para mostrar titulares que contengan palabras de una lista
void mostrarTitularesConPalabras() {
    cout << "Mostrar titulares que contengan palabras a ingresar" << endl;

    listaDEnlazada<string> listaBusqueda = miTitular.buscar();
    for (int i = 0 ; i < listaBusqueda.getLong() ; i++){
        string dato = listaBusqueda.getInfo(i);
        cout<< i+1 <<". " << dato <<endl;
    }
    
}

// Función para eliminar noticias que contengan palabras de una lista
void eliminarNoticiasConPalabras() {
    cout << "Eliminar noticias que contengan palabras de una lista" << endl;
    
    miTitular.eliminarListado();

    lista=miTitular.listar();
    cout << endl;
        for (int i = 0 ; i < lista.getLong() ; i++){
            string dato = lista.getInfo(i);
            cout<< i+1 <<". " << dato <<endl;
    }
}

// Función para subir o bajar un titular de relevancia
void subirBajarTitular() {
    cout << "Subir o bajar un titular de relevancia" << endl;
    string titularRelevancia;
    int numeroAMover
    cout << "Ingrese el titular a borrar: ";
    cin >> titularRelevancia;
    cout << "Ingrese el numero de posiciones a mover: ";
    cin >> numeroAMover;
    miTitular.mover(titularRelevancia, numeroAMover);
}

int main() {
    for (int i = 0 ; i < 5 ; i++){
        string dato = lista.getInfo(i);
        cout<< i+1 <<". " << dato <<endl;
    };

    int opcion;
    do {
        cout << endl;
        cout << "Menú de opciones:" << endl;
        cout << "1) Mostrar todas las noticias ordenadas por relevancia" << endl;
        cout << "2) Mostrar titulares que contengan palabras de una lista" << endl;
        cout << "3) Eliminar noticias que contengan palabras de una lista" << endl;
        cout << "4) Subir o bajar un titular de relevancia" << endl;
        cout << "5) Mostrar top 5 noticias" << endl;
        cout << "0) Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarNoticiasOrdenadas();
                break;
            case 2:
                mostrarTitularesConPalabras();
                break;
            case 3:
                eliminarNoticiasConPalabras();
                break;
            case 4:
                subirBajarTitular();
                break;
            case 5:
                << cout << "Top 5 noticias por relevancia: " << endl;

                lista=miTitular.listar()
                for (int i = 0 ; i < 5 ; i++){
                    string dato = lista.getInfo(i);
                    cout<< i+1 <<". " << dato <<endl;
                }
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
