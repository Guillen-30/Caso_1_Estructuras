#include "MetodosTAD.h"
#include "MetodosOperacion.h"

#include <iostream>
#include <string>

int main() {

    Titular<string> miTitular;

    cout << endl;
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
    cout << endl;

    //Prueba listar titulares y comprobar que se haya agragado bien
    cout << "Lista luego de agregar titulares" << endl;
    cout << endl;

    listaDEnlazada<string> lista = miTitular.listar();

    for (int i = 0 ; i < lista.getLong() ; i++){
        string dato = lista.getInfo(i);
        cout<<dato <<endl;
    }


    //Prueba imprimir longitud de la lista
    cout << endl;
    cout << "Longitud de la lista: " << lista.getLong() << endl;

    //Prueba borrar dato especifico y luego imprimir para ver si se borro

    miTitular.eliminar("Titular 3");
    lista = miTitular.listar();

    //Prueba imprimir longitud de la lista luego de borrar
    cout << endl;
    cout << "Longitud de la lista luego de borrar: " << lista.getLong() << endl;
    cout << endl;
    cout << "Lista después de borrar: " << endl;
        for (int i = 0 ; i < lista.getLong() ; i++){
        string dato = lista.getInfo(i);
        cout<<dato <<endl;
    }
    cout << endl;
    cout << "Lista de elementos que contienen 'busca': " << endl;
    cout << endl;
    listaDEnlazada<string> listaBusqueda = miTitular.buscar("busca");
    for (int i = 0 ; i < listaBusqueda.getLong() ; i++){
        string dato = listaBusqueda.getInfo(i);
        cout<<dato <<endl;
    }


    cout << endl;
    cout << "Lista luego de mover el titular 'noticia' a la posicion 2: " << endl;
    miTitular.mover("noticia", 2);

    lista= miTitular.listar();
    cout << endl;
    cout << "Lista después de mover: " << endl;
        for (int i = 0 ; i < lista.getLong() ; i++){
        string dato = lista.getInfo(i);
        cout<<dato <<endl;
    }
    cout << endl;
    cout << "Lista luego de eliminar los titulares que contienen 'buscar': " << endl;

    listaBusqueda = miTitular.buscar("busca");
    miTitular.eliminarListado("busca");

    lista=miTitular.listar();
    cout << endl;
        for (int i = 0 ; i < lista.getLong() ; i++){
            string dato = lista.getInfo(i);
            cout<<dato <<endl;
    }
    cout << endl;
    return 0;
};
