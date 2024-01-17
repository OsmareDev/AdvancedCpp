#include "lista.h"
#include "tabla.h"
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void printContainer(T ini, T end);

int main()
{
    Lista<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    std::cout << "******** TESTING LISTA ******** \n\n";
    // 1
    std::cout << "\n[1] ......................... " << '\n';
    Lista<int>::iterator it2;
    it2 = list.begin();
    std::cout << *it2 << std::endl;

    // 2
    std::cout << "\n[2] ......................... " << '\n';
    printContainer(list.begin(), list.end());

    // 3
    std::cout << "\n[3] ......................... " << '\n';
    std::vector<int> v2(std::distance(list.begin(), list.end()));
    std::copy(list.begin(), list.end(), v2.begin());
    printContainer(v2.begin(), v2.end());

    // 4
    std::cout << "\n[4] ......................... " << '\n';
    std::cout << *std::min_element(list.begin(), list.end()) << std::endl;

    std::cout << "\n\n ******** TESTING TABLA ******** \n\n";

    // probando tabla

    // 1
    std::cout << "\n[1] ......................... " << '\n';
    Tabla<std::string, std::string> t(5);
    t.insertar("123", "hello1");
    t.insertar("124", "hello2");
    t.insertar("125", "hello3");
    t.insertar("125", "hello4");
    t.insertar("125", "hello5");

    Tabla<std::string, std::string>::iterator it;
    it = t.begin();
    std::cout << *it << std::endl;

    // 2
    std::cout << "\n[2] ......................... " << '\n';
    printContainer(t.begin(), t.end());

    // 3
    std::cout << "\n[3] ......................... " << '\n';
    std::vector<Tabla<std::string, std::string>::Celda> v(std::distance(t.begin(), t.end()));
    std::copy(t.begin(), t.end(), v.begin());
    printContainer(v.begin(), v.end());

    // 4
    std::cout << "\n[4] ......................... " << '\n';
    std::cout << *std::min_element(t.begin(), t.end()) << '\n';
}

template <typename T>
void printContainer(T ini, T end)
{
    for (auto x = ini; x != end; x++)
        std::cout << *x << '\n';
}

/*
******** How to implement const_iterator in ListaIterator ********

--> The only thing you would have to do is change the return of the * operator to a constant by reference so that the cell value cannot be modified.


template <typename T>
const T &ListIterator<T>::operator*()
{
     return it->value;
}

--> This instruction gives an error since you are trying to modify the value of the cell, but since the * operator returns a constant value by reference, it cannot be modified.

int &x = *it2;

*/
