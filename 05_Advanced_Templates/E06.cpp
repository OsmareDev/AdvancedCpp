#include <iostream>

template<int n, int i=0>
struct B2D {
    static const int resultado = ((n%10)<<i) + B2D<n/10, i+1>::resultado;
};

template<int i>
struct B2D<0, i> {
    static const int resultado = 0;
};

int main() {
    std::cout << "1101: " << B2D<1101>::resultado << '\n';
    std::cout << "1000: " << B2D<1000>::resultado << '\n';
    std::cout << "1001: " << B2D<1001>::resultado << '\n';
    std::cout << "0001: " << B2D<0001>::resultado << '\n';
}