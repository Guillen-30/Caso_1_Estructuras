/* Se usara un TAD lita doblemente enlazada, se ordenara segun la relevancia que puede ser modificada, 
por lo tanto se ordenara antes de cualquier busqueda y para la busqueda solo se mostraran aquellos 
titulares que contengan una o mas palabras de la lista ingresada por el usuario, ya con eso, se puede decidir 
si eliminar la noticia o mostrarla, la fecha sera otro parametro del titular */

#include <string>


class listaDEnlazada{
    private:
        int long; // Longitud de la lista

    public:
        void insertar(info pDato, int pos = -1); // Se revisara si pos es == -1, si lo es, se agrega al final, si no, se inserta al indice indicado
        bool esVacia(); // Revisa si la lista esta vacia
        int getLong(); // Retorna el atributo long
        info borrar(info pDato); // Elimina de la lista el elemento con el dato dado
        info getNext(); // Devuelve el siguiente elemento de la lista
        info getPast(); // Devuelve el elemento pasado de la lista
        info buscar(String pKey); // Devuelve el elemento con la keyWord dada
        void mostrar(info pDato); // Muestra el elemento con el dato dado
};  

