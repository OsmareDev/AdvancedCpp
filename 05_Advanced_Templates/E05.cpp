#include <iterator>
#include <vector>
#include <math.h>
#include <iostream>

struct GeometricPolicy {
    template<typename T>
    static typename std::iterator_traits<T>::value_type obtain(T ini, T end) {
        typename std::iterator_traits<T>::value_type resultado = 1;

        for (T x = ini; x != end; ++x)
            resultado *= *x;

        return pow(resultado, 1./(end-ini));
    }
};

struct HarmonicPolicy {
    template<typename T>
    static typename std::iterator_traits<T>::value_type obtain(T ini, T end) {
        typename std::iterator_traits<T>::value_type resultado = 0;
        
        for (T x = ini; x != end; ++x)
            resultado += 1./ *x;
        
        return (end-ini)/resultado;
    }
};

int main() {
    std::vector<int> v = {1,2,3,4,5};

    std::cout << GeometricPolicy::obtain(v.begin(), v.end()) << '\n';
    std::cout << HarmonicPolicy::obtain(v.begin(), v.end()) << '\n';
}
