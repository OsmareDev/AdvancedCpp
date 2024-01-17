/**
 * Implementation of a hash table
 * 
 */
#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;

class Tabla
{
public:
    typedef string TipoClave;
    typedef Alumno TipoDato;
    struct Celda {
        TipoClave clave;
        TipoDato dato;
    };
        
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

#endif
