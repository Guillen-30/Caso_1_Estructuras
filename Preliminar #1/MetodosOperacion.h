/* Se usara un TAD lita simple/Array, se ordenara el array segun la relevancia que puede ser modificada, 
por lo tanto se ordenara antes de cualquier busqueda y para la busqueda solo se mostraran aquellos 
titulares que contengan una o mas palabras de la lista ingresada por el usuario, ya con eso, se puede decidir 
si eliminar la noticia o mostrarla, la fecha sera otro parametro del titular */
#include "MetodosTAD.h"
#include <string>


class MetodosOperacion {
public:
    MetodosOperacion(int cap = 10);

    void agregar(const std::string& elemento);  // Agregar un elemento al array
    bool buscar(const std::string& elemento) const;  // Buscar un elemento en el array
    void eliminar(const std::string& elemento);  // Eliminar un elemento del array
    // Otros métodos para reordenar, etc.

private:
    MiArray miArray;  // Usar la clase MiArray para almacenar los datos
};

