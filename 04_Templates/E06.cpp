#include <iostream>

template<typename T, unsigned N>
class Array2 {
    unsigned size;
    T item[N];

    public:
        Array2(T x){
            for (T &i : item)
                i = x;
        }

        T& operator[] (unsigned n);
};

template<typename T, unsigned N>
int sumarArray2(Array2<T,N> &a);

int main() {
    Array2<int, 10> a(4);

    std::cout << sumarArray2(a) << "\n";
}

template<typename T, unsigned N>
T& Array2<T,N>::operator[] (unsigned n){
    if (n >= N){
        throw std::out_of_range("out of range");
    } else {
        return item[n];
    }
}

template<typename T, unsigned N>
int sumarArray2(Array2<T,N> &a) {
    int suma = 0;
    for(unsigned i = 0; i < N; ++i){
        suma += a[i];
    }
    return suma;
}