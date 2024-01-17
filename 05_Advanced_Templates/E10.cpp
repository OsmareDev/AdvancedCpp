#include <random>
#include <vector>
#include <iostream>
#include <type_traits>

template < template < typename Elem, class Allocator = std::allocator<Elem> > class Container = std::vector,
           typename T>
typename std::enable_if<std::is_integral<T>::value, Container<T>>::type random(T ini, T end, unsigned tam, unsigned seed) {
    static_assert(std::is_integral<T>::value, "no es un entero");
    Container<T> v(tam);

    std::uniform_int_distribution<T> distribution(ini, end);
    std::mt19937 rand(seed);

    for (T &a : v)
        a = distribution(rand);

    return v;
}

template < template < typename Elem, class Allocator = std::allocator<Elem> > class Container = std::vector,
           typename T>
typename std::enable_if<std::is_floating_point<T>::value, Container<T>>::type random(T ini, T end, unsigned tam, unsigned seed) {
    static_assert(std::is_floating_point<T>::value, "no es un real");
    Container<T> v(tam);

    std::uniform_real_distribution<T> distribution(ini, end);
    std::mt19937 rand(seed);

    for (T &a : v)
        a = distribution(rand);

    return v;
}

int main() {
    std::vector<int> v1;
    v1 = random<std::vector>(0, 20, 5, 2);
    std::vector<float> v2;
    v2 = random<std::vector>(0.f, 20.f, 5, 2);

    for (int &i : v1) {
        std::cout << i << '\n';
    }
    for (float &i : v2) {
        std::cout << i << '\n';
    }
}