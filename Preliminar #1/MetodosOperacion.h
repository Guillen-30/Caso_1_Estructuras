/* Se usara un TAD lita doblemente enlazada, se ordenara segun la relevancia que puede ser modificada, 
por lo tanto se ordenara antes de cualquier busqueda y para la busqueda solo se mostraran aquellos 
titulares que contengan una o mas palabras de la lista ingresada por el usuario, ya con eso, se puede decidir 
si eliminar la noticia o mostrarla, la fecha sera otro parametro del titular */

#ifndef METODOS_OPERACION 
#define METODOS_OPERACION 1

#include "MetodosTAD.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
    class Titular {
        private:
            listaDEnlazada<T> titulares; // Se utiliza la lista doblemente enlazada para almacenar los titulares

        public:
            // Agregar un titular a la lista
            void agregar(T titular) {
                titulares.insertar(titular);
            }

            // Eliminar un titular de la lista
            void eliminar(T titular) {
                titulares.borrar(titular);
            }

            // Listar todos los titulares
            listaDEnlazada<T> listar() {
                return titulares;
            }

            // Buscar titulares que contengan una palabra clave
            listaDEnlazada<T> buscar(string keyWord) {
                listaDEnlazada<T> resultados;
                for (Nodo<T> nodo: titulares) {
                    T titular = nodo.data;
                    if (titular.find(keyWord) != std::string::npos) {
                        resultados.insertar(titular);
                    }
                }
                return resultados;
                
            }



            // Mover un titular a una posición específica en la lista

            void mover(T titular, int posicion) {
                if (posicion < 0 || posicion >= titulares.getLong()) {
                    cout << "Posición fuera de rango." << endl;
                    return;
                }

                Nodo<T>* current = titulares.begin();
                int currentIndex = 0;

                while (current != nullptr) {
                    if (current->data == titular) {
                        // Se elimina el titular de su posición original
                        titulares.borrar( titular);

                        // Se inserta el titular en la nueva posición
                        titulares.insertar( titular, posicion);

                        cout << "Titular movido a la posición " << posicion << "." << endl;
                        return;
                    }
                    current = current->next;
                    currentIndex++;
                }

                cout << "Titular no encontrado en la lista." << endl;
            }


            // Eliminar titulares que contengan una palabra clave
            void eliminarListado(string keyWord) {
                for (string titular : titulares) {
                    if (titular.find(keyWord)!= std::string::npos){
                        titulares.borrar(titular);
                    };
                };
            };
        };

#endif
