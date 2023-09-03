#ifndef METODOS_TAD 

#define METODOS_TAD 1

#include <iostream>
#include <string>

using namespace std;

template <class T>
// Definición de la estructura para los nodos de la lista
struct Nodo {
    T data;
    Nodo* next;
    Nodo* prev;
    Nodo(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <class T>
class listaDEnlazada {
private:
    Nodo<T>* head;  // Puntero al primer nodo
    Nodo<T>* tail;  // Puntero al último nodo
    int length;  // Longitud de la lista

public:
    listaDEnlazada() : head(nullptr), tail(nullptr), length(0) {}

    // Funcion begin y end para poder recorrer con un for

    Nodo<T>* begin(){
        return head;
    }

    Nodo<T>* end(){
        return tail;
    }

    // Insertar un elemento en la lista
    void insertar(T pDato, int pos = -1) {
        Nodo<T>* newNode = new Nodo(pDato);
        if (esVacia()) {
            head = newNode;
            tail = newNode;
        } else if (pos == -1) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            if (pos <= 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (pos >= length) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                Nodo<T>* current = head;
                for (int i = 0; i < pos - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next->prev = newNode;
                newNode->prev = current;
                current->next = newNode;
            }
        }
        length++;
    }

    // Revisar si la lista está vacía
    bool esVacia() {
        return length == 0;
    }

    // Obtener la longitud de la lista
    int getLong() {
        return length;
    }

    // Borrar un elemento de la lista
    int borrar(T pDato) {
        if (esVacia()) {
            return -1;  // La lista está vacía
        }

        Nodo<T>* current = head;
        while (current != nullptr) {
            if (current->data == pDato) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                T deletedData = current->data;
                delete current;
                length--;
                return 1;
            }
            current = current->next;
        }
        return -1;  // Elemento no encontrado
    }

// Obtener el siguiente elemento de la lista
int getNext(T pDato) {
    Nodo<T>* current = head;
    while (current != nullptr) {
        if (current->data == pDato) {
            if (current->next != nullptr) {
                return current->next->data;
            } else {
                return -1;  // No hay un siguiente elemento
            }
        }
        current = current->next;
    }
    return -1;  // Elemento no encontrado
}

// Obtener el elemento pasado de la lista
int getPast(T pDato) {
    Nodo<T>* current = head;
    while (current != nullptr) {
        if (current->data == pDato) {
            if (current->prev != nullptr) {
                return current->prev->data;
            } else {
                return -1;  // No hay un elemento previo
            }
        }
        current = current->next;
    }
    return -1;  // Elemento no encontrado
}

// Mostrar un elemento
void mostrar(T pDato) {
    Nodo<T>* current = head;
    while (current != nullptr) {
        if (current->data == pDato) {
            cout << "Dato encontrado: " << current->data << endl;
            return;
        }
        current = current->next;
    }
    cout << "Dato no encontrado en la lista." << endl;
}

};

#endif
