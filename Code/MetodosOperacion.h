/* Se usara un TAD lita doblemente enlazada, se ordenara segun la relevancia que puede ser modificada, 
por lo tanto se ordenara antes de cualquier busqueda y para la busqueda solo se mostraran aquellos 
titulares que contengan una o mas palabras de la lista ingresada por el usuario, ya con eso, se puede decidir 
si eliminar la noticia o mostrarla, la fecha sera otro parametro del titular */

#ifndef METODOS_OPERACION 
#define METODOS_OPERACION 1

#include "MetodosTAD.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
            listaDEnlazada<T> buscar() {
                vector<string> keyWords;
                listaDEnlazada<T> resultados;
                string keyWord;
                cout << "Ingrese palabras o oraciones para buscar (ingrese -1 para salir):" << endl;
                
                while (true) {
                    cin >> keyWord;
                    if (keyWord == "-1") {
                        break;
                    }
                    keyWords.push_back(keyWord);
                    }

                for (int i=0;i<keyWords.size();i++){
                    Nodo<T>* current = titulares.begin(); // Obtener el puntero al primer nodo
                    
                    while (current != nullptr) {
                        T titular = current->data;
                        string upp = std::transform(keyWords[i].begin(),keyWords[i].end(),::toupper)
                        if (titular.find(upp) != string::npos) {
                            resultados.insertar(titular);
                        }
                        current = current->next;
                    }
                }
                return resultados;
            }

            // Mover un titular a una posición específica en la lista

            void mover(T titular, int posicion) {
                if (posicion >= titulares.getLong()) {
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
                        titulares.insertar( titular, currentIndex+posicion);

                        cout << "Titular movido " << posicion << "posiciones" << endl;
                        return;
                    }
                    current = current->next;
                    currentIndex++;
                }

                cout << "Titular no encontrado en la lista." << endl;
            }


            // Eliminar titulares que contengan una palabra clave
            void eliminarListado() {
                vector<string> keyWords;
                listaDEnlazada<T> resultados;
                string keyWord;
                cout << "Ingrese palabras o oraciones para buscar (ingrese -1 para salir):" << endl;
                
                while (true) {
                    cin >> keyWord;
                    if (keyWord == "-1") {
                        break;
                    }
                    keyWords.push_back(keyWord);
                    }

                for (int i=0;i<keyWords.size();i++){
                    Nodo<T>* current = titulares.begin(); // Obtener el puntero al primer nodo
                    
                    while (current != nullptr) {
                        T titular = current->data;
                        string upp = transform(keyWords[i].begin(),keyWords[i].end(),::toupper)
                        if (titular.find(upp) != string::npos) {
                            resultados.insertar(titular);
                        }
                        current = current->next;
                    }
                }
                for (int i=0;i<resultados.getLong();i++){
                    eliminar(resultados.getInfo(i));
                }
            }
        };

#endif
