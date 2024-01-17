/**
 * Single linked list implementation
 * 
 */

#ifndef _LISTA_H
#define _LISTA_H

#include<iostream>
#include<iterator>

template <typename T>
class ListaIterator;

/**
 * Single linked list
 * @tparam T Type of the elements in the list
 */
template<typename T>
class Lista
{
    struct Nodo
    {
        T valor;
        Nodo* sig;
    };
    
    typedef Nodo* PtrNodo;
    PtrNodo ptr;
public:
    typedef ListaIterator<T> iterator;
    typedef T value_type;
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;

    friend class ListaIterator<T>;
    iterator begin();
    iterator end();
};

/**
 * Add element at the beginning of the list
 * @param x element
 */
template<typename T>
void Lista<T>::push_front(const T & x)
{
    PtrNodo aux = new Nodo;
    aux->valor = x;
    aux->sig = ptr;
    ptr = aux;
}

/**
 * Show the list
 */
template<typename T>
void Lista<T>::mostrar() const
{
    PtrNodo aux = ptr;
    
    while(aux != nullptr)
    {
        std::cout << aux->valor << " ";
        aux = aux->sig;
    }
}


/**
 * Create and return an IteratorList pointing to the first element of Lista
 * @return ListaIterator<T> list 
 */
template <typename T>
typename Lista<T>::iterator Lista<T>::begin() { 
    return ptr; 
};

/**
 * Create and return an IteratorList pointing to the end of Lista
 * @return ListaIterator<T> list 
 */
template <typename T>
typename Lista<T>::iterator Lista<T>::end() { 
    return nullptr; 
};



/****************************************************************************************
 *                                                                                      *
 *                                  LISTA ITERATOR                                      *
 *                                                                                      *
 ***************************************************************************************/


// https://en.cppreference.com/w/cpp/iterator/iterator_tags
template <typename T>
class ListaIterator : public std::iterator<std::forward_iterator_tag, T>{
    typedef typename Lista<T>::PtrNodo PtrNodo;
    PtrNodo it;

public:
    ListaIterator(PtrNodo ptr);
    ListaIterator();

    // operators overload
    bool operator==(const ListaIterator<T>&);
    bool operator!=(const ListaIterator<T>&);
    T& operator*();
    ListaIterator<T> operator++(); //prefix
    ListaIterator<T> operator++(int); //postfix
};

/**
 * Constructor
 * @param ptr pointer to the node
 */
template <typename T>
ListaIterator<T>::ListaIterator(PtrNodo ptr) {
    it = ptr;
}

/**
 * Default constructor
 */
template <typename T>
ListaIterator<T>::ListaIterator() {
    it = nullptr;
}

/**
 * Overload of operator ==
 * @param other_it iterator to compare
 * @return true if the iterators are equal, false otherwise
 */
template <typename T>
bool ListaIterator<T>::operator== (const ListaIterator &other_it)
{
    return it == other_it.it;
}

/**
 * Overload of operator !=
 * @param other_it iterator to compare
 * @return true if the iterators are not equal, false otherwise
 */
template <typename T>
bool ListaIterator<T>::operator!= (const ListaIterator &other_it)
{
    return it != other_it.it;
}

/**
 * Overload of operator *
 * @return the value of the node pointed by the iterator
 */
template <typename T>
T& ListaIterator<T>::operator* ()
{
    return it->valor;
}

/**
 * Overload of operator ++(prefix)
 * @return the iterator pointing to the next node
 */
template <typename T>
ListaIterator<T> ListaIterator<T>::operator++ ()
{
    it = it->sig;
    return it;
}

/**
 * Overload of operator ++
 * @return the iterator pointing to the next node
 */
template <typename T>
ListaIterator<T> ListaIterator<T>::operator++ (int)
{
    ListaIterator<T> aux = *this;
    it = it->sig;
    return aux;
}



#endif
