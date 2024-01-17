#include <random>
#include <vector>
#include <iostream>

template < template < typename Elem, class Allocator = std::allocator<Elem> > class Container = std::vector,
           typename T>
Container<T> random(T ini, T end, unsigned tam, unsigned seed);

int main() {
    std::vector<int> v1;
    v1 = random<std::vector>(0, 20, 5, 2);

    for (int &i : v1) {
        std::cout << i << '\n';
    }
}

template < template < typename Elem, class Allocator = std::allocator<Elem> > class Container = std::vector,
           typename T>
Container<T> random(T ini, T end, unsigned tam, unsigned seed) {
    static_assert(std::is_integral<T>::value, "no es un entero");
    Container<T> v(tam);

    std::uniform_int_distribution<T> distribution(ini, end);
    std::mt19937 rand(seed);

    for (T &a : v)
        a = distribution(rand);

    return v;
}