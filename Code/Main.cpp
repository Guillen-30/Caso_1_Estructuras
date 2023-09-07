#include "MetodosTAD.h"
#include "MetodosOperacion.h"
#include "News.cpp"
#include "json.hpp"

#include <iostream>
#include <string>

int main() {

    Titular<string> miTitular;

    // Obtener noticias reales utilizando la clase Newsapi
    Newsapi newsapi;
    vector<News *> noticias = newsapi.getRecords();

    // Agregar los titulares de noticias a miTitular
    for (News *noticia : noticias) {
        miTitular.agregar(noticia->getTitle());
    }

    //Prueba listar titulares y comprobar que se haya agragado bien

    listaDEnlazada<string> lista = miTitular.listar();

    for (int i = 0 ; i < 5 ; i++){
        string dato = lista.getInfo(i);
        cout<< i+1 <<". " << dato <<endl;
    }

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
                case 1:{
                    for (int i = 0 ; i < lista.getLong() ; i++){
                        string dato = lista.getInfo(i);
                        cout<< i+1 <<". " << dato <<endl;
                    };
                    break;}
                case 2:{
                    cout << endl;
                    cout << "Lista de elementos que contienen una palabra de la lista: " << endl;
                    cout << endl;
                    listaDEnlazada<string> listaBusqueda = miTitular.buscar();
                    for (int i = 0 ; i < listaBusqueda.getLong() ; i++){
                        string dato = listaBusqueda.getInfo(i);
                        cout<< i+1 <<". " << dato <<endl;
                    }
                    break;}
                case 3:{
                    cout << "Lista luego de eliminar los titulares que contienen una palabra de la lista: " << endl;
                    miTitular.eliminarListado();
                    lista=miTitular.listar();
                    cout << endl;
                        for (int i = 0 ; i < lista.getLong() ; i++){
                            string dato = lista.getInfo(i);
                            cout<< i+1 <<". " << dato <<endl;
                    }
                    cout << endl;
                    break;}
                case 4:{
                    cout << endl;
                    cout << "Subir o bajar un titular de relevancia" << endl;
                    cout << "Ingrese el titular a mover: ";
                    string titular;
                    cin >> titular;
                    cin.ignore();
                    cout << "Ingrese el numero de posiciones a mover: ";
                    int posicion;
                    cin >> posicion;
                    cin.ignore();
                    miTitular.mover(titular, posicion);
                    cin.ignore();
                    lista= miTitular.listar();
                    cout << endl;
                    cout << "Lista después de mover: " << endl;
                        for (int i = 0 ; i < lista.getLong() ; i++){
                        string dato = lista.getInfo(i);
                        cout<< i+1 <<". " << dato <<endl;
                    }
                    cout << endl;
                    break;}
                case 5:{
                    cout << "Top 5 noticias por relevancia: " << endl;

                    lista=miTitular.listar();
                    for (int i = 0 ; i < 5 ; i++){
                        string dato = lista.getInfo(i);
                        cout<< i+1 <<". " << dato <<endl;
                    }
                    break;}
                case 0:{
                    cout << "Saliendo del programa." << endl;
                    break;}
                default:
                    cout << "Opción no válida. Por favor, elija una opción válida." << endl;
            }

        } while (opcion != 0);
    return 0;
};
