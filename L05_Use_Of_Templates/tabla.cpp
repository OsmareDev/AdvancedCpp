
#include "tabla.h"

/**
 * Constructor of class
 * @param tam Size of table. Must be double of the number of elements.
 */
Tabla::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
void Tabla::insertar(TipoClave clave, const TipoDato & valor)
{
    unsigned i;
    i = hash(clave);
    t[i].push_back(Celda{clave,valor} );
}

/**
 * Search for an element
 * @param clave Key of the element
 * @param valor Value founded with key "clave"
 * @return true if element founded, false otherwise
 */
bool Tabla::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    for(unsigned j=0; j < t[i].size(); j++)
    {
       if(t[i][j].clave == clave) 
       {
           valor = t[i][j].dato;
           return true;
       }
    }
    return false;
}

/**
 * Hash function for strings
 * @param clave Key
 */
unsigned Tabla::hash(TipoClave clave) const
{
    unsigned long h = 5381;
    
    // Only valid for strings
    for(unsigned i = 0; i < clave.size(); i++)
        h = ((h << 5) + h) + clave[i];
        
    return h % t.size();
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
void Tabla::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j].dato << " -> ";
        sal << std::endl;
    }
}
