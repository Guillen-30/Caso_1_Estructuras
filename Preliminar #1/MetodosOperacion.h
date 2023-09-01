/* Se usara un TAD lita doblemente enlazada, se ordenara segun la relevancia que puede ser modificada, 
por lo tanto se ordenara antes de cualquier busqueda y para la busqueda solo se mostraran aquellos 
titulares que contengan una o mas palabras de la lista ingresada por el usuario, ya con eso, se puede decidir 
si eliminar la noticia o mostrarla, la fecha sera otro parametro del titular */

#include "MetodosTAD.h"
#include <string>


void agregar(titular);

void eliminar(titular);

Titular *listar();

Titular *buscar(string keyWord );

Titular void mover(titular, int posicion);

Titular void eliminar(string keyWord)