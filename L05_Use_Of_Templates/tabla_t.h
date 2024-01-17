/**
 * Implementation of a hash table
 * 
 */
#ifndef _TABLA_T_H
#define _TABLA_T_H

#define Typenames typename KeyT, typename ValueT, template < class Elem, class Allocator = std::allocator<Elem> > class Container, typename Policy
#define Parameters KeyT, ValueT, Container, Policy

#include <string>
#include <vector>
#include <iostream>
#include <functional>

using std::string;
using std::vector;

template <typename T>
class Default {
    public:
        static size_t Hashing(T def) {
            return std::hash<T>{}(def);
        }
};

template <  typename KeyT, 
            typename ValueT, 
            template < class Elem, class Allocator = std::allocator<Elem> > 
            class Container = std::vector,
            typename Policy = Default<KeyT>
            >
class Tabla
{
public:
    typedef KeyT TipoClave;
    typedef ValueT TipoDato;
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
    typedef Container<Celda> ListaDatos; 
    std::vector<ListaDatos> t;
};

/**
 * Constructor of class
  * @param tam Size of table. Must be double of the number of elements.
 */
template <Typenames>
Tabla<Parameters>::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Insert an element
  * @param key Key of the element
  * @param value Value to be stored
 */
template <Typenames>
void Tabla<Parameters>::insertar(TipoClave clave, const TipoDato & valor)
{
    unsigned i;
    i = hash(clave);
    t[i].push_back(Celda{clave,valor} );
}

/**
 * Search for an element
  * @param key Key of the element
  * @param value Value founded with key "key"
  * @return true if element founded, false otherwise
 */
template <Typenames>
bool Tabla<Parameters>::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    //for(unsigned j=0; j < t[i].size(); j++)
    for (const auto & celda : t[i])
    {
       if(celda.clave == clave) 
       {
           valor = celda.dato;
           return true;
       }
    }
    return false;
}

/**
 * Hash function for strings
 * @param clave Key
 */
 // custom specialization of std::hash can be injected in namespace std
/*template<typename S>
struct std::hash
{
    std::size_t operator()(S const& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};*/

template <Typenames>
unsigned Tabla<Parameters>::hash(TipoClave clave) const
{
    return Policy::Hashing(clave) % t.size();
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
template <Typenames>
void Tabla<Parameters>::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        //for(unsigned j = 0; j < t[i].size(); j++)
        for (const auto & celda : t[i])
            sal << celda.dato << " -> ";
        sal << std::endl;
    }
}

#endif
