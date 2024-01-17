#include <iostream>
#include <stdexcept>

template<typename T, unsigned N>
class Array2 {
    unsigned size;
    T item[N];

    public:
        T& operator[] (unsigned n);
};

int main() {
    Array2<int, 10> a;

    std::cout << a[5] << "\n";
    a[5] = 10;
    std::cout << a[5] << "\n";
}

template<typename T, unsigned N>
T& Array2<T,N>::operator[] (unsigned n){
    if (n >= N){
        throw std::out_of_range("out of range");
    } else {
        return item[n];
    }
}