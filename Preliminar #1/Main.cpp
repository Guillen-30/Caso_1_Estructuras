#include "MetodosTAD.h"
#include "MetodosOperacion.h"

#include <iostream>

int main() {

    cout<<"Hola" << endl;

    Titular<string> miTitular;


    miTitular.agregar("Titular 1");
    cout << "Se agrego 'Titular 1'" << endl;
    miTitular.agregar("Titular 2 busca");
    cout << "Se agrego 'Titular 2 busca'" << endl;
    miTitular.agregar("Titular 3");
    cout << "Se agrego 'Titular 3'" << endl;
    miTitular.agregar("Titular 4");
    cout << "Se agrego 'Titular 4'" << endl;
    miTitular.agregar("Titular 5 busca");
    cout << "Se agrego 'Titular 5 busca'" << endl;
    miTitular.agregar("documento");
    cout << "Se agrego 'documento'" << endl;
    miTitular.agregar("noticia");
    cout << "Se agrego 'noticia'" << endl;


    //Prueba listar titulares y comprobar que se haya agragado bien
    cout << "Lista luego de agregar titulares" << endl;

    listaDEnlazada<string> lista = miTitular.listar();

    //Prueba imprimir longitud de la lista

    cout << "Longitud de la lista: " << lista.getLong() << endl;

    //Prueba borrar dato especifico y luego imprimir para ver si se borro

    miTitular.eliminar("Titular 3");

    cout << "Lista después de borrar: ";
    miTitular.listar();
    cout << endl;

    cout << "Lista de elementos que contienen 'busca': ";
    miTitular.buscar("busca");
    cout << endl;

    cout << "Lista luego de mover el titular 'noticia' a la posicion 2";
    miTitular.mover("noticia", 2);
    cout << endl;



    return 0;
};
