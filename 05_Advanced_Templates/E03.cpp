#include <iterator>
#include <vector>
#include <list>
#include <iostream>

template <typename It>
typename std::iterator_traits<It>::value_type sumar (It ini, It end);

int main() {
    std::vector<int> v1 = {1,1,1,1,1};
    std::list<int> l1 = {1,1,1,1,1};

    std::cout << "Suma de vector v1: " << sumar(v1.begin(), v1.end()) << '\n';
    std::cout << "Suma de lista l1: " << sumar(l1.begin(), l1.end()) << '\n';
}

template <typename It>
typename std::iterator_traits<It>::value_type sumar (It ini, It end) {
    typename std::iterator_traits<It>::value_type suma = 0;

    while(ini != end) {
        suma += *ini;
        ++ini;
    }

    return suma;
}