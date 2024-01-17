/**
 * Implementation of a hash table
 * 
 */
#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

template <typename TKey, typename TValue>
class TablaIterator;

template <typename KeyT, typename ValueT>
class Tabla
{
public:
    typedef KeyT TipoClave;
    typedef ValueT TipoDato;
    struct Celda {
        TipoClave clave;
        TipoDato dato;

        friend std::ostream& operator<<(std::ostream& os, const Celda& c)
        {
            os << c.clave << " " << c.dato;
            return os;
        }

        bool operator<(const Celda& c) const
        {
            return clave < c.clave;
        }
    };
        
    typedef TablaIterator<KeyT, ValueT> iterator;
    typedef Celda value_type;
    friend class TablaIterator<KeyT, ValueT>;
    
    iterator begin();
    iterator end();

    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

/**
 * Constructor of class
 * @param tam Size of table. Must be double of the number of elements.
 */
template <typename KeyT, typename ValueT>
Tabla<KeyT, ValueT>::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
template <typename KeyT, typename ValueT>
void Tabla<KeyT, ValueT>::insertar(TipoClave clave, const TipoDato & valor)
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
template <typename KeyT, typename ValueT>
bool Tabla<KeyT, ValueT>::buscar(TipoClave clave, TipoDato & valor) 
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
 * @return Hash value
 */
template <typename KeyT, typename ValueT>
unsigned Tabla<KeyT, ValueT>::hash(TipoClave clave) const
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
template <typename KeyT, typename ValueT>
void Tabla<KeyT, ValueT>::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j].dato << " -> ";
        sal << std::endl;
    }
}

/**
 * Create and return an IteratorList pointing to the first element of Lista
 * @return ListaIterator<T> list 
 */
template <typename TKey, typename TValue>
typename Tabla<TKey, TValue>::iterator Tabla<TKey, TValue>::begin() { 
    return TablaIterator<TKey, TValue>(t.begin(), t.end());
    //return ptr;
};

/**
 * Create and return an IteratorList pointing to the end of Lista
 * @return ListaIterator<T> list 
 */
template <typename TKey, typename TValue>
typename Tabla<TKey, TValue>::iterator Tabla<TKey, TValue>::end() { 
    return TablaIterator<TKey, TValue>(t.end(), t.end());
};

/****************************************************************************************
 *                                                                                      *
 *                                  TABLA ITERATOR                                      *
 *                                                                                      *
 ***************************************************************************************/

template <typename TKey, typename TValue>
class TablaIterator : public std::iterator<std::forward_iterator_tag, typename Tabla<TKey, TValue>::Celda>
{
    typedef typename std::vector<typename Tabla<TKey, TValue>::ListaDatos>::iterator PtrCelda;
    typedef typename Tabla<TKey, TValue>::ListaDatos::iterator PtrInerCelda;
    PtrCelda it;
    PtrCelda end;
    PtrInerCelda it2;

public:
    TablaIterator(PtrCelda ptrIni, PtrCelda ptrEnd);
    TablaIterator();

    // operators overload
    bool operator==(const TablaIterator<TKey, TValue>&);
    bool operator!=(const TablaIterator<TKey, TValue>&);
    typename Tabla<TKey, TValue>::Celda& operator*();
    TablaIterator<TKey, TValue> operator++(); //prefix
    TablaIterator<TKey, TValue> operator++(int); //postfix
};


/**
 * Constructor of class
 * @param ptrIni Pointer to the first element of the list
 * @param ptrEnd Pointer to the end of the list
 */
template <typename TKey, typename TValue>
TablaIterator<TKey, TValue>::TablaIterator(PtrCelda ptrIni, PtrCelda ptrFin)
{
    // Buscar un valor no nulo dentro de tabla
    while(ptrIni != ptrFin && ptrIni->empty())
        ptrIni++;

    it = ptrIni;
    end = ptrFin;
    if (it != end) {
        it2 = it->begin();
    } else {
        it2 = typename Tabla<TKey, TValue>::ListaDatos::iterator();
    }
}

/**
 * Constructor of class
 */
template <typename TKey, typename TValue>
TablaIterator<TKey, TValue>::TablaIterator()
{
    it = typename TablaIterator<TKey, TValue>::PtrCelda();
    it2 = typename TablaIterator<TKey, TValue>::PtrInerCelda();
}

/**
 * Operator overload ==
 * @param it Iterator to compare
 * @return true if both iterators are equal, false otherwise
 */
template <typename TKey, typename TValue>
bool TablaIterator<TKey, TValue>::operator==(const TablaIterator<TKey, TValue>& otherIt)
{
    return (it == otherIt.it && it2 == otherIt.it2);
}

/**
 * Operator overload !=
 * @param it Iterator to compare
 * @return true if both iterators are not equal, false otherwise
 */
template <typename TKey, typename TValue>
bool TablaIterator<TKey, TValue>::operator!=(const TablaIterator<TKey, TValue>& otherIt)
{
    return !(it == otherIt.it && it2 == otherIt.it2);
}

/**
 * Operator overload *
 * @return Value pointed by the iterator
 */
template <typename TKey, typename TValue>
typename Tabla<TKey, TValue>::Celda& TablaIterator<TKey, TValue>::operator*()
{
    return *it2; 
}

/**
 * Operator overload ++ (prefix)
 * @return Iterator pointing to the next element
 */
template <typename TKey, typename TValue>
TablaIterator<TKey, TValue> TablaIterator<TKey, TValue>::operator++()
{
    // hay que comprobar que it 2 puede avanzar
    it2++;

    if (it2 == it->end()) {
        // Buscar un valor no nulo dentro de tabla
        it++;
        while(it != end && it->empty())
            it++;

        if (it != end) {
            it2 = it->begin();
        } else {
            it2 = typename Tabla<TKey, TValue>::ListaDatos::iterator();
        }
    } 

    return *this;
}


/**
 * Operator overload ++ (postfix)
 * @return Iterator pointing to the next element
 */
template <typename TKey, typename TValue>
TablaIterator<TKey, TValue> TablaIterator<TKey, TValue>::operator++(int)
{
    // hay que comprobar que it 2 puede avanzar
    auto aux = *this;
    it2++;
    if (it2 == it->end()) {
        // Buscar un valor no nulo dentro de tabla
        it++;
        while(it != end && it->empty()){
            it++;
        }

        if (it != end) {
            it2 = it->begin();
        } else {
            it2 = typename Tabla<TKey, TValue>::ListaDatos::iterator();
        }
    } 
    
    return aux;
}


#endif
